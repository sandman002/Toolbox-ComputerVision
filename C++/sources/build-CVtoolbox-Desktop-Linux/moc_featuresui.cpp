/****************************************************************************
** Meta object code from reading C++ file 'featuresui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../opencv_opengl_toolbox/featuresui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'featuresui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_featuresUI_t {
    QByteArrayData data[14];
    char stringdata[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_featuresUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_featuresUI_t qt_meta_stringdata_featuresUI = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 10),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 22),
QT_MOC_LITERAL(4, 46, 4),
QT_MOC_LITERAL(5, 51, 26),
QT_MOC_LITERAL(6, 78, 23),
QT_MOC_LITERAL(7, 102, 23),
QT_MOC_LITERAL(8, 126, 22),
QT_MOC_LITERAL(9, 149, 26),
QT_MOC_LITERAL(10, 176, 26),
QT_MOC_LITERAL(11, 203, 23),
QT_MOC_LITERAL(12, 227, 21),
QT_MOC_LITERAL(13, 249, 24)
    },
    "featuresUI\0sendParams\0\0on_hNeigh_valueChanged\0"
    "arg1\0on_hAperature_valueChanged\0"
    "on_hMaxStr_valueChanged\0on_hThresh_valueChanged\0"
    "on_hParam_valueChanged\0"
    "on_siftThresh_valueChanged\0"
    "on_edgeThresh_valueChanged\0"
    "on_gthresh_valueChanged\0on_pushButton_clicked\0"
    "on_spinSize_valueChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_featuresUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   70,    2, 0x08,
       5,    1,   73,    2, 0x08,
       6,    1,   76,    2, 0x08,
       7,    1,   79,    2, 0x08,
       8,    1,   82,    2, 0x08,
       9,    1,   85,    2, 0x08,
      10,    1,   88,    2, 0x08,
      11,    1,   91,    2, 0x08,
      12,    0,   94,    2, 0x08,
      13,    1,   95,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void featuresUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        featuresUI *_t = static_cast<featuresUI *>(_o);
        switch (_id) {
        case 0: _t->sendParams(); break;
        case 1: _t->on_hNeigh_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_hAperature_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_hMaxStr_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_hThresh_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_hParam_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_siftThresh_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_edgeThresh_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_gthresh_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_spinSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (featuresUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&featuresUI::sendParams)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject featuresUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_featuresUI.data,
      qt_meta_data_featuresUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *featuresUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *featuresUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_featuresUI.stringdata))
        return static_cast<void*>(const_cast< featuresUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int featuresUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void featuresUI::sendParams()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
