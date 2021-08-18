/****************************************************************************
** Meta object code from reading C++ file 'pixeon.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Pixeon/pixeon.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pixeon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pixeon_t {
    const uint offsetsAndSize[40];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Pixeon_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Pixeon_t qt_meta_stringdata_Pixeon = {
    {
QT_MOC_LITERAL(0, 6), // "Pixeon"
QT_MOC_LITERAL(7, 4), // "open"
QT_MOC_LITERAL(12, 0), // ""
QT_MOC_LITERAL(13, 6), // "zoomIn"
QT_MOC_LITERAL(20, 7), // "zoomOut"
QT_MOC_LITERAL(28, 10), // "normalSize"
QT_MOC_LITERAL(39, 11), // "fitToWindow"
QT_MOC_LITERAL(51, 5), // "about"
QT_MOC_LITERAL(57, 7), // "rotLeft"
QT_MOC_LITERAL(65, 8), // "rotRight"
QT_MOC_LITERAL(74, 22), // "handleSelectionChanged"
QT_MOC_LITERAL(97, 11), // "QModelIndex"
QT_MOC_LITERAL(109, 5), // "index"
QT_MOC_LITERAL(115, 17), // "brightnessChanged"
QT_MOC_LITERAL(133, 7), // "QImage*"
QT_MOC_LITERAL(141, 7), // "QImage&"
QT_MOC_LITERAL(149, 5), // "image"
QT_MOC_LITERAL(155, 5), // "value"
QT_MOC_LITERAL(161, 15), // "contrastChanged"
QT_MOC_LITERAL(177, 13) // "valuesChanged"

    },
    "Pixeon\0open\0\0zoomIn\0zoomOut\0normalSize\0"
    "fitToWindow\0about\0rotLeft\0rotRight\0"
    "handleSelectionChanged\0QModelIndex\0"
    "index\0brightnessChanged\0QImage*\0QImage&\0"
    "image\0value\0contrastChanged\0valuesChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pixeon[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    0 /* Private */,
       3,    0,   87,    2, 0x08,    1 /* Private */,
       4,    0,   88,    2, 0x08,    2 /* Private */,
       5,    0,   89,    2, 0x08,    3 /* Private */,
       6,    0,   90,    2, 0x08,    4 /* Private */,
       7,    0,   91,    2, 0x08,    5 /* Private */,
       8,    0,   92,    2, 0x08,    6 /* Private */,
       9,    0,   93,    2, 0x08,    7 /* Private */,
      10,    1,   94,    2, 0x08,    8 /* Private */,
      13,    2,   97,    2, 0x08,   10 /* Private */,
      18,    2,  102,    2, 0x08,   13 /* Private */,
      19,    0,  107,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    0x80000000 | 14, 0x80000000 | 15, QMetaType::Int,   16,   17,
    0x80000000 | 14, 0x80000000 | 15, QMetaType::Int,   16,   17,
    QMetaType::Void,

       0        // eod
};

void Pixeon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pixeon *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->open(); break;
        case 1: _t->zoomIn(); break;
        case 2: _t->zoomOut(); break;
        case 3: _t->normalSize(); break;
        case 4: _t->fitToWindow(); break;
        case 5: _t->about(); break;
        case 6: _t->rotLeft(); break;
        case 7: _t->rotRight(); break;
        case 8: _t->handleSelectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 9: { QImage* _r = _t->brightnessChanged((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage**>(_a[0]) = std::move(_r); }  break;
        case 10: { QImage* _r = _t->contrastChanged((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage**>(_a[0]) = std::move(_r); }  break;
        case 11: _t->valuesChanged(); break;
        default: ;
        }
    }
}

const QMetaObject Pixeon::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Pixeon.offsetsAndSize,
    qt_meta_data_Pixeon,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Pixeon_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>, QtPrivate::TypeAndForceComplete<QImage *, std::false_type>, QtPrivate::TypeAndForceComplete<QImage &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QImage *, std::false_type>, QtPrivate::TypeAndForceComplete<QImage &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Pixeon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pixeon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pixeon.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Pixeon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
