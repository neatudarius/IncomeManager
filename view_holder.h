#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "default_panel.h"
#include "statistics_panel.h"
#include "menu_bar.h"

struct ViewHolder : public QMainWindow  {
    MenuBar* menuBar;
    QWidget* centralWidget;
    QTabWidget* tabWidget;
    DefaultPanel* defaultPanel;
    StatisticsPanel* statisticsPanel;

    ~ViewHolder ();

    void setupUi ();

    void createCentralWidget ();

    void createTabWidget (QWidget* parent);

    // Notify close application button was pressed
    void closeEvent (QCloseEvent* event);

    void setTitleSaved ();

    void setTitleChanged ();

    static ViewHolder* getInstance ( );

    static void releaseInstance ();

    private:
    static ViewHolder* _INSTANCE;

    ViewHolder (QMainWindow* parent);
};
