#pragma once
#include <qvector.h>
#include "event.h"
#include <QtWidgets/QTableWidget>
#include <QMessageBox>
#include "alert_emiter.h"
#include <QPushButton>
#include <QHBoxLayout>

struct DefaultPanel;

class DbManager : QObject {
    Q_OBJECT
    public:

    void populateTable ( ) const;

    static DbManager* getInstance ();

    static void releaseInstance ();

    std::vector<Event> getEvents () const;

    int getEventsCount () const;
    void load ( std::vector<Event> _events );
    void reset ( );
    void print ( );

    public slots:

    // Notify a type was selected. Save it if is a new one.
    void typeSelected (const QString& type);

    void addEvent ();
    void tableCellChanged (int row, int column);

    private:
    static DbManager* _INSTANCE;
    std::vector<Event> events;

    DbManager ();
    ~DbManager ();
};
