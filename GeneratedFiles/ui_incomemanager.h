/********************************************************************************
** Form generated from reading UI file 'incomemanager.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOMEMANAGER_H
#define UI_INCOMEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "../../../../../Qt/5.7/msvc2013/include/QtCore/qobjectdefs.h"

QT_BEGIN_NAMESPACE

class Ui_IncomeManagerClass
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *addIncomePushButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMainWindow *incomeManagerClass;

    void setupUi(QMainWindow *IncomeManagerClass)
    {
        this->incomeManagerClass = IncomeManagerClass;
        createCentralWidget();
        createTableWidget();
        createMainToolBar();
        createStatusBar();
        createAddIcomeButton();
       
        retranslateUi(IncomeManagerClass);

        connectSignalToSlots();
        

        QMetaObject::connectSlotsByName(IncomeManagerClass);
    } // setupUi


    void createCentralWidget() {
        if (incomeManagerClass->objectName().isEmpty())
            incomeManagerClass->setObjectName(QStringLiteral("IncomeManagerClass"));
        incomeManagerClass->showMaximized();
        centralWidget = new QWidget(incomeManagerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        incomeManagerClass->setCentralWidget(centralWidget);
    }
    void createTableWidget() {
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(70, 50, 1021, 241));
    }

    void createMainToolBar() {
        mainToolBar = new QToolBar(incomeManagerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        incomeManagerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
    }

    void createStatusBar() {
        statusBar = new QStatusBar(incomeManagerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        incomeManagerClass->setStatusBar(statusBar);
    }
    void createAddIcomeButton() {
        addIncomePushButton = new QPushButton(centralWidget);
        addIncomePushButton->setObjectName(QStringLiteral("addIncomePushButton"));
        addIncomePushButton->setGeometry(QRect(70, 10, 75, 23));
    }

    void connectSignalToSlots() {
        QObject::connect(addIncomePushButton, SIGNAL(clicked()), incomeManagerClass, SLOT(addIncome()));
    }
    void retranslateUi(QMainWindow *IncomeManagerClass)
    {
        IncomeManagerClass->setWindowTitle(QApplication::translate("IncomeManagerClass", "IncomeManager", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("IncomeManagerClass", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("IncomeManagerClass", "Event", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("IncomeManagerClass", "Value", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("IncomeManagerClass", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("IncomeManagerClass", "Obs", 0));
        addIncomePushButton->setText(QApplication::translate("IncomeManagerClass", "Add income", 0));
    } // retranslateUi

};

namespace Ui {
    class IncomeManagerClass: public Ui_IncomeManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOMEMANAGER_H
