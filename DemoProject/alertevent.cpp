#include "alertevent.h"

AlertEvent::AlertEvent(QDate date, QString message)
{
    this->date = date;
    this->message = message;
}
