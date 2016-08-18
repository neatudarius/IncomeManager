#include <QString>
#include "event.h"
#include <QPushButton>
#include <QHBoxLayout>

int Event::ID_COUNTER = 0;
QStringList Event::TYPES = QStringList({
    "INCOME",
    "SALARY",
    "SCHOLARSHIP",
    "COACHING",
    "TEACHING",
    "SOFTWARE_SELLING",
    "SELLING",
    "EXPENSE",
    "PAYMENT",
    "TRANSACTION",
    "SHOPPING",
    "TRIP",
    "HOLIDAY",
    "RENT",
    "FOOD",
    "TRANSPORT"
});

Event::Event() {
}

Event::Event(QString _name, QString _type, double _amount, QDateTime _date, QString _notes) 
    : name(_name), type(_type), amount(_amount), date(_date), notes(_notes) {
    id = ++ID_COUNTER;


    idWidget = new QTableWidgetItem;
    idWidget->setData(0, id);

    nameWidget = new QTableWidgetItem;
    nameWidget->setData(0, name);

    amountWidget = new QTableWidgetItem;
    amountWidget->setData(0, amount);

    typeWidget = new QTableWidgetItem;
    typeWidget->setData(0, type);

    dateWidget = new QTableWidgetItem;
    dateWidget->setData(0, date);

    notesWidget = new QTableWidgetItem;
    notesWidget->setData(0, notes);

    QPushButton *editableButton = new QPushButton;
    editableButton->setIcon(QIcon("Images/Icons/locked-black.png"));
    //    QObject::connect(editableButton, SIGNAL(clicked(bool)), editableButton->pa, SLOT(tableCellChanged(int, int)));

    actionsWidget = new QWidget();
    QHBoxLayout* pLayout = new QHBoxLayout(actionsWidget);
    pLayout->addWidget(editableButton);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 0, 0, 0);
    actionsWidget->setLayout(pLayout);
}

Event::~Event() {
}

bool Event::operator==(const Event& e) {
    return this->name == e.name && this->amount == e.amount && this->date == e.date;
}



