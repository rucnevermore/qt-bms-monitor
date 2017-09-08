#include "widget.h"
#include <ctime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);

    log(QString::number(this->width(),10));
    log(QString::number(this->height(),10));

    log(QString::fromStdString("application start..."));
    log(QString::fromStdString("init data pool..."));
    dataPool = DataPool::newInstance();
//    connect(dataPool,SIGNAL(log(QString)),this,SLOT(log(QString)));

    configure = Configure::newInstance();

    // start the display thread.
    log(QString::fromStdString("start display thread..."));
    displayThread = new DisplayThread();
    connect(displayThread,SIGNAL(display()),this,SLOT(display()));
    displayThread->start();

    log(QString::fromStdString("start collection thread..."));
    collectionThread = new CollectionThread();
    connect(collectionThread,SIGNAL(log(QString)),this,SLOT(log(QString)));
    collectionThread->start();

    connect(ui->pbutton_left,SIGNAL(clicked()),this,SLOT(decreaseCluster()));
    connect(ui->pbutton_right,SIGNAL(clicked()),this,SLOT(increaseCluster()));

    configure->setClusterId(1);

    // for debug purpose.
    dataPool->store("max_event_number", 100);
    dataPool->store("cluster_number", 10);
}


Widget::~Widget()
{
    delete ui;
    if(displayThread)
    {
        displayThread->stop();
        displayThread->deleteLater();
    }
    if(collectionThread)
    {
        collectionThread->stop();
        collectionThread->deleteLater();
    }
}

void Widget::decreaseCluster()
{
    int currentNum = ui->label_cluster->text().toInt();
    log(QString::fromStdString("current num is ").append(QString::number(currentNum)).append(QString::fromStdString("cluster number is ")).append(QString::number(configure->getClusterNum())));
    if (currentNum > 1){        
        ui->label_cluster->setText(QString::number(currentNum - 1));
        configure->setClusterId(currentNum - 1);
    }else{
        ui->label_cluster->setText(QString::number(configure->getClusterNum()));
        configure->setClusterId(configure->getClusterNum());
    }
    this->display();
}

void Widget::increaseCluster()
{
    int currentNum = ui->label_cluster->text().toInt();
    if (currentNum < configure->getClusterNum()){
        ui->label_cluster->setText(QString::number(currentNum + 1));
        configure->setClusterId(currentNum + 1);
    }else{
        ui->label_cluster->setText(QString::number(1));
        configure->setClusterId(1);
    }
    this->display();
}

// set alert value and change color accordingly.
void Widget::setAlertText(QTextBrowser* textBrowser, double value){
    if (value == 0){
        textBrowser->setText(QString::fromUtf8("正常"));
        textBrowser->setStyleSheet("background-color: green");
    }else if (value == 1){
        textBrowser->setText(QString::fromUtf8("一级"));
        textBrowser->setStyleSheet("background-color: yellow");
    }else if (value == 2){
        textBrowser->setText(QString::fromUtf8("二级"));
        textBrowser->setStyleSheet("background-color: orange");
    }else if (value == 3){
        textBrowser->setText(QString::fromUtf8("三级"));
        textBrowser->setStyleSheet("background-color: red");
    }else{
        textBrowser->setText(QString::fromUtf8("未知"));
    }
}

void Widget::display()
{
    // page 1
    ui->lcd_soc->display(dataPool->getDouble("soc"));
    ui->lcd_zdl->display(dataPool->getDouble("zdl"));
    ui->lcd_zdwc->display(dataPool->getDouble("zdwc"));
    ui->lcd_zdy->display(dataPool->getDouble("zdy"));
    ui->lcd_zdyc->display(dataPool->getDouble("zdyc"));
    ui->pBar_soc->setValue(dataPool->getDouble("soc"));

    // page 2
    int current_cluster_id = configure->getClusterId();

    // 最高电压
    ui->lcd_p2_zgdy->display(dataPool->getDoubleByIndex(current_cluster_id, "dtzgdy"));
    // 最低电压
    ui->lcd_p2_zddy->display(dataPool->getDoubleByIndex(current_cluster_id, "dtzddy"));
    // 最高温度
    ui->lcd_p2_zgwd->display(dataPool->getDoubleByIndex(current_cluster_id, "dtzgwd"));
    // 最低温度
    ui->lcd_p2_zdwd->display(dataPool->getDoubleByIndex(current_cluster_id, "dtzdwd"));

    // 系统总压
    ui->lcd_p2_xtzy->display(dataPool->getDoubleByIndex(current_cluster_id, "zdy"));
    // 系统状态
    int value = dataPool->getDoubleByIndex(current_cluster_id, "xtyxzt");
    if (value == 0){
        ui->text_p2_xtzt->setText(QString::fromUtf8("上电"));
    }else if (value == 1){
        ui->text_p2_xtzt->setText(QString::fromUtf8("直流充电"));
    }else if (value == 2){
        ui->text_p2_xtzt->setText(QString::fromUtf8("交流充电"));
    }else if (value == 3){
        ui->text_p2_xtzt->setText(QString::fromUtf8("放电"));
    }else{
        ui->text_p2_xtzt->setText(QString::fromUtf8("未知"));
    }
    // 电流
    ui->lcd_p2_dl->display(dataPool->getDoubleByIndex(current_cluster_id, "zdl"));
    // SOC
    ui->lcd_p2_soc->display(dataPool->getDoubleByIndex(current_cluster_id, "soc"));
    // SOH
    ui->lcd_p2_soh->display(dataPool->getDoubleByIndex(current_cluster_id, "soh"));
    // 故障状态
    value = dataPool->getDoubleByIndex(current_cluster_id, "xtgz");
    if (value == 0){
        ui->text_p2_gzzt->setText(QString::fromUtf8("无故障"));
    }else if (value == 1){
        ui->text_p2_gzzt->setText(QString::fromUtf8("一级故障"));
    }else if (value == 2){
        ui->text_p2_gzzt->setText(QString::fromUtf8("二级故障"));
    }else if (value == 3){
        ui->text_p2_gzzt->setText(QString::fromUtf8("三级故障"));
    }else{
        ui->text_p2_gzzt->setText(QString::fromUtf8("未知"));
    }
    // 功率
    ui->lcd_p2_gl->display(dataPool->getDoubleByIndex(current_cluster_id, "xdcsrscgl"));
    // 子模数量
    ui->lcd_p2_zmsl->display(dataPool->getDoubleByIndex(current_cluster_id, "xdcxtmkzsl"));
    // 充电次数
    ui->lcd_p2_cdcs->display(dataPool->getDoubleByIndex(current_cluster_id, "xdccdcs"));
    // 电池状态
    value = dataPool->getDoubleByIndex(current_cluster_id, "dccdzt");
    if (value == 1){
        ui->text_p2_dczt->setText(QString::fromUtf8("充电中"));
    }else if (value == 0){
        ui->text_p2_dczt->setText(QString::fromUtf8("未充电"));
    }else{
        ui->text_p2_dczt->setText(QString::fromUtf8("未知"));
    }
    // 绝缘阻值
    ui->lcd_p2_jyzz->display(dataPool->getDoubleByIndex(current_cluster_id, "jyzz"));
    // 生命周期
    ui->lcd_p2_smzq->display(dataPool->getDoubleByIndex(current_cluster_id, "smzq"));
    // 软件版本号   
    ui->lcd_p2_rjbbh->display(dataPool->getDoubleByIndex(current_cluster_id, "ver"));

    // 单体过压报警
    setAlertText(ui->text_p2_bj_dtgy, dataPool->getDoubleByIndex(current_cluster_id, "dtgy_bj"));
    // 单体欠压报警
    setAlertText(ui->text_p2_bj_dtqy, dataPool->getDoubleByIndex(current_cluster_id, "dtqy_bj"));
    // 系统过压报警
    setAlertText(ui->text_p2_bj_xtgy, dataPool->getDoubleByIndex(current_cluster_id, "xtgy_bj"));
    // 系统欠压报警
    setAlertText(ui->text_p2_bj_xtqy, dataPool->getDoubleByIndex(current_cluster_id, "xtqy_bj"));
    // 系统压差报警
    setAlertText(ui->text_p2_bj_xtyc, dataPool->getDoubleByIndex(current_cluster_id, "xtyc_bj"));
    // 系统温差报警
    setAlertText(ui->text_p2_bj_xtwc, dataPool->getDoubleByIndex(current_cluster_id, "xtwc_bj"));
    // 系统过温报警
    setAlertText(ui->text_p2_bj_xtgw, dataPool->getDoubleByIndex(current_cluster_id, "xtgw_bj"));
    // 系统低温报警
    setAlertText(ui->text_p2_bj_xtdw, dataPool->getDoubleByIndex(current_cluster_id, "xtdw_bj"));
    // 放电过流报警
    setAlertText(ui->text_p2_bj_fdgl, dataPool->getDoubleByIndex(current_cluster_id, "fdgl_bj"));
    // 充电过流报警
    setAlertText(ui->text_p2_bj_cdgl, dataPool->getDoubleByIndex(current_cluster_id, "cdgl_bj"));
    // SOC高报警
    setAlertText(ui->text_p2_bj_socg, dataPool->getDoubleByIndex(current_cluster_id, "socg_bj"));
    // SOC低报警
    setAlertText(ui->text_p2_bj_socd, dataPool->getDoubleByIndex(current_cluster_id, "socd_bj"));
    // 系统绝缘报警
    setAlertText(ui->text_p2_bj_xtjy, dataPool->getDoubleByIndex(current_cluster_id, "xtjy_bj"));
    // 极柱高温报警
    setAlertText(ui->text_p2_bj_jzgw, dataPool->getDoubleByIndex(current_cluster_id, "jzgw_bj"));
    // 数据自检故障
    setAlertText(ui->text_p2_gz_sjzj, dataPool->getDoubleByIndex(current_cluster_id, "sjzj_gz"));
    // 与整车通信故障
    setAlertText(ui->text_p2_gz_yzctx, dataPool->getDoubleByIndex(current_cluster_id, "yzctx_gz"));
    // 与bmu通信故障
    setAlertText(ui->text_p2_gz_ybmutx, dataPool->getDoubleByIndex(current_cluster_id, "ybmutx_gz"));
    // 与充电机通信故障
    setAlertText(ui->text_p2_gz_ycdjtx, dataPool->getDoubleByIndex(current_cluster_id, "ycdjtx_gz"));
    // 加热故障
    setAlertText(ui->text_p2_gz_jr, dataPool->getDoubleByIndex(current_cluster_id, "rj_gz"));
    // 风扇故障
    setAlertText(ui->text_p2_gz_fs, dataPool->getDoubleByIndex(current_cluster_id, "fs_gz"));
    // 主正粘连故障
    setAlertText(ui->text_p2_gz_zzzl, dataPool->getDoubleByIndex(current_cluster_id, "zzzl_gz"));
    // 主负粘连故障
    setAlertText(ui->text_p2_gz_zfzl, dataPool->getDoubleByIndex(current_cluster_id, "zfzl_gz"));
    // 预充故障
    setAlertText(ui->text_p2_gz_yc, dataPool->getDoubleByIndex(current_cluster_id, "yc_gz"));
    // 电压传感器故障
    setAlertText(ui->text_p2_gz_dycgq, dataPool->getDoubleByIndex(current_cluster_id, "dycgq_gz"));
    // 温度传感器故障
    setAlertText(ui->text_p2_gz_wdcgq, dataPool->getDoubleByIndex(current_cluster_id, "wdcgq_gz"));

}
void Widget::log(QString str)
{
    ui->text_log->append(str);
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
