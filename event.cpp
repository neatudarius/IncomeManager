#include <QString>
#include "event.h"

int Event::ID_COUNTER = 0;

Event::Event() {
    
}

Event::Event(QString _name, QString _type, double _amount, QDateTime _date, QString _notes) 
    : name(_name), type(_type), amount(_amount), date(_date), notes(_notes) {
    id = ++ID_COUNTER;
}

Event::~Event() {
}


