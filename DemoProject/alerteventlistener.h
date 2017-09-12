#ifndef ALERTEVENTLISTENER_H
#define ALERTEVENTLISTENER_H

#include "eventlistener.h"
#include "datapool.h"

class AlertEventListener : public EventListener
{
public:
    AlertEventListener();
    virtual void notify(string name, QString value);
private:
    DataPool* dataPool;
};

#endif // ALERTEVENTLISTENER_H
