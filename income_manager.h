/*
     IncomeManager main class
*/
#pragma once

#include "db_manager.h"
#include "alert_emiter.h"
#include "view_holder.h"

#include <QCloseEvent>
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
        ViewHolder ui;
        DbManager dbManager;
};
