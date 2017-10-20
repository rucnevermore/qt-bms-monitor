#include "configure.h"
#include <stddef.h>


Configure* Configure::instance_ = NULL;

Configure::Configure(){
    QString iniFilePath = "/yctek/app/DemoProject.ini";
    QSettings settings(iniFilePath,QSettings::IniFormat);
    CLUSTER_NUM = settings.value("Public/ClusterNumber", 10).toInt();
    MODULE_NUM = settings.value("Public/ModuleNumber", 10).toInt();
    MAX_EVENT_NUM = settings.value("Public/MaxEventNum", 100).toInt();
    MAX_EVENT_IN_ONE_PAGE = settings.value("Public/MaxEventInOnePage", 10).toInt();
    GLOBAL_DATA_NUM = settings.value("Private/GlobalDataNum", 30).toInt();
    CLUSTER_DATA_NUM = settings.value("Private/ClusterDataNum", 60).toInt();
    MODULE_DATA_NUM = settings.value("Private/ModuleDataNum", 100).toInt();
    current_module_selected = new int[CLUSTER_NUM]();
    current_event_page=0;
    current_cluster_index=0;
}

Configure::~Configure(){
    delete []current_module_selected;
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
    return MAX_EVENT_NUM;
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
    return MAX_EVENT_IN_ONE_PAGE;
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

QString Configure::print(){
    return QString("Configure:\n").append(QString("Cluster Number: ")).append(QString::number(CLUSTER_NUM)).append(QString("\n"))
            .append(QString("Cluster Number: ")).append(QString::number(CLUSTER_NUM)).append(QString("\n"))
            .append(QString("Module Number: ")).append(QString::number(MODULE_NUM)).append(QString("\n"))
            .append(QString("Max Event Number: ")).append(QString::number(MAX_EVENT_NUM)).append(QString("\n"))
            .append(QString("Max Event In One Page: ")).append(QString::number(MAX_EVENT_IN_ONE_PAGE)).append(QString("\n"));
}
