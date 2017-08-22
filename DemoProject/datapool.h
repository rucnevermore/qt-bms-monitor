#ifndef DATAPOOL_H
#define DATAPOOL_H

#include <map>
#include <data.h>
#include <string>
#include <stdio.h>
#include "ui_widget.h"
#include <stdexcept>

class DataPool
{
public:   
    static DataPool* newInstance();
    void store(string name, double value);
    void store(string name, Channel channel, DataType type, unsigned char* value);
    Data* retrieve(string name);
    double getDouble(string name);
private:
    DataPool(){};
    ~DataPool();
    map<string, Data*> dataMap;
    static DataPool* instance_;
};

#endif // DATAPOOL_H
