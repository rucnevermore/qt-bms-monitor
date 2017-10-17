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
    listeners = new QList<EventListener*>();
    clusterDataMap = new QMap<int, ClusterDataPool*>();
    events = new QList<AlertEvent*>();
}

DataPool::~DataPool(){
    events->clear();
    listeners->clear();
    clusterDataMap->clear();
}

void DataPool::registerListener(EventListener* listener){
    if (!listeners->contains(listener)){
        listeners->append(listener);
    }
}

void DataPool::notifyListener(string name, QString value){
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

void DataPool::storeById(int clusterId, string name, double value){
    ClusterDataPool* currentClusterDataPool = NULL;
    if (clusterDataMap->contains(clusterId)){
        currentClusterDataPool = clusterDataMap->value(clusterId);
    }else{
        currentClusterDataPool = new ClusterDataPool();
        this->clusterDataMap->insert(clusterId, currentClusterDataPool);
    }
    if (currentClusterDataPool->store(name, value)){
        this->notifyListener(name, QString::number(value));
    }
}

void DataPool::storeById(int clusterId, int moduleId, string name, double value){
    ClusterDataPool* currentClusterDataPool = NULL;
    if (clusterDataMap->contains(clusterId)){
        currentClusterDataPool = clusterDataMap->value(clusterId);
    }else{
        currentClusterDataPool = new ClusterDataPool();
        this->clusterDataMap->insert(clusterId, currentClusterDataPool);
    }
    if (currentClusterDataPool->storeById(moduleId, name, value)){
        this->notifyListener(name, QString::number(value));
    }
}

void DataPool::storeByIndex(int clusterIndex, string name, double value){
    int i = 1;
    int key = -1;
    QMap<int, ClusterDataPool* >::iterator iter;
    for(iter = clusterDataMap->begin(); iter != clusterDataMap->end(); ++iter)
    {
        if (i == clusterIndex){
            key = iter.key();
            break;
        }
        i++;
    }
    if(key == -1){
        return;
    }
    try{
        clusterDataMap->value(key)->store(name, value);
    }catch(std::out_of_range &e){// no such data
        return;
    }
}

double DataPool::getDoubleByIndex(int clusterIndex, string name){
    int i = 1;
    int key = -1;
    QMap<int, ClusterDataPool* >::iterator iter;
    for(iter = clusterDataMap->begin(); iter != clusterDataMap->end(); ++iter)
    {
        if (i == clusterIndex){
            key = iter.key();
            break;
        }
        i++;
    }
    if(key == -1){
        return 0;
    }
    // special treatment for macro.
    if (name == "_MODULE_NUMBER_"){
        return clusterDataMap->value(key)->moduleDataMap.size();
    }
    try{
        return clusterDataMap->value(key)->getDouble(name);
    }catch(std::out_of_range &e){// no such data
        return 0;
    }
}

double DataPool::getDoubleByIndex(int clusterIndex, int moduleIndex, string name){
    int i = 1;
    int key = -1;
    QMap<int, ClusterDataPool* >::iterator iter;
    for(iter = clusterDataMap->begin(); iter != clusterDataMap->end(); ++iter)
    {
        if (i == clusterIndex){
            key = iter.key();
            break;
        }
        i++;
    }
    if(key == -1){
        return 0;
    }
    return clusterDataMap->value(key)->getDoubleByIndex(moduleIndex, name);
}

double DataPool::getDoubleById(int clusterId, int moduleId, string name){
    if (clusterDataMap->contains(clusterId)){
        return clusterDataMap->value(clusterId)->getDoubleById(moduleId, name);
    }else{// no such data
        return 0;
    }
}

QString DataPool::statistic(){
    int dataNumber = this->dataMap.size();
    int clusterNumber = clusterDataMap->size();
    QMap<int, ClusterDataPool* >::iterator iter;
    for(iter = clusterDataMap->begin(); iter != clusterDataMap->end(); ++iter)
    {
        ClusterDataPool* clusterDataPool = iter.value();
        dataNumber = dataNumber + clusterDataPool->getDataNumber();
    }
    return QString("cluster number : ").append(QString::number(clusterNumber)).append(QString(". data number : ")).append(QString::number(dataNumber));
}


