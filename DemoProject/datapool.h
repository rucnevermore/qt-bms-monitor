#ifndef DATAPOOL_H
#define DATAPOOL_H

#include <map>
#include "data.h"
#include <string>
#include <stdio.h>
#include "ui_widget.h"
#include <stdexcept>

class DataPool : public QObject
{
    Q_OBJECT
public:   
    static DataPool* newInstance();
    void store(string name, double value);
    void store(int moduleId, string name, double value);
    void store(string name, unsigned char* value, int length);
    void store(map<string, Data*>* localMap, string name, Channel channel, DataType type, QString value);

    Data* retrieve(string name);
    double getDouble(string name);
    double getDouble(int index, string name);
    int getInt(string name);
    unsigned char* getUnsignedCharArray(string name);
signals:
    void log(QString str);
private:
    DataPool(){};
    ~DataPool();
    map<string, Data*> dataMap;
    map<int, map<string, Data*>* > subDataMap;
    static DataPool* instance_;
};

#endif // DATAPOOL_H
