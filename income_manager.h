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

class IncomeManager : public QObject {
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

    // Return true if there are unsaved changes
    bool savedChanges ( );

    // Notify data was changed
    void dataChanged ( );

    // Notify data was saved
    void dataSaved ();

    private:
    // Constructor: make window
    IncomeManager ();

    // Class instance (Singeton Pattern)
    static IncomeManager* _INSTANCE;

    // This variable is FALSE only when all changes were saved on disk
    bool saved;

    // This object is a holder for all views
    ViewHolder* ui;
    // This object handles database changes
    DbManager* db;
    // This object handles file system operations
    FileManager* fm;
    // This object handles user request
    Controller *controller;
};
