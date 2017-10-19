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
    BaseDataPool(int size);
    bool store(int name, double value);
    bool store(int name, unsigned char* value, int length);
    bool store(double* localMap, int name, double value);
    double getDouble(int name);
    int getInt(int name);
    double* dataMap;
};

#endif // BASEDATAPOOL_H
