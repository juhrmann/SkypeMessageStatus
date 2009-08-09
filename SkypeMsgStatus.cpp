/*
	Programm to indicate unsent skype messages in the system tray.
	J. Uhrmann, 08.2009

	All rights reserved.
*/

#include <QApplication>

#include <QIcon>
#include "SkypeTrayIcon.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	
	SkypeTrayIcon sti;

	return app.exec();
}
