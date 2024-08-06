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
    "NB_Box*",
    "ptr_box",
    "RotateBoxes",
    "angle",
    "intensity",
    "mousePressEvent",
    "QGraphicsSceneMouseEvent*",
    "event",
    "mouseReleaseEvent",
    "BoxStatus",
    "BLUEBERRY",
    "PLAYER1",
    "PLAYER2",
    "NUMBER_OF_STATES"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSNB_BoxENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[7];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[8];
    char stringdata5[12];
    char stringdata6[6];
    char stringdata7[10];
    char stringdata8[16];
    char stringdata9[26];
    char stringdata10[6];
    char stringdata11[18];
    char stringdata12[10];
    char stringdata13[10];
    char stringdata14[8];
    char stringdata15[8];
    char stringdata16[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSNB_BoxENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSNB_BoxENDCLASS_t qt_meta_stringdata_CLASSNB_BoxENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "NB_Box"
        QT_MOC_LITERAL(7, 9),  // "NewStatus"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 7),  // "NB_Box*"
        QT_MOC_LITERAL(26, 7),  // "ptr_box"
        QT_MOC_LITERAL(34, 11),  // "RotateBoxes"
        QT_MOC_LITERAL(46, 5),  // "angle"
        QT_MOC_LITERAL(52, 9),  // "intensity"
        QT_MOC_LITERAL(62, 15),  // "mousePressEvent"
        QT_MOC_LITERAL(78, 25),  // "QGraphicsSceneMouseEvent*"
        QT_MOC_LITERAL(104, 5),  // "event"
        QT_MOC_LITERAL(110, 17),  // "mouseReleaseEvent"
        QT_MOC_LITERAL(128, 9),  // "BoxStatus"
        QT_MOC_LITERAL(138, 9),  // "BLUEBERRY"
        QT_MOC_LITERAL(148, 7),  // "PLAYER1"
        QT_MOC_LITERAL(156, 7),  // "PLAYER2"
        QT_MOC_LITERAL(164, 16)   // "NUMBER_OF_STATES"
    },
    "NB_Box",
    "NewStatus",
    "",
    "NB_Box*",
    "ptr_box",
    "RotateBoxes",
    "angle",
    "intensity",
    "mousePressEvent",
    "QGraphicsSceneMouseEvent*",
    "event",
    "mouseReleaseEvent",
    "BoxStatus",
    "BLUEBERRY",
    "PLAYER1",
    "PLAYER2",
    "NUMBER_OF_STATES"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNB_BoxENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       1,   54, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       5,    3,   41,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   48,    2, 0x0a,    7 /* Public */,
      11,    1,   51,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,

 // enums: name, alias, flags, count, data
      12,   12, 0x0,    4,   59,

 // enum data: key, value
      13, uint(NB_Box::BLUEBERRY),
      14, uint(NB_Box::PLAYER1),
      15, uint(NB_Box::PLAYER2),
      16, uint(NB_Box::NUMBER_OF_STATES),

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
        QtPrivate::TypeAndForceComplete<NB_Box *, std::false_type>,
        // method 'RotateBoxes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<NB_Box *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
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
        case 0: _t->NewStatus((*reinterpret_cast< std::add_pointer_t<NB_Box*>>(_a[1]))); break;
        case 1: _t->RotateBoxes((*reinterpret_cast< std::add_pointer_t<NB_Box*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->mousePressEvent((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        case 3: _t->mouseReleaseEvent((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< NB_Box* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< NB_Box* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NB_Box::*)(NB_Box * );
            if (_t _q_method = &NB_Box::NewStatus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NB_Box::*)(NB_Box * , int , int );
            if (_t _q_method = &NB_Box::RotateBoxes; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
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
    if (!strcmp(_clname, "QGraphicsEllipseItem"))
        return static_cast< QGraphicsEllipseItem*>(this);
    return QObject::qt_metacast(_clname);
}

int NB_Box::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NB_Box::NewStatus(NB_Box * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NB_Box::RotateBoxes(NB_Box * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
