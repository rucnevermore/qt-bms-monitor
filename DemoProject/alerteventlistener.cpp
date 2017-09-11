#include "alerteventlistener.h"

AlertEventListener::AlertEventListener()
{
    dataPool = DataPool::newInstance();
}

void AlertEventListener::notify(Data* data){
    string name = data->getName();
    int value = data->getValue().toInt();
    string textValue;
    if (value == 0){
        textValue = "正常";
    }else if (value == 1){
        textValue = "一级";
    }else if (value == 2){
        textValue = "二级";
    }else if (value == 3){
        textValue = "三级";
    }else{
        textValue = "未知";
    }

    if (name == "dtgy_bj"){
        textValue = "单体过压报警" + textValue;
    }else if (name == "dtqy_bj"){
        textValue = "单体欠压报警" + textValue;
    }else if (name == "xtgy_bj"){
        textValue = "系统过压报警" + textValue;
    }else if (name == "xtqy_bj"){
        textValue = "系统欠压报警" + textValue;
    }else if (name == "xtyc_bj"){
        textValue = "系统压差报警" + textValue;
    }else if (name == "xtwc_bj"){
        textValue = "系统温差报警" + textValue;
    }else if (name == "xtgw_bj"){
        textValue = "系统过温报警" + textValue;
    }else if (name == "xtdw_bj"){
        textValue = "系统低温报警" + textValue;
    }else if (name == "fdgl_bj"){
        textValue = "放电过流报警" + textValue;
    }else if (name == "cdgl_bj"){
        textValue = "充电过流报警" + textValue;
    }else if (name == "socg_bj"){
        textValue = "SOC高报警" + textValue;
    }else if (name == "socd_bj"){
        textValue = "SOC低报警" + textValue;
    }else if (name == "xtjy_bj"){
        textValue = "系统绝缘报警" + textValue;
    }else if (name == "jzgw_bj"){
        textValue = "极柱高温报警" + textValue;
    }else if (name == "sjzj_gz"){
        textValue = "数据自检故障" + textValue;
    }else if (name == "yzctx_gz"){
        textValue = "与整车通信故障" + textValue;
    }else if (name == "ybmutxgz_gz"){
        textValue = "与bmu通信故障" + textValue;
    }else if (name == "ycdjtx_gz"){
        textValue = "与充电机通信故障" + textValue;
    }else if (name == "jr_gz"){
        textValue = "加热故障" + textValue;
    }else if (name == "fs_gz"){
        textValue = "风扇故障" + textValue;
    }else if (name == "zzzl_gz"){
        textValue = "主正粘连故障" + textValue;
    }else if (name == "zfzl_gz"){
        textValue = "主负粘连故障" + textValue;
    }else if (name == "yc_gz"){
        textValue = "预充故障" + textValue;
    }else if (name == "dycgq_gz"){
        textValue = "电压传感器故障" + textValue;
    }else if (name == "wdcgq_gz"){
        textValue = "温度传感器故障" + textValue;
    }
    dataPool->addEvent(QString::fromStdString(textValue));
}
