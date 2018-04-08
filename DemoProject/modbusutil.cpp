#include "modbusutil.h"

ModbusUtil* ModbusUtil::instance_ = NULL;

bool flag = false;

ModbusUtil* ModbusUtil::newInstance(){
    if (NULL == instance_){
        instance_ = new ModbusUtil();
    }
    return instance_;
}

ModbusUtil::ModbusUtil()
{
    configure = Configure::newInstance();
    QString dev = configure->getModbusDev();
    QByteArray ba = dev.toUtf8();
    device = strdup(ba.data());
}

char* ModbusUtil::getDevice(){
    return device;
}

int ModbusUtil::createTCPServer()
{
    ctx = modbus_new_tcp(configure->getModbusAddress().toLocal8Bit().data(), configure->getModbusPort());
    if (ctx == NULL) {
        return -1;
    }
    flag = true;
    return 0;
}

int ModbusUtil::createRTUConnection()
{
    ctx = modbus_new_rtu(device, 9600, 'N', 8, 1);
    if (ctx == NULL) {
        return -1;
    }
    modbus_rtu_set_serial_mode(ctx, MODBUS_RTU_RS485);
    modbus_set_slave(ctx, 9);
    if (modbus_connect(ctx) == -1){
        modbus_free(ctx);
        return -1;
    }
    flag = true;
    return 0;
}

int ModbusUtil::write(int addr, int nb, const uint16_t *data)
{
    return modbus_write_registers(ctx, addr, nb, data);
}

int ModbusUtil::read(int addr, int nb, uint16_t *dest)
{
    return modbus_read_registers(ctx, addr, nb, dest);
}

bool ModbusUtil::isConnected()
{
    return flag;
}

void ModbusUtil::close()
{
    flag = false;
    modbus_close(ctx);
    modbus_free(ctx);
}


