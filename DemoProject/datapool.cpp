#include "datapool.h"
#include "configure.h"

DataPool* DataPool::instance_ = NULL;

DataPool* DataPool::newInstance(){
    if (NULL == instance_){
        static DataPool instanceT;
        instance_ = &instanceT;
    }
    return instance_;
};

DataPool::~DataPool(){
    //remove all the instance in the map.
    dataMap.clear();
    clusterDataMap.clear();
    events.clear();
}

void DataPool::addEvent(QString message){
    addEvent(QDate::currentDate(), message);
}

// add an event into datapool, if event number exceed maximum number, the oldest event will be remove.
void DataPool::addEvent(QDate date, QString message){
    Configure* configure = Configure::newInstance();
    int maxEventNum = configure->getMaxEventNum();
    if (events.size() >= maxEventNum){
        events.remove(0);
    }
    events.append(new AlertEvent(date, message));
}

void DataPool::storeById(int clusterId, string name, double value){
    ClusterDataPool* currentClusterDataPool;

    if (clusterDataMap.contains(clusterId)){
        currentClusterDataPool = clusterDataMap.value(clusterId);
    }else{
        currentClusterDataPool = new ClusterDataPool;
        this->clusterDataMap.insert(clusterId, currentClusterDataPool);
    }
    currentClusterDataPool->store(name, value);
}

void DataPool::storeById(int clusterId, int moduleId, string name, double value){
    ClusterDataPool* currentClusterDataPool;
    if (clusterDataMap.contains(clusterId)){
        currentClusterDataPool = clusterDataMap.value(clusterId);
    }else{
        currentClusterDataPool = new ClusterDataPool;
        this->clusterDataMap.insert(clusterId, currentClusterDataPool);
    }
    currentClusterDataPool->storeById(moduleId, name, value);
}

double DataPool::getDoubleByIndex(int clusterIndex, string name){
    int i = 1;
    int key = -1;
    QMap<int, ClusterDataPool* >::iterator iter;
    for(iter = clusterDataMap.begin(); iter != clusterDataMap.end(); ++iter)
    {
        if (i == clusterIndex){
            key = iter.key();
            break;
        }
        i++;
    }
    if(key == -1){
        return 0;
    }
    try{
        return clusterDataMap[key]->getDouble(name);
    }catch(std::out_of_range &e){// no such data
        return 0;
    }
}

double DataPool::getDoubleByIndex(int clusterIndex, int moduleIndex, string name){
    int i = 1;
    int key = -1;
    QMap<int, ClusterDataPool* >::iterator iter;
    for(iter = clusterDataMap.begin(); iter != clusterDataMap.end(); ++iter)
    {
        if (i == clusterIndex){
            key = iter.key();
            break;
        }
        i++;
    }
    if(key == -1){
        return 0;
    }
    return clusterDataMap[key]->getDoubleByIndex(moduleIndex, name);
}

double DataPool::getDoubleById(int clusterId, int moduleId, string name){
    if (clusterDataMap.contains(clusterId)){
        return clusterDataMap.value(clusterId)->getDoubleById(moduleId, name);
    }else{// no such data
        return 0;
    }
}


