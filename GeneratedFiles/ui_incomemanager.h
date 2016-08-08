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
#include <QDoubleValidator>
#include <QtCore/QVariant>
#include <QComboBox>
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <event.h>
#include <dbmanager.h>

QT_BEGIN_NAMESPACE

class Ui_IncomeManagerClass {
public:
    QMainWindow *incomeManagerClass;
    QWidget *centralWidget, *defaultTabWidget;
    QTableWidget *defaultTableWidget, *tableWidget;
    QPushButton *addIncomePushButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QTabWidget *tabWidget;
    QLineEdit *nameLineEdit, *notesLineEdit, *amountLineEdit;
    QComboBox *typeComboBox;
    QRadioButton *radioButton;
    QDateTimeEdit *dateTimeEditWidget;

    void setupUi(QMainWindow *IncomeManagerClass) {
        this->incomeManagerClass = IncomeManagerClass;
       
        createCentralWidget();
//        createMainToolBar(centralWidget);
//        createStatusBar(centralWidget);

        createDefaultTab(centralWidget);
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        createTabWidget(centralWidget);

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

    void createTabWidget(QWidget *parent) {
        tabWidget = new QTabWidget(parent);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->addTab(defaultTabWidget, QObject::tr("Default panel"));
        tabWidget->addTab(tableWidget, QObject::tr("PWP"));
        tabWidget->setGeometry(QRect(10, 10, 1300, 600));
    }

    void createDefaultTab(QWidget *parent) {
        defaultTabWidget = new QWidget(parent);
        defaultTabWidget->setObjectName(QStringLiteral("defaultTabWidget"));
        defaultTabWidget->setGeometry( QRect(10, 20,1400, 800));
        createAddEventForm(defaultTabWidget);
        createTableWidget(defaultTabWidget);
    }



    void createAddEventForm(QWidget *parent) {
        nameLineEdit = new QLineEdit(parent);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(50, 10, 200, 20));
        nameLineEdit->insert("Name");
        nameLineEdit->setClearButtonEnabled(true);

        amountLineEdit = new QLineEdit(parent);
        amountLineEdit->setObjectName(QStringLiteral("amountLineEdit"));
        amountLineEdit->setGeometry(QRect(260, 10, 50, 20));
        amountLineEdit->insert("13");
        amountLineEdit->setClearButtonEnabled(true);
        amountLineEdit->setValidator(new QDoubleValidator());


        typeComboBox = new QComboBox(parent);
        typeComboBox->setObjectName(QStringLiteral("typeComboBox"));
        typeComboBox->setGeometry(QRect(320, 10, 200, 20));
        typeComboBox->addItems(Event::TYPES);
        typeComboBox->setEditable(true);

        dateTimeEditWidget = new QDateTimeEdit(parent);
        dateTimeEditWidget->setObjectName(QStringLiteral("dateTimeEditWidget"));
        dateTimeEditWidget->setGeometry(QRect(540, 10, 120, 20));
        dateTimeEditWidget->setDateTime(QDateTime::currentDateTime());


        notesLineEdit = new QLineEdit(parent);
        notesLineEdit->setObjectName(QStringLiteral("notesLineEdit"));
        notesLineEdit->setGeometry(QRect(700, 10, 120, 20));
        notesLineEdit->insert("notesLineEdit");
        notesLineEdit->setClearButtonEnabled(true);
                
        addIncomePushButton = new QPushButton(parent);
        addIncomePushButton->setObjectName(QStringLiteral("addIncomePushButton"));
        addIncomePushButton->setGeometry(QRect(900, 10, 75, 23));
        addIncomePushButton->setText(QApplication::translate("IncomeManagerClass", "Add event", 0));
    }

    void createTableWidget(QWidget *parent) {
        QVector<QString> colName({
            "ID", "Name", "Amount", "Type", "Date", "Notes"
        });
        QVector<int> colWidth({
            50, 350, 100, 100, 100, 500
        });
        QVector<Qt::Alignment> colAligment({
            Qt::AlignHCenter, Qt::AlignLeft, Qt::AlignHCenter, Qt::AlignHCenter, Qt::AlignHCenter, Qt::AlignLeft
        });
        defaultTableWidget = new QTableWidget( parent );

        defaultTableWidget->setColumnCount(colName.size());

        for (int i = 0; i < colName.size(); ++i) {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(QApplication::translate("IncomeManagerClass", colName[i].toLatin1().data()));
            item->setTextAlignment(colAligment[i]);
            defaultTableWidget->setHorizontalHeaderItem(i, item);
            defaultTableWidget->setColumnWidth(i, colWidth[i]);
        }
        defaultTableWidget->setObjectName(QStringLiteral("defaultTableWidget"));
        defaultTableWidget->setGeometry(QRect(50,50, 1200, 600));
    }

    void createMainToolBar(QWidget *parent) {
        mainToolBar = new QToolBar(parent);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        incomeManagerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
    }

    void createStatusBar(QWidget *parent) {
        statusBar = new QStatusBar(parent);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        incomeManagerClass->setStatusBar(statusBar);
    }

    void connectSignalToSlots() {
        QObject::connect(addIncomePushButton, SIGNAL(clicked()), incomeManagerClass, SLOT(tableAddIncome()));
        QObject::connect(defaultTableWidget, SIGNAL(cellChanged(int, int)), incomeManagerClass, SLOT(tableCellChanged(int, int)));
        QObject::connect(typeComboBox, SIGNAL(editTextChanged(QString)), incomeManagerClass, SLOT(typeSelected(QString)));
    }
};

namespace Ui {
    class IncomeManagerClass: public Ui_IncomeManagerClass {};
}

QT_END_NAMESPACE

#endif // UI_INCOMEMANAGER_H
