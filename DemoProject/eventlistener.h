#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "data.h"

class EventListener
{
public:
    virtual void notify(string name, QString value)=0;
};

#endif // EVENTLISTENER_H
