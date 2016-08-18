#pragma once
#include <string>

class AlertEmiter {
    public:
        AlertEmiter();
        ~AlertEmiter();
        
        static void emitMessageBox(std::string& text);
        static void emitMessageBox(const char *text);
};

