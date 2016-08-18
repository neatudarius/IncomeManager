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
        void addEvent();
        void tableCellChanged(int row, int column);
        void typeSelected(QString& type);

    private:
        Ui::IncomeManagerClass ui;
        DbManager dbManager;
};
