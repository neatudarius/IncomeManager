#pragma once
#include <QMenuBar>
#include <QAction>
#include <QCloseEvent>
#include <QFileDialog>
#include <QStandardPaths>
#include "alert_emiter.h"

class MenuBar : public QMenuBar {
    public:
        // Constructors & destructors
        MenuBar ( QWidget* parent );
        ~MenuBar ( );

    private:
        // Type wich define a pointer to an instance function from this class
        typedef void ( MenuBar::* FncPtr ) ( );

        // Action is the base element from menus
        struct Action : public QAction {
            // Name, status tip of the action in MenuBar
            std::string name, statusTip;
            // Function is called when action is selected
            FncPtr function;
            // Optional key shortcut
            QKeySequence::StandardKey shortcut;

            // Constructor: initialize members & connect signal to slots
            Action ( std::string name, MenuBar* parent, std::string statusTip, FncPtr _function,
                     QKeySequence::StandardKey shortcut = QKeySequence::StandardKey::UnknownKey ) :
                QAction ( QString::fromStdString ( name ) , parent ),
                function ( _function ) {
                setShortcuts ( shortcut );
                setStatusTip ( QString::fromStdString ( statusTip ) );
                QObject::connect ( this , &QAction::triggered , ( MenuBar * ) parent , function );
            }
        };

        // File menu
        void fileMenu ( );
        /** File menu's actions **/
        // Create new database (file)
        void newFile ( );
        // Open database (file)
        void open ( );
        // Save current database (file)
        void save ( );
        // Save current database to other file
        void saveAs ( );
};
