#include "incomemanager.h"
#include "alertemiter.h"

IncomeManager::IncomeManager(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
    dbManager.initTable(ui.defaultTableWidget);
}

IncomeManager::~IncomeManager(){
}

void IncomeManager::addEvent() {
    if (!ui.nameLineEdit->text().length (  )) {
        AlertEmiter::emitMessageBox("Name is missing");
        return;
    }

    if (!ui.amountLineEdit->text().length ( )) {
        AlertEmiter::emitMessageBox("Amount is missing");
        return;
    }
    if (!ui.typeComboBox->currentText().length ( )) {
        AlertEmiter::emitMessageBox("Type is missing");
        return;
    }

    QString name = ui.nameLineEdit->text();
    double amount = ui.amountLineEdit->text().toDouble();
    QString type = ui.typeComboBox->currentText();
    QDateTime date = ui.dateTimeEditWidget->dateTime();
    QString notes = ui.notesLineEdit->text();

    dbManager.addEvent(Event(name, type, amount, date, notes));
    ui.defaultTableWidget->setRowCount ( dbManager.getEventsCount() );
    dbManager.initTable(ui.defaultTableWidget);
}

void IncomeManager::tableCellChanged(int row, int column) {
    QString text = ui.defaultTableWidget->item(row, column)->text();
}

void IncomeManager::typeSelected(QString& type) {
    emit DbManager::typeSelected(type);
}
