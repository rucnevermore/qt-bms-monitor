#include "basedatapool.h"
#include <stdexcept>

BaseDataPool::BaseDataPool(int size)
{
    dataMap = new double[size]();
}

bool BaseDataPool::store(int name, double value){
    dataMap[name]=value;
    return true;
}

//bool BaseDataPool::store(double* localMap, int name, double value){
//    dataMap[name]=value;
//    return true;
//}

bool BaseDataPool::store(int name, unsigned char* value, int length){
    QString temp = QString::fromLocal8Bit((char*)value, length);
    dataMap[name]=temp.toDouble();
    return true;
}

int BaseDataPool::getInt(int name){
    return dataMap[name];
}

double BaseDataPool::getDouble(int name){
    return dataMap[name];
}
