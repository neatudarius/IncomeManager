#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "default_panel.h"
#include "statistics_panel.h"
#include "menu_bar.h"

struct ViewHolder  {
    QMainWindow* mainWindow;
    MenuBar* menuBar;
    QWidget* centralWidget;
    QTabWidget* tabWidget;
    DefaultPanel* defaultPanel;
    StatisticsPanel* statisticsPanel;

    ~ViewHolder ();

    void setupUi ();

    void createCentralWidget ();

    void createTabWidget (QWidget* parent);

    static ViewHolder* getInstance ( QMainWindow* parent = NULL );

    static void releaseInstance ();

    private:
    static ViewHolder* _INSTANCE;

    ViewHolder (QMainWindow* parent);
};
