/****************************************************************************
** Meta object code from reading C++ file 'SkypeTrayIcon.h'
**
** Created: Sat Aug 8 23:12:15 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SkypeTrayIcon.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SkypeTrayIcon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_SkypeTrayIcon[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x0a,
      49,   39,   14,   14, 0x08,
      78,   14,   14,   14, 0x08,
      92,   14,   14,   14, 0x08,
     113,  106,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SkypeTrayIcon[] = {
    "SkypeTrayIcon\0\0message\0Notify(QString)\0"
    "msg_state\0changeState(skype_msg_state)\0"
    "detectSkype()\0updateState()\0reason\0"
    "on_trayIcon_activated(QSystemTrayIcon::ActivationReason)\0"
};

const QMetaObject SkypeTrayIcon::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SkypeTrayIcon,
      qt_meta_data_SkypeTrayIcon, 0 }
};

const QMetaObject *SkypeTrayIcon::metaObject() const
{
    return &staticMetaObject;
}

void *SkypeTrayIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SkypeTrayIcon))
	return static_cast<void*>(const_cast< SkypeTrayIcon*>(this));
    return QObject::qt_metacast(_clname);
}

int SkypeTrayIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Notify((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: changeState((*reinterpret_cast< skype_msg_state(*)>(_a[1]))); break;
        case 2: detectSkype(); break;
        case 3: updateState(); break;
        case 4: on_trayIcon_activated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        }
        _id -= 5;
    }
    return _id;
}
