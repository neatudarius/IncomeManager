#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "default_panel.h"
#include "statistics_panel.h"
#include "menu_bar.h"

struct ViewHolder {
    QMainWindow* incomeManagerClass;
    MenuBar *menuBar;

    QWidget* centralWidget;
    QTabWidget* tabWidget;
    DefaultPanel* defaultPanel;
    StatisticsPanel* statisticsPanel;


    // Methods
    ViewHolder ( QMainWindow* parent );
    ~ViewHolder ( );
    void setupUi ( );
    void connectSignalToSlots ( );
    void createCentralWidget ( );
    void createTabWidget ( QWidget* parent );
};
