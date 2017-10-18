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
    bool store(string name, double value);
    bool store(string name, unsigned char* value, int length);
    bool store(QMap<string, Data*>* localMap, string name, int channel, int type, double value);
    Data* retrieve(string name);
    double getDouble(string name);
    int getInt(string name);
    QMap<string, Data*> dataMap;
};

#endif // BASEDATAPOOL_H
