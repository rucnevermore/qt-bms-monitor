#include "clusterdatapool.h"
#include <stdexcept>

ClusterDataPool::ClusterDataPool()
{
}

void ClusterDataPool::storeById(int moduleId, string name, double value){
    QMap<string, Data*>* currentMap;
    if (moduleDataMap.contains(moduleId)){
        currentMap = moduleDataMap.value(moduleId);
    }else{
        QMap<string, Data*>* tempDataMap = new QMap<string, Data*>();
        moduleDataMap.insert(moduleId, tempDataMap);
        currentMap = tempDataMap;
    }
    QString temp = QString::number(value);
    this->store(currentMap, name, CAN, DOUBLE, temp);
}

double ClusterDataPool::getDoubleByIndex(int moduleIndex, string name){
    int i = 1;
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

    if (moduleDataMap[key]->contains(name)){
        return moduleDataMap[key]->value(name)->getValue().toDouble();
    }else{// no such data
        return 0;
    }
}

double ClusterDataPool::getDoubleById(int moduleId, string name){
    if (moduleDataMap.contains(moduleId)&&moduleDataMap.value(moduleId)->contains(name)){
        return moduleDataMap.value(moduleId)->value(name)->getValue().toDouble();
    }else{// no such data
        return 0;
    }
}