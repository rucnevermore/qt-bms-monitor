#ifndef MODBUSUTIL_H
#define MODBUSUTIL_H

#include "modbus.h"
#include <stdio.h>

class ModbusUtil
{
public:
    static ModbusUtil* newInstance();
    int createConnection();
    int write(int addr, int nb, const uint16_t *data);
    int read(int addr, int nb, uint16_t *dest);
    void close();
    bool isConnected();
    char* getDevice();
private:
    ModbusUtil();
    static ModbusUtil* instance_;
    modbus_t *ctx;
    char* device;
};

#endif // MODBUSUTIL_H
