/****************************************************************************
** Meta object code from reading C++ file 'contoursui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../opencv_opengl_toolbox/contoursui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contoursui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_contoursUI_t {
    QByteArrayData data[18];
    char stringdata[407];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_contoursUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_contoursUI_t qt_meta_stringdata_contoursUI = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 12),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 28),
QT_MOC_LITERAL(4, 54, 4),
QT_MOC_LITERAL(5, 59, 31),
QT_MOC_LITERAL(6, 91, 28),
QT_MOC_LITERAL(7, 120, 28),
QT_MOC_LITERAL(8, 149, 28),
QT_MOC_LITERAL(9, 178, 23),
QT_MOC_LITERAL(10, 202, 26),
QT_MOC_LITERAL(11, 229, 26),
QT_MOC_LITERAL(12, 256, 28),
QT_MOC_LITERAL(13, 285, 23),
QT_MOC_LITERAL(14, 309, 26),
QT_MOC_LITERAL(15, 336, 23),
QT_MOC_LITERAL(16, 360, 23),
QT_MOC_LITERAL(17, 384, 21)
    },
    "contoursUI\0paramChanged\0\0"
    "on_spinSobelApt_valueChanged\0arg1\0"
    "on_spinSobelThresh_valueChanged\0"
    "on_spinLapKSize_valueChanged\0"
    "on_spinCannyMin_valueChanged\0"
    "on_spinCannyMax_valueChanged\0"
    "on_spinBox_valueChanged\0"
    "on_spinMinRad_valueChanged\0"
    "on_spinMaxRad_valueChanged\0"
    "on_spinCircDist_valueChanged\0"
    "on_spinrho_valueChanged\0"
    "on_spinthresh_valueChanged\0"
    "on_spinmin_valueChanged\0on_spinmax_valueChanged\0"
    "on_pushButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_contoursUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   90,    2, 0x08,
       5,    1,   93,    2, 0x08,
       6,    1,   96,    2, 0x08,
       7,    1,   99,    2, 0x08,
       8,    1,  102,    2, 0x08,
       9,    1,  105,    2, 0x08,
      10,    1,  108,    2, 0x08,
      11,    1,  111,    2, 0x08,
      12,    1,  114,    2, 0x08,
      13,    1,  117,    2, 0x08,
      14,    1,  120,    2, 0x08,
      15,    1,  123,    2, 0x08,
      16,    1,  126,    2, 0x08,
      17,    0,  129,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

void contoursUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        contoursUI *_t = static_cast<contoursUI *>(_o);
        switch (_id) {
        case 0: _t->paramChanged(); break;
        case 1: _t->on_spinSobelApt_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_spinSobelThresh_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_spinLapKSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_spinCannyMin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_spinCannyMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_spinMinRad_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_spinMaxRad_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_spinCircDist_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_spinrho_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_spinthresh_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_spinmin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_spinmax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (contoursUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&contoursUI::paramChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject contoursUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_contoursUI.data,
      qt_meta_data_contoursUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *contoursUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *contoursUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_contoursUI.stringdata))
        return static_cast<void*>(const_cast< contoursUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int contoursUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void contoursUI::paramChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
