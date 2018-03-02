#include "datapool.h"
#include "configure.h"
#include <QFile>

DataPool* DataPool::instance_ = NULL;

DataPool* DataPool::newInstance(){
    if (NULL == instance_){
        instance_ = new DataPool();
    }
    return instance_;
}

DataPool::DataPool(){
    Configure* configure = Configure::newInstance();
    listeners = new QList<EventListener*>();
    clusterDataMap = new ClusterDataPool[configure->CLUSTER_NUM+1];
    dataMap = new double[configure->GLOBAL_DATA_NUM+1]();
    events = new QList<AlertEvent*>();
}

DataPool::~DataPool(){
    events->clear();
    listeners->clear();
    delete []clusterDataMap;
    delete []dataMap;
}

void DataPool::registerListener(EventListener* listener){
    if (!listeners->contains(listener)){
        listeners->append(listener);
    }
}

void DataPool::notifyListener(int name, double value){
    EventListener* listener = NULL;
    for(int i = 0; i < listeners->length(); i++){
        listener = listeners->at(i);
        listener->notify(name, value);
    }
}

void DataPool::addEvent(QString message){
    addEvent(QDateTime::currentDateTime(), message);
}

// add an event into datapool, if event number exceed maximum number, the oldest event will be remove.
void DataPool::addEvent(QDateTime date, QString message){
    Configure* configure = Configure::newInstance();
    int maxEventNum = configure->getMaxEventNum();
    if (events->size() > 0 && events->size() >= maxEventNum){
        AlertEvent* event = events->takeFirst();
        delete event;
        event = NULL;
    }
    events->append(new AlertEvent(date, message));
    // serialize the event list into file system.
    serializeEvents();
}

void DataPool::serializeEvents(){
    QFile f("./serialization.txt");
    f.open(QIODevice::ReadWrite);
    QDataStream ds(&f);
    for (int i=0; i!=events->size(); ++i )
    {
       ds << events->at(i)->date;
       ds << events->at(i)->message;
    }
    f.close();
}

void DataPool::storeById(int clusterId, int name, double value){
    clusterDataMap[clusterId].store(name, value);
}

void DataPool::storeById(int clusterId, int moduleId, int name, double value){
    clusterDataMap[clusterId].storeById(moduleId, name, value);
}

void DataPool::storeByIndex(int clusterIndex, int name, double value){
    this->storeById(clusterIndex, name, value);
}

double DataPool::getDoubleByIndex(int clusterIndex, int name){
    return clusterDataMap[clusterIndex].getDouble(name);
}

double DataPool::getDoubleByIndex(int clusterIndex, int moduleIndex, int name){
    return clusterDataMap[clusterIndex].getDoubleById(moduleIndex, name);
}

double DataPool::getDoubleById(int clusterId, int moduleId, int name){
    return clusterDataMap[clusterId].getDoubleById(moduleId, name);
}

bool DataPool::store(int name, double value){
    dataMap[name]=value;
    return true;
}

bool DataPool::store(int name, unsigned char* value, int length){
    QString temp = QString::fromLocal8Bit((char*)value, length);
    dataMap[name]=temp.toDouble();
    return true;
}

//short DataPool::getShort(int name){
//    return dataMap[name];
//}

int DataPool::getInt(int name){
    return dataMap[name];
}

double DataPool::getDouble(int name){
    return dataMap[name];
}

int DataPool::getEventTotal(){
    return events->size();
}

