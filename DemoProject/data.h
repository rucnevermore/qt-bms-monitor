#ifndef DATA_H
#define DATA_H

#include <string>
#include <qstring.h>

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

using namespace std;

class Data
{
public:
    Data(string name, Channel channel, DataType type, QString value);
    string getName();
    QString getValue();
    void replaceby(Data* data);
    bool update(string name, Channel channel, DataType type, QString value);
    ~Data();
private:
    string name;
    Channel channel;
    DataType type;
    QString value;
};

#endif // DATA_H
