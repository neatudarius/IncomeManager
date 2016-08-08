#pragma once
#include <qvector.h>
#include "event.h"
#include <QtWidgets/QTableWidget>

class DbManager {
    public:
        DbManager();
        ~DbManager();
        void initTable(QTableWidget *defaultTableWidget);

    public slots:
        static void typeSelected(const QString& type);

    private:
        QVector<Event> events;

};
