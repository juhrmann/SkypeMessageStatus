#    Copyright Johann Uhrmann 2009
#
#    This file is part of SkypeMessageStatus.
#
#    SkypeMessageStatus is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    SkypeMessageStatus is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with SkypeMessageStatus.  If not, see <http://www.gnu.org/licenses/>.



TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += qdbus

# Input
HEADERS += client_adaptor.h skype_interface.h SkypeTrayIcon.h
SOURCES += client_adaptor.cpp \
           skype_interface.cpp \
           SkypeMsgStatus.cpp \
           SkypeTrayIcon.cpp
