#ifndef DATAPOOL_H
#define DATAPOOL_H

#include <map>
#include "data.h"
#include <string>
#include <stdio.h>
#include "ui_widget.h"
#include <stdexcept>
#include "basedatapool.h"
#include "clusterdatapool.h"
#include "alertevent.h"

class DataPool : public BaseDataPool
{
public:
    static DataPool* newInstance();
    void storeById(int clusterId, string name, double value);
    void storeById(int clusterId, int moduleId, string name, double value);
    double getDoubleByIndex(int clusterIndex, string name);
    double getDoubleByIndex(int clusterIndex, int moduleIndex, string name);
    double getDoubleById(int clusterId, int moduleId, string name);
private:
    DataPool(){};
    ~DataPool(){};
    // Cluster id, Module id, datamap
    map<int, ClusterDataPool*> clusterDataMap;
    AlertEvent[100] events;
    static DataPool* instance_;
};

#endif // DATAPOOL_H
