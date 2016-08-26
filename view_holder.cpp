#include "view_holder.h"
#include "income_manager.h"

ViewHolder* ViewHolder::_INSTANCE = NULL;

ViewHolder::ViewHolder ( QMainWindow* parent ) : QMainWindow ( parent ) {}

ViewHolder::~ViewHolder () {
    delete centralWidget;
    delete menuBar;
    delete tabWidget;
    delete defaultPanel;
    delete statisticsPanel;
}

ViewHolder* ViewHolder::getInstance () {
    if (_INSTANCE == NULL) {
        _INSTANCE = new ViewHolder(NULL);
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
    if (objectName().isEmpty()) {
        setObjectName(QStringLiteral ( "IncomeManagerClass" ));
    }
    showMaximized();
    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QStringLiteral ( "centralWidget" ));
    setCentralWidget(centralWidget);
    setWindowTitle(QApplication::translate("IncomeManagerClass" , "IncomeManager" , 0));
}

void ViewHolder::createTabWidget (QWidget* parent) {
    tabWidget = new QTabWidget(parent);
    tabWidget->setObjectName(QStringLiteral ( "tabWidget" ));
    tabWidget->addTab(defaultPanel , QObject::tr("Default Panel"));
    tabWidget->addTab(statisticsPanel , QObject::tr("Statistics Panel"));
    tabWidget->setGeometry(QRect(0 , 20 , 1300 , 650));
}

// Notify close application button was pressed
void ViewHolder::closeEvent ( QCloseEvent* event ) {
    bool saved = IncomeManager::getInstance ( )->savedChanges ( );
    QMessageBox::StandardButton res;
    if ( saved ) {
        res = QMessageBox::question ( ViewHolder::getInstance ( ), "Close Confirmation",
                                "Are you sure you want to exit?",
                                QMessageBox::Yes | QMessageBox::No );

    } else {
        res = QMessageBox::question ( ViewHolder::getInstance ( ), "Close Confirmation",
                                           "Do you want to save changes?",
                                           QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    }

    // Check if user wants to save data
    if ( !saved && res == QMessageBox::Yes ) {
        Controller::getInstance ( )->save ( );
        event->accept ( ); // close application
        return; 
    }

    if ( ( saved && res == QMessageBox::Yes ) ||
         (!saved && res == QMessageBox::No)) {
        event->accept ( ); // close application
        return;
    }


    // res == NO 
    event->ignore ( );
}

void ViewHolder::setTitleSaved () {
    QString windowTitle ( " " );
    windowTitle.append ( FileManager::getInstance ( )->getCurrentFile ( ) );
    windowTitle.append ( " - Income Manager" );
    setWindowTitle ( windowTitle );
}

void ViewHolder::setTitleChanged () {
    QString windowTitle ( "* " );
    windowTitle.append ( FileManager::getInstance ( )->getCurrentFile ( ) );
    windowTitle.append ( " - Income Manager" );
    setWindowTitle ( windowTitle );
};

