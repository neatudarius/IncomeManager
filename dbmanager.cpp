#include "dbmanager.h"
#include <QMessageBox>


DbManager::DbManager() {
    events.push_back( Event("Buy clothes", "SHOPPING", -134.01, QDateTime::currentDateTime(), ""));
    events.push_back(Event("Teach", "SCHOLARSHIP", 200, QDateTime::currentDateTime(), ""));
    events.push_back(Event("Buy food", "SHOPPING", -23.00, QDateTime::currentDateTime(), ""));
}

DbManager::~DbManager() {
}

void DbManager::initTable(QTableWidget* defaultTableWidget) {
    defaultTableWidget->setRowCount(events.size());

    QTableWidgetItem *item = NULL;
    for (int i = 0; i < events.size(); ++i) {

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].id);
        defaultTableWidget->setItem(i, 0, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].name);
        defaultTableWidget->setItem(i, 1, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].amount);
        defaultTableWidget->setItem(i, 2, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].type);
        defaultTableWidget->setItem(i, 3, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].date);
        defaultTableWidget->setItem(i, 4, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].notes);
        defaultTableWidget->setItem(i, 5, item);
        
    }
}

void DbManager::typeSelected(const QString& type) {
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
}
