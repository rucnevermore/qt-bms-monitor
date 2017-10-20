#include "clusterdatapool.h"
#include <stdexcept>
#include "configure.h"

ClusterDataPool::ClusterDataPool()
{
    Configure* configure = Configure::newInstance();
    dataMap = new double[configure->CLUSTER_DATA_NUM+1]();
    moduleDataMap = new double*[configure->MODULE_NUM+1]();
    for(int i = 0; i < configure->MODULE_NUM+1; i++){
        moduleDataMap[i] = new double[configure->MODULE_DATA_NUM+1]();
    }

}

ClusterDataPool::~ClusterDataPool(){
    delete []moduleDataMap;
    delete []dataMap;
}

bool ClusterDataPool::storeById(int moduleId, int name, double value){
    moduleDataMap[moduleId][name]=value;
    return true;
}

double ClusterDataPool::getDoubleByIndex(int moduleIndex, int name){
    // special treatment for macro.
//    if (name == "_ID_"){
//        return moduleIndex;
//    }
    return moduleDataMap[moduleIndex][name];
}

double ClusterDataPool::getDoubleById(int moduleId, int name){
    return moduleDataMap[moduleId][name];
}

bool ClusterDataPool::store(int name, double value){
    dataMap[name]=value;
    return true;
}

bool ClusterDataPool::store(int name, unsigned char* value, int length){
    QString temp = QString::fromLocal8Bit((char*)value, length);
    dataMap[name]=temp.toDouble();
    return true;
}

int ClusterDataPool::getInt(int name){
    return dataMap[name];
}

double ClusterDataPool::getDouble(int name){
    return dataMap[name];
}
