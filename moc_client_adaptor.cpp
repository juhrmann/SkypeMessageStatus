/****************************************************************************
** Meta object code from reading C++ file 'client_adaptor.h'
**
** Created: Sat Aug 8 21:47:52 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "client_adaptor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client_adaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_ClientAdaptor[] = {

 // content:
       1,       // revision
       0,       // classname
       2,   10, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // classinfo: key, value
      35,   14,
     282,   51,

 // slots: signature, parameters, type, tag, flags
     321,  313,  312,  302, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ClientAdaptor[] = {
    "ClientAdaptor\0com.Skype.API.Client\0"
    "D-Bus Interface\0"
    "  <interface name=\"com.Skype.API.Client\" >\n    <method name=\"Notif"
    "y\" >\n      <annotation value=\"true\" name=\"org.freedesktop.DBus.Me"
    "thod.NoReply\" />\n      <arg direction=\"in\" type=\"s\" name=\"messa"
    "ge\" />\n    </method>\n  </interface>\n\0"
    "D-Bus Introspection\0Q_NOREPLY\0\0message\0"
    "Notify(QString)\0"
};

const QMetaObject ClientAdaptor::staticMetaObject = {
    { &QDBusAbstractAdaptor::staticMetaObject, qt_meta_stringdata_ClientAdaptor,
      qt_meta_data_ClientAdaptor, 0 }
};

const QMetaObject *ClientAdaptor::metaObject() const
{
    return &staticMetaObject;
}

void *ClientAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientAdaptor))
	return static_cast<void*>(const_cast< ClientAdaptor*>(this));
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int ClientAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Notify((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
    return _id;
}
