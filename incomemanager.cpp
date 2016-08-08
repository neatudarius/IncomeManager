#include "incomemanager.h"

IncomeManager::IncomeManager(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
    dbManager.initTable(ui.defaultTableWidget);
}

IncomeManager::~IncomeManager(){
}

void IncomeManager::tableAddIncome() {
    ui.defaultTableWidget->insertRow(0);
//    ui.defaultTableWidget->resizeColumnsToContents();
}

void IncomeManager::tableCellChanged(int row, int column) {
    QString text = ui.defaultTableWidget->item(row, column)->text();

//    QMessageBox msgBox;
//    msgBox.setText(QString::number(row) + QString::number(column) + text);
//    msgBox.exec();
}

void IncomeManager::typeSelected(QString& type) {
        QMessageBox msgBox;
        msgBox.setText("text");
        msgBox.exec();
    emit DbManager::typeSelected(type);
}
