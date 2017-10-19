#ifndef ALERTEVENTLISTENER_H
#define ALERTEVENTLISTENER_H

#include "eventlistener.h"
#include "datapool.h"

class AlertEventListener : public EventListener
{
public:
    AlertEventListener();
    virtual void notify(int name, double value);
private:
    DataPool* dataPool;
};

#endif // ALERTEVENTLISTENER_H
