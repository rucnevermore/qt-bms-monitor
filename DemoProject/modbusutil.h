#ifndef MODBUSUTIL_H
#define MODBUSUTIL_H

#include "modbus.h"
#include <stdio.h>
#include "configure.h"

class ModbusUtil
{
public:
    static ModbusUtil* newInstance();
    int createRTUConnection();
    int createTCPServer();
    int write(int addr, int nb, const uint16_t *data);
    int read(int addr, int nb, uint16_t *dest);
    void close();
    bool isConnected();
    char* getDevice();

    modbus_t *ctx;
private:
    ModbusUtil();
    static ModbusUtil* instance_;  
    Configure* configure;
    char* device;
};

#endif // MODBUSUTIL_H
