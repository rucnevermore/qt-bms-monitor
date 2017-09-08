#include "basedatapool.h"
#include <stdexcept>

BaseDataPool::BaseDataPool()
{
}


void BaseDataPool::store(string name, double value){
    QString temp = QString::number(value);
    this->store(&dataMap, name, CAN, DOUBLE, temp);
}

void BaseDataPool::registerListener(EventListener listener){

}

void BaseDataPool::notifyListener(){

}

void BaseDataPool::store(QMap<string, Data*>* localMap, string name, Channel channel, DataType type, QString value){
    if (localMap->find(name) != localMap->end()){
        Data* dataT = localMap->value(name);
        if (dataT->update(name, channel, type, value)){
            this->notifyListener();
        }
    }else{
        Data* data = new Data(name, channel, type, value);
        localMap->insert(name, data);
        this->notifyListener();
    }
}

void BaseDataPool::store(string name, unsigned char* value, int length){
    QString temp = QString::fromLocal8Bit((char*)value, length);
    this->store(&dataMap, name, CAN, DOUBLE, temp);
}

int BaseDataPool::getInt(string name){
    if (dataMap.contains(name)){
        return dataMap.value(name)->getValue().toInt();
    }else{
        return 0;
    }
}

double BaseDataPool::getDouble(string name){
    if (dataMap.contains(name)){
        return dataMap.value(name)->getValue().toDouble();
    }else{
        return 0;
    }
}

Data* BaseDataPool::retrieve(string name){
    return this->dataMap.value(name);
}
