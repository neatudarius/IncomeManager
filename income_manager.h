/*
     IncomeManager main class
*/
#pragma once
#include <QMainWindow>
#include <QCloseEvent>
#include "alert_emiter.h"
#include "db_manager.h"

#include "file_manager.h"
#include "controller.h"

struct ViewHolder;

class IncomeManager : public QMainWindow {
    Q_OBJECT

    public:
    // Destructor close app
    ~IncomeManager ();

    // Initialize app
    void init ();

    // Method for accesing Instance of this application from every class
    static IncomeManager* getInstance ();

    // Method for accesing Instance of this application from every class
    static void releaseInstance ();

    public slots:
    // Notify close application button was pressed
    void closeEvent (QCloseEvent* event);

    private:
    // Constructor: make window
    IncomeManager (QWidget* parent = 0);

    // Class instance (Singeton Pattern)
    static IncomeManager* _INSTANCE;

    // This object is a holder for all views
    ViewHolder* ui;
    // This object handles database changes
    DbManager* db;
    // This object handles file system operations
    FileManager* fm;
    // 
    Controller *controller;
};
