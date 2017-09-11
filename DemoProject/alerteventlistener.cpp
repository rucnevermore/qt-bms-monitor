#include "alerteventlistener.h"

AlertEventListener::AlertEventListener()
{
    dataPool = DataPool::newInstance();
}

void AlertEventListener::notify(Data* data){
    string name = data->getName();
    int value = data->getValue().toInt();
    QString textValue;
    if (value == 0){
        textValue = QString::fromUtf8("正常");
    }else if (value == 1){
        textValue = QString::fromUtf8("一级");
    }else if (value == 2){
        textValue = QString::fromUtf8("二级");
    }else if (value == 3){
        textValue = QString::fromUtf8("三级");
    }else{
        textValue = QString::fromUtf8("未知");
    }

    if (name == "dtgy_bj"){
        textValue = QString::fromUtf8("单体过压报警").append(textValue);
    }else if (name == "dtqy_bj"){
        textValue = QString::fromUtf8("单体欠压报警").append(textValue);
    }else if (name == "xtgy_bj"){
        textValue = QString::fromUtf8("系统过压报警").append(textValue);
    }else if (name == "xtqy_bj"){
        textValue = QString::fromUtf8("系统欠压报警").append(textValue);
    }else if (name == "xtyc_bj"){
        textValue = QString::fromUtf8("系统压差报警").append(textValue);
    }else if (name == "xtwc_bj"){
        textValue = QString::fromUtf8("系统温差报警").append(textValue);
    }else if (name == "xtgw_bj"){
        textValue = QString::fromUtf8("系统过温报警").append(textValue);
    }else if (name == "xtdw_bj"){
        textValue = QString::fromUtf8("系统低温报警").append(textValue);
    }else if (name == "fdgl_bj"){
        textValue = QString::fromUtf8("放电过流报警").append(textValue);
    }else if (name == "cdgl_bj"){
        textValue = QString::fromUtf8("充电过流报警").append(textValue);
    }else if (name == "socg_bj"){
        textValue = QString::fromUtf8("SOC高报警").append(textValue);
    }else if (name == "socd_bj"){
        textValue = QString::fromUtf8("SOC低报警").append(textValue);
    }else if (name == "xtjy_bj"){
        textValue = QString::fromUtf8("系统绝缘报警").append(textValue);
    }else if (name == "jzgw_bj"){
        textValue = QString::fromUtf8("极柱高温报警").append(textValue);
    }else if (name == "sjzj_gz"){
        textValue = QString::fromUtf8("数据自检故障").append(textValue);
    }else if (name == "yzctx_gz"){
        textValue = QString::fromUtf8("与整车通信故障").append(textValue);
    }else if (name == "ybmutxgz_gz"){
        textValue = QString::fromUtf8("与bmu通信故障").append(textValue);
    }else if (name == "ycdjtx_gz"){
        textValue = QString::fromUtf8("与充电机通信故障").append(textValue);
    }else if (name == "jr_gz"){
        textValue = QString::fromUtf8("加热故障").append(textValue);
    }else if (name == "fs_gz"){
        textValue = QString::fromUtf8("风扇故障").append(textValue);
    }else if (name == "zzzl_gz"){
        textValue = QString::fromUtf8("主正粘连故障").append(textValue);
    }else if (name == "zfzl_gz"){
        textValue = QString::fromUtf8("主负粘连故障").append(textValue);
    }else if (name == "yc_gz"){
        textValue = QString::fromUtf8("预充故障").append(textValue);
    }else if (name == "dycgq_gz"){
        textValue = QString::fromUtf8("电压传感器故障").append(textValue);
    }else if (name == "wdcgq_gz"){
        textValue = QString::fromUtf8("温度传感器故障").append(textValue);
    }
    dataPool->addEvent(textValue);
}
