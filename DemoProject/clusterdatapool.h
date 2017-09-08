#ifndef CLUSTERDATAPOOL_H
#define CLUSTERDATAPOOL_H

#include <QObject>
#include "basedatapool.h"
#include <QMap>

class ClusterDataPool : public QObject, public BaseDataPool
{
public:
    ClusterDataPool();
    void storeById(int moduleId, string name, double value);
    double getDoubleByIndex(int moduleIndex, string name);
    double getDoubleById(int moduleId, string name);
private:
    QMap<int, QMap<string, Data*>*> moduleDataMap;
};

#endif // CLUSTERDATAPOOL_H
