#include "modbustcpserverthread.h"

ModbusTCPServerThread::ModbusTCPServerThread(QObject *parent) :
        QThread(parent)
{
    running = true;
    datapool = DataPool::newInstance();
    modbus = ModbusUtil::newInstance();
}

void ModbusTCPServerThread::run()
{
    modbus->createTCPServer();
    uint8_t *query = new uint8_t[MODBUS_TCP_MAX_ADU_LENGTH];
    modbus_mapping_t *mb_mapping = modbus_mapping_new(0,0,32000,0);
    if (mb_mapping == NULL){
        log(QString("failed to create modbus mapping"));
        modbus->close();
        return;
    }
    modbus_t *ctx = modbus->ctx;
    int s = modbus_tcp_listen(ctx, 1);
    modbus_tcp_accept(ctx, &s);
    int rc = 0;
    while(running)
    {
        do {
            rc = modbus_receive(ctx, query);
            /* Filtered queries return 0 */
        } while (rc == 0);
        if (rc == -1) {
            continue;
        }
        this->arm(mb_mapping);
        rc = modbus_reply(ctx, query, rc, mb_mapping);
    }
}

// fill the mb_mappin with data
void ModbusTCPServerThread::arm(modbus_mapping_t *mb_mapping)
{
    uint16_t * registers = mb_mapping->tab_registers;
    // 电池簇数据 0~999
    int cluster_num = 20;
    for (int i = 0; i < cluster_num; i++){
        //簇总电压
        registers[0 + i * 20] = datapool->getDoubleByIndex(i, zdy)* 50;
        //簇总电流
        //SOC
        //软件版本号
        //簇运行状态
        //簇故障
        //单体最高电压
        //最高单体电压PACK/Cell号码
        //单体最低电压
        //最低单体电压PACK/Cell号码
        //单体最高温度
        //最高温度采集点号码
        //单体最低温度
        //最低温度采集点号码
        //SOH
        //绝缘阻值
        //簇上电成功
        //簇下电成功
        //保留
        //保留
    }

// 单体电压数据 1000~5799

// 单体电池温度数据 20000~21599

// 故障/告警数据 30000~31199
}

void ModbusTCPServerThread::stop()
{
    running = false;
}
