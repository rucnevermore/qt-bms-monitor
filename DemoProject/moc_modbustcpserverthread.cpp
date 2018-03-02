/****************************************************************************
** Meta object code from reading C++ file 'modbustcpserverthread.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "modbustcpserverthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbustcpserverthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ModbusTCPServerThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   23,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   22,   22,   22, 0x0a,
      46,   22,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ModbusTCPServerThread[] = {
    "ModbusTCPServerThread\0\0str\0log(QString)\0"
    "run()\0stop()\0"
};

void ModbusTCPServerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ModbusTCPServerThread *_t = static_cast<ModbusTCPServerThread *>(_o);
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->run(); break;
        case 2: _t->stop(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ModbusTCPServerThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ModbusTCPServerThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ModbusTCPServerThread,
      qt_meta_data_ModbusTCPServerThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ModbusTCPServerThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ModbusTCPServerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ModbusTCPServerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusTCPServerThread))
        return static_cast<void*>(const_cast< ModbusTCPServerThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ModbusTCPServerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ModbusTCPServerThread::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
