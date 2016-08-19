#include "event.h"


int Event::ID_COUNTER = 0;
QStringList Event::TYPES = QStringList ( {
                                            "INCOME",
                                            "SALARY",
                                            "SCHOLARSHIP",
                                            "COACHING",
                                            "TEACHING",
                                            "SOFTWARE_SELLING",
                                            "SELLING",
                                            "EXPENSE",
                                            "PAYMENT",
                                            "TRANSACTION",
                                            "SHOPPING",
                                            "TRIP",
                                            "HOLIDAY",
                                            "RENT",
                                            "FOOD",
                                            "TRANSPORT"
                                        } );

Event::Event ( ) {
    id = ++ID_COUNTER;
}

Event::Event ( QString _name, QString _type, double _amount, QDateTime _date, QString _notes )
    : name ( _name ),
      type ( _type ),
      amount ( _amount ),
      date ( _date ),
      notes ( _notes ) {
    id = ++ID_COUNTER;
    connect ( );
}

Event::~Event ( ) {
    //    if (idWidget != NULL) {
    //        delete idWidget;
    //        idWidget = NULL;
    //    }
    //    if (nameWidget) {
    //        delete nameWidget;
    //        idWidget = NULL;
    //    }
    //    if (amountWidget) {
    //        delete amountWidget;
    //        amountWidget = NULL;
    //    }
    //    if (typeWidget) {
    //        delete typeWidget;
    //        typeWidget = NULL;
    //    }
    //    if (dateWidget) {
    //        delete dateWidget;
    //        dateWidget = NULL;
    //    }
    //    if (notesWidget) {
    //        delete notesWidget;
    //        notesWidget = NULL;
    //    }
    //    if (actionsWidget) {
    //        delete actionsWidget;
    //        actionsWidget = NULL;
    //    }
}

bool Event::operator== ( const Event& e ) {
    return this -> name == e . name && this -> amount == e . amount && this -> date == e . date;
}

void Event::connect ( ) {
    idWidget = new QTableWidgetItem;
    idWidget -> setData ( 0 , id );

    nameWidget = new QTableWidgetItem;
    nameWidget -> setData ( 0 , name );

    amountWidget = new QTableWidgetItem;
    amountWidget -> setData ( 0 , amount );

    typeWidget = new QTableWidgetItem;
    typeWidget -> setData ( 0 , type );

    dateWidget = new QTableWidgetItem;
    dateWidget -> setData ( 0 , date );

    notesWidget = new QTableWidgetItem;
    notesWidget -> setData ( 0 , notes );

    QPushButton* editableButton = new QPushButton;
    editableButton -> setIcon ( QIcon ( "Images/Icons/locked-black.png" ) );
    //    QObject::connect(editableButton, SIGNAL(clicked(bool)), editableButton->pa, SLOT(tableCellChanged(int, int)));

    actionsWidget = new QWidget ( );
    QHBoxLayout* pLayout = new QHBoxLayout ( actionsWidget );
    pLayout -> addWidget ( editableButton );
    pLayout -> setAlignment ( Qt::AlignCenter );
    pLayout -> setContentsMargins ( 0 , 0 , 0 , 0 );
    actionsWidget -> setLayout ( pLayout );
}

void Event::write ( FILE* f ) {
    fwrite ( &id , sizeof(int) , 1 , f );
    fwrite ( &amount , sizeof(double) , 1 , f );

    qint64 mSecs = date . toMSecsSinceEpoch ( );
    fwrite ( &mSecs , sizeof(qint64) , 1 , f );

    QStringList stringList ( { name, type, notes } );
    for ( auto str : stringList ) {
        char* buffer = ( char * ) str . toStdString ( ) . c_str ( );
        int len = str . toStdString ( ) . size ( );

        fwrite ( &len , sizeof(int) , 1 , f );
        fwrite ( buffer , sizeof(char) , len , f );
    }
}


void Event::read ( FILE* f ) {
    fread ( &id , sizeof(int) , 1 , f );
    fread ( &amount , sizeof(double) , 1 , f );

    qint64 mSecs;
    fread ( &mSecs , sizeof(qint64) , 1 , f );
    date . fromMSecsSinceEpoch ( mSecs );

    QStringList stringList;
    stringList . reserve ( 3 );
    for ( auto str : stringList ) {
        char buffer[2000];
        int len;

        fread ( &len , sizeof(int) , 1 , f );
        fread ( buffer , sizeof(char) , len , f );

        buffer[ len ] = '\0';
        str . append ( buffer );
    }

    name = stringList[ 0 ];
    type = stringList[ 1 ];
    notes = stringList[ 2 ];
}
