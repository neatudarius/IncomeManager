#include "menu_bar.h"


MenuBar::MenuBar ( QWidget* parent ) : QMenuBar(parent) {
    fileMenu ( );
}


MenuBar::~MenuBar ( ) {
}


//QAction *createAction ( std::string name, QMenu *parent) {
//    QAction *action = new QAction ( "&", parent );
//    action->setShortcuts ( QKeySequence::New );
//    action->setStatusTip ( "Create a new file" );
////    QObject::connect ( action, &QAction::triggered, this, &MenuBar::newFile );
//    return NULL;
//}

void MenuBar::fileMenu ( ) {
    QMenu* menu = new QMenu ( "File" );

    menu->addAction ( new Action ( "&New", this, "Create new file", &MenuBar::newFile, QKeySequence::New) );
    menu->addAction ( new Action ( "&Open", this, "Open file", &MenuBar::open, QKeySequence::Open ) );
    menu->addAction ( new Action ( "&Save", this, "Save current file", &MenuBar::save, QKeySequence::Save ) );
    menu->addAction ( new Action ( "&Save as ...", this, "Save data to othr file", &MenuBar::saveAs, QKeySequence::SaveAs ) );

    addMenu ( menu );
}

void MenuBar::newFile ( ) {
    AlertEmiter::emitMessageBox ( "new" );
}

void MenuBar::open ( ) {
    AlertEmiter::emitMessageBox ( "open" );
}

void MenuBar::save ( ) {
    AlertEmiter::emitMessageBox ( "save" );
}

void MenuBar::saveAs ( ) {
    AlertEmiter::emitMessageBox ( "save as" );
}
