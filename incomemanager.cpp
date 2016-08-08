#include "incomemanager.h"

IncomeManager::IncomeManager(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
    dbManager.initTable(ui.tableWidget);
}

IncomeManager::~IncomeManager(){
}

void IncomeManager::tableAddIncome() {
    ui.tableWidget->insertRow(0);
//    ui.tableWidget->resizeColumnsToContents();
}

void IncomeManager::tableCellChanged(int row, int column) {
    QString text = ui.tableWidget->item(row, column)->text();

//    QMessageBox msgBox;
//    msgBox.setText(QString::number(row) + QString::number(column) + text);
//    msgBox.exec();
}

