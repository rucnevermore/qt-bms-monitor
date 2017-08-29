#include "datapool.h"

DataPool* DataPool::instance_ = NULL;

DataPool* DataPool::newInstance(){
    if (NULL == instance_){
        static DataPool instanceT;
        instance_ = &instanceT;
    }
    return instance_;
};

DataPool::~DataPool(){
    //remove all the instance in the map.
}

void DataPool::store(string name, unsigned char* value, int length){
    QString temp = QString::fromLocal8Bit((char*)value, length);
//    log(QString::fromStdString("[DataPool]store double value ").append(QString::fromLocal8Bit((char*)temp)));
    this->store(&dataMap, name, CAN, DOUBLE, temp);
}

void DataPool::store(string name, double value){
    QString temp = QString::number(value);
//    log(QString::fromStdString("[DataPool]store double value ").append(QString::fromLocal8Bit((char*)temp)));
    this->store(&dataMap, name, CAN, DOUBLE, temp);
}

void DataPool::store(int moduleId, string name, double value){
    map<string, Data*>* currentMap;
    try{
        currentMap = subDataMap.at(moduleId);
    }catch(std::out_of_range &e){
        map<string, Data*>* tempMap = new map<string, Data*>();
        subDataMap.insert(std::pair<int, map<string, Data*>*>(moduleId, tempMap));
        currentMap = tempMap;
    }
    QString temp = QString::number(value);
//    log(QString::fromStdString("[DataPool]store double value ").append(QString::fromLocal8Bit((char*)temp)));
    this->store(currentMap, name, CAN, DOUBLE, temp);
}

void DataPool::store(map<string, Data*>* localMap, string name, Channel channel, DataType type, QString value){
    if (localMap->find(name) != localMap->end()){
        Data* dataT = localMap->at(name);
        dataT->update(name, channel, type, value);
    }else{
//        log(QString("create new Data in the data pool for ").append(QString::fromStdString(name)));
        Data* data = new Data(name, channel, type, value);
        localMap->insert(std::pair<string, Data*>(name, data));
    }
}

double DataPool::getDouble(string name){
    try{
        return dataMap.at(name)->getValue().toDouble();
    }catch(std::out_of_range &e){
        return 0;
    }
}

double DataPool::getDouble(int index, string name){
    int i = 1;
    int key = -1;
    map<int, map<string, Data*>* >::iterator iter;
    for(iter = subDataMap.begin(); iter != subDataMap.end(); ++iter)
    {
        if (i == index){
            key = iter->first;
            break;
        }
        i++;
    }
    if(key == -1){
        return 0;
    }

    try{
        return subDataMap[key]->at(name)->getValue().toDouble();
    }catch(std::out_of_range &e){// no such data
        return 0;
    }
}

int DataPool::getInt(string name){
    try{
        return dataMap.at(name)->getValue().toInt();
    }catch(std::out_of_range &e){
        return 0;
    }
}

Data* DataPool::retrieve(string name){
    return this->dataMap.at(name);
}    void store(string name, Data *data);
