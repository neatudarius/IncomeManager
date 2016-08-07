#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <QtWidgets/QMainWindow>
#include "ui_incomemanager.h"
#include <QMessageBox>

class IncomeManager : public QMainWindow
{
    Q_OBJECT

    public:
        IncomeManager(QWidget *parent = 0);
        ~IncomeManager();

    public slots:
        void addIncome();
        void cellChanged(int row, int column);
    private:
        Ui::IncomeManagerClass ui;
};

#endif // INCOMEMANAGER_H
