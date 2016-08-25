#include "income_manager.h"
#include "view_holder.h"

IncomeManager* IncomeManager::_INSTANCE = NULL;

// Constructor: make app
IncomeManager::IncomeManager (QWidget* parent)
    : QMainWindow(parent) {}

void IncomeManager::init () {
    // Setup uiL create view
    ui = ViewHolder::getInstance(this);
    ui->setupUi();

    // init view with data
    db = DbManager::getInstance ( );
    db->initTable(ui->defaultPanel->table);

    // init file manager
    fm = FileManager::getInstance ( );

    //
    controller = Controller::getInstance ( );

    QMetaObject::connectSlotsByName ( this );
}

// Destructor close app
IncomeManager::~IncomeManager () {
    ViewHolder::releaseInstance();
    DbManager::releaseInstance ( );
    FileManager::releaseInstance ( );
    Controller::releaseInstance ( );
}

// Method for accesing the Instance of this class
IncomeManager* IncomeManager::getInstance () {
    if (_INSTANCE == NULL) {
        _INSTANCE = new IncomeManager();
    }
    return _INSTANCE;
}

// Method for release the Instance of this class
void IncomeManager::releaseInstance () {
    if (_INSTANCE != NULL) {
        delete _INSTANCE;
        _INSTANCE = NULL;
    }
}

// Notify close application button was pressed
void IncomeManager::closeEvent (QCloseEvent* event) {
    QMessageBox::StandardButton response = QMessageBox::question(this , "Close Confirmation?" ,
                                                                 "Are you sure you want to exit?" ,
                                                                 QMessageBox::Yes | QMessageBox::No);
    event->ignore();
    if (response == QMessageBox::Yes) {
        event->accept();
        return;
    }
};
