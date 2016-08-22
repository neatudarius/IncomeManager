/*
     IncomeManager main class
*/
#pragma once
#include <QMainWindow>
#include <QCloseEvent>
#include "alert_emiter.h"
#include "db_manager.h"
#include "view_holder.h"
#include "file_manager.h"

class IncomeManager : public QMainWindow {
    Q_OBJECT

    public:
        // Destructor close app
        ~IncomeManager ( );

        // Method for accesing Instance of this application from every class
        static IncomeManager* getInstance ( );
    
    public slots:
        // Add event to default table
        void addEvent ( );

        // TODO
        void tableCellChanged ( int row, int column );

        // Notify a type was selected. Save it if is a new one.
        void typeSelected ( QString& type );

        // Notify close application button was pressed
        void closeEvent ( QCloseEvent * event );

    private:
        // Constructor: make window
        IncomeManager ( QWidget* parent = 0 );
        
        // Class instance (Singeton Pattern)
        static IncomeManager *_INSTANCE;

        // This object is a holder for all views
        ViewHolder ui;
        // This object handles database changes
        DbManager dbManager;
        // This object handles file system operations
        FileManager fm;
};
