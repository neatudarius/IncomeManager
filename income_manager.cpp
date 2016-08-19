#include "income_manager.h"

// Constructor: make app
IncomeManager::IncomeManager ( QWidget* parent )
    : QMainWindow ( parent ), ui(this) {

    // Setup uiL create view
    ui . setupUi ();

    // init view with data
    dbManager . initTable ( ui . defaultTableWidget );
}

// Destructor close app
IncomeManager::~IncomeManager ( ) {}

// Add event to default table
void IncomeManager::addEvent ( ) {
    // Check if name was given
    if ( !ui . nameLineEdit -> text ( ) . length ( ) ) {
        AlertEmiter::emitMessageBox ( "Name is missing" );
        return;
    }

    // Check if amount was given
    if ( !ui . amountLineEdit -> text ( ) . length ( ) ) {
        AlertEmiter::emitMessageBox ( "Amount is missing" );
        return;
    }

    // Check if type was given
    if ( !ui . typeComboBox -> currentText ( ) . length ( ) ) {
        AlertEmiter::emitMessageBox ( "Type is missing" );
        return;
    }

    // Collect info
    QString name = ui . nameLineEdit -> text ( );
    double amount = ui . amountLineEdit -> text ( ) . toDouble ( );
    QString type = ui . typeComboBox -> currentText ( );
    QDateTime date = ui . dateTimeEditWidget -> dateTime ( );
    QString notes = ui . notesLineEdit -> text ( );

    // Save event to database and refresh view
    dbManager . addEvent ( Event ( name , type , amount , date , notes ) );
    ui . defaultTableWidget -> setRowCount ( dbManager . getEventsCount ( ) );
    dbManager . initTable ( ui . defaultTableWidget );
}

// TODO
void IncomeManager::tableCellChanged ( int row, int column ) {
    QString text = ui . defaultTableWidget -> item ( row , column ) -> text ( );
}

// Notify a type was selected. Save it if is a new one.
void IncomeManager::typeSelected ( QString& type ) {
    emit DbManager::typeSelected ( type );
}
