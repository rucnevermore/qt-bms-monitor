#ifndef MODBUSTCPSERVERTHREAD_H
#define MODBUSTCPSERVERTHREAD_H

#include <QThread>
#include "modbus-tcp.h"
#include "modbus.h"
#include "modbusutil.h"
#include "datapool.h"

class ModbusTCPServerThread : public QThread
{
    Q_OBJECT
public:
    explicit ModbusTCPServerThread(QObject *parent = 0);

signals:
    void log(QString str);

public slots:
    void run();
    void stop();

private:
    void arm(modbus_mapping_t *mb_mapping);
    bool running;
    DataPool* datapool;
    ModbusUtil* modbus;
};

#endif // MODBUSTCPSERVERTHREAD_H
