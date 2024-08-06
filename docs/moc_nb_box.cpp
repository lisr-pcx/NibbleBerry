/****************************************************************************
** Meta object code from reading C++ file 'nb_box.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/nb_box.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nb_box.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSNB_BoxENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSNB_BoxENDCLASS = QtMocHelpers::stringData(
    "NB_Box",
    "NewStatus",
    "",
    "index",
    "mousePressEvent",
    "QGraphicsSceneMouseEvent*",
    "event",
    "mouseReleaseEvent"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSNB_BoxENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[7];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[16];
    char stringdata5[26];
    char stringdata6[6];
    char stringdata7[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSNB_BoxENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSNB_BoxENDCLASS_t qt_meta_stringdata_CLASSNB_BoxENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "NB_Box"
        QT_MOC_LITERAL(7, 9),  // "NewStatus"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 5),  // "index"
        QT_MOC_LITERAL(24, 15),  // "mousePressEvent"
        QT_MOC_LITERAL(40, 25),  // "QGraphicsSceneMouseEvent*"
        QT_MOC_LITERAL(66, 5),  // "event"
        QT_MOC_LITERAL(72, 17)   // "mouseReleaseEvent"
    },
    "NB_Box",
    "NewStatus",
    "",
    "index",
    "mousePressEvent",
    "QGraphicsSceneMouseEvent*",
    "event",
    "mouseReleaseEvent"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNB_BoxENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   35,    2, 0x0a,    3 /* Public */,
       7,    1,   38,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject NB_Box::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSNB_BoxENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNB_BoxENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSNB_BoxENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NB_Box, std::true_type>,
        // method 'NewStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'mousePressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>,
        // method 'mouseReleaseEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>
    >,
    nullptr
} };

void NB_Box::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NB_Box *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->NewStatus((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 1: _t->mousePressEvent((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        case 2: _t->mouseReleaseEvent((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NB_Box::*)(unsigned int );
            if (_t _q_method = &NB_Box::NewStatus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *NB_Box::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NB_Box::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNB_BoxENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(this);
    return QObject::qt_metacast(_clname);
}

int NB_Box::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void NB_Box::NewStatus(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
