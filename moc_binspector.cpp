/****************************************************************************
** Meta object code from reading C++ file 'binspector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/binspector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'binspector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_view__binspector_t {
    QByteArrayData data[8];
    char stringdata[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_view__binspector_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_view__binspector_t qt_meta_stringdata_view__binspector = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 10),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 15),
QT_MOC_LITERAL(4, 45, 8),
QT_MOC_LITERAL(5, 54, 4),
QT_MOC_LITERAL(6, 59, 8),
QT_MOC_LITERAL(7, 68, 11)
    },
    "view::binspector\0messageBox\0\0"
    "setupMainWidget\0openFile\0name\0showHelp\0"
    "saveProject"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_view__binspector[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void view::binspector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        binspector *_t = static_cast<binspector *>(_o);
        switch (_id) {
        case 0: _t->messageBox(); break;
        case 1: _t->setupMainWidget(); break;
        case 2: _t->openFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->showHelp(); break;
        case 4: _t->saveProject(); break;
        default: ;
        }
    }
}

const QMetaObject view::binspector::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_view__binspector.data,
      qt_meta_data_view__binspector,  qt_static_metacall, 0, 0}
};


const QMetaObject *view::binspector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view::binspector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_view__binspector.stringdata))
        return static_cast<void*>(const_cast< binspector*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int view::binspector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
