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
    this->store(name, CAN, DOUBLE, temp);
}

void DataPool::store(string name, double value){
    QString temp = QString::number(value);
//    log(QString::fromStdString("[DataPool]store double value ").append(QString::fromLocal8Bit((char*)temp)));
    this->store(name, CAN, DOUBLE, temp);
}

void DataPool::store(string name, Channel channel, DataType type, QString value){
    if (dataMap.find(name) != dataMap.end()){
        Data* dataT = dataMap.at(name);
        dataT->update(name, channel, type, value);
    }else{
//        log(QString("create new Data in the data pool for ").append(QString::fromStdString(name)));
        Data* data = new Data(name, channel, type, value);
        this->dataMap.insert(std::pair<string, Data*>(name, data));
    }
}

unsigned char* DataPool::getUnsignedCharArray(string name){
    try{
        return (unsigned char*)(((Data*)dataMap.at(name))->getValue().toLocal8Bit().data());
    }catch(std::out_of_range &e){
        return NULL;
    }
}

double DataPool::getDouble(string name){
    try{
        return dataMap.at(name)->getValue().toDouble();
    }catch(std::out_of_range &e){
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
