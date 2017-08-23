#include "canparser.h"

CanParser::CanParser()
{
    dataPool = DataPool::newInstance();
}

// parse the can data and store into the data pool according to the can id.
void CanParser::parse(CanFrame frame){
    int id = frame.can_id;
    switch (id){
    case BMS_INF:
        log(QString("receive can package ").append(QString::number(id, 16)));
        processBMS_INF(frame);
        break;
    default:
        log(QString("receive unknown can package ").append(QString::number(id, 16)));
        break;
    }
}

double CanParser::visit8BytesArray(QString source, long long mask, int mask_offset, string name, double resol, double offset){
    long long bytes = source.toLongLong();
    bytes = (bytes & mask) >> mask_offset;
    double res = bytes * resol + offset;
    log(QString("[visit8BytesArray] res = ").append(QString::number(res)));
    dataPool->store(name, res);
    return res;
}

void CanParser::processBMS_INF(CanFrame frame){
    // byte 2-1, 动力电池的总电压, 0.02, 0, V
    visit8BytesArray(QString::fromLocal8Bit((char*)frame.data, 8),0x000000000000FFFF, 0, "zdy", 0.02, 0);
    // byte 4-3, 动力电池的总电流, 0.1, -3200, A
    visit8BytesArray(QString::fromLocal8Bit((char*)frame.data, 8),0x00000000FFFF0000, 4, "zdl", 0.1, -3200);
    // byte 5, 蓄电池荷电状态（SOC）, 0.4, 0, %

    // byte 6, BMS软件版本号, 0.1, 0,

    // byte 8 bit 8 - 5, 系统运行状态, 1, 0,

    // byte 8 bit 4 - 1, BMS系统故障, 1, 0,
}
