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
    int res = modbus->createTCPServer();
    if (res == -1){
        log(QString("create tcp server failed!"));
        return;
    }
    uint8_t *query = new uint8_t[MODBUS_TCP_MAX_ADU_LENGTH];
    log(QString("create modbus mapping"));
    modbus_mapping_t *mb_mapping = modbus_mapping_new(0,0,32000,0);
    if (mb_mapping == NULL){
        log(QString("failed to create modbus mapping"));
        modbus->close();
        return;
    }
    modbus_t *ctx = modbus->ctx;
    modbus_set_debug(ctx, TRUE);
    log(QString("start to listen..."));
    int s = modbus_tcp_listen(ctx, 1);
    while(running)
    {
        log(QString("accept connection..."));
        modbus_tcp_accept(ctx, &s);
        int rc = 0;
        do {
            log(QString("request receiving..."));
            rc = modbus_receive(ctx, query);
            log(QString("modbus tcp request received."));
            if (rc == -1) {
                log(QString("timeout, connection close."));
                modbus_close(ctx);
                break;
            }
            log(QString("arm mb_mapping."));
            this->arm(mb_mapping);
            log(QString("modbus tcp response reply."));
            rc = modbus_reply(ctx, query, rc, mb_mapping);
            log(QString("modbus tcp response reply finished."));
        } while (true);

    }
}

// fill the mb_mappin with data
void ModbusTCPServerThread::arm(modbus_mapping_t *mb_mapping)
{
    uint16_t * registers = mb_mapping->tab_registers;
    // 电池簇数据 0~999
    int cluster_num = 20;
    for (int i = 0; i < cluster_num; i++){
        int cluster_index = i + 1;
        //簇总电压
        registers[0 + i * 20] = datapool->getDoubleByIndex(cluster_index, zdy) * 50;
        //簇总电流
        registers[1 + i * 20] = datapool->getDoubleByIndex(cluster_index, zdl) * 10 + 3200;
        //SOC
        registers[2 + i * 20] = datapool->getDoubleByIndex(cluster_index, soc) * 2.5;
        //软件版本号
        registers[3 + i * 20] = datapool->getDoubleByIndex(cluster_index, ver) * 100;
        //簇运行状态
        registers[4 + i * 20] = datapool->getDoubleByIndex(cluster_index, xtyxzt) + 1;
        //簇故障
        registers[5 + i * 20] = datapool->getDoubleByIndex(cluster_index, xtgz);
        //单体最高电压
        registers[6 + i * 20] = datapool->getDoubleByIndex(cluster_index, dtzgdy) * 50;
        //最高单体电压PACK/Cell号码
        registers[7 + i * 20] = ((int(datapool->getDoubleByIndex(cluster_index, zgdywz)) & 0xFF) << 8)
                                & (int(datapool->getDoubleByIndex(cluster_index, zgdyxh)) & 0xFF);
        //单体最低电压
        registers[8 + i * 20] = datapool->getDoubleByIndex(cluster_index, dtzddy) * 50;
        //最低单体电压PACK/Cell号码
        registers[9 + i * 20] = ((int(datapool->getDoubleByIndex(cluster_index, zddywz)) & 0xFF) << 8)
                                & (int(datapool->getDoubleByIndex(cluster_index, zddyxh)) & 0xFF);
        //单体最高温度
        registers[10 + i * 20] = datapool->getDoubleByIndex(cluster_index, dtzgwd) + 40;
        //最高温度采集点号码
        registers[11 + i * 20] = ((int(datapool->getDoubleByIndex(cluster_index, zgwdwz)) & 0xFF) << 8)
                                 & (int(datapool->getDoubleByIndex(cluster_index, zgwdxh)) & 0xFF);
        //单体最低温度
        registers[12 + i * 20] = datapool->getDoubleByIndex(cluster_index, dtzdwd) + 40;
        //最低温度采集点号码
        registers[13 + i * 20] = ((int(datapool->getDoubleByIndex(cluster_index, zdwdwz)) & 0xFF) << 8)
                                 & (int(datapool->getDoubleByIndex(cluster_index, zdwdxh)) & 0xFF);
        //SOH
        registers[14 + i * 20] = datapool->getDoubleByIndex(cluster_index, soh) * 2.5;
        //绝缘阻值
        registers[15 + i * 20] = datapool->getDoubleByIndex(cluster_index, jyzz) * 5;
        //簇上电成功
        registers[16 + i * 20] = datapool->getDoubleByIndex(cluster_index, dccdzt);
        //簇下电成功
        registers[17 + i * 20] = 1 - datapool->getDoubleByIndex(cluster_index, dccdzt);
        //保留
        registers[18 + i * 20] = 0xFFFF;
        //保留
        registers[19 + i * 20] = 0xFFFF;

        int module_num = 10;
        for (int j = 0; j < module_num; j++){
            // 单体电压数据 1000~5799
            registers[1000 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_1) * 1000;
            registers[1001 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_2) * 1000;
            registers[1002 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_3) * 1000;
            registers[1003 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_4) * 1000;
            registers[1004 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_5) * 1000;
            registers[1005 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_6) * 1000;
            registers[1006 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_7) * 1000;
            registers[1007 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_8) * 1000;
            registers[1008 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_9) * 1000;
            registers[1009 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_10) * 1000;
            registers[1010 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_11) * 1000;
            registers[1011 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_12) * 1000;
            registers[1012 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_13) * 1000;
            registers[1013 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_14) * 1000;
            registers[1014 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_15) * 1000;
            registers[1015 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_16) * 1000;
            registers[1016 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_17) * 1000;
            registers[1017 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_18) * 1000;
            registers[1018 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_19) * 1000;
            registers[1019 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_20) * 1000;
            registers[1020 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_21) * 1000;
            registers[1021 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_22) * 1000;
            registers[1022 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_23) * 1000;
            registers[1023 + i * 240 + j * 24] = datapool->getDoubleByIndex(cluster_index, j, dcdy_24) * 1000;
            // 单体电池温度数据 20000~21599
            registers[20000 + i * 80 + j * 8] = datapool->getDoubleByIndex(cluster_index, j, cywd_1) + 40;
            registers[20001 + i * 80 + j * 8] = datapool->getDoubleByIndex(cluster_index, j, cywd_2) + 40;
            registers[20002 + i * 80 + j * 8] = datapool->getDoubleByIndex(cluster_index, j, cywd_3) + 40;
            registers[20003 + i * 80 + j * 8] = datapool->getDoubleByIndex(cluster_index, j, cywd_4) + 40;
            registers[20004 + i * 80 + j * 8] = datapool->getDoubleByIndex(cluster_index, j, cywd_5) + 40;
            registers[20005 + i * 80 + j * 8] = datapool->getDoubleByIndex(cluster_index, j, cywd_6) + 40;
            registers[20006 + i * 80 + j * 8] = datapool->getDoubleByIndex(cluster_index, j, cywd_7) + 40;
            registers[20007 + i * 80 + j * 8] = datapool->getDoubleByIndex(cluster_index, j, cywd_8) + 40;
        }
    }
    // 目前只放第一簇的告警信息
    // 故障/告警数据 30000~31199
    for (int k = 0; k < 25; k++){
        registers[30000 + k * 6] = k + 1;
        registers[30001 + k * 6] = datapool->getDoubleByIndex(1, 13 + k);
        registers[30002 + k * 6] = 1;
        registers[30003 + k * 6] = 0xFFFF;
        registers[30004 + k * 6] = 0xFFFF;
        registers[30005 + k * 6] = 0xFFFF;
    }
}

void ModbusTCPServerThread::stop()
{
    running = false;
}
