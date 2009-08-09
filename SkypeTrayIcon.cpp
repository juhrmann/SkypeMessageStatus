/*
    Copyright Johann Uhrmann 2009

    This file is part of SkypeMessageStatus.

    SkypeMessageStatus is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SkypeMessageStatus is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SkypeMessageStatus.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "SkypeTrayIcon.h"
#include <QIcon>
#include <QRegExp>
#include <QSet>
#include <QtDebug>
#include "client_adaptor.h"

using namespace std;



SkypeTrayIcon::SkypeTrayIcon()
:skype(NULL)
{
	connect(&trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(on_trayIcon_activated(QSystemTrayIcon::ActivationReason)));

	trayIcon.hide();
	changeState(SKYPE_NOT_CONNECTED);
	new ClientAdaptor(this);

	if (!QDBusConnection::sessionBus().registerObject("/com/Skype/Client", this))
        {
                qFatal(qPrintable(QDBusConnection::sessionBus().lastError().message()));
        }

	detectSkype();
}

void SkypeTrayIcon::detectSkype()
{
	delete skype;

	skype = new ComSkypeAPIInterface("com.Skype.API", "/com/Skype", QDBusConnection::sessionBus(), this);
	if (!skype->isValid())
	{
		changeState(SKYPE_NOT_CONNECTED);
		delete skype;
		skype = NULL;
	}
	else
	{
		SendMessage("NAME SkypeMessageStatus");
		SendMessage("PROTOCOL 5");
		updateState();
	}
}

void SkypeTrayIcon::Notify(const QString &message)
{
	static QRegExp pendingMsgRegExp("^CHATMESSAGE (\\d+) STATUS SENDING");
	static QRegExp ackedMsgRegExp("^CHATMESSAGE (\\d+) STATUS SENT");

	// Check for new message being sent...
	if (pendingMsgRegExp.indexIn(message) != -1)
	{
		queueMessage(pendingMsgRegExp.cap(1));
		return;
	}

	// Check for acknoledged messages
	if (ackedMsgRegExp.indexIn(message) != -1)
	{
		ackedMessage(ackedMsgRegExp.cap(1));
		return;
	}
}

void SkypeTrayIcon::queueMessage(QString msgNumber)
{
	// Get the type of the message
	QString reply = SendMessage(QString("GET CHATMESSAGE " + msgNumber + " TYPE"));
	
	QString expect("CHATMESSAGE ");
	expect.append(msgNumber);
	expect.append(" TYPE SAID");

	// if message was no chat message -> done
	if (reply != expect)
		return;

	skype_message msg;
	msg.number = msgNumber;
	
	// Get the body of the chatmessage
	reply = SendMessage(QString("GET CHATMESSAGE " + msgNumber + " BODY"));
	QRegExp getBody(QString("^CHATMESSAGE ") + msgNumber + " BODY (.*)");
	if (getBody.indexIn(reply) != -1)
	{
		msg.body = getBody.cap(1);
	}

	pending_messages.append(msg);

	updateState();
}

void SkypeTrayIcon::ackedMessage(QString msgNumber)
{
	static QSet<QString> acked;
	acked.insert(msgNumber);

	QList<struct skype_message>::iterator it = pending_messages.begin();
	while (it != pending_messages.end())
	{
		if (acked.remove(it->number))
		{
			it = pending_messages.erase(it);
			continue;
		}

		it++;
	}

	updateState();
}

QString SkypeTrayIcon::SendMessage(const QString & text)
{
	if (skype == NULL)
		detectSkype();

	if (skype == NULL)
		return "";

	QDBusReply<QString> reply = skype->Invoke(text);
	if (!reply.isValid())
	{
		changeState(SKYPE_NOT_CONNECTED);
		return "";
	}

	return reply.value();
}

void SkypeTrayIcon::changeState(enum skype_msg_state state)
{
	static QIcon black("black.xpm");
	static QIcon red("red.xpm");
	static QIcon green("green.xpm");

	trayIcon.hide();

	switch (state)
	{
		case SKYPE_NOT_CONNECTED:
			trayIcon.setIcon(black);
			trayIcon.setToolTip("Connecting to Skype...");
			break;

		case SKYPE_MSG_PENDING:
			trayIcon.setIcon(red);
			{
				QString tt = "Unsent messages:\n";
				for (QList<struct skype_message>::iterator it = pending_messages.begin(); it != pending_messages.end(); it++)
				{
					tt.append(it->body);
					tt.append("\n");
				}
				trayIcon.setToolTip(tt);
			}
			break;

		case SKYPE_ALL_SENT:
			trayIcon.setIcon(green);
			trayIcon.setToolTip("There are no unsent messages!");
			break;
	}
	trayIcon.show();
}

void SkypeTrayIcon::updateState()
{
	if (skype == NULL)
	{
		changeState(SKYPE_NOT_CONNECTED);
		return;
	}

	changeState(pending_messages.isEmpty() ? SKYPE_ALL_SENT : SKYPE_MSG_PENDING);
}

void SkypeTrayIcon::on_trayIcon_activated(QSystemTrayIcon::ActivationReason reason)
{
	// On doubleclick, reset state to "no pending messages"
	if (reason == QSystemTrayIcon::DoubleClick)
	{
		pending_messages.clear();
		updateState();
	}
}

