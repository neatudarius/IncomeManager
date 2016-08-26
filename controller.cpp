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

    FileManager::getInstance()->createFile(fileName.toStdString().c_str());
    FileManager::getInstance()->setCurrentFile(fileName);
}

// Open database (file)
void Controller::open () {
    QString fileName = QFileDialog::getOpenFileName(NULL ,
                                                        tr("Open file") ,
                                                        QStandardPaths::standardLocations(QStandardPaths::DesktopLocation)[ 0 ] ,
                                                        tr("Income Manager Files (*.income)"));
    FileManager::getInstance()->setCurrentFile(fileName);
    if (FileManager::getInstance()->fileSet()) {
        FileManager::getInstance()->load();
    }
}

// Save current database (file)
void Controller::save () {
    if ( IncomeManager::getInstance()->savedChanges ( ) ) {
        return;
    }

    if (FileManager::getInstance()->fileSet()) {
        FileManager::getInstance()->save();
    }
    else {
        saveAs();
    }
}

// Save current database to other file
void Controller::saveAs () {
    if ( IncomeManager::getInstance ( )->savedChanges ( ) ) {
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(NULL ,
                                                        tr("Save as") ,
                                                        QStandardPaths::standardLocations(QStandardPaths::DesktopLocation)[ 0 ] ,
                                                        tr("Income Manager Files (*.income)"));
    FileManager::getInstance()->createFile(fileName.toStdString().c_str());
    FileManager::getInstance()->setCurrentFile(fileName);
    if (FileManager::getInstance()->fileSet()) {
        FileManager::getInstance()->save();
    }
}
