#ifndef BASEDATAPOOL_H
#define BASEDATAPOOL_H

#include <QObject>
#include <map>
#include "data.h"
#include <string>

class BaseDataPool
{
public:
    BaseDataPool();
    void store(string name, double value);
    void store(string name, unsigned char* value, int length);
    void store(map<string, Data*>* localMap, string name, Channel channel, DataType type, QString value);
    Data* retrieve(string name);
    double getDouble(string name);
    int getInt(string name);
protected:
    map<string, Data*> dataMap;
};

#endif // BASEDATAPOOL_H
