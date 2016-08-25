#pragma once
#include <QMenuBar>
#include <QAction>
#include <QCloseEvent>
#include "alert_emiter.h"
#include "controller.h"
#include "income_manager.h"

class MenuBar : public QMenuBar {
    public:
        // Constructors & destructors
        MenuBar ( QWidget* parent );
        ~MenuBar ( );

    private:
        // File menu
        void fileMenu ( );
};
