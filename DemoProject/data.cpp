#include "data.h"
#include <qstring.h>
/*
 * store raw data from collection
 */
Data::Data(string name, int channel, int type, double value)
{
    this->name = name;
    this->channel = channel;
    this->type = type;
    this->value = value;
}

Data::~Data(){
    delete &value;
}

string Data::getName(){
    return name;
}

double Data::getValue(){
    return value;
}

void Data::replaceby(Data* data){
    if (data != NULL){
        this->name = data->name;
        this->channel = data->channel;
        this->type = data->type;
        this->value = data->value;
    }
}

bool Data::update(string name, int channel, int type, double value){
    this->name = name;
    this->channel = channel;
    this->type = type;

    bool flag = false;
    if (this->value != value){
        flag = true;
    }
    this->value = value;
    return flag;
}
