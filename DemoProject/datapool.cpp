#include "datapool.h"

DataPool* DataPool::instance_ = NULL;

DataPool* DataPool::newInstance(){
    if (NULL == instance_){
        static DataPool instanceT;
        instance_ = &instanceT;
        events = new AlertEvent[100]();
    }
    return instance_;
};

//DataPool::~DataPool(){
//    //remove all the instance in the map.
//}

void DataPool::storeById(int clusterId, string name, double value){
    ClusterDataPool* currentClusterDataPool;
    try{
        currentClusterDataPool = clusterDataMap.at(clusterId);
    }catch(std::out_of_range &e){
        currentClusterDataPool = new ClusterDataPool;
        this->clusterDataMap.insert(std::pair<int, ClusterDataPool*>(clusterId, currentClusterDataPool));
    }
//    log(QString("store data by id"));
    currentClusterDataPool->store(name, value);
}

void DataPool::storeById(int clusterId, int moduleId, string name, double value){
    ClusterDataPool* currentClusterDataPool;
    try{
        currentClusterDataPool = clusterDataMap.at(clusterId);
    }catch(std::out_of_range &e){
        currentClusterDataPool = new ClusterDataPool;
        this->clusterDataMap.insert(std::pair<int, ClusterDataPool*>(clusterId, currentClusterDataPool));
    }
    currentClusterDataPool->storeById(moduleId, name, value);
}

double DataPool::getDoubleByIndex(int clusterIndex, string name){
    int i = 1;
    int key = -1;
    map<int, ClusterDataPool* >::iterator iter;
    for(iter = clusterDataMap.begin(); iter != clusterDataMap.end(); ++iter)
    {
        if (i == clusterIndex){
            key = iter->first;
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
    map<int, ClusterDataPool* >::iterator iter;
    for(iter = clusterDataMap.begin(); iter != clusterDataMap.end(); ++iter)
    {
        if (i == clusterIndex){
            key = iter->first;
            break;
        }
        i++;
    }
    if(key == -1){
        return 0;
    }
    try{
        return clusterDataMap[key]->getDoubleByIndex(moduleIndex, name);
    }catch(std::out_of_range &e){// no such data
        return 0;
    }
}

double DataPool::getDoubleById(int clusterId, int moduleId, string name){
    try{
        return clusterDataMap.at(clusterId)->getDoubleById(moduleId, name);
    }catch(std::out_of_range &e){// no such data
        return 0;
    }
}


