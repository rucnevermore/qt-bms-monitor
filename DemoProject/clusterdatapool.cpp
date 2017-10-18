#include "clusterdatapool.h"
#include <stdexcept>

ClusterDataPool::ClusterDataPool()
{
}

bool ClusterDataPool::storeById(int moduleId, string name, double value){
    QMap<string, Data*>* currentMap;
    if (moduleDataMap.contains(moduleId)){
        currentMap = moduleDataMap.value(moduleId);
    }else{
        QMap<string, Data*>* tempDataMap = new QMap<string, Data*>();
        moduleDataMap.insert(moduleId, tempDataMap);
        currentMap = tempDataMap;
    }
    return this->store(currentMap, name, CAN, DOUBLE, value);
}

double ClusterDataPool::getDoubleByIndex(int moduleIndex, string name){
    int i = 0;
    int key = -1;
    QMap<int, QMap<string, Data*>* >::iterator iter;
    for(iter = moduleDataMap.begin(); iter != moduleDataMap.end(); ++iter)
    {
        if (i == moduleIndex){
            key = iter.key();
            break;
        }
        i++;
    }
    if(key == -1){
        return 0;
    }
    // special treatment for macro.
    if (name == "_ID_"){
        return key;
    }

    if (moduleDataMap[key]->contains(name)){
        return moduleDataMap[key]->value(name)->getValue();
    }else{// no such data
        return 0;
    }
}

double ClusterDataPool::getDoubleById(int moduleId, string name){
    if (moduleDataMap.contains(moduleId)&&moduleDataMap.value(moduleId)->contains(name)){
        return moduleDataMap.value(moduleId)->value(name)->getValue();
    }else{// no such data
        return 0;
    }
}

int ClusterDataPool::getDataNumber(){
    int dataNumber = this->dataMap.size();
    QMap<int, QMap<string, Data*>* >::iterator iter;
    for(iter = moduleDataMap.begin(); iter != moduleDataMap.end(); ++iter)
    {
        QMap<string, Data*>* moduleDataMap = iter.value();
        dataNumber = dataNumber + moduleDataMap->size();
    }
    return dataNumber;
}
