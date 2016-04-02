/****************************************************************************
** Meta object code from reading C++ file 'CvGlWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../opencv_opengl_toolbox/CvGlWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CvGlWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CvGlWidget_t {
    QByteArrayData data[12];
    char stringdata[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CvGlWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CvGlWidget_t qt_meta_stringdata_CvGlWidget = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 16),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 6),
QT_MOC_LITERAL(4, 36, 6),
QT_MOC_LITERAL(5, 43, 8),
QT_MOC_LITERAL(6, 52, 13),
QT_MOC_LITERAL(7, 66, 9),
QT_MOC_LITERAL(8, 76, 7),
QT_MOC_LITERAL(9, 84, 5),
QT_MOC_LITERAL(10, 90, 15),
QT_MOC_LITERAL(11, 106, 3)
    },
    "CvGlWidget\0imageSizeChanged\0\0imageW\0"
    "imageH\0finished\0workRequested\0showImage\0"
    "cv::Mat\0image\0showContextMenu\0pos\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CvGlWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06,
       5,    0,   44,    2, 0x06,
       6,    0,   45,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    1,   46,    2, 0x0a,
      10,    1,   49,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QPoint,   11,

       0        // eod
};

void CvGlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CvGlWidget *_t = static_cast<CvGlWidget *>(_o);
        switch (_id) {
        case 0: _t->imageSizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->finished(); break;
        case 2: _t->workRequested(); break;
        case 3: { bool _r = _t->showImage((*reinterpret_cast< cv::Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->showContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CvGlWidget::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CvGlWidget::imageSizeChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (CvGlWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CvGlWidget::finished)) {
                *result = 1;
            }
        }
        {
            typedef void (CvGlWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CvGlWidget::workRequested)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CvGlWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_CvGlWidget.data,
      qt_meta_data_CvGlWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *CvGlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CvGlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CvGlWidget.stringdata))
        return static_cast<void*>(const_cast< CvGlWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int CvGlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CvGlWidget::imageSizeChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CvGlWidget::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CvGlWidget::workRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
