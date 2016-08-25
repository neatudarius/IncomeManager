#pragma once
#include <QFileDialog>
#include <QStandardPaths>
#include "alert_emiter.h"
#include <QMenuBar>
#include <QAction>
#include <QCloseEvent>
#include "alert_emiter.h"

class Controller : public QWidget {
    public:
    /** File menu's actions **/
    // Create new database (file)
    void newFile ();

    // Open database (file)
    void open ();

    // Save current database (file)
    void save ();

    // Save current database to other file
    void saveAs ();

    static Controller* getInstance ();

    static void releaseInstance ();

    private:
    static Controller* _INSTANCE;

    Controller ();

    ~Controller ();
};

// Type wich define a pointer to an instance function from this class

typedef void ( Controller::* FncPtr ) ();
