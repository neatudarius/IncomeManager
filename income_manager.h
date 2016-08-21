/*
     IncomeManager main class
*/
#pragma once

#include "db_manager.h"
#include "alert_emiter.h"
#include "view_holder.h"

#include <QCloseEvent>
#include "file_manager.h"

class IncomeManager : public QMainWindow {
    Q_OBJECT

    public:
        // Constructor: make app
        IncomeManager ( QWidget* parent = 0 );

        // Destructor close app
        ~IncomeManager ( );

    
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
        // This object is a holder for all views
        ViewHolder ui;
        // This object handles database changes
        DbManager dbManager;
        // This object handles file system operations
        FileManager fm;
};
