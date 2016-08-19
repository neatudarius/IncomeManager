#include "view_holder.h"


ViewHolder::ViewHolder ( QMainWindow *parent ) : incomeManagerClass ( parent ) {}


ViewHolder::~ViewHolder ( ) {}

void ViewHolder::setupUi () {

    createCentralWidget ( );
    //        createMainToolBar(centralWidget);
    //        createStatusBar(centralWidget);


    createDefaultTab ( centralWidget );
    tableWidget = new QTableWidget ( centralWidget );
    tableWidget -> setObjectName ( QStringLiteral ( "tableWidget" ) );

    createTabWidget ( centralWidget );

    connectSignalToSlots ( );

    QMetaObject::connectSlotsByName ( incomeManagerClass );
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
    tabWidget -> addTab ( defaultTabWidget , QObject::tr ( "Default panel" ) );
    tabWidget -> addTab ( tableWidget , QObject::tr ( "PWP" ) );
    tabWidget -> setGeometry ( QRect ( 10 , 10 , 1300 , 600 ) );
}

void ViewHolder::createDefaultTab ( QWidget* parent ) {
    defaultTabWidget = new QWidget ( parent );
    defaultTabWidget -> setObjectName ( QStringLiteral ( "defaultTabWidget" ) );
    defaultTabWidget -> setGeometry ( QRect ( 10 , 20 , 1400 , 800 ) );
    createAddEventForm ( defaultTabWidget );
    createTableWidget ( defaultTabWidget );
}


void ViewHolder::createAddEventForm ( QWidget* parent ) {
    nameLineEdit = new QLineEdit ( parent );
    nameLineEdit -> setObjectName ( QStringLiteral ( "nameLineEdit" ) );
    nameLineEdit -> setGeometry ( QRect ( 50 , 10 , 200 , 20 ) );
    nameLineEdit -> setPlaceholderText ( QStringLiteral ( "Name" ) );
    nameLineEdit -> setClearButtonEnabled ( true );

    amountLineEdit = new QLineEdit ( parent );
    amountLineEdit -> setObjectName ( QStringLiteral ( "amountLineEdit" ) );
    amountLineEdit -> setGeometry ( QRect ( 260 , 10 , 80 , 20 ) );
    amountLineEdit -> setPlaceholderText ( QStringLiteral ( "Amount" ) );
    amountLineEdit -> setClearButtonEnabled ( true );
    amountLineEdit -> setValidator ( new QDoubleValidator ( ) );


    typeComboBox = new QComboBox ( parent );
    typeComboBox -> setObjectName ( QStringLiteral ( "typeComboBox" ) );
    typeComboBox -> setGeometry ( QRect ( 350 , 10 , 150 , 20 ) );
    typeComboBox -> addItems ( Event::TYPES );
    typeComboBox -> setEditable ( true );

    dateTimeEditWidget = new QDateTimeEdit ( parent );
    dateTimeEditWidget -> setObjectName ( QStringLiteral ( "dateTimeEditWidget" ) );
    dateTimeEditWidget -> setGeometry ( QRect ( 520 , 10 , 150 , 20 ) );
    dateTimeEditWidget -> setDateTime ( QDateTime::currentDateTime ( ) );


    notesLineEdit = new QLineEdit ( parent );
    notesLineEdit -> setObjectName ( QStringLiteral ( "notesLineEdit" ) );
    notesLineEdit -> setGeometry ( QRect ( 680 , 10 , 150 , 20 ) );
    notesLineEdit -> setPlaceholderText ( QStringLiteral ( "Notes" ) );
    notesLineEdit -> setClearButtonEnabled ( true );

    addEventButton = new QPushButton ( parent );
    addEventButton -> setObjectName ( QStringLiteral ( "addEventButton" ) );
    addEventButton -> setGeometry ( QRect ( 860 , 0 , 75 , 40 ) );
    addEventButton -> setText ( QApplication::translate ( "IncomeManagerClass" , "Add event" , 0 ) );
}

void ViewHolder::createTableWidget ( QWidget* parent ) {
    QVector < QString > colName ( {
                                     "ID", "Name", "Amount", "Type", "Date", "Notes", "Actions"
                                 } );
    QVector < int > colWidth ( {
                                  50, 350, 100, 100, 100, 400, 100
                              } );
    QVector < Qt::Alignment > colAligment ( {
                                               Qt::AlignHCenter, Qt::AlignLeft, Qt::AlignHCenter, Qt::AlignHCenter, Qt::AlignHCenter, Qt::AlignLeft, Qt::AlignLeft
                                           } );
    defaultTableWidget = new QTableWidget ( parent );

    defaultTableWidget -> setColumnCount ( colName . size ( ) );

    for ( int i = 0; i < colName . size ( ); ++i ) {
        QTableWidgetItem* item = new QTableWidgetItem ( );
        item -> setText ( QApplication::translate ( "IncomeManagerClass" , colName[ i ] . toLatin1 ( ) . data ( ) ) );
        item -> setTextAlignment ( colAligment[ i ] );
        defaultTableWidget -> setHorizontalHeaderItem ( i , item );
        defaultTableWidget -> setColumnWidth ( i , colWidth[ i ] );
    }
    defaultTableWidget -> setObjectName ( QStringLiteral ( "defaultTableWidget" ) );
    defaultTableWidget -> setGeometry ( QRect ( 50 , 50 , 1200 , 600 ) );
}

void ViewHolder::createMainToolBar ( QWidget* parent ) {
    mainToolBar = new QToolBar ( parent );
    mainToolBar -> setObjectName ( QStringLiteral ( "mainToolBar" ) );
    incomeManagerClass -> addToolBar ( Qt::TopToolBarArea , mainToolBar );
}

void ViewHolder::createStatusBar ( QWidget* parent ) {
    statusBar = new QStatusBar ( parent );
    statusBar -> setObjectName ( QStringLiteral ( "statusBar" ) );
    incomeManagerClass -> setStatusBar ( statusBar );
}

void ViewHolder::connectSignalToSlots ( ) {
    QObject::connect ( addEventButton , SIGNAL ( clicked ( ) ) , incomeManagerClass , SLOT ( addEvent ( ) ) );
    QObject::connect ( defaultTableWidget , SIGNAL ( cellChanged ( int, int ) ) , incomeManagerClass , SLOT ( tableCellChanged ( int, int ) ) );
    QObject::connect ( typeComboBox , SIGNAL ( editTextChanged ( QString ) ) , incomeManagerClass , SLOT ( typeSelected ( QString ) ) );
}
