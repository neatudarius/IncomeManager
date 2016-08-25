#include "event.h"
#include "alert_emiter.h"

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
}

Event::~Event ( ) {
}

bool Event::operator== ( const Event& e ) {
    return this -> name == e . name && this -> amount == e . amount && this -> date == e . date;
}

void Event::write ( FILE* f ) {
    fwrite ( &id , sizeof(int) , 1 , f );
    fwrite ( &amount , sizeof(double) , 1 , f );

    qint64 mSecs = date . toMSecsSinceEpoch ( );
    fwrite ( &mSecs , sizeof(qint64) , 1 , f );

    writeStdString ( f, name.toStdString ( ) );
    writeStdString ( f, type.toStdString ( ) );
    writeStdString ( f, notes.toStdString ( ) );
}

void Event::writeStdString ( FILE* f, const std::string& str ) {
    char* buffer = ( char * ) ( str.c_str ( ) );
    int len = str.size ( );

    fwrite ( &len, sizeof ( int ), 1, f );
    fwrite ( buffer, sizeof ( char ), len, f );
}


void Event::read ( FILE* f ) {
    fread ( &id , sizeof(int) , 1 , f );
    fread ( &amount , sizeof(double) , 1 , f );

    qint64 mSecs;
    fread ( &mSecs , sizeof(qint64) , 1 , f );
    date = QDateTime:: fromMSecsSinceEpoch ( mSecs );

    QStringList stringList;
    stringList.push_back ( name );
    stringList.push_back ( type );
    stringList.push_back ( notes );

    for ( auto& str : stringList ) {
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

QString Event::toQString () {
    QString qstr;
    qstr.append ( QStringLiteral("name: ") );
    qstr.append ( name );

    qstr.append ( QStringLiteral ( "type: " ) );
    qstr.append ( type );

    qstr.append ( QStringLiteral ( "amount: " ) );
    qstr.append ( QString::number(amount) );

    qstr.append ( QStringLiteral ( "date: " ) );
    qstr.append ( QString::number ( date.toMSecsSinceEpoch ( ) ) );

    qstr.append ( QStringLiteral ( "notes: " ) );
    qstr.append ( notes );

    return  qstr;
}
