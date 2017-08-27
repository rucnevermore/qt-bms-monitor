/****************************************************************************
** Meta object code from reading C++ file 'displaythread.h'
**
** Created: Sun Aug 27 03:13:20 2017
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "displaythread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displaythread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DisplayThread[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,   14,   14,   14, 0x0a,
      31,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DisplayThread[] = {
    "DisplayThread\0\0display()\0run()\0stop()\0"
};

const QMetaObject DisplayThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DisplayThread,
      qt_meta_data_DisplayThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DisplayThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DisplayThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DisplayThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DisplayThread))
        return static_cast<void*>(const_cast< DisplayThread*>(this));
    return QThread::qt_metacast(_clname);
}

int DisplayThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: display(); break;
        case 1: run(); break;
        case 2: stop(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DisplayThread::display()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
