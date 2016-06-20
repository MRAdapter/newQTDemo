/****************************************************************************
** Meta object code from reading C++ file 'fiveparamswidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../finalQTDemo/fiveparamswidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fiveparamswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fiveParamsWidget_t {
    QByteArrayData data[5];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fiveParamsWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fiveParamsWidget_t qt_meta_stringdata_fiveParamsWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "fiveParamsWidget"
QT_MOC_LITERAL(1, 17, 14), // "sendFiveParams"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 13), // "sureBtn_click"
QT_MOC_LITERAL(4, 47, 13) // "backBtn_click"

    },
    "fiveParamsWidget\0sendFiveParams\0\0"
    "sureBtn_click\0backBtn_click"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fiveParamsWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   32,    2, 0x08 /* Private */,
       4,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void fiveParamsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fiveParamsWidget *_t = static_cast<fiveParamsWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFiveParams((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sureBtn_click(); break;
        case 2: _t->backBtn_click(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (fiveParamsWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fiveParamsWidget::sendFiveParams)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject fiveParamsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fiveParamsWidget.data,
      qt_meta_data_fiveParamsWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fiveParamsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fiveParamsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fiveParamsWidget.stringdata0))
        return static_cast<void*>(const_cast< fiveParamsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int fiveParamsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void fiveParamsWidget::sendFiveParams(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
