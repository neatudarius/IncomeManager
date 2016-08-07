/********************************************************************************
** Form generated from reading UI file 'incomemanager.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOMEMANAGER_H
#define UI_INCOMEMANAGER_H

#include <QObject>
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
    QMainWindow *incomeManagerClass;
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *addIncomePushButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QTabWidget *tabWidget;

    void setupUi(QMainWindow *IncomeManagerClass) {
        this->incomeManagerClass = IncomeManagerClass;
        createCentralWidget();
        createTableWidget();
        createMainToolBar();
        createStatusBar();
        createAddIcomeButton();
      
        connectSignalToSlots();
        
        QMetaObject::connectSlotsByName(IncomeManagerClass);
    }

    void createCentralWidget() {
        if (incomeManagerClass->objectName().isEmpty())
            incomeManagerClass->setObjectName(QStringLiteral("IncomeManagerClass"));
        incomeManagerClass->showMaximized();
        centralWidget = new QWidget(incomeManagerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        incomeManagerClass->setCentralWidget(centralWidget);
        incomeManagerClass->setWindowTitle(QApplication::translate("IncomeManagerClass", "IncomeManager", 0));

    }

    void createTabWidget() {
        tabWidget = new QTabWidget;
        tabWidget->addTab(tableWidget, QObject::tr("PWP1"));
        tabWidget->addTab(tableWidget, QObject::tr("PWP2"));
        tabWidget->addTab(tableWidget, QObject::tr("PWP2"));
        tabWidget->setGeometry(QRect(70, 50, 1200, 600));
    }

    void createTableWidget() {
        QVector<QString> colName({
            "ID", "Name", "Value", "Type", "Date", "Obs"
        });
        tableWidget = new QTableWidget( centralWidget );
        tableWidget->setColumnCount(colName.size());
        for (int i = 0; i < colName.size(); ++i) {
            QTableWidgetItem *qtablewidgetitem = new QTableWidgetItem();
            qtablewidgetitem->setText(QApplication::translate("IncomeManagerClass", colName[i].toLatin1().data()));
            tableWidget->setHorizontalHeaderItem(i, qtablewidgetitem);
        }
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(70, 50, 1200, 600));
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
        addIncomePushButton->setText(QApplication::translate("IncomeManagerClass", "Add income", 0));
    }

    void connectSignalToSlots() {
        QObject::connect(addIncomePushButton, SIGNAL(clicked()), incomeManagerClass, SLOT(addIncome()));
        QObject::connect(tableWidget, SIGNAL(cellChanged(int, int)), incomeManagerClass, SLOT(cellChanged(int, int)));
    }
};

namespace Ui {
    class IncomeManagerClass: public Ui_IncomeManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOMEMANAGER_H
