#include "alertevent.h"

AlertEvent::AlertEvent(QDateTime date, QString message)
{
    this->date = date;
    this->message = message;
}
