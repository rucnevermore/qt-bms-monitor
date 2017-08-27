#include "configure.h"

Configure* Configure::instance_ = NULL;
DataPool* dataPool = NULL;

Configure::~Configure(){

}

Configure* Configure::newInstance(){
    if (NULL == instance_){
        instance_ = new Configure();
        dataPool = DataPool::newInstance();
    }
    return instance_;
}

int Configure::getClusterNum(){
    return dataPool->getInt("cluster_number");
}

void Configure::setClusterId(int clusterId){
    dataPool->store("current_cluster_id", clusterId);
}

int Configure::getClusterId(){
    return dataPool->getInt("current_cluster_id");
}
