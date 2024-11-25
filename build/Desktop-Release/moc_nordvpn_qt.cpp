/****************************************************************************
** Meta object code from reading C++ file 'nordvpn_qt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../nordvpn_qt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nordvpn_qt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NordVPNGUI_t {
    QByteArrayData data[20];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NordVPNGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NordVPNGUI_t qt_meta_stringdata_NordVPNGUI = {
    {
QT_MOC_LITERAL(0, 0, 10), // "NordVPNGUI"
QT_MOC_LITERAL(1, 11, 17), // "onCountrySelected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "country"
QT_MOC_LITERAL(4, 38, 16), // "onConnectClicked"
QT_MOC_LITERAL(5, 55, 19), // "onDisconnectClicked"
QT_MOC_LITERAL(6, 75, 15), // "onStatusClicked"
QT_MOC_LITERAL(7, 91, 16), // "onVersionClicked"
QT_MOC_LITERAL(8, 108, 17), // "onProcessFinished"
QT_MOC_LITERAL(9, 126, 8), // "exitCode"
QT_MOC_LITERAL(10, 135, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(11, 156, 10), // "exitStatus"
QT_MOC_LITERAL(12, 167, 14), // "onProcessError"
QT_MOC_LITERAL(13, 182, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(14, 205, 5), // "error"
QT_MOC_LITERAL(15, 211, 15), // "onProcessOutput"
QT_MOC_LITERAL(16, 227, 20), // "onProcessErrorOutput"
QT_MOC_LITERAL(17, 248, 20), // "onConnectStatusCheck"
QT_MOC_LITERAL(18, 269, 23), // "onDisconnectStatusCheck"
QT_MOC_LITERAL(19, 293, 21) // "onPeriodicStatusCheck"

    },
    "NordVPNGUI\0onCountrySelected\0\0country\0"
    "onConnectClicked\0onDisconnectClicked\0"
    "onStatusClicked\0onVersionClicked\0"
    "onProcessFinished\0exitCode\0"
    "QProcess::ExitStatus\0exitStatus\0"
    "onProcessError\0QProcess::ProcessError\0"
    "error\0onProcessOutput\0onProcessErrorOutput\0"
    "onConnectStatusCheck\0onDisconnectStatusCheck\0"
    "onPeriodicStatusCheck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NordVPNGUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    0,   77,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    2,   81,    2, 0x08 /* Private */,
      12,    1,   86,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    0,   90,    2, 0x08 /* Private */,
      17,    0,   91,    2, 0x08 /* Private */,
      18,    0,   92,    2, 0x08 /* Private */,
      19,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 10,    9,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NordVPNGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NordVPNGUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onCountrySelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onConnectClicked(); break;
        case 2: _t->onDisconnectClicked(); break;
        case 3: _t->onStatusClicked(); break;
        case 4: _t->onVersionClicked(); break;
        case 5: _t->onProcessFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 6: _t->onProcessError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 7: _t->onProcessOutput(); break;
        case 8: _t->onProcessErrorOutput(); break;
        case 9: _t->onConnectStatusCheck(); break;
        case 10: _t->onDisconnectStatusCheck(); break;
        case 11: _t->onPeriodicStatusCheck(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NordVPNGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_NordVPNGUI.data,
    qt_meta_data_NordVPNGUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NordVPNGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NordVPNGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NordVPNGUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int NordVPNGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
