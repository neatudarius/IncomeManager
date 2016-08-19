#include "default_panel.h"

DefaultPanel::DefaultPanel ( QWidget* parent ) : QWidget ( parent ) {
    this -> setObjectName ( QStringLiteral ( "defaultPanel" ) );
    this -> setGeometry ( QRect ( 10 , 20 , 1400 , 800 ) );

    createAddEventForm ( this );
    createTableWidget ( this );
}

DefaultPanel::~DefaultPanel ( ) {
    delete name;
    delete amount;
    delete type;
    delete date;
    delete notes;
    delete addEvent;
}

void DefaultPanel::createAddEventForm ( QWidget* parent ) {
    name = new QLineEdit ( parent );
    name -> setObjectName ( QStringLiteral ( "name" ) );
    name -> setGeometry ( QRect ( 50 , 10 , 200 , 20 ) );
    name -> setPlaceholderText ( QStringLiteral ( "Name" ) );
    name -> setClearButtonEnabled ( true );

    amount = new QLineEdit ( parent );
    amount -> setObjectName ( QStringLiteral ( "amount" ) );
    amount -> setGeometry ( QRect ( 260 , 10 , 80 , 20 ) );
    amount -> setPlaceholderText ( QStringLiteral ( "Amount" ) );
    amount -> setClearButtonEnabled ( true );
    amount -> setValidator ( new QDoubleValidator ( ) );


    type = new QComboBox ( parent );
    type -> setObjectName ( QStringLiteral ( "type" ) );
    type -> setGeometry ( QRect ( 350 , 10 , 150 , 20 ) );
    type -> addItems ( Event::TYPES );
    type -> setEditable ( true );

    date = new QDateTimeEdit ( parent );
    date -> setObjectName ( QStringLiteral ( "date" ) );
    date -> setGeometry ( QRect ( 520 , 10 , 150 , 20 ) );
    date -> setDateTime ( QDateTime::currentDateTime ( ) );


    notes = new QLineEdit ( parent );
    notes -> setObjectName ( QStringLiteral ( "notes" ) );
    notes -> setGeometry ( QRect ( 680 , 10 , 150 , 20 ) );
    notes -> setPlaceholderText ( QStringLiteral ( "Notes" ) );
    notes -> setClearButtonEnabled ( true );

    addEvent = new QPushButton ( parent );
    addEvent -> setObjectName ( QStringLiteral ( "addEvent" ) );
    addEvent -> setGeometry ( QRect ( 860 , 0 , 75 , 40 ) );
    addEvent -> setText ( QApplication::translate ( "IncomeManagerClass" , "Add event" , 0 ) );
}

void DefaultPanel::createTableWidget ( QWidget* parent ) {
    QVector < QString > colName ( {
                                     "ID", "Name", "Amount", "Type", "Date", "Notes", "Actions"
                                 } );
    QVector < int > colWidth ( {
                                  50, 350, 100, 100, 100, 400, 100
                              } );
    QVector < Qt::Alignment > colAligment ( {
                                               Qt::AlignHCenter, Qt::AlignLeft, Qt::AlignHCenter, Qt::AlignHCenter, Qt::AlignHCenter, Qt::AlignLeft, Qt::AlignLeft
                                           } );
    table = new QTableWidget ( parent );

    table -> setColumnCount ( colName . size ( ) );

    for ( int i = 0; i < colName . size ( ); ++i ) {
        QTableWidgetItem* item = new QTableWidgetItem ( );
        item -> setText ( QApplication::translate ( "IncomeManagerClass" , colName[ i ] . toLatin1 ( ) . data ( ) ) );
        item -> setTextAlignment ( colAligment[ i ] );
        table -> setHorizontalHeaderItem ( i , item );
        table -> setColumnWidth ( i , colWidth[ i ] );
    }
    table -> setObjectName ( QStringLiteral ( "table" ) );
    table -> setGeometry ( QRect ( 50 , 50 , 1200 , 600 ) );
}
