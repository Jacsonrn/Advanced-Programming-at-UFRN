/****************************************************************************
** Meta object code from reading C++ file 'supcliente_qt.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../supcliente_qt.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'supcliente_qt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
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
struct qt_meta_tag_ZN12SupClienteQtE_t {};
} // unnamed namespace

template <> constexpr inline auto SupClienteQt::qt_create_metaobjectdata<qt_meta_tag_ZN12SupClienteQtE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SupClienteQt",
        "signExibirErro",
        "",
        "std::string",
        "msg",
        "signExibirInterface",
        "on_actionLogin_triggered",
        "on_actionLogout_triggered",
        "on_actionQuit_triggered",
        "on_buttonV1_clicked",
        "open",
        "on_buttonV2_clicked",
        "on_sliderPump_valueChanged",
        "value",
        "on_showLevel_toggled",
        "checked",
        "on_spinRefresh_valueChanged",
        "arg1",
        "slotConectar",
        "IP",
        "Login",
        "Senha",
        "slotExibirErro",
        "slotExibirInterface"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'signExibirErro'
        QtMocHelpers::SignalData<void(const std::string &) const>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'signExibirInterface'
        QtMocHelpers::SignalData<void() const>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_actionLogin_triggered'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionLogout_triggered'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionQuit_triggered'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_buttonV1_clicked'
        QtMocHelpers::SlotData<void(bool)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 10 },
        }}),
        // Slot 'on_buttonV2_clicked'
        QtMocHelpers::SlotData<void(bool)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 10 },
        }}),
        // Slot 'on_sliderPump_valueChanged'
        QtMocHelpers::SlotData<void(int)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Slot 'on_showLevel_toggled'
        QtMocHelpers::SlotData<void(bool)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 15 },
        }}),
        // Slot 'on_spinRefresh_valueChanged'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'slotConectar'
        QtMocHelpers::SlotData<void(QString, QString, QString)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 19 }, { QMetaType::QString, 20 }, { QMetaType::QString, 21 },
        }}),
        // Slot 'slotExibirErro'
        QtMocHelpers::SlotData<void(const std::string &)>(22, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'slotExibirInterface'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SupClienteQt, qt_meta_tag_ZN12SupClienteQtE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SupClienteQt::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12SupClienteQtE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12SupClienteQtE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12SupClienteQtE_t>.metaTypes,
    nullptr
} };

void SupClienteQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SupClienteQt *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->signExibirErro((*reinterpret_cast<std::add_pointer_t<std::string>>(_a[1]))); break;
        case 1: _t->signExibirInterface(); break;
        case 2: _t->on_actionLogin_triggered(); break;
        case 3: _t->on_actionLogout_triggered(); break;
        case 4: _t->on_actionQuit_triggered(); break;
        case 5: _t->on_buttonV1_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->on_buttonV2_clicked((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->on_sliderPump_valueChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_showLevel_toggled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->on_spinRefresh_valueChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->slotConectar((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3]))); break;
        case 11: _t->slotExibirErro((*reinterpret_cast<std::add_pointer_t<std::string>>(_a[1]))); break;
        case 12: _t->slotExibirInterface(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SupClienteQt::*)(const std::string & ) const>(_a, &SupClienteQt::signExibirErro, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupClienteQt::*)() const>(_a, &SupClienteQt::signExibirInterface, 1))
            return;
    }
}

const QMetaObject *SupClienteQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SupClienteQt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12SupClienteQtE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "SupCliente"))
        return static_cast< SupCliente*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SupClienteQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void SupClienteQt::signExibirErro(const std::string & _t1)const
{
    QMetaObject::activate<void>(const_cast< SupClienteQt *>(this), &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void SupClienteQt::signExibirInterface()const
{
    QMetaObject::activate(const_cast< SupClienteQt *>(this), &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
