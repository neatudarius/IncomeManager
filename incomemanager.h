#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_incomemanager.h"
#include <QMessageBox>
#include "dbmanager.h"

class IncomeManager : public QMainWindow {
    Q_OBJECT

    public:
        IncomeManager(QWidget *parent = 0);
        ~IncomeManager();

    public slots:
        void tableAddIncome();
        void tableCellChanged(int row, int column);

    private:
        Ui::IncomeManagerClass ui;
        DbManager dbManager;
};
