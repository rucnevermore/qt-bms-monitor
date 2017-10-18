#ifndef DATA_H
#define DATA_H

#include <string>
#include <qstring.h>

#define CAN 0
#define OTHER 9

#define INTEGER 0
#define LONG 1
#define DOUBLE 2
#define BOOLEAN 3
#define STRING 4

using namespace std;

class Data
{
public:
    Data(string name, int channel, int type, double value);
    string getName();
    double getValue();
    void replaceby(Data* data);
    bool update(string name, int channel, int type, double value);
    ~Data();
private:
    string name;
    int channel;
    int type;
    double value;
};

#endif // DATA_H
