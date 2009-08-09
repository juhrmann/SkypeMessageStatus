/*
	Programm to indicate unsent skype messages in the system tray.
	J. Uhrmann, 08.2009

	All rights reserved.
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
