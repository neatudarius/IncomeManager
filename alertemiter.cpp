#include "alertemiter.h"
#include <QMessageBox>


AlertEmiter::AlertEmiter() {
}


AlertEmiter::~AlertEmiter() {
}

void AlertEmiter::emitMessageBox(std::string& text) {
    emitMessageBox(text.c_str());
}

void AlertEmiter::emitMessageBox(const char* text) {
    QMessageBox msgBox;
    msgBox.setText(QString(text));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}
