/****************************************************************************
** Meta object code from reading C++ file 'skype_interface.h'
**
** Created: Sat Aug 8 21:47:53 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "skype_interface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skype_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_ComSkypeAPIInterface[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      50,   42,   22,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ComSkypeAPIInterface[] = {
    "ComSkypeAPIInterface\0\0QDBusReply<QString>\0"
    "message\0Invoke(QString)\0"
};

const QMetaObject ComSkypeAPIInterface::staticMetaObject = {
    { &QDBusAbstractInterface::staticMetaObject, qt_meta_stringdata_ComSkypeAPIInterface,
      qt_meta_data_ComSkypeAPIInterface, 0 }
};

const QMetaObject *ComSkypeAPIInterface::metaObject() const
{
    return &staticMetaObject;
}

void *ComSkypeAPIInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ComSkypeAPIInterface))
	return static_cast<void*>(const_cast< ComSkypeAPIInterface*>(this));
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int ComSkypeAPIInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QDBusReply<QString> _r = Invoke((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusReply<QString>*>(_a[0]) = _r; }  break;
        }
        _id -= 1;
    }
    return _id;
}
