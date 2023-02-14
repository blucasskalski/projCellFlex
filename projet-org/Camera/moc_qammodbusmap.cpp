/****************************************************************************
** Meta object code from reading C++ file 'qammodbusmap.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qammodbusmap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qammodbusmap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QamModbusMap_t {
    const uint offsetsAndSize[30];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_QamModbusMap_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_QamModbusMap_t qt_meta_stringdata_QamModbusMap = {
    {
QT_MOC_LITERAL(0, 12), // "QamModbusMap"
QT_MOC_LITERAL(13, 12), // "responseDone"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 12), // "valueChanged"
QT_MOC_LITERAL(40, 5), // "table"
QT_MOC_LITERAL(46, 4), // "name"
QT_MOC_LITERAL(51, 4), // "info"
QT_MOC_LITERAL(56, 6), // "source"
QT_MOC_LITERAL(63, 7), // "message"
QT_MOC_LITERAL(71, 8), // "response"
QT_MOC_LITERAL(80, 8), // "setValue"
QT_MOC_LITERAL(89, 12), // "PrimaryTable"
QT_MOC_LITERAL(102, 5), // "value"
QT_MOC_LITERAL(108, 13), // "setLocalValue"
QT_MOC_LITERAL(122, 14) // "setRemoteValue"

    },
    "QamModbusMap\0responseDone\0\0valueChanged\0"
    "table\0name\0info\0source\0message\0response\0"
    "setValue\0PrimaryTable\0value\0setLocalValue\0"
    "setRemoteValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QamModbusMap[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    2,   57,    2, 0x06,    2 /* Public */,
       6,    2,   62,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   67,    2, 0x0a,    8 /* Public */,
      10,    3,   70,    2, 0x0a,   10 /* Public */,
      13,    3,   77,    2, 0x0a,   14 /* Public */,
      14,    3,   84,    2, 0x0a,   18 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString, QMetaType::QString,    4,    5,   12,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString, QMetaType::QString,    4,    5,   12,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString, QMetaType::QString,    4,    5,   12,

       0        // eod
};

void QamModbusMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QamModbusMap *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->responseDone(); break;
        case 1: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->info((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->response((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 4: _t->setValue((*reinterpret_cast< std::add_pointer_t<PrimaryTable>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 5: _t->setLocalValue((*reinterpret_cast< std::add_pointer_t<PrimaryTable>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 6: _t->setRemoteValue((*reinterpret_cast< std::add_pointer_t<PrimaryTable>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QamModbusMap::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QamModbusMap::responseDone)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QamModbusMap::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QamModbusMap::valueChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QamModbusMap::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QamModbusMap::info)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QamModbusMap::staticMetaObject = { {
    QMetaObject::SuperData::link<QamAbstractServer::staticMetaObject>(),
    qt_meta_stringdata_QamModbusMap.offsetsAndSize,
    qt_meta_data_QamModbusMap,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_QamModbusMap_t
, QtPrivate::TypeAndForceComplete<QamModbusMap, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<PrimaryTable, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<PrimaryTable, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<PrimaryTable, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *QamModbusMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QamModbusMap::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QamModbusMap.stringdata0))
        return static_cast<void*>(this);
    return QamAbstractServer::qt_metacast(_clname);
}

int QamModbusMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QamAbstractServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QamModbusMap::responseDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QamModbusMap::valueChanged(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QamModbusMap::info(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
