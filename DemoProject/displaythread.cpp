#include "displaythread.h"
#include "cancache.h"
#include "modbusutil.h"

DataPool* datapool = DataPool::newInstance();
ModbusUtil* modbus = ModbusUtil::newInstance();

DisplayThread::DisplayThread(QObject *parent) :
    QThread(parent)
{
    running = true;
    configure = Configure::newInstance();
}

void DisplayThread::run()
{
    while(running)
    {
        display();
        if (configure->getModbusType() == QString("RTU")){
            sendModbusData();
        }
        this->sleep(1);
    }

}

void DisplayThread::sendModbusData()
{
    log(QString("create connection"));
    modbus->createRTUConnection();
    int dataNum = 21;
    uint16_t* data = new uint16_t[dataNum];
    // 1000 动力电池的总电压
    data[0] = datapool->getDouble(g_xtdy) * 10;
    // 1001 动力电池的总电流
    data[1] = datapool->getDouble(g_xtdl) * 10;
    // 1002 绝缘阻值
    data[2] = 0xFFFF;
    // 1003 SOC
    data[3] = datapool->getDouble(g_xtsoc) * 10;
    // 1004 SOH
    data[4] = 0xFFFF;
    // 1005 系统可充电量（低两字节）
    data[5] = 0xFFFF;
    // 1006 系统可充电量（高两字节）
    data[6] = 0xFFFF;
    // 1007 系统可放电量（低两字节）
    data[7] = 0xFFFF;
    // 1008 系统可放电量（高两字节）
    data[8] = 0xFFFF;
    // 1009 单体最大电压
    data[9] = datapool->getDouble(g_zgdy) * 50;
    // 100A 单体最大电压单体编号
    data[10] = datapool->getDouble(g_zgdy_mkh);
    // 100B 单体最小电压
    data[11] = datapool->getDouble(g_zddy) * 50;
    // 100C 单体最小电压单体编号
    data[12] = datapool->getDouble(g_zddy_mkh);
    // 100D 单体最高温度
    data[13] = datapool->getDouble(g_zgwd);
    // 100E 单体最高温度单体编号
    data[14] = datapool->getDouble(g_zgwd_mkh);
    // 100F 单体最低温度
    data[15] = datapool->getDouble(g_zdwd);
    // 1010 单体最低温度单体编号
    data[16] = datapool->getDouble(g_zdwd_mkh);
    // 1011 报警信息1

//    系统压差报警
//    系统温差报警
//    系统过温报警
//    系统低温报警
//    单体过压报警
//    单体欠压报警
//    系统过压报警
//    系统欠压报警
    data[17] = getDoubleBytes(xtyc_bj, 14) +
               getDoubleBytes(xtwc_bj, 12) +
               getDoubleBytes(xtgw_bj, 10) +
               getDoubleBytes(xtdw_bj, 8) +
               getDoubleBytes(dtgy_bj, 6) +
               getDoubleBytes(dtqy_bj, 4) +
               getDoubleBytes(xtgy_bj, 2) +
               getDoubleBytes(xtqy_bj, 0);
    // 1012 报警信息2
    data[18] = getDoubleBytes(fdgl_bj, 14) +
               getDoubleBytes(cdgl_bj, 12) +
               getDoubleBytes(socg_bj, 10) +
               getDoubleBytes(socd_bj, 8);
    // 1013 报警信息3
    data[19] = getDoubleBytes(yc_gz, 15) +
               getDoubleBytes(dycgq_gz, 14) +
               getDoubleBytes(wdcgq_gz, 13) +
               getDoubleBytes(xtjy_bj, 11) +
               getDoubleBytes(jzgw_bj, 9) +
               getDoubleBytes(sjzj_gz, 7) +
               getDoubleBytes(ycdjtx_gz, 6) +
               getDoubleBytes(ybmutx_gz, 5) +
               getDoubleBytes(yzctx_gz, 4) +
               getDoubleBytes(jr_gz, 3) +
               getDoubleBytes(fs_gz, 2) +
               getDoubleBytes(zzzl_gz, 1) +
               getDoubleBytes(zfzl_gz, 0);
    // 1014 电池运行状态
    data[20] = 0xFFFF;
    log(QString("write data"));
    modbus->write(1000, dataNum, data);
    modbus->close();
}

double DisplayThread::getDoubleBytes(int name, int offset)
{
    /*
     * always return the first cluster value
     */
    return ((int)datapool->getDoubleByIndex(1, name)) << offset;
}

void DisplayThread::stop()
{
    running = false;
}
