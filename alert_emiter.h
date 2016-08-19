#pragma once
#include <QMessageBox>

class AlertEmiter {
    public:
    // Default constructor
    AlertEmiter ( );
    // Destructor
    ~AlertEmiter ( );

    // Display basic alert message box
    static void emitMessageBox ( std::string &text );
    // Display basic alert message box
    static void emitMessageBox ( const char *text );
};
