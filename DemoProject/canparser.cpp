#include "canparser.h"

CanParser::CanParser()
{
    dataPool = DataPool::newInstance();
}

// parse the can data and store into the data pool according to the can id.
void CanParser::parse(can_frame frame){
    //use mask to remove the cluster information.
    int id = frame.can_id& CAN_ID_MASK;
    switch (id){
        case BAMS_INF1:
            log(QString("receive can package BAMS_INF1"));
            processBAMS_INF1(frame);
            break;
        case BAMS_INF2:
            log(QString("receive can package BAMS_INF2"));
            processBAMS_INF2(frame);
            break;
        case BAMS_INF3:
            log(QString("receive can package BAMS_INF3"));
            processBAMS_INF3(frame);
            break;
        case BAMS_INF4:
            log(QString("receive can package BAMS_INF4"));
            processBAMS_INF4(frame);
            break;
        case BMS_INF:
            log(QString("receive can package BMS_INF"));
            processBMS_INF(frame);
            break;
        case BMS_INF1:
            log(QString("receive can package BMS_INF1"));
            processBMS_INF1(frame);
            break;
        case FAU_ALA:
            log(QString("receive can package FAU_ALA"));
            processFAU_ALA(frame);
            break;
        case BMS_INF2:
            log(QString("receive can package BMS_INF2"));
            processBMS_INF2(frame);
            break;
        case NOM_PAR:
            log(QString("receive can package NOM_PAR"));
            processNOM_PAR(frame);
            break;
        case MUN_ID:
            log(QString("receive can package NOM_PAR"));
            processMUN_ID(frame);
            break;
        case MNOM_PAR:
            log(QString("receive can package MNOM_PAR"));
            processMNOM_PAR(frame);
            break;
        case MVT_PAR1:
            log(QString("receive can package MVT_PAR1"));
            processMVT_PAR1(frame);
            break;
        case MVT_PAR2:
            log(QString("receive can package MVT_PAR2"));
            processMVT_PAR2(frame);
            break;
        case CELL_V1:
        case CELL_V2:
        case CELL_V3:
        case CELL_V4:
        case CELL_V5:
        case CELL_V6:
        case CELL_V7:
        case CELL_V8:
        case CELL_V9:
        case CELL_V10:
        case CELL_V11:
        case CELL_V12:
        case CELL_V13:
        case CELL_V14:
        case CELL_V15:
        case CELL_V16:
            log(QString("receive can package CELL_V"));
            processCELL_V(id, frame);
            break;
        case CELL_T1:
            log(QString("receive can package CELL_T1"));
            processCELL_T1(frame);
            break;
        case CELL_T2:
            log(QString("receive can package CELL_T2"));
            processCELL_T2(frame);
            break;
        case PCBA_6803_1:
        case PCBA_6803_2:
        case PCBA_6803_3:
        case PCBA_6803_4:
            log(QString("receive can package PCBA_6803"));
            processPCBA(id, frame);
            break;
        default:
            log(QString("receive unknown can package ").append(QString::number(id, 16)));
            break;
    }
}

double CanParser::maskAndGetValue(char* source, long long mask, int mask_offset, double resol, double offset){
    long long bytes;
    memcpy(&bytes, source, 8);
    bytes = (bytes & mask) >> mask_offset;
    double res = bytes * resol + offset;
    return res;
}

double CanParser::visit8BytesArray(char* source, long long mask, int mask_offset, string name, double resol, double offset){
    double res = maskAndGetValue(source, mask, mask_offset, resol, offset);
    dataPool->store(name, res);
    return res;
}

double CanParser::visit8BytesArray(int clusterId, int moduleId, char* source, long long mask, int mask_offset, string name, double resol, double offset){
    double res = maskAndGetValue(source, mask, mask_offset, resol, offset);
    dataPool->storeById(clusterId, moduleId, name, res);
    return res;
}

double CanParser::visit8BytesArray(int clusterId, char* source, long long mask, int mask_offset, string name, double resol, double offset){
    double res = maskAndGetValue(source, mask, mask_offset, resol, offset);
    dataPool->storeById(clusterId, name, res);
    return res;
}

void CanParser::processBAMS_INF1(can_frame frame){
    // byte 2-1, 系统电压, 0.02, 0, V
    visit8BytesArray((char*)frame.data,0x000000000000FFFF, 0, "g_xtdy", 0.02, 0);
    // byte 4-3, 系统电流, 0.1, -400, A
    visit8BytesArray((char*)frame.data,0x00000000FFFF0000, 16, "g_xtdl", 0.1, -400);
    // byte 5, 系统SOC, 0.4, 0, %
    visit8BytesArray((char*)frame.data,0x000000FF00000000, 32, "g_xtsoc", 0.4, 0);
    // byte 6, 系统状态, 1, 0,
    visit8BytesArray((char*)frame.data,0x0000FF0000000000, 40, "g_xtzt", 1, 0);
}

void CanParser::processBAMS_INF2(can_frame frame){
    // byte 2-1, 最高电压, 0.02, 0, V
    visit8BytesArray((char*)frame.data,0x000000000000FFFF, 0, "g_zgdy", 0.02, 0);
    // byte 4-3, 最低电压, 0.02, 0, V
    visit8BytesArray((char*)frame.data,0x00000000FFFF0000, 16, "g_zddy", 0.02, 0);
    // byte 6-5, 最高温度, 1, -40,
    visit8BytesArray((char*)frame.data,0x0000FFFF00000000, 32, "g_zgwd", 1, -40);
    // byte 8-7, 最低温度, 1, -40,
    visit8BytesArray((char*)frame.data,0xFFFF000000000000, 48, "g_zdwd", 1, -40);
}

void CanParser::processBAMS_INF3(can_frame frame){
    // byte 1, 最高电压所在组号, 1, 0,
    visit8BytesArray((char*)frame.data,0x00000000000000FF, 0, "g_zgdy_zh", 1, 0);
    // byte 2, 最高电压所在模块号, 1, 0,
    visit8BytesArray((char*)frame.data,0x000000000000FF00, 8, "g_zgdy_mkh", 1, 0);
    // byte 3, 最高电压所在位置, 1, 0,
    visit8BytesArray((char*)frame.data,0x0000000000FF0000, 16, "g_zgdy_wz", 1, 0);
    // byte 4, 最低电压所在组号, 1, 0,
    visit8BytesArray((char*)frame.data,0x00000000FF000000, 24, "g_zddy_zh", 1, 0);
    // byte 5, 最低电压所在模块号, 1, 0,
    visit8BytesArray((char*)frame.data,0x000000FF00000000, 32, "g_zddy_mkh", 1, 0);
    // byte 6, 最低电压所在位置, 1, 0,
    visit8BytesArray((char*)frame.data,0x0000FF0000000000, 40, "g_zddy_wz", 1, 0);
    // byte 7, 最高SOC, 1, 0,
    visit8BytesArray((char*)frame.data,0x00FF000000000000, 48, "g_zgsoc", 1, 0);
    // byte 8, 最高SOC所在箱号, 1, 0,
    visit8BytesArray((char*)frame.data,0xFF00000000000000, 56, "g_zgsoc_xh", 1, 0);
}

void CanParser::processBAMS_INF4(can_frame frame){
    // byte 1, 最高温度所在组号, 1, 0,
    visit8BytesArray((char*)frame.data,0x00000000000000FF, 0, "g_zgwd_zh", 1, 0);
    // byte 2, 最高温度所在模块号, 1, 0,
    visit8BytesArray((char*)frame.data,0x000000000000FF00, 8, "g_zgwd_mkh", 1, 0);
    // byte 3, 最高温度所在位置, 1, 0,
    visit8BytesArray((char*)frame.data,0x0000000000FF0000, 16, "g_zgwd_wz", 1, 0);
    // byte 4, 最低温度所在组号, 1, 0,
    visit8BytesArray((char*)frame.data,0x00000000FF000000, 24, "g_zdwd_zh", 1, 0);
    // byte 5, 最低温度所在模块号, 1, 0,
    visit8BytesArray((char*)frame.data,0x000000FF00000000, 32, "g_zdwd_mkh", 1, 0);
    // byte 6, 最低温度所在位置, 1, 0,
    visit8BytesArray((char*)frame.data,0x0000FF0000000000, 40, "g_zdwd_wz", 1, 0);
    // byte 7, 最低SOC, 1, 0,
    visit8BytesArray((char*)frame.data,0x00FF000000000000, 48, "g_zdsoc", 1, 0);
    // byte 8, 最低SOC所在箱号, 1, 0,
    visit8BytesArray((char*)frame.data,0xFF00000000000000, 56, "g_zdsoc_xh", 1, 0);
}

void CanParser::processBMS_INF(can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 2-1, 动力电池的总电压, 0.02, 0, V
    visit8BytesArray(clusterId, (char*)frame.data,0x000000000000FFFF, 0, "zdy", 0.02, 0);
    // byte 4-3, 动力电池的总电流, 0.1, -3200, A
    visit8BytesArray(clusterId, (char*)frame.data,0x00000000FFFF0000, 16, "zdl", 0.1, -3200);
    // byte 5, 蓄电池荷电状态（SOC）, 0.4, 0, %
    visit8BytesArray(clusterId, (char*)frame.data,0x000000FF00000000, 32, "soc", 0.4, 0);
    // byte 6, BMS软件版本号, 0.1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x0000FF0000000000, 40, "ver", 0.1, 0);
    // byte 8 bit 4-1, BMS系统故障, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x0F00000000000000, 56, "xtgz", 1, 0);
    // byte 8 bit 8-5, 系统运行状态, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0xF000000000000000, 60, "xtyxzt", 1, 0);
}

void CanParser::processBMS_INF1(can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 1, 单体最高电压, 0.02, 0, V
    visit8BytesArray(clusterId, (char*)frame.data,0x00000000000000FF, 0, "dtzgdy", 0.02, 0);
    // byte 2, 单体最低电压, 0.02, 0, V
    visit8BytesArray(clusterId, (char*)frame.data,0x000000000000FF00, 8, "dtzddy", 0.02, 0);
    // byte 3, 单体最高温度, 1, -40,
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000000FF0000, 16, "dtzgwd", 1, -40);
    // byte 4, 单体最低温度, 1, -40,
    visit8BytesArray(clusterId, (char*)frame.data,0x00000000FF000000, 24, "dtzdwd", 1, -40);
    // byte 6, SOH, 0.4, 0, %
    visit8BytesArray(clusterId, (char*)frame.data,0x0000FF0000000000, 40, "soh", 0.4, 0);
    // byte 8-7, 绝缘阻值, 0.2, 0, k
    visit8BytesArray(clusterId, (char*)frame.data,0xFFFF000000000000, 48, "jyzz", 0.2, 0);
}

void CanParser::processFAU_ALA(can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 1 bit 8-7, 单体过压报警, 1, 0,
    // byte 1 bit 6-5, 单体欠压报警, 1, 0,
    // byte 1 bit 4-3, 系统过压报警, 1, 0,
    // byte 1 bit 2-1, 系统欠压报警, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x00000000000000C0, 6, "dtgy_bj", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000000000030, 4, "dtqy_bj", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x000000000000000C, 2, "xtgy_bj", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000000000003, 0, "xtqy_bj", 1, 0);

    // byte 2 bit 8-7, 系统压差报警, 1, 0,
    // byte 2 bit 6-5, 系统温差报警, 1, 0,
    // byte 2 bit 4-3, 系统过温报警, 1, 0,
    // byte 2 bit 2-1, 系统低温报警, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x000000000000C000, 14, "xtyc_bj", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000000003000, 12, "xtwc_bj", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000000000C00, 10, "xtgw_bj", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000000000300,  8, "xtdw_bj", 1, 0);

    // byte 3 bit 8-7, 放电过流报警, 1, 0,
    // byte 3 bit 6-5, 充电过流报警, 1, 0,
    // byte 3 bit 4-3, SOC高报警,   1, 0,
    // byte 3 bit 2-1, SOC低报警,   1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000000C00000, 22, "fdgl_bj", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000000300000, 20, "cdgl_bj", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x00000000000C0000, 18, "socg_bj", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000000030000, 16, "socd_bj", 1, 0);

    // byte 4 bit 8-7, 系统绝缘报警, 1, 0,
    // byte 4 bit 6-5, 极柱高温报警, 1, 0,
    // byte 4 bit 4-3, 保留,   1, 0,
    // byte 4 bit 2-1, 保留,   1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x00000000C0000000, 30, "xtjy_bj", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000030000000, 28, "jzgw_bj", 1, 0);

    // byte 6 bit 8, 数据自检故障, 1, 0,
    // byte 6 bit 7, 与整车通信故障, 1, 0,
    // byte 6 bit 6, 与bmu通信故障,   1, 0,
    // byte 6 bit 5, 与充电机通信故障,   1, 0,
    // byte 6 bit 4, 加热故障, 1, 0,
    // byte 6 bit 3, 风扇故障, 1, 0,
    // byte 6 bit 2, 主正粘连故障,   1, 0,
    // byte 6 bit 1, 主负粘连故障,   1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x0000800000000000, 47, "sjzj_gz", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000400000000000, 46, "yzctx_gz", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000200000000000, 45, "ybmutxgz_gz", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000100000000000, 44, "ycdjtx_gz", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000080000000000, 43, "jr_gz", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000040000000000, 42, "fs_gz", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000020000000000, 41, "zzzl_gz", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0000010000000000, 40, "zfzl_gz", 1, 0);

    // byte 7 bit 8, 预充故障, 1, 0,
    // byte 7 bit 7, 电压传感器故障, 1, 0,
    // byte 7 bit 6, 温度传感器故障,   1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x0080000000000000, 55, "yc_gz", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0040000000000000, 54, "dycgq_gz", 1, 0);
    visit8BytesArray(clusterId, (char*)frame.data,0x0020000000000000, 53, "wdcgq_gz", 1, 0);
}

void CanParser::processBMS_INF2(can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 1, 最高电压位置, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x00000000000000FF, 0, "zgdywz", 1, 0);
    // byte 2, 最低电压位置, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x000000000000FF00, 8, "zddywz", 1, 0);
    // byte 3, 最高温度位置, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000000FF0000, 16, "zgwdwz", 1, 0);
    // byte 4, 最低温度位置, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x00000000FF000000, 24, "zdwdwz", 1, 0);
    // byte 5, 最高电压箱号, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x000000FF00000000, 32, "zgdyxh", 1, 0);
    // byte 6, 最低电压箱号, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x0000FF0000000000, 40, "zddyxh", 1, 0);
    // byte 7, 最高温度箱号, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x00FF000000000000, 48, "zgwdxh", 1, 0);
    // byte 8, 最低温度箱号, 1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0xFF00000000000000, 56, "zdwdxh", 1, 0);
}

void CanParser::processNOM_PAR(can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 1,          蓄电池组编号,         1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x00000000000000FF, 0, "xdczbh", 1, 0);
    // byte 2,          蓄电池系统模块总数量,  1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x000000000000FF00, 8, "xdcxtmkzsl", 1, 0);
    // byte 4-3,        蓄电池充电次数,       1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x00000000FFFF0000, 16, "xdccdcs", 1, 0);
    // byte 5 bit 1,    电池充电状态,         1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x0000000100000000, 32, "dccdzt", 1, 0);
    // byte 7-6,        蓄电池输入输出功率,    1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x00FFFF0000000000, 40, "xdcsrscgl", 1, 0);
    // byte 8,          生命周期,            1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0xFF00000000000000, 56, "smzq", 1, 0);
}

void CanParser::processMUN_ID(can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 4-1,          电池模块的唯一编号信息,         1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x00000000FFFFFFFF, 0, "wybhxx", 1, 0);
    // byte 6-5,          最大允许充电（回馈）电流,       1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0x0000FFFF00000000, 32, "zdyxcddl", 1, 0);
    // byte 8-7,          最大允许放电电流,              1, 0,
    visit8BytesArray(clusterId, (char*)frame.data,0xFFFF000000000000, 48, "zdyxfddl", 1, 0);
}

void CanParser::processMNOM_PAR(can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 1,          蓄电池模块号,         1, 0,
    int moduleId = maskAndGetValue((char*)frame.data, 0x00000000000000FF, 0, 1, 0);
    // byte 2,          模块内单体电池数,       1, 0,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000000000FF00, 8, "mkndtdcs", 1, 0);
    // byte 3,          模块内温度采样点数,       1, 0,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FF0000, 16, "mknwdcyds", 1, 0);
    // byte 4,          模块SOC,              0.4, 0, %
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00000000FF000000, 24, "mksoc", 0.4, 0);
    // byte 6-5,        模块充电次数,         1, 0,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000FFFF00000000, 32, "mkcdcs", 1, 0);
    // byte 8-7,        模块总电流,            0.1, -3200,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0xFFFF000000000000, 48, "mkzdl", 0.1, -3200);
}

void CanParser::processMVT_PAR1(can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 1,          蓄电池模块号,
    int moduleId = maskAndGetValue((char*)frame.data, 0x00000000000000FF, 0, 1, 0);
    // byte 3-2,        模块总电压,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "mkzdy", 0.02, 0);
    // byte 4,          模块内最高温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00000000FF000000, 24, "mknzgwd", 1, -40);
    // byte 5,          最高温度采样点号,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FF00000000, 32, "zgwdcydh", 1, 0);
    // byte 6,          模块内最低温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000FF0000000000, 40, "mknzdwd", 1, -40);
    // byte 7,          最低温度采样点号,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FF000000000000, 48, "zdwdcydh", 1, 0);
    // byte 8 bit 8,    内部通讯故障,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x8000000000000000, 63, "nbtxgz", 1, 0);
}

void CanParser::processMVT_PAR2(can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 1,          蓄电池模块号,
    int moduleId = maskAndGetValue((char*)frame.data, 0x00000000000000FF, 0, 1, 0);
    // byte 3-2,        模块内单体最高电压,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "mkndtzgdy", 0.001, 0);
    // byte 4,          电压最高单体号,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00000000FF000000, 24, "dyzgdth", 1, 0);
    // byte 6-5,        模块内单体最低电压,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000FFFF00000000, 32, "mkndtzddy", 0.001, 0);
    // byte 7,          电压最低单体号,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FF000000000000, 48, "dyzddth", 1, 0);
}

void CanParser::processCELL_V(int index, can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 1,          蓄电池模块号,
    int moduleId = maskAndGetValue((char*)frame.data, 0x00000000000000FF, 0, 1, 0);
    switch(index){
        case CELL_V1:
            // byte 3-2, 第1节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_1", 0.001, 0);
            // byte 5-4, 第2节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_2", 0.001, 0);
            // byte 7-6, 第3节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_3", 0.001, 0);
            break;
        case CELL_V2:
            // byte 3-2, 第4节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_4", 0.001, 0);
            // byte 5-4, 第5节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_5", 0.001, 0);
            // byte 7-6, 第6节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_6", 0.001, 0);
            break;
        case CELL_V3:
            // byte 3-2, 第7节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_7", 0.001, 0);
            // byte 5-4, 第8节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_8", 0.001, 0);
            // byte 7-6, 第9节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_9", 0.001, 0);
            break;
        case CELL_V4:
            // byte 3-2, 第10节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_10", 0.001, 0);
            // byte 5-4, 第11节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_11", 0.001, 0);
            // byte 7-6, 第12节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_12", 0.001, 0);
            break;
        case CELL_V5:
            // byte 3-2, 第13节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_13", 0.001, 0);
            // byte 5-4, 第14节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_14", 0.001, 0);
            // byte 7-6, 第15节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_15", 0.001, 0);
            break;
        case CELL_V6:
            // byte 3-2, 第16节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_16", 0.001, 0);
            // byte 5-4, 第17节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_17", 0.001, 0);
            // byte 7-6, 第18节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_18", 0.001, 0);
            break;
        case CELL_V7:
            // byte 3-2, 第19节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_19", 0.001, 0);
            // byte 5-4, 第20节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_20", 0.001, 0);
            // byte 7-6, 第21节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_21", 0.001, 0);
            break;
        case CELL_V8:
            // byte 3-2, 第22节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_22", 0.001, 0);
            // byte 5-4, 第23节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_23", 0.001, 0);
            // byte 7-6, 第24节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_24", 0.001, 0);
            break;
        case CELL_V9:
            // byte 3-2, 第25节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_25", 0.001, 0);
            // byte 5-4, 第26节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_26", 0.001, 0);
            // byte 7-6, 第27节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_27", 0.001, 0);
            break;
        case CELL_V10:
            // byte 3-2, 第28节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_28", 0.001, 0);
            // byte 5-4, 第29节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_29", 0.001, 0);
            // byte 7-6, 第30节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_30", 0.001, 0);
            break;
        case CELL_V11:
            // byte 3-2, 第31节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_31", 0.001, 0);
            // byte 5-4, 第32节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_32", 0.001, 0);
            // byte 7-6, 第33节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_33", 0.001, 0);
            break;
        case CELL_V12:
            // byte 3-2, 第34节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_34", 0.001, 0);
            // byte 5-4, 第35节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_35", 0.001, 0);
            // byte 7-6, 第36节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_36", 0.001, 0);
            break;
        case CELL_V13:
            // byte 3-2, 第37节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_37", 0.001, 0);
            // byte 5-4, 第38节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_38", 0.001, 0);
            // byte 7-6, 第39节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_39", 0.001, 0);
            break;
        case CELL_V14:
            // byte 3-2, 第40节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_40", 0.001, 0);
            // byte 5-4, 第41节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_41", 0.001, 0);
            // byte 7-6, 第42节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_42", 0.001, 0);
            break;
        case CELL_V15:
            // byte 3-2, 第43节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_43", 0.001, 0);
            // byte 5-4, 第44节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_44", 0.001, 0);
            // byte 7-6, 第45节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_45", 0.001, 0);
            break;
        case CELL_V16:
            // byte 3-2, 第46节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FFFF00, 8, "dcdy_46", 0.001, 0);
            // byte 5-4, 第47节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FFFF000000, 24, "dcdy_47", 0.001, 0);
            // byte 7-6, 第48节电池电压,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FFFF0000000000, 40, "dcdy_48", 0.001, 0);
            break;
        default:
            log(QString("no such battery cell."));
            break;
    }
}

void CanParser::processCELL_T1(can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 1,          蓄电池模块号,
    int moduleId = maskAndGetValue((char*)frame.data, 0x00000000000000FF, 0, 1, 0);
    // byte 2,          模块内第1个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000000000FF00,  8, "cywd_1", 1, -40);
    // byte 3,          模块内第2个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FF0000, 16, "cywd_2", 1, -40);
    // byte 4,          模块内第3个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00000000FF000000, 24, "cywd_3", 1, -40);
    // byte 5,          模块内第4个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FF00000000, 32, "cywd_4", 1, -40);
    // byte 6,          模块内第5个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000FF0000000000, 40, "cywd_5", 1, -40);
    // byte 7,          模块内第6个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FF000000000000, 48, "cywd_6", 1, -40);
    // byte 8,          模块内第7个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0xFF00000000000000, 56, "cywd_7", 1, -40);
}

void CanParser::processCELL_T2(can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 1,          蓄电池模块号,
    int moduleId = maskAndGetValue((char*)frame.data, 0x00000000000000FF, 0, 1, 0);
    // byte 2,          模块内第8个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000000000FF00,  8, "cywd_8", 1, -40);
    // byte 3,          模块内第9个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FF0000, 16, "cywd_9", 1, -40);
    // byte 4,          模块内第10个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00000000FF000000, 24, "cywd_10", 1, -40);
    // byte 5,          模块内第11个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FF00000000, 32, "cywd_11", 1, -40);
    // byte 6,          模块内第12个采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000FF0000000000, 40, "cywd_12", 1, -40);
    // byte 7,          正极柱采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00FF000000000000, 48, "zjzcywd", 1, -40);
    // byte 8,          负极柱采样温度,
    visit8BytesArray(clusterId, moduleId, (char*)frame.data,0xFF00000000000000, 56, "fjzcywd", 1, -40);
}

void CanParser::processPCBA(int index, can_frame frame){
    int clusterId = frame.can_id & CLUSTER_ID_MASK;
    // byte 1,          蓄电池模块号,
    int moduleId = maskAndGetValue((char*)frame.data, 0x00000000000000FF, 0, 1, 0);
    switch(index){
        case PCBA_6803_1:
            // byte 2,          PCBA1温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000000000FF00,  8, "6803_1_pcba1wd", 1, -40);
            // byte 3,          PCBA2温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FF0000, 16, "6803_1_pcba2wd", 1, -40);
            // byte 4,          PCBA3温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00000000FF000000, 24, "6803_1_pcba3wd", 1, -40);
            // byte 5,          PCBA4温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FF00000000, 32, "6803_1_pcba4wd", 1, -40);
            break;
        case PCBA_6803_2:
            // byte 2,          PCBA1温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000000000FF00,  8, "6803_2_pcba1wd", 1, -40);
            // byte 3,          PCBA2温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FF0000, 16, "6803_2_pcba2wd", 1, -40);
            // byte 4,          PCBA3温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00000000FF000000, 24, "6803_2_pcba3wd", 1, -40);
            // byte 5,          PCBA4温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FF00000000, 32, "6803_2_pcba4wd", 1, -40);
            break;
        case PCBA_6803_3:
            // byte 2,          PCBA1温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000000000FF00,  8, "6803_3_pcba1wd", 1, -40);
            // byte 3,          PCBA2温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FF0000, 16, "6803_3_pcba2wd", 1, -40);
            // byte 4,          PCBA3温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00000000FF000000, 24, "6803_3_pcba3wd", 1, -40);
            // byte 5,          PCBA4温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FF00000000, 32, "6803_3_pcba4wd", 1, -40);
            break;
        case PCBA_6803_4:
            // byte 2,          PCBA1温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000000000FF00,  8, "6803_4_pcba1wd", 1, -40);
            // byte 3,          PCBA2温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x0000000000FF0000, 16, "6803_4_pcba2wd", 1, -40);
            // byte 4,          PCBA3温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x00000000FF000000, 24, "6803_4_pcba3wd", 1, -40);
            // byte 5,          PCBA4温度,
            visit8BytesArray(clusterId, moduleId, (char*)frame.data,0x000000FF00000000, 32, "6803_4_pcba4wd", 1, -40);
            break;
        default:
            log(QString("no such PCBA type."));
            break;
    }


}








