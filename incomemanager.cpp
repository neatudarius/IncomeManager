#include "incomemanager.h"

IncomeManager::IncomeManager(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
//    QMainWindow::showFullScreen();
}

IncomeManager::~IncomeManager()
{

}

void IncomeManager::addIncome() {
    ui.tableWidget->insertRow( 0 );
    ui.tableWidget->resizeColumnsToContents();
}
