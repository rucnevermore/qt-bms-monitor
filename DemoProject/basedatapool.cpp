#include "basedatapool.h"
#include <stdexcept>

BaseDataPool::BaseDataPool()
{
}


void BaseDataPool::store(string name, double value){
    QString temp = QString::number(value);
//    log(QString::fromStdString("[DataPool]store double value ").append(QString::fromLocal8Bit((char*)temp)));
    this->store(&dataMap, name, CAN, DOUBLE, temp);
}

void BaseDataPool::store(map<string, Data*>* localMap, string name, Channel channel, DataType type, QString value){
    if (localMap->find(name) != localMap->end()){
        Data* dataT = localMap->at(name);
        dataT->update(name, channel, type, value);
    }else{
//        log(QString("create new Data in the data pool for ").append(QString::fromStdString(name)));
        Data* data = new Data(name, channel, type, value);
        localMap->insert(std::pair<string, Data*>(name, data));
    }
}

void BaseDataPool::store(string name, unsigned char* value, int length){
    QString temp = QString::fromLocal8Bit((char*)value, length);
//    log(QString::fromStdString("[DataPool]store double value ").append(QString::fromLocal8Bit((char*)temp)));
    this->store(&dataMap, name, CAN, DOUBLE, temp);
}

int BaseDataPool::getInt(string name){
    try{
        return dataMap.at(name)->getValue().toInt();
    }catch(std::out_of_range &e){
        return 0;
    }
}

double BaseDataPool::getDouble(string name){
    try{
        return dataMap.at(name)->getValue().toDouble();
    }catch(std::out_of_range &e){
        return 0;
    }
}

Data* BaseDataPool::retrieve(string name){
    return this->dataMap.at(name);
}
