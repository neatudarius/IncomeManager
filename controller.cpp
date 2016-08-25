#include "controller.h"
#include "view_holder.h"

Controller* Controller::_INSTANCE = NULL;

Controller::Controller () {}

Controller::~Controller () {}

Controller* Controller::getInstance () {
    if (_INSTANCE == NULL) {
        _INSTANCE = new Controller();
    }
    return _INSTANCE;
}

void Controller::releaseInstance () {
    if (_INSTANCE != NULL) {
        delete _INSTANCE;
        _INSTANCE = NULL;
    }
}

// Create new database (file)
void Controller::newFile () {
    QString fileName = QFileDialog::getSaveFileName(NULL ,
                                                        tr("New file") ,
                                                        QStandardPaths::standardLocations(QStandardPaths::DesktopLocation)[ 0 ] ,
                                                        tr("Income Manager Files (*.income)"));
    AlertEmiter::emitMessageBox(fileName.toStdString().c_str());
}

// Open database (file)
void Controller::open () {
    QString fileName = QFileDialog::getOpenFileName(NULL ,
                                                        tr("Open file") ,
                                                        QStandardPaths::standardLocations(QStandardPaths::DesktopLocation)[ 0 ] ,
                                                        tr("Income Manager Files (*.income)"));
    AlertEmiter::emitMessageBox(fileName.toStdString().c_str());
}

// Save current database (file)
void Controller::save () {
    AlertEmiter::emitMessageBox("save");
}

// Save current database to other file
void Controller::saveAs () {
    QString fileName = QFileDialog::getSaveFileName(NULL ,
                                                        tr("Save as") ,
                                                        QStandardPaths::standardLocations(QStandardPaths::DesktopLocation)[ 0 ] ,
                                                        tr("Income Manager Files (*.income)"));
    AlertEmiter::emitMessageBox(fileName.toStdString().c_str());
}
