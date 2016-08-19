#pragma once
#include <QDateTime>
#include <QStringList>
#include <QTableWidget>
#include <QPushButton>
#include <QHBoxLayout>

struct Event {
    static int ID_COUNTER;
    static QStringList TYPES;

    Event ( );
    Event ( QString _name, QString _type, double _amount, QDateTime _date, QString _notes );
    ~Event ( );
    bool operator== ( const Event& e );

    int id;
    QString name;
    QString type;
    double amount;
    QDateTime date;
    QString notes;
    QWidget* actions;

    void write ( FILE* f );
    void read ( FILE* f );
};
