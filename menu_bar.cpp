#include "menu_bar.h"
#include "Action.h"

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
    menu->addAction ( new Action<Controller> ( "&New", "Create new file", &Controller::newFile, QKeySequence::New ) );
    menu->addAction ( new Action<Controller> ( "&Open",  "Open file", &Controller::open, QKeySequence::Open ) );
    menu->addAction ( new Action<Controller> ( "&Save", "Save current file", &Controller::save, QKeySequence::Save ) );
    menu->addAction ( new Action<Controller> ( "&Save as ...", "Save data to othr file", &Controller::saveAs, QKeySequence::SaveAs ) );

    // Save it
    addMenu ( menu );
}

