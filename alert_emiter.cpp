#include "alert_emiter.h"

// Default constructor
AlertEmiter::AlertEmiter ( ) {}

// Destructor
AlertEmiter::~AlertEmiter ( ) {}

// Display basic alert messafe box
void AlertEmiter::emitMessageBox ( std::string& text ) {
    emitMessageBox ( text . c_str ( ) );
}

// Display basic alert message box
void AlertEmiter::emitMessageBox ( const char* text ) {
    QMessageBox msgBox;

    // display text
    msgBox . setText ( QString ( text ) );

    // only "Ok" button showed
    msgBox . setStandardButtons ( QMessageBox::Ok );
    msgBox . setDefaultButton ( QMessageBox::Ok );
    msgBox . exec ( );
}
