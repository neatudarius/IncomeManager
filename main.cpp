#include "income_manager.h"
#include <QtWidgets/QApplication>

int main ( int argc, char *argv[] ) {
    // create application
    QApplication a ( argc , argv );

    // create and display main window
    IncomeManager *w =  IncomeManager::getInstance ( ) ;
    w -> show ( );
    
    int res = a.exec ( );

    delete w;

    return res;
}
