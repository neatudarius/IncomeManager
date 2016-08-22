#include "view_holder.h"

ViewHolder::ViewHolder ( QMainWindow *parent ) : mainWindow(parent) {}

ViewHolder::~ViewHolder ( ) {
    delete centralWidget;
    delete menuBar;
    delete tabWidget;
    delete defaultPanel;
    delete statisticsPanel;
}

void ViewHolder::setupUi ( ) {

    createCentralWidget ( );

    menuBar = new MenuBar ( centralWidget );
    defaultPanel = new DefaultPanel ( centralWidget );
    statisticsPanel = new StatisticsPanel ( centralWidget );

    createTabWidget ( centralWidget );

    connectSignalToSlots ( );

}                                 

void ViewHolder::connectSignalToSlots ( ) {
//    IncomeManager *w = IncomeManager::getInstance ( );
//    QObject::connect ( defaultPanel -> addEvent , SIGNAL ( clicked ( ) ), 
//                       w, SLOT ( addEvent ( ) ) );
//    QObject::connect ( defaultPanel -> table, SIGNAL ( cellChanged ( int, int ) ), 
//                       w, SLOT ( tableCellChanged ( int, int ) ) );
//    QObject::connect ( defaultPanel -> type, SIGNAL ( editTextChanged ( QString ) ), 
//                       w, SLOT ( typeSelected ( QString ) ) );
}

void ViewHolder::createCentralWidget ( ) {
    if ( mainWindow -> objectName ( ) . isEmpty ( ) ) {
        mainWindow -> setObjectName ( QStringLiteral ( "IncomeManagerClass" ) );
    }
    mainWindow -> showMaximized ( );
    centralWidget = new QWidget ( mainWindow );
    centralWidget -> setObjectName ( QStringLiteral ( "centralWidget" ) );
    mainWindow -> setCentralWidget ( centralWidget );
    mainWindow -> setWindowTitle ( QApplication::translate ( "IncomeManagerClass" , "IncomeManager" , 0 ) );
}

void ViewHolder::createTabWidget ( QWidget* parent ) {
    tabWidget = new QTabWidget ( parent );
    tabWidget -> setObjectName ( QStringLiteral ( "tabWidget" ) );
    tabWidget -> addTab ( defaultPanel , QObject::tr ( "Default Panel" ) );
    tabWidget -> addTab ( statisticsPanel , QObject::tr ( "Statistics Panel" ) );
    tabWidget -> setGeometry ( QRect ( 0 , 20 , 1300 , 650 ) );
}
