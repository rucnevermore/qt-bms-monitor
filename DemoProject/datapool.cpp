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

void DataPool::store(string name, double value){
    unsigned char temp[8]={0};
    memcpy(temp, &value, 8);
    this->store(name, CAN, DOUBLE, temp);
}

void DataPool::store(string name, Channel channel, DataType type, unsigned char* value){
//    this->store(name, new Data(name, channel, type, new DataValue(value)));
    if (dataMap.find(name) != dataMap.end()){
        Data* dataT = dataMap.at(name);
        dataT->update(name, channel, type, value);
    }else{
        Data* data = new Data(name, channel, type, value);
        this->dataMap.insert(std::pair<string, Data*>(name, data));
    }
}

double DataPool::getDouble(string name){
    try{      
        return atof((char*)((Data*)this->dataMap.at(name))->getValue());
    }catch(std::out_of_range &e){
        return 0;
    }
}

Data* DataPool::retrieve(string name){
    return this->dataMap.at(name);
}    void store(string name, Data *data);
