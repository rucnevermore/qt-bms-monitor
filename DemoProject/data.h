#ifndef DATA_H
#define DATA_H

#include <string>

enum Channel{
    CAN = 0,
    OTHER = 9
};

enum DataType{
    INTEGER = 0,
    LONG = 1,
    DOUBLE = 2,
    BOOLEAN = 3,
    STRING = 4
};

//class DataValue{
//public:
//    DataValue(unsigned char* value){
//        this->value = value;
//    };
//    unsigned char* value;
//};

using namespace std;

class Data
{
public:
    Data(string name, Channel channel, DataType type, unsigned char* value);
    unsigned char* getValue();
    void replaceby(Data* data);
    void update(string name, Channel channel, DataType type, unsigned char* value);
private:
    string name;
    Channel channel;
    DataType type;
    unsigned char* value;
};

#endif // DATA_H
