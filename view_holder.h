#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "default_panel.h"
#include "statistics_panel.h"

struct ViewHolder {
    QMainWindow* incomeManagerClass;
    QToolBar* mainToolBar;
    QStatusBar* statusBar;
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
    void createMainToolBar ( QWidget* parent );
    void createStatusBar ( QWidget* parent );
    void createTabWidget ( QWidget* parent );
};
