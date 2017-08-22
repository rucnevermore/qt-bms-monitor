#include "data.h"
#include <qstring.h>
/*
 * store raw data from collection
 */
Data::Data(string name, Channel channel, DataType type, unsigned char* value)
{
    this->name = name;
    this->channel = channel;
    this->type = type;
    this->value = value;
}

unsigned char* Data::getValue(){
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

void Data::update(string name, Channel channel, DataType type, unsigned char* value){
    this->name = name;
    this->channel = channel;
    this->type = type;
    this->value = value;
}
