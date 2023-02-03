/****************************************************************************
** Meta object code from reading C++ file 'camera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Camera/camera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_camera_t {
    QByteArrayData data[17];
    char stringdata[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_camera_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_camera_t qt_meta_stringdata_camera = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 16),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 27),
QT_MOC_LITERAL(4, 53, 10),
QT_MOC_LITERAL(5, 64, 17),
QT_MOC_LITERAL(6, 82, 16),
QT_MOC_LITERAL(7, 99, 10),
QT_MOC_LITERAL(8, 110, 6),
QT_MOC_LITERAL(9, 117, 11),
QT_MOC_LITERAL(10, 129, 11),
QT_MOC_LITERAL(11, 141, 13),
QT_MOC_LITERAL(12, 155, 13),
QT_MOC_LITERAL(13, 169, 13),
QT_MOC_LITERAL(14, 183, 11),
QT_MOC_LITERAL(15, 195, 14),
QT_MOC_LITERAL(16, 210, 12)
    },
    "camera\0erreurConnection\0\0"
    "QNetworkReply::NetworkError\0connection\0"
    "reponse_connexion\0traitement_photo\0"
    "mousepoint\0config\0valeur_bin1\0valeur_bin2\0"
    "valeur_blanc1\0valeur_blanc2\0message_photo\0"
    "save_config\0traitement_spe\0creation_BdD\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_camera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a,
       4,    0,   87,    2, 0x0a,
       5,    0,   88,    2, 0x0a,
       6,    0,   89,    2, 0x0a,
       7,    4,   90,    2, 0x0a,
       8,    0,   99,    2, 0x0a,
       9,    1,  100,    2, 0x0a,
      10,    1,  103,    2, 0x0a,
      11,    1,  106,    2, 0x0a,
      12,    1,  109,    2, 0x0a,
      13,    0,  112,    2, 0x0a,
      14,    0,  113,    2, 0x0a,
      15,    0,  114,    2, 0x0a,
      16,    0,  115,    2, 0x0a,

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

       0        // eod
};

void camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        camera *_t = static_cast<camera *>(_o);
        switch (_id) {
        case 0: _t->erreurConnection((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 1: _t->connection(); break;
        case 2: _t->reponse_connexion(); break;
        case 3: _t->traitement_photo(); break;
        case 4: _t->mousepoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->config(); break;
        case 6: _t->valeur_bin1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->valeur_bin2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->valeur_blanc1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->valeur_blanc2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->message_photo(); break;
        case 11: _t->save_config(); break;
        case 12: _t->traitement_spe(); break;
        case 13: _t->creation_BdD(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    }
}

const QMetaObject camera::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_camera.data,
      qt_meta_data_camera,  qt_static_metacall, 0, 0}
};


const QMetaObject *camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *camera::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_camera.stringdata))
        return static_cast<void*>(const_cast< camera*>(this));
    return QWidget::qt_metacast(_clname);
}

int camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
