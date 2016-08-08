#pragma once
#include <qvector.h>
#include "event.h"
#include <QtWidgets/QTableWidget>

class DbManager {
    public:
        DbManager();
        ~DbManager();
        void initTable(QTableWidget *tableWidget);
    private:
        QVector<Event> events;

};
