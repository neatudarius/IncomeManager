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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IncomeManagerClass
{
public:
    QWidget *centralWidget;
    QTableWidget *defaultTableWidget;
    QPushButton *addIncomePushButton;
    QLineEdit *lineEdit;
    QRadioButton *radioButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IncomeManagerClass)
    {
        if (IncomeManagerClass->objectName().isEmpty())
            IncomeManagerClass->setObjectName(QStringLiteral("IncomeManagerClass"));
        IncomeManagerClass->resize(1035, 649);
        centralWidget = new QWidget(IncomeManagerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        defaultTableWidget = new QTableWidget(centralWidget);
        if (defaultTableWidget->columnCount() < 5)
            defaultTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        defaultTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        defaultTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        defaultTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        defaultTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        defaultTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        defaultTableWidget->setObjectName(QStringLiteral("defaultTableWidget"));
        defaultTableWidget->setGeometry(QRect(70, 50, 681, 601));
        addIncomePushButton = new QPushButton(centralWidget);
        addIncomePushButton->setObjectName(QStringLiteral("addIncomePushButton"));
        addIncomePushButton->setGeometry(QRect(70, 10, 75, 23));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(310, 10, 113, 20));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(440, 10, 82, 17));
        IncomeManagerClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(IncomeManagerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        IncomeManagerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(IncomeManagerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        IncomeManagerClass->setStatusBar(statusBar);

        retranslateUi(IncomeManagerClass);

        QMetaObject::connectSlotsByName(IncomeManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *IncomeManagerClass)
    {
        IncomeManagerClass->setWindowTitle(QApplication::translate("IncomeManagerClass", "IncomeManager", 0));
        QTableWidgetItem *___qtablewidgetitem = defaultTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("IncomeManagerClass", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = defaultTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("IncomeManagerClass", "Event", 0));
        QTableWidgetItem *___qtablewidgetitem2 = defaultTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("IncomeManagerClass", "Value", 0));
        QTableWidgetItem *___qtablewidgetitem3 = defaultTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("IncomeManagerClass", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem4 = defaultTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("IncomeManagerClass", "Obs", 0));
        addIncomePushButton->setText(QApplication::translate("IncomeManagerClass", "Add income", 0));
        radioButton->setText(QApplication::translate("IncomeManagerClass", "RadioButton", 0));
    } // retranslateUi

};

namespace Ui {
    class IncomeManagerClass: public Ui_IncomeManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOMEMANAGER_H
