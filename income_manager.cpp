#include "income_manager.h"

// Constructor: make app
IncomeManager::IncomeManager ( QWidget* parent )
    : QMainWindow ( parent ),
      ui ( this ) {

    // Setup uiL create view
    ui . setupUi ( );

    // init view with data
    dbManager . initTable ( ui . defaultPanel -> table );
}

// Destructor close app
IncomeManager::~IncomeManager ( ) {}

// Add event to default table
void IncomeManager::addEvent ( ) {
    // Check if name was given
    if ( !ui . defaultPanel -> name -> text ( ) . length ( ) ) {
        AlertEmiter::emitMessageBox ( "Name is missing" );
        return;
    }

    // Check if amount was given
    if ( !ui . defaultPanel -> amount -> text ( ) . length ( ) ) {
        AlertEmiter::emitMessageBox ( "Amount is missing" );
        return;
    }

    // Check if type was given
    if ( !ui . defaultPanel -> type -> currentText ( ) . length ( ) ) {
        AlertEmiter::emitMessageBox ( "Type is missing" );
        return;
    }

    // Collect info
    QString name = ui . defaultPanel -> name -> text ( );
    double amount = ui . defaultPanel -> amount -> text ( ) . toDouble ( );
    QString type = ui . defaultPanel -> type -> currentText ( );
    QDateTime date = ui . defaultPanel -> date -> dateTime ( );
    QString notes = ui . defaultPanel -> notes -> text ( );

    // Save event to database and refresh view
    dbManager . addEvent ( Event ( name , type , amount , date , notes ) );
    ui . defaultPanel -> table -> setRowCount ( dbManager . getEventsCount ( ) );
    dbManager . initTable ( ui . defaultPanel -> table );
}

// TODO
void IncomeManager::tableCellChanged ( int row, int column ) {
    QString text = ui . defaultPanel -> table -> item ( row , column ) -> text ( );
}

// Notify a type was selected. Save it if is a new one.
void IncomeManager::typeSelected ( QString& type ) {
    emit DbManager::typeSelected ( type );
}
