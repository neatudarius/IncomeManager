#include "income_manager.h"
#include "view_holder.h"

IncomeManager* IncomeManager::_INSTANCE = NULL;

// Constructor: make app
IncomeManager::IncomeManager () {
    saved = true;
}

void IncomeManager::init () {
    // Setup uiL create view
    ui = ViewHolder::getInstance();
    ui->setupUi();

    // init view with data
    db = DbManager::getInstance();

    // init file manager
    fm = FileManager::getInstance();

    // init file manager
    controller = Controller::getInstance();

    QMetaObject::connectSlotsByName(this);
}

// Destructor close app
IncomeManager::~IncomeManager () {
    ViewHolder::releaseInstance();
    DbManager::releaseInstance();
    FileManager::releaseInstance();
    Controller::releaseInstance();
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

bool IncomeManager::savedChanges () {
    return  saved;
}
void IncomeManager::dataChanged () {
    saved = false;
    ViewHolder::getInstance ( )->setTitleChanged ( );
}

void IncomeManager::dataSaved ( ) {
    saved = true;
    ViewHolder::getInstance ( )->setTitleSaved( );
}
