#ifndef DATAPOOL_H
#define DATAPOOL_H

#include <string>
#include <stdio.h>
#include "ui_widget.h"
#include <stdexcept>
#include "eventlistener.h"
#include "clusterdatapool.h"
#include "alertevent.h"
#include <QList>

class DataPool
{
public:
    static DataPool* newInstance();
    void storeById(int clusterId, int name, double value);
    void storeById(int clusterId, int moduleId, int name, double value);
    void storeByIndex(int clusterIndex, int name, double value);

    bool store(int name, double value);
    bool store(int name, unsigned char* value, int length);
    double getDouble(int name);
    int getInt(int name);

    double getDoubleByIndex(int clusterIndex, int name);
    double getDoubleByIndex(int clusterIndex, int moduleIndex, int name);
    double getDoubleById(int clusterId, int moduleId, int name);
    void addEvent(QString message);
    void addEvent(QDateTime date, QString message);
    QString statistic();
    void registerListener(EventListener* listener);
    void notifyListener(int name, double value);
    int getEventTotal();

    QList<EventListener*>* listeners;
    ClusterDataPool* clusterDataMap;
    double* dataMap;
    QList<AlertEvent*>* events;
private:
    DataPool();
    ~DataPool();
    void serializeEvents();
    static DataPool* instance_;
};

#endif // DATAPOOL_H
