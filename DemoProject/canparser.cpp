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
        log(QString("receive can package BMS_INF"));
        processBMS_INF(frame);
        break;
    case FAU_ALA:
        log(QString("receive can package FAU_ALA"));
        processFAU_ALA(frame);
        break;
    default:
        log(QString("receive unknown can package ").append(QString::number(id, 16)));
        break;
    }
}

double CanParser::visit8BytesArray(char* source, long long mask, int mask_offset, string name, double resol, double offset){
    long long bytes;
    memcpy(&bytes, source, 8);
    bytes = (bytes & mask) >> mask_offset;
    double res = bytes * resol + offset;
    log(QString("[visit8BytesArray] res = ").append(QString::number(res)));
    dataPool->store(name, res);
    return res;
}

void CanParser::processBMS_INF(CanFrame frame){
    // byte 2-1, 动力电池的总电压, 0.02, 0, V
    visit8BytesArray((char*)frame.data,0x000000000000FFFF, 0, "zdy", 0.02, 0);
    // byte 4-3, 动力电池的总电流, 0.1, -3200, A
    visit8BytesArray((char*)frame.data,0x00000000FFFF0000, 16, "zdl", 0.1, -3200);
    // byte 5, 蓄电池荷电状态（SOC）, 0.4, 0, %
    visit8BytesArray((char*)frame.data,0x000000FF00000000, 32, "soc", 0.4, 0);
    // byte 6, BMS软件版本号, 0.1, 0,
    visit8BytesArray((char*)frame.data,0x0000FF0000000000, 40, "ver", 0.1, 0);
    // byte 8 bit 4 - 1, BMS系统故障, 1, 0,
    visit8BytesArray((char*)frame.data,0x0F00000000000000, 56, "xtgz", 1, 0);
    // byte 8 bit 8 - 5, 系统运行状态, 1, 0,
    visit8BytesArray((char*)frame.data,0xF000000000000000, 60, "xtyxzt", 1, 0);
}

void CanParser::processFAU_ALA(CanFrame frame){
    // byte 2-1, 动力电池的总电压, 0.02, 0, V
    visit8BytesArray((char*)frame.data,0x000000000000FFFF, 0, "zdy", 0.02, 0);
    // byte 4-3, 动力电池的总电流, 0.1, -3200, A
    visit8BytesArray((char*)frame.data,0x00000000FFFF0000, 16, "zdl", 0.1, -3200);
    // byte 5, 蓄电池荷电状态（SOC）, 0.4, 0, %
    visit8BytesArray((char*)frame.data,0x000000FF00000000, 32, "soc", 0.4, 0);
    // byte 6, BMS软件版本号, 0.1, 0,
    visit8BytesArray((char*)frame.data,0x0000FF0000000000, 40, "ver", 0.1, 0);
    // byte 8 bit 4 - 1, BMS系统故障, 1, 0,
    visit8BytesArray((char*)frame.data,0x0F00000000000000, 56, "xtgz", 1, 0);
    // byte 8 bit 8 - 5, 系统运行状态, 1, 0,
    visit8BytesArray((char*)frame.data,0xF000000000000000, 60, "xtyxzt", 1, 0);
}
