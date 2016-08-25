#include "view_holder.h"
#include "income_manager.h"

ViewHolder* ViewHolder::_INSTANCE = NULL;

ViewHolder::ViewHolder (QMainWindow* parent) : mainWindow(parent) {}

ViewHolder::~ViewHolder () {
    delete centralWidget;
    delete menuBar;
    delete tabWidget;
    delete defaultPanel;
    delete statisticsPanel;
}

ViewHolder* ViewHolder::getInstance (QMainWindow* parent) {
    if (_INSTANCE == NULL) {
        _INSTANCE = new ViewHolder(parent);
    }

    return _INSTANCE;
}

void ViewHolder::releaseInstance ( ) {
    if ( _INSTANCE != NULL ) {
        delete _INSTANCE;
        _INSTANCE = NULL;
    }
}

void ViewHolder::setupUi () {
    createCentralWidget();

    menuBar = new MenuBar(centralWidget);
    defaultPanel = new DefaultPanel(centralWidget);
    statisticsPanel = new StatisticsPanel(centralWidget);

    createTabWidget(centralWidget);
}


void ViewHolder::createCentralWidget () {
    if (mainWindow->objectName().isEmpty()) {
        mainWindow->setObjectName(QStringLiteral ( "IncomeManagerClass" ));
    }
    mainWindow->showMaximized();
    centralWidget = new QWidget(mainWindow);
    centralWidget->setObjectName(QStringLiteral ( "centralWidget" ));
    mainWindow->setCentralWidget(centralWidget);
    mainWindow->setWindowTitle(QApplication::translate("IncomeManagerClass" , "IncomeManager" , 0));
}

void ViewHolder::createTabWidget (QWidget* parent) {
    tabWidget = new QTabWidget(parent);
    tabWidget->setObjectName(QStringLiteral ( "tabWidget" ));
    tabWidget->addTab(defaultPanel , QObject::tr("Default Panel"));
    tabWidget->addTab(statisticsPanel , QObject::tr("Statistics Panel"));
    tabWidget->setGeometry(QRect(0 , 20 , 1300 , 650));
}

