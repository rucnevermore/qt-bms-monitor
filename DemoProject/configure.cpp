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
    MODBUS_DEV = settings.value("Private/ModbusDev", "/dev/ttySAC0").toString();
    MODBUS_TYPE = settings.value("Private/ModbusType", "RTU").toString();
    MODBUS_PORT = settings.value("Private/ModbusPort", 1502).toInt();
    MODBUS_ADDRESS = settings.value("Private/ModbusAddress", "127.0.0.1").toString();
    current_module_selected = new int[CLUSTER_NUM+1]();
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

QString Configure::getModbusDev(){
    return MODBUS_DEV;
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

QString Configure::getModbusType(){
    return MODBUS_TYPE;
}

int Configure::getModbusPort(){
    return MODBUS_PORT;
}

QString Configure::getModbusAddress(){
    return MODBUS_ADDRESS;
}

QString Configure::print(){
    return QString("Configure:\n").append(QString("\tCluster Number: ")).append(QString::number(CLUSTER_NUM)).append(QString("\n"))
            .append(QString("\tModule Number: ")).append(QString::number(MODULE_NUM)).append(QString("\n"))
            .append(QString("\tMax Event Number: ")).append(QString::number(MAX_EVENT_NUM)).append(QString("\n"))
            .append(QString("\tMax Event In One Page: ")).append(QString::number(MAX_EVENT_IN_ONE_PAGE)).append(QString("\n"))
            .append(QString("\tModbus device: ")).append(MODBUS_DEV).append(QString("\n"))
            .append(QString("\tModbus type: ")).append(MODBUS_TYPE).append(QString("\n"))
            .append(QString("\tModbus port: ")).append(QString::number(MODBUS_PORT)).append(QString("\n"))
            .append(QString("\tModbus address: ")).append(MODBUS_ADDRESS).append(QString("\n"));
}
