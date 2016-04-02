/****************************************************************************
** Meta object code from reading C++ file 'fundoptui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../opencv_opengl_toolbox/fundoptui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fundoptui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fundOptUI_t {
    QByteArrayData data[9];
    char stringdata[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_fundOptUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_fundOptUI_t qt_meta_stringdata_fundOptUI = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 31),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 4),
QT_MOC_LITERAL(4, 48, 30),
QT_MOC_LITERAL(5, 79, 22),
QT_MOC_LITERAL(6, 102, 24),
QT_MOC_LITERAL(7, 127, 34),
QT_MOC_LITERAL(8, 162, 5)
    },
    "fundOptUI\0on_comboBox_currentIndexChanged\0"
    "\0arg1\0on_spinConfidence_valueChanged\0"
    "on_spinNN_valueChanged\0on_spinDist_valueChanged\0"
    "on_methodcombo_currentIndexChanged\0"
    "index\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fundOptUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08,
       4,    1,   42,    2, 0x08,
       5,    1,   45,    2, 0x08,
       6,    1,   48,    2, 0x08,
       7,    1,   51,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void fundOptUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fundOptUI *_t = static_cast<fundOptUI *>(_o);
        switch (_id) {
        case 0: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_spinConfidence_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_spinNN_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_spinDist_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_methodcombo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject fundOptUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fundOptUI.data,
      qt_meta_data_fundOptUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *fundOptUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fundOptUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fundOptUI.stringdata))
        return static_cast<void*>(const_cast< fundOptUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int fundOptUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
