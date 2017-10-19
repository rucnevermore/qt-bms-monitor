#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

class EventListener
{
public:
    virtual void notify(int name, double value)=0;
};

#endif // EVENTLISTENER_H
