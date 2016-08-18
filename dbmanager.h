#pragma once
#include <qvector.h>
#include "event.h"
#include <QtWidgets/QTableWidget>

class DbManager {
    public:
        DbManager();
        ~DbManager();
        void initTable(QTableWidget *defaultTableWidget) const;
        void addEvent(const Event& e);
        QVector<Event> getEvents() const;
        int getEventsCount() const;

    public slots:
        static void typeSelected(const QString& type);

    private:
        QVector<Event> events;

};
