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
    case NOM_PAR:
        log(QString("receive can package NOM_PAR"));
        processNOM_PAR(frame);
        break;
    case MUN_ID:
        log(QString("receive can package NOM_PAR"));
        processMUN_ID(frame);
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
//    log(QString("[visit8BytesArray] res = ").append(QString::number(res)));
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
    // byte 1 bit 8-7, 单体过压报警, 1, 0,
    // byte 1 bit 6-5, 单体欠压报警, 1, 0,
    // byte 1 bit 4-3, 系统过压报警, 1, 0,
    // byte 1 bit 2-1, 系统欠压报警, 1, 0,
    visit8BytesArray((char*)frame.data,0x00000000000000C0, 6, "dtgy_bj", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000000000000030, 4, "dtqy_bj", 1, 0);
    visit8BytesArray((char*)frame.data,0x000000000000000C, 2, "xtgy_bj", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000000000000003, 0, "xtqy_bj", 1, 0);

    // byte 2 bit 8-7, 系统压差报警, 1, 0,
    // byte 2 bit 6-5, 系统温差报警, 1, 0,
    // byte 2 bit 4-3, 系统过温报警, 1, 0,
    // byte 2 bit 2-1, 系统低温报警, 1, 0,
    visit8BytesArray((char*)frame.data,0x000000000000C000, 14, "xtyc_bj", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000000000003000, 12, "xtwc_bj", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000000000000C00, 10, "xtgw_bj", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000000000000300,  8, "xtdw_bj", 1, 0);

    // byte 3 bit 8-7, 放电过流报警, 1, 0,
    // byte 3 bit 6-5, 充电过流报警, 1, 0,
    // byte 3 bit 4-3, SOC高报警,   1, 0,
    // byte 3 bit 2-1, SOC低报警,   1, 0,
    visit8BytesArray((char*)frame.data,0x0000000000C00000, 22, "fdgl_bj", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000000000300000, 20, "cdgl_bj", 1, 0);
    visit8BytesArray((char*)frame.data,0x00000000000C0000, 18, "socg_bj", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000000000030000, 16, "socd_bj", 1, 0);

    // byte 4 bit 8-7, 系统绝缘报警, 1, 0,
    // byte 4 bit 6-5, 极柱高温报警, 1, 0,
    // byte 4 bit 4-3, 保留,   1, 0,
    // byte 4 bit 2-1, 保留,   1, 0,
    visit8BytesArray((char*)frame.data,0x00000000C0000000, 30, "xtjy_bj", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000000030000000, 28, "jzgw_bj", 1, 0);


    // byte 6 bit 8, 数据自检故障, 1, 0,
    // byte 6 bit 7, 与整车通信故障, 1, 0,
    // byte 6 bit 6, 与bmu通信故障,   1, 0,
    // byte 6 bit 5, 与充电机通信故障,   1, 0,
    // byte 6 bit 4, 加热故障, 1, 0,
    // byte 6 bit 3, 风扇故障, 1, 0,
    // byte 6 bit 2, 主正粘连故障,   1, 0,
    // byte 6 bit 1, 主负粘连故障,   1, 0,
    visit8BytesArray((char*)frame.data,0x0000800000000000, 47, "sjzj_gz", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000400000000000, 46, "yzctx_gz", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000200000000000, 45, "ybmutxgz_gz", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000100000000000, 44, "ycdjtx_gz", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000080000000000, 43, "jr_gz", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000040000000000, 42, "fs_gz", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000020000000000, 41, "zzzl_gz", 1, 0);
    visit8BytesArray((char*)frame.data,0x0000010000000000, 40, "zfzl_gz", 1, 0);

    // byte 7 bit 8, 预充故障, 1, 0,
    // byte 7 bit 7, 电压传感器故障, 1, 0,
    // byte 7 bit 6, 温度传感器故障,   1, 0,
    visit8BytesArray((char*)frame.data,0x0080000000000000, 55, "yc_gz", 1, 0);
    visit8BytesArray((char*)frame.data,0x0040000000000000, 54, "dycgq_gz", 1, 0);
    visit8BytesArray((char*)frame.data,0x0020000000000000, 53, "wdcgq_gz", 1, 0);
}

void CanParser::processNOM_PAR(CanFrame frame){
    // byte 1,          蓄电池组编号,         1, 0,
    visit8BytesArray((char*)frame.data,0x00000000000000FF, 0, "xdczbh", 1, 0);
    // byte 2,          蓄电池系统模块总数量,  1, 0,
    visit8BytesArray((char*)frame.data,0x000000000000FF00, 8, "xdcxtmkzsl", 1, 0);
    // byte 4-3,        蓄电池充电次数,       1, 0,
    visit8BytesArray((char*)frame.data,0x00000000FFFF0000, 16, "xdccdcs", 1, 0);
    // byte 5 bit 1,    电池充电状态,         1, 0,
    visit8BytesArray((char*)frame.data,0x0000000100000000, 32, "dccdzt", 1, 0);
    // byte 7-6,        蓄电池输入输出功率,    1, 0,
    visit8BytesArray((char*)frame.data,0x00FFFF0000000000, 40, "xdcsrscgl", 1, 0);
    // byte 8,          生命周期,            1, 0,
    visit8BytesArray((char*)frame.data,0xFF00000000000000, 56, "xtyxzt", 1, 0);
}

void CanParser::processMUN_ID(CanFrame frame){
    // byte 4-1,          电池模块的唯一编号信息,         1, 0,
    visit8BytesArray((char*)frame.data,0x00000000FFFFFFFF, 0, "wybhxx", 1, 0);
    // byte 6-5,          最大允许充电（回馈）电流,       1, 0,
    visit8BytesArray((char*)frame.data,0x0000FFFF00000000, 8, "zdyxcddl", 1, 0);
    // byte 8-7,          最大允许放电电流,              1, 0,
    visit8BytesArray((char*)frame.data,0xFFFF000000000000, 16, "zdyxfddl", 1, 0);
}

void CanParser::processMNOM_PAR(CanFrame frame){
    // byte 1,          蓄电池模块号,         1, 0,
    visit8BytesArray((char*)frame.data,0x00000000000000FF, 0, "xdcmkh", 1, 0);
    // byte 2,          模块内单体电池数,       1, 0,
    visit8BytesArray((char*)frame.data,0x000000000000FF00, 8, "mkndtdcs", 1, 0);
    // byte 3,          模块内温度采样点数,       1, 0,
    visit8BytesArray((char*)frame.data,0x0000000000FF0000, 16, "mknwdcyds", 1, 0);
    // byte 4,          模块SOC,              0.4, 0, %
    visit8BytesArray((char*)frame.data,0x00000000FF000000, 24, "mksoc", 0.4, 0);
    // byte 6-5,        模块充电次数,         1, 0,
    visit8BytesArray((char*)frame.data,0x0000FFFF00000000, 32, "mkcdcs", 1, 0);
    // byte 8-7,        模块总电流,            0.1, -3200,
    visit8BytesArray((char*)frame.data,0xFFFF000000000000, 48, "mkzdl", 0.1, -3200);
}










