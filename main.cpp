#include "income_manager.h"
#include <QtWidgets/QApplication>

int main ( int argc, char *argv[] ) {
    // create application
    QApplication a ( argc , argv );

    // create and display main window
    IncomeManager *incomeManager = IncomeManager::getInstance ( );
    incomeManager->init ( );
    
    int res = a.exec ( );

    IncomeManager::releaseInstance ( );

    return res;
}
