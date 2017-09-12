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
    return dataPool->clusterDataMap.size();
}

int Configure::getMaxEventNum(){
    return dataPool->getInt("max_event_number");
}

// maximum event number in one page
int Configure::getMaxEventInOnePage(){
    return dataPool->getInt("max_num_in_one_page");
}

void Configure::setMaxEventInOnePage(int num){
    dataPool->store("max_num_in_one_page", num);
}

// event current page number for event
int Configure::getEventCurrentPageNum(){
    return dataPool->getInt("current_event_page");
}

void Configure::setEventCurrentPageNum(int num){
    dataPool->store("current_event_page", num);
}

// event total
int Configure::getEventTotal(){
    return dataPool->events.size();
}

void Configure::setClusterIndex(int clusterId){
    dataPool->store("current_cluster_index", clusterId);
}

int Configure::getClusterIndex(){
    return dataPool->getInt("current_cluster_index");
}
