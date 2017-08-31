#include "clusterdatapool.h"
#include <stdexcept>

ClusterDataPool::ClusterDataPool()
{
}

void ClusterDataPool::storeById(int moduleId, string name, double value){
    map<string, Data*>* currentMap;
    try{
        currentMap = moduleDataMap.at(moduleId);
    }catch(std::out_of_range &e){
        map<string, Data*>* tempDataMap = new map<string, Data*>();
        moduleDataMap.insert(std::pair<int, map<string, Data*>*>(moduleId, tempDataMap));
        currentMap = tempDataMap;
    }
    QString temp = QString::number(value);
//    log(QString::fromStdString("[DataPool]store double value ").append(QString::fromLocal8Bit((char*)temp)));
    this->store(currentMap, name, CAN, DOUBLE, temp);
}

double ClusterDataPool::getDoubleByIndex(int moduleIndex, string name){
    int i = 1;
    int key = -1;
    map<int, map<string, Data*>* >::iterator iter;
    for(iter = moduleDataMap.begin(); iter != moduleDataMap.end(); ++iter)
    {
        if (i == moduleIndex){
            key = iter->first;
            break;
        }
        i++;
    }
    if(key == -1){
        return 0;
    }

    try{
        return moduleDataMap[key]->at(name)->getValue().toDouble();
    }catch(std::out_of_range &e){// no such data
        return 0;
    }
}

double ClusterDataPool::getDoubleById(int moduleId, string name){
    try{
        return moduleDataMap.at(moduleId)->at(name)->getValue().toDouble();
    }catch(std::out_of_range &e){// no such data
        return 0;
    }
}
