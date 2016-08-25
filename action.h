#pragma once
#include  "controller.h"

// Action is the base element from menus
template<typename T>
struct Action : public QAction {
    // Name, status tip of the action in MenuBar
    std::string name, statusTip;
    // Function is called when action is selected
    FncPtr function;
    // Optional key shortcut
    QKeySequence::StandardKey shortcut;

    // Constructor: initialize members & connect signal to slots
    Action ( std::string name, std::string statusTip, FncPtr _function,
             QKeySequence::StandardKey shortcut = QKeySequence::StandardKey::UnknownKey ) :
             QAction ( QString::fromStdString ( name ), NULL ),
             function ( _function ) {
        setShortcuts ( shortcut );
        setStatusTip ( QString::fromStdString ( statusTip ) );
        QObject::connect ( this, &QAction::triggered, T::getInstance ( ), function );
    }
};