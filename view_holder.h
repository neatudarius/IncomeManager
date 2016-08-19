#pragma once

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
#include <db_manager.h>

struct ViewHolder {
    QMainWindow* incomeManagerClass;
    QWidget *centralWidget, *defaultTabWidget;
    QTableWidget *defaultTableWidget, *tableWidget;
    QPushButton* addEventButton;
    QToolBar* mainToolBar;
    QStatusBar* statusBar;
    QTabWidget* tabWidget;
    QLineEdit *nameLineEdit, *notesLineEdit, *amountLineEdit;
    QComboBox* typeComboBox;
    QRadioButton* radioButton;
    QDateTimeEdit* dateTimeEditWidget;

    ViewHolder ( QMainWindow* parent );
    ~ViewHolder ( );
    void setupUi ( );

    void createCentralWidget ( );
    void createTabWidget ( QWidget* parent );
    void createDefaultTab ( QWidget* parent );

    void createAddEventForm ( QWidget* parent );

    void createTableWidget ( QWidget* parent );

    void createMainToolBar ( QWidget* parent );
    void createStatusBar ( QWidget* parent );

    void connectSignalToSlots ( );
};
