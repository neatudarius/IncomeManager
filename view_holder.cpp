#include "view_holder.h"

ViewHolder::ViewHolder ( QMainWindow* parent ) : incomeManagerClass ( parent ) {}

ViewHolder::~ViewHolder ( ) {
    delete incomeManagerClass;
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

    QMetaObject::connectSlotsByName ( incomeManagerClass );
}

void ViewHolder::connectSignalToSlots ( ) {
    QObject::connect ( defaultPanel -> addEvent , SIGNAL ( clicked ( ) ) , incomeManagerClass , SLOT ( addEvent ( ) ) );
    QObject::connect ( defaultPanel -> table , SIGNAL ( cellChanged ( int, int ) ) , incomeManagerClass , SLOT ( tableCellChanged ( int, int ) ) );
    QObject::connect ( defaultPanel -> type , SIGNAL ( editTextChanged ( QString ) ) , incomeManagerClass , SLOT ( typeSelected ( QString ) ) );
}

void ViewHolder::createCentralWidget ( ) {
    if ( incomeManagerClass -> objectName ( ) . isEmpty ( ) ) {
        incomeManagerClass -> setObjectName ( QStringLiteral ( "IncomeManagerClass" ) );
    }
    incomeManagerClass -> showMaximized ( );
    centralWidget = new QWidget ( incomeManagerClass );
    centralWidget -> setObjectName ( QStringLiteral ( "centralWidget" ) );
    incomeManagerClass -> setCentralWidget ( centralWidget );
    incomeManagerClass -> setWindowTitle ( QApplication::translate ( "IncomeManagerClass" , "IncomeManager" , 0 ) );
}

void ViewHolder::createTabWidget ( QWidget* parent ) {
    tabWidget = new QTabWidget ( parent );
    tabWidget -> setObjectName ( QStringLiteral ( "tabWidget" ) );
    tabWidget -> addTab ( defaultPanel , QObject::tr ( "Default Panel" ) );
    tabWidget -> addTab ( statisticsPanel , QObject::tr ( "Statistics Panel" ) );
    tabWidget -> setGeometry ( QRect ( 0 , 20 , 1300 , 650 ) );
}
