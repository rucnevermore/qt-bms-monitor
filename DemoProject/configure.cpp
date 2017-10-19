#include "configure.h"
#include <stddef.h>

Configure* Configure::instance_ = NULL;

Configure::Configure(){
    max_event_number=100;
    current_module_selected = new int[CLUSTER_NUM]();
    max_num_in_one_page=10;
    current_event_page=0;
    current_cluster_index=0;
}

Configure::~Configure(){

}

Configure* Configure::newInstance(){
    if (NULL == instance_){
        instance_ = new Configure();
    }
    return instance_;
}

int Configure::getClusterNum(){
    return CLUSTER_NUM;
}

int Configure::getMaxEventNum(){
    return max_event_number;
}

// current selected module index
int Configure::getCurrentModuleSelected(int clusterIndex){
    return current_module_selected[clusterIndex];
}

void Configure::setCurrentModuleSelected(int clusterIndex, int moduleIndex){
    current_module_selected[clusterIndex]=moduleIndex;
}

// maximum event number in one page
int Configure::getMaxEventInOnePage(){
    return max_num_in_one_page;
}

void Configure::setMaxEventInOnePage(int num){
    max_num_in_one_page=num;
}

// event current page number for event
int Configure::getEventCurrentPageNum(){
    return current_event_page;
}

void Configure::setEventCurrentPageNum(int num){
    current_event_page=num;
}

void Configure::setClusterIndex(int clusterId){
    current_cluster_index=clusterId;
}

int Configure::getClusterIndex(){
    return current_cluster_index;
}
