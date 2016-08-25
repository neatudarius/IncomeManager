#include "db_manager.h"
#include "income_manager.h"
#include "default_panel.h"
#include  "view_holder.h"
DbManager* DbManager::_INSTANCE = NULL;

DbManager::DbManager () {}

DbManager::~DbManager () {}

DbManager* DbManager::getInstance ( ) {
    if ( _INSTANCE == NULL ) {
        _INSTANCE = new DbManager ( );
    }
    return _INSTANCE;
}

void DbManager::releaseInstance ( ) {
    if ( _INSTANCE != NULL ) {
        delete _INSTANCE;
        _INSTANCE = NULL;
    }
}

void DbManager::reset ( ) {
    events.clear ( );
    ViewHolder::getInstance ( )->defaultPanel->table->clearContents ( );
}

void DbManager::addEvent () {
    DefaultPanel *dp = ViewHolder::getInstance ( )->defaultPanel;

    // Check if name was given
    if ( !dp->name->text ( ).length ( ) ) {
        AlertEmiter::emitMessageBox ( "Name is missing" );
        return;
    }

    // Check if amount was given
    if ( !dp->amount->text ( ).length ( ) ) {
        AlertEmiter::emitMessageBox ( "Amount is missing" );
        return;
    }

    // Check if type was given
    if ( !dp->type->currentText ( ).length ( ) ) {
        AlertEmiter::emitMessageBox ( "Type is missing" );
        return;
    }

    // Collect info
    QString name = dp->name->text ( );
    double amount = dp->amount->text ( ).toDouble ( );
    QString type = dp->type->currentText ( );
    QDateTime date = dp->date->dateTime ( );
    QString notes = dp->notes->text ( );

    Event event ( name, type, amount, date, notes );

    for (auto e : events) {
        if (event == e) {
            AlertEmiter::emitMessageBox("Event already exists!");
            return;
        }
    }
    events.push_back(event);

    
    populateTable ( );
    dp->resetAddEventForm ( );
}



QVector <Event> DbManager::getEvents () const {
    return events;
}

int DbManager::getEventsCount () const {
    return events.size();
}

void DbManager::load (QVector<Event> _events) {
    reset ( );
    events = _events;
    populateTable ( );
}

void DbManager::populateTable ( ) const {
    QTableWidget* table = ViewHolder::getInstance ( )->defaultPanel->table;
    table->setRowCount(events.size());

    QTableWidgetItem* item = NULL;
    for (int i = 0; i < events.size(); ++i) {
        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0 , events[ i ].id);
        table->setItem(i , 0 , item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0 , events[ i ].name);
        table->setItem(i , 1 , item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0 , events[ i ].amount);
        table->setItem(i , 2 , item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0 , events[ i ].type);
        table->setItem(i , 3 , item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0 , events[ i ].date);
        table->setItem(i , 4 , item);

        item = new QTableWidgetItem;
        item->setFlags(Qt::ItemIsEnabled);
        item->setData(0 , events[ i ].notes);
        table->setItem(i , 5 , item);
    }
}

// Notify a type was selected. Save it if is a new one.
void DbManager::typeSelected (const QString& type) {
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
}

void DbManager::tableCellChanged ( int row, int column ) {}