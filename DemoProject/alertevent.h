#ifndef ALERTEVENT_H
#define ALERTEVENT_H

#include <QDate>

class AlertEvent
{
public:
    AlertEvent(QDate date, QString message);
    QDate date;
    QString message;
    // TODO: detail
};

#endif // ALERTEVENT_H
