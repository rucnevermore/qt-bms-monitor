#ifndef DATAPOOL_H
#define DATAPOOL_H

#include <QMap>
#include "data.h"
#include <string>
#include <stdio.h>
#include "ui_widget.h"
#include <stdexcept>
#include "basedatapool.h"
#include "clusterdatapool.h"
#include "alertevent.h"
#include <QList>

class DataPool : public BaseDataPool
{
public:
    static DataPool* newInstance();
    void storeById(int clusterId, string name, double value);
    void storeById(int clusterId, int moduleId, string name, double value);
    void storeByIndex(int clusterIndex, string name, double value);

    double getDoubleByIndex(int clusterIndex, string name);
    double getDoubleByIndex(int clusterIndex, int moduleIndex, string name);
    double getDoubleById(int clusterId, int moduleId, string name);
    void addEvent(QString message);
    void addEvent(QDateTime date, QString message);
    QString statistic();
    void registerListener(EventListener* listener);
    void notifyListener(string name, QString value);


    QList<EventListener*>* listeners;
    // Cluster id, Module id, datamap
    QMap<int, ClusterDataPool*>* clusterDataMap;
    QList<AlertEvent*>* events;
private:
    DataPool();
    ~DataPool();
    void serializeEvents();
    static DataPool* instance_;
};

#endif // DATAPOOL_H
