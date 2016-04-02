/****************************************************************************
** Meta object code from reading C++ file 'calibwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../opencv_opengl_toolbox/calibwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calibwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_calibWindow_t {
    QByteArrayData data[17];
    char stringdata[373];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_calibWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_calibWindow_t qt_meta_stringdata_calibWindow = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 23),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 28),
QT_MOC_LITERAL(4, 66, 11),
QT_MOC_LITERAL(5, 78, 11),
QT_MOC_LITERAL(6, 90, 21),
QT_MOC_LITERAL(7, 112, 23),
QT_MOC_LITERAL(8, 136, 23),
QT_MOC_LITERAL(9, 160, 23),
QT_MOC_LITERAL(10, 184, 24),
QT_MOC_LITERAL(11, 209, 28),
QT_MOC_LITERAL(12, 238, 30),
QT_MOC_LITERAL(13, 269, 30),
QT_MOC_LITERAL(14, 300, 47),
QT_MOC_LITERAL(15, 348, 10),
QT_MOC_LITERAL(16, 359, 12)
    },
    "calibWindow\0on_actionOpen_triggered\0"
    "\0on_actionCalibrate_triggered\0chessFinder\0"
    "timeOutSlot\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_actionHelp_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionSolve_PnP_triggered\0"
    "on_actionLoad_config_triggered\0"
    "on_actionSave_config_triggered\0"
    "on_actionSave_Transformation_Function_triggered\0"
    "closeEvent\0QCloseEvent*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calibWindow[] = {

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
       1,    0,   84,    2, 0x08,
       3,    0,   85,    2, 0x08,
       4,    0,   86,    2, 0x08,
       5,    0,   87,    2, 0x08,
       6,    0,   88,    2, 0x08,
       7,    0,   89,    2, 0x08,
       8,    0,   90,    2, 0x08,
       9,    0,   91,    2, 0x08,
      10,    0,   92,    2, 0x08,
      11,    0,   93,    2, 0x08,
      12,    0,   94,    2, 0x08,
      13,    0,   95,    2, 0x08,
      14,    0,   96,    2, 0x08,
      15,    1,   97,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,    2,

       0        // eod
};

void calibWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        calibWindow *_t = static_cast<calibWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionOpen_triggered(); break;
        case 1: _t->on_actionCalibrate_triggered(); break;
        case 2: _t->chessFinder(); break;
        case 3: _t->timeOutSlot(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_actionHelp_triggered(); break;
        case 8: _t->on_actionAbout_triggered(); break;
        case 9: _t->on_actionSolve_PnP_triggered(); break;
        case 10: _t->on_actionLoad_config_triggered(); break;
        case 11: _t->on_actionSave_config_triggered(); break;
        case 12: _t->on_actionSave_Transformation_Function_triggered(); break;
        case 13: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject calibWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_calibWindow.data,
      qt_meta_data_calibWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *calibWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calibWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_calibWindow.stringdata))
        return static_cast<void*>(const_cast< calibWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int calibWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
