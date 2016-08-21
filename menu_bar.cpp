#include "menu_bar.h"

// Constructor
MenuBar::MenuBar ( QWidget* parent ) : QMenuBar(parent) {
    fileMenu ( );
}

// Destructor
MenuBar::~MenuBar ( ) {
}

// Create file menu
void MenuBar::fileMenu ( ) {
    // file menu object
    QMenu* menu = new QMenu ( "File" );

    // Menu's actions
    menu->addAction ( new Action ( "&New", this, "Create new file", &MenuBar::newFile, QKeySequence::New) );
    menu->addAction ( new Action ( "&Open", this, "Open file", &MenuBar::open, QKeySequence::Open ) );
    menu->addAction ( new Action ( "&Save", this, "Save current file", &MenuBar::save, QKeySequence::Save ) );
    menu->addAction ( new Action ( "&Save as ...", this, "Save data to othr file", &MenuBar::saveAs, QKeySequence::SaveAs ) );

    // Save it
    addMenu ( menu );
}

// Create new database (file)
void MenuBar::newFile ( ) {
    QString fileName = QFileDialog::getSaveFileName ( this,
                                                      tr ( "New file" ), 
                                                      QStandardPaths::standardLocations ( QStandardPaths::DesktopLocation ) [ 0 ],
                                                      tr ( "Income Manager Files (*.income)" ) );
    AlertEmiter::emitMessageBox ( fileName.toStdString().c_str() );
}

// Open database (file)
void MenuBar::open ( ) {
    QString fileName = QFileDialog::getOpenFileName ( this,
                                                      tr ( "Open file" ),
                                                      QStandardPaths::standardLocations ( QStandardPaths::DesktopLocation ) [ 0 ],
                                                      tr ( "Income Manager Files (*.income)" ) );
    AlertEmiter::emitMessageBox ( fileName.toStdString ( ).c_str ( ) );
}

// Save current database (file)
void MenuBar::save ( ) {
    AlertEmiter::emitMessageBox ( "save" );
}

// Save current database to other file
void MenuBar::saveAs ( ) {
    QString fileName = QFileDialog::getSaveFileName ( this,
                                                      tr ( "Save as" ),
                                                      QStandardPaths::standardLocations ( QStandardPaths::DesktopLocation ) [ 0 ],
                                                      tr ( "Income Manager Files (*.income)" ) );
    AlertEmiter::emitMessageBox ( fileName.toStdString ( ).c_str ( ) );
}
