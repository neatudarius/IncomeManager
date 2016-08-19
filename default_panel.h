#pragma once

#include <QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QTableWidget>
#include <qapplication.h>
#include "event.h"

struct DefaultPanel : QWidget {
    // Form elements
    QLineEdit *name, *notes, *amount;
    QComboBox* type;
    QDateTimeEdit* date;
    QPushButton* addEvent;

    // Table
    QTableWidget* table;

    // Methods
    DefaultPanel ( QWidget* parent );
    ~DefaultPanel ( );
    void createAddEventForm ( QWidget* parent );
    void createTableWidget ( QWidget* parent );
};
