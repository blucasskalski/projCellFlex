/****************************************************************************
** Meta object code from reading C++ file 'camera.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "camera.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_camera_t {
    uint offsetsAndSizes[36];
    char stringdata0[7];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[28];
    char stringdata4[11];
    char stringdata5[18];
    char stringdata6[17];
    char stringdata7[11];
    char stringdata8[7];
    char stringdata9[12];
    char stringdata10[12];
    char stringdata11[14];
    char stringdata12[14];
    char stringdata13[14];
    char stringdata14[12];
    char stringdata15[15];
    char stringdata16[13];
    char stringdata17[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_camera_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_camera_t qt_meta_stringdata_camera = {
    {
        QT_MOC_LITERAL(0, 6),  // "camera"
        QT_MOC_LITERAL(7, 16),  // "erreurConnection"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 27),  // "QNetworkReply::NetworkError"
        QT_MOC_LITERAL(53, 10),  // "connection"
        QT_MOC_LITERAL(64, 17),  // "reponse_connexion"
        QT_MOC_LITERAL(82, 16),  // "traitement_photo"
        QT_MOC_LITERAL(99, 10),  // "mousepoint"
        QT_MOC_LITERAL(110, 6),  // "config"
        QT_MOC_LITERAL(117, 11),  // "valeur_bin1"
        QT_MOC_LITERAL(129, 11),  // "valeur_bin2"
        QT_MOC_LITERAL(141, 13),  // "valeur_blanc1"
        QT_MOC_LITERAL(155, 13),  // "valeur_blanc2"
        QT_MOC_LITERAL(169, 13),  // "message_photo"
        QT_MOC_LITERAL(183, 11),  // "save_config"
        QT_MOC_LITERAL(195, 14),  // "traitement_spe"
        QT_MOC_LITERAL(210, 12),  // "creation_BdD"
        QT_MOC_LITERAL(223, 14)   // "reglage_button"
    },
    "camera",
    "erreurConnection",
    "",
    "QNetworkReply::NetworkError",
    "connection",
    "reponse_connexion",
    "traitement_photo",
    "mousepoint",
    "config",
    "valeur_bin1",
    "valeur_bin2",
    "valeur_blanc1",
    "valeur_blanc2",
    "message_photo",
    "save_config",
    "traitement_spe",
    "creation_BdD",
    "reglage_button"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_camera[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x0a,    1 /* Public */,
       4,    0,  107,    2, 0x0a,    3 /* Public */,
       5,    0,  108,    2, 0x0a,    4 /* Public */,
       6,    0,  109,    2, 0x0a,    5 /* Public */,
       7,    4,  110,    2, 0x0a,    6 /* Public */,
       8,    0,  119,    2, 0x0a,   11 /* Public */,
       9,    1,  120,    2, 0x0a,   12 /* Public */,
      10,    1,  123,    2, 0x0a,   14 /* Public */,
      11,    1,  126,    2, 0x0a,   16 /* Public */,
      12,    1,  129,    2, 0x0a,   18 /* Public */,
      13,    0,  132,    2, 0x0a,   20 /* Public */,
      14,    0,  133,    2, 0x0a,   21 /* Public */,
      15,    0,  134,    2, 0x0a,   22 /* Public */,
      16,    0,  135,    2, 0x0a,   23 /* Public */,
      17,    0,  136,    2, 0x0a,   24 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject camera::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_camera.offsetsAndSizes,
    qt_meta_data_camera,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_camera_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<camera, std::true_type>,
        // method 'erreurConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply::NetworkError, std::false_type>,
        // method 'connection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reponse_connexion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'traitement_photo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mousepoint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'config'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'valeur_bin1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'valeur_bin2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'valeur_blanc1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'valeur_blanc2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'message_photo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'save_config'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'traitement_spe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'creation_BdD'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reglage_button'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<camera *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->erreurConnection((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1]))); break;
        case 1: _t->connection(); break;
        case 2: _t->reponse_connexion(); break;
        case 3: _t->traitement_photo(); break;
        case 4: _t->mousepoint((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 5: _t->config(); break;
        case 6: _t->valeur_bin1((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->valeur_bin2((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->valeur_blanc1((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->valeur_blanc2((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->message_photo(); break;
        case 11: _t->save_config(); break;
        case 12: _t->traitement_spe(); break;
        case 13: _t->creation_BdD(); break;
        case 14: _t->reglage_button(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    }
}

const QMetaObject *camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *camera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_camera.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
