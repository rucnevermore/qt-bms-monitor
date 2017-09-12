#ifndef ALERTEVENT_H
#define ALERTEVENT_H

#include <QDateTime>

class AlertEvent
{
public:
    AlertEvent(QDateTime date, QString message);
    QDateTime date;
    QString message;
    // TODO: detail
};

#endif // ALERTEVENT_H
