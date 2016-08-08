#pragma once
#include "eventtype.h"
#include <QDateTime>
#include <QStringList>

struct Event {
        static int ID_COUNTER;
        static QStringList TYPES;
    
        Event();
        Event(QString _name, QString _type, double _amount, QDateTime _date, QString _notes);
        ~Event();

        int id;
        QString name;
        QString type;
        double amount;
        QDateTime date;
        QString notes;
};

