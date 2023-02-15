/****************************************************************************
** Meta object code from reading C++ file 'qammodbusmapviewer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ModipMap/qammodbusmapviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qammodbusmapviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QamModbusMapViewer_t {
    const uint offsetsAndSize[16];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_QamModbusMapViewer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_QamModbusMapViewer_t qt_meta_stringdata_QamModbusMapViewer = {
    {
QT_MOC_LITERAL(0, 18), // "QamModbusMapViewer"
QT_MOC_LITERAL(19, 11), // "itemChanged"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 14), // "QStandardItem*"
QT_MOC_LITERAL(47, 4), // "item"
QT_MOC_LITERAL(52, 16), // "updateModbusData"
QT_MOC_LITERAL(69, 5), // "table"
QT_MOC_LITERAL(75, 4) // "name"

    },
    "QamModbusMapViewer\0itemChanged\0\0"
    "QStandardItem*\0item\0updateModbusData\0"
    "table\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QamModbusMapViewer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x08,    1 /* Private */,
       5,    2,   29,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    7,

       0        // eod
};

void QamModbusMapViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QamModbusMapViewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->itemChanged((*reinterpret_cast< std::add_pointer_t<QStandardItem*>>(_a[1]))); break;
        case 1: _t->updateModbusData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject QamModbusMapViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeView::staticMetaObject>(),
    qt_meta_stringdata_QamModbusMapViewer.offsetsAndSize,
    qt_meta_data_QamModbusMapViewer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_QamModbusMapViewer_t
, QtPrivate::TypeAndForceComplete<QamModbusMapViewer, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStandardItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *QamModbusMapViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QamModbusMapViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QamModbusMapViewer.stringdata0))
        return static_cast<void*>(this);
    return QTreeView::qt_metacast(_clname);
}

int QamModbusMapViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
