#pragma once
#include <qvector.h>
#include "event.h"
#include <QtWidgets/QTableWidget>
#include "file_manager.h"

class DbManager {
    public:
    DbManager ( );
    ~DbManager ( );
    void initTable ( QTableWidget *defaultTableWidget ) const;
    void addEvent ( const Event &e );
    QVector < Event > getEvents ( ) const;
    int getEventsCount ( ) const;

    public slots:

    // Notify a type was selected. Save it if is a new one.
    static void typeSelected ( const QString &type );

    private:
    FileManager fm;
    QVector < Event > events;
};
