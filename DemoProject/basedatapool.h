#ifndef BASEDATAPOOL_H
#define BASEDATAPOOL_H

#include <QObject>
#include "data.h"
#include <string>
#include <QMap>
#include <QList>
#include "eventlistener.h"

class BaseDataPool
{
public:
    BaseDataPool();
    void store(string name, double value);
    void store(string name, unsigned char* value, int length);
    void store(QMap<string, Data*>* localMap, string name, Channel channel, DataType type, QString value);
    Data* retrieve(string name);
    double getDouble(string name);
    int getInt(string name);

    void registerListener(EventListener* listener);
    void notifyListener(Data* data);
protected:
    QMap<string, Data*> dataMap;
    QList<EventListener*> listeners;
};

#endif // BASEDATAPOOL_H
