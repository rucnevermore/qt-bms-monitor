#ifndef CLUSTERDATAPOOL_H
#define CLUSTERDATAPOOL_H

#include <QObject>
#include "configure.h"

class ClusterDataPool : public QObject
{
public:
    ClusterDataPool();
    ~ClusterDataPool();
    bool storeById(int moduleId, int name, double value);
    double getDoubleByIndex(int moduleIndex, int name);
    double getDoubleById(int moduleId, int name);

    bool store(string name, double value);
    bool store(string name, unsigned char* value, int length);
    double getDouble(int name);
    int getInt(int name);

    // two dimension [][]
    double* moduleDataMap;
    double* dataMap;
};

#endif // CLUSTERDATAPOOL_H
