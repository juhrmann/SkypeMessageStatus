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

#ifndef SKYPETRAYICON_H
#define SKYPETRAYICON_H

#include <QSystemTrayIcon>
#include <QHash>
#include "skype_interface.h"

enum skype_msg_state
{
	SKYPE_NOT_CONNECTED,
	SKYPE_MSG_PENDING,
	SKYPE_ALL_SENT
};

class SkypeTrayIcon : QObject
{
	Q_OBJECT
public:
	SkypeTrayIcon();

public Q_SLOTS:
	void Notify(const QString &message);	// called from ClientAdaptor

private Q_SLOTS:
	void changeState(enum skype_msg_state msg_state);
	void detectSkype();
	void updateState();
	void on_trayIcon_activated(QSystemTrayIcon::ActivationReason reason);

private:
	QSystemTrayIcon trayIcon;	
	ComSkypeAPIInterface *skype;
	QString SendMessage(const QString & text);

	void queueMessage(QString msgNumber);
	void ackedMessage(QString msgNumber);

	struct skype_message
	{
		QString number;
		QString body;
	};

	QList<struct skype_message> pending_messages;
};

#endif
