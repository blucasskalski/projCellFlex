/****************************************************************************
** Meta object code from reading C++ file 'qamtcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ModipTcp/qamtcpclient.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qamtcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_QamTcpClient_t {
    uint offsetsAndSizes[26];
    char stringdata0[13];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[10];
    char stringdata5[10];
    char stringdata6[5];
    char stringdata7[9];
    char stringdata8[10];
    char stringdata9[29];
    char stringdata10[6];
    char stringdata11[14];
    char stringdata12[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QamTcpClient_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QamTcpClient_t qt_meta_stringdata_QamTcpClient = {
    {
        QT_MOC_LITERAL(0, 12),  // "QamTcpClient"
        QT_MOC_LITERAL(13, 11),  // "sockReceive"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 8),  // "sockInfo"
        QT_MOC_LITERAL(35, 9),  // "sockClose"
        QT_MOC_LITERAL(45, 9),  // "sockWrite"
        QT_MOC_LITERAL(55, 4),  // "data"
        QT_MOC_LITERAL(60, 8),  // "sockRead"
        QT_MOC_LITERAL(69, 9),  // "sockError"
        QT_MOC_LITERAL(79, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(108, 5),  // "error"
        QT_MOC_LITERAL(114, 13),  // "sockConnected"
        QT_MOC_LITERAL(128, 16)   // "sockDisconnected"
    },
    "QamTcpClient",
    "sockReceive",
    "",
    "sockInfo",
    "sockClose",
    "sockWrite",
    "data",
    "sockRead",
    "sockError",
    "QAbstractSocket::SocketError",
    "error",
    "sockConnected",
    "sockDisconnected"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QamTcpClient[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       3,    1,   65,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   68,    2, 0x0a,    5 /* Public */,
       5,    1,   69,    2, 0x0a,    6 /* Public */,
       7,    0,   72,    2, 0x08,    8 /* Private */,
       8,    1,   73,    2, 0x08,    9 /* Private */,
      11,    0,   76,    2, 0x08,   11 /* Private */,
      12,    0,   77,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QamTcpClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpSocket::staticMetaObject>(),
    qt_meta_stringdata_QamTcpClient.offsetsAndSizes,
    qt_meta_data_QamTcpClient,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QamTcpClient_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QamTcpClient, std::true_type>,
        // method 'sockReceive'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'sockInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sockClose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sockWrite'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'sockRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sockError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'sockConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sockDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QamTcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QamTcpClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sockReceive((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 1: _t->sockInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->sockClose(); break;
        case 3: _t->sockWrite((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 4: _t->sockRead(); break;
        case 5: _t->sockError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 6: _t->sockConnected(); break;
        case 7: _t->sockDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QamTcpClient::*)(const QByteArray & );
            if (_t _q_method = &QamTcpClient::sockReceive; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QamTcpClient::*)(const QString & );
            if (_t _q_method = &QamTcpClient::sockInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *QamTcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QamTcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QamTcpClient.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int QamTcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QamTcpClient::sockReceive(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QamTcpClient::sockInfo(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
