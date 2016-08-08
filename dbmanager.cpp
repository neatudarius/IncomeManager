#include "dbmanager.h"


DbManager::DbManager() {
    events.push_back( Event("Buy clothes", "SHOPPING", -134.01, QDateTime::currentDateTime(), ""));
    events.push_back(Event("Teach", "SCHOLARSHIP", 200, QDateTime::currentDateTime(), ""));
    events.push_back(Event("Buy food", "SHOPPING", -23.00, QDateTime::currentDateTime(), ""));
}


DbManager::~DbManager() {
}

void DbManager::initTable(QTableWidget* tableWidget) {
    tableWidget->setRowCount(events.size());

    QTableWidgetItem *item = NULL;
    for (int i = 0; i < events.size(); ++i) {

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].id);
        tableWidget->setItem(i, 0, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].name);
        tableWidget->setItem(i, 1, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].amount);
        tableWidget->setItem(i, 2, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].type);
        tableWidget->setItem(i, 3, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].date);
        tableWidget->setItem(i, 4, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].notes);
        tableWidget->setItem(i, 5, item);
        
    }
}
