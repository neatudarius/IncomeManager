#pragma once
#include <QMenuBar>
#include <QAction>
#include <QCloseEvent>
#include "alert_emiter.h"


class MenuBar : public QMenuBar {
    public:
        MenuBar ( QWidget* parent );
        ~MenuBar ( );

        // File
        void fileMenu ( );
        void newFile ( );
        void open ( );
        void save ( );
        void saveAs ( );

    private:
        typedef void ( MenuBar::* FncPtr )( );

        struct Action : public QAction {
            std::string name, statusTip;
            QAction::ActionEvent signal;
            FncPtr slot;
            QKeySequence::StandardKey shortcut;

            Action ( std::string name, MenuBar * parent, std::string statusTip, FncPtr function,
                     QKeySequence::StandardKey shortcut = QKeySequence::StandardKey::UnknownKey ) :
                     QAction ( QString::fromStdString ( name ), parent ) {

                setShortcuts ( shortcut );
                setStatusTip ( QString::fromStdString ( statusTip ) );
                QObject::connect ( this, &QAction::triggered, ( MenuBar * ) parent, function );
            }

            ~Action ( ) {
            }
        };


};
