#include "dbmanager.h"
#include <QMessageBox>
#include "alertemiter.h"
#include <QPushButton>
#include <QHBoxLayout>

DbManager::DbManager() {
    events.push_back( Event("Buy clothes", "SHOPPING", -134.01, QDateTime::currentDateTime(), ""));
    events.push_back(Event("Teach", "SCHOLARSHIP", 200, QDateTime::currentDateTime(), ""));
    events.push_back(Event("Buy food", "SHOPPING", -23.00, QDateTime::currentDateTime(), ""));
}

DbManager::~DbManager() {
}

void DbManager::addEvent(const Event& e) {
    for (auto event : events) {
        if (event == e) {
            AlertEmiter::emitMessageBox("Event already exists!");
            return;
        }
    }
    events.push_back(e);
}

QVector<Event> DbManager::getEvents() const {
    return  events;
}

int DbManager::getEventsCount() const {
    return events.size();
}


void DbManager::initTable(QTableWidget* table) const {
    table->setRowCount(events.size());

    QTableWidgetItem *item = NULL;
    for (int i = 0; i < events.size(); ++i) {
        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].id);
        table->setItem(i, 0, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].name);
        table->setItem(i, 1, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].amount);
        table->setItem(i, 2, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].type);
        table->setItem(i, 3, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].date);
        table->setItem(i, 4, item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0, events[i].notes);
        table->setItem(i, 5, item);
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
