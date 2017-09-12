#include "widget.h"
#include <ctime>
#include "alerteventlistener.h"

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

    dataPool->registerListener(new AlertEventListener());
    // for debug purpose.
    dataPool->store("max_event_number", 100);
    dataPool->store("cluster_number", 10);

    configure = Configure::newInstance();
    configure->setEventCurrentPageNum(1);
    configure->setMaxEventInOnePage(10);
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

    connect(ui->pbutton_left_2,SIGNAL(clicked()),this,SLOT(decreaseCluster()));
    connect(ui->pbutton_right_2,SIGNAL(clicked()),this,SLOT(increaseCluster()));

    connect(ui->pbutton_up,SIGNAL(clicked()),this,SLOT(lastPage()));
    connect(ui->pbutton_down,SIGNAL(clicked()),this,SLOT(nextPage()));

    configure->setClusterIndex(1);
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
    if (currentNum > 1){        
        ui->label_cluster->setText(QString::number(currentNum - 1));
        ui->label_cluster_2->setText(QString::number(currentNum - 1));
        configure->setClusterIndex(currentNum - 1);
    }else{
        ui->label_cluster->setText(QString::number(configure->getClusterNum()));
        ui->label_cluster_2->setText(QString::number(configure->getClusterNum()));
        configure->setClusterIndex(configure->getClusterNum());
    }
    this->display();
}

void Widget::increaseCluster()
{
    int currentNum = ui->label_cluster->text().toInt();
    if (currentNum < configure->getClusterNum()){
        ui->label_cluster->setText(QString::number(currentNum + 1));
        ui->label_cluster_2->setText(QString::number(currentNum + 1));
        configure->setClusterIndex(currentNum + 1);
    }else{
        ui->label_cluster->setText(QString::number(1));
        ui->label_cluster_2->setText(QString::number(1));
        configure->setClusterIndex(1);
    }
    this->display();
}

void Widget::lastPage(){
    int currentPage = configure->getEventCurrentPageNum();
    if (currentPage == 1){
        return;
    }else{
        configure->setEventCurrentPageNum(currentPage - 1);
        this->display();
    }
}

void Widget::nextPage(){
    int currentPage = configure->getEventCurrentPageNum();
    int eventTotal = configure->getEventTotal();
    int maxEventInOnePage = configure->getMaxEventInOnePage();

    if ((currentPage * maxEventInOnePage) >= eventTotal){
        return;
    }else{
        configure->setEventCurrentPageNum(currentPage + 1);
        this->display();
    }
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
    int current_cluster_index = configure->getClusterIndex();

    // 最高电压
    ui->lcd_p2_zgdy->display(dataPool->getDoubleByIndex(current_cluster_index, "dtzgdy"));
    // 最低电压
    ui->lcd_p2_zddy->display(dataPool->getDoubleByIndex(current_cluster_index, "dtzddy"));
    // 最高温度
    ui->lcd_p2_zgwd->display(dataPool->getDoubleByIndex(current_cluster_index, "dtzgwd"));
    // 最低温度
    ui->lcd_p2_zdwd->display(dataPool->getDoubleByIndex(current_cluster_index, "dtzdwd"));

    // 系统总压
    ui->lcd_p2_xtzy->display(dataPool->getDoubleByIndex(current_cluster_index, "zdy"));
    // 系统状态
    int value = dataPool->getDoubleByIndex(current_cluster_index, "xtyxzt");
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
    ui->lcd_p2_dl->display(dataPool->getDoubleByIndex(current_cluster_index, "zdl"));
    // SOC
    ui->lcd_p2_soc->display(dataPool->getDoubleByIndex(current_cluster_index, "soc"));
    // SOH
    ui->lcd_p2_soh->display(dataPool->getDoubleByIndex(current_cluster_index, "soh"));
    // 故障状态
    value = dataPool->getDoubleByIndex(current_cluster_index, "xtgz");
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
    ui->lcd_p2_gl->display(dataPool->getDoubleByIndex(current_cluster_index, "xdcsrscgl"));
    // 子模数量
    ui->lcd_p2_zmsl->display(dataPool->getDoubleByIndex(current_cluster_index, "xdcxtmkzsl"));
    // 充电次数
    ui->lcd_p2_cdcs->display(dataPool->getDoubleByIndex(current_cluster_index, "xdccdcs"));
    // 电池状态
    value = dataPool->getDoubleByIndex(current_cluster_index, "dccdzt");
    if (value == 1){
        ui->text_p2_dczt->setText(QString::fromUtf8("充电中"));
    }else if (value == 0){
        ui->text_p2_dczt->setText(QString::fromUtf8("未充电"));
    }else{
        ui->text_p2_dczt->setText(QString::fromUtf8("未知"));
    }
    // 绝缘阻值
    ui->lcd_p2_jyzz->display(dataPool->getDoubleByIndex(current_cluster_index, "jyzz"));
    // 生命周期
    ui->lcd_p2_smzq->display(dataPool->getDoubleByIndex(current_cluster_index, "smzq"));
    // 软件版本号   
    ui->lcd_p2_rjbbh->display(dataPool->getDoubleByIndex(current_cluster_index, "ver"));

    // 单体过压报警
    setAlertText(ui->text_p2_bj_dtgy, dataPool->getDoubleByIndex(current_cluster_index, "dtgy_bj"));
    // 单体欠压报警
    setAlertText(ui->text_p2_bj_dtqy, dataPool->getDoubleByIndex(current_cluster_index, "dtqy_bj"));
    // 系统过压报警
    setAlertText(ui->text_p2_bj_xtgy, dataPool->getDoubleByIndex(current_cluster_index, "xtgy_bj"));
    // 系统欠压报警
    setAlertText(ui->text_p2_bj_xtqy, dataPool->getDoubleByIndex(current_cluster_index, "xtqy_bj"));
    // 系统压差报警
    setAlertText(ui->text_p2_bj_xtyc, dataPool->getDoubleByIndex(current_cluster_index, "xtyc_bj"));
    // 系统温差报警
    setAlertText(ui->text_p2_bj_xtwc, dataPool->getDoubleByIndex(current_cluster_index, "xtwc_bj"));
    // 系统过温报警
    setAlertText(ui->text_p2_bj_xtgw, dataPool->getDoubleByIndex(current_cluster_index, "xtgw_bj"));
    // 系统低温报警
    setAlertText(ui->text_p2_bj_xtdw, dataPool->getDoubleByIndex(current_cluster_index, "xtdw_bj"));
    // 放电过流报警
    setAlertText(ui->text_p2_bj_fdgl, dataPool->getDoubleByIndex(current_cluster_index, "fdgl_bj"));
    // 充电过流报警
    setAlertText(ui->text_p2_bj_cdgl, dataPool->getDoubleByIndex(current_cluster_index, "cdgl_bj"));
    // SOC高报警
    setAlertText(ui->text_p2_bj_socg, dataPool->getDoubleByIndex(current_cluster_index, "socg_bj"));
    // SOC低报警
    setAlertText(ui->text_p2_bj_socd, dataPool->getDoubleByIndex(current_cluster_index, "socd_bj"));
    // 系统绝缘报警
    setAlertText(ui->text_p2_bj_xtjy, dataPool->getDoubleByIndex(current_cluster_index, "xtjy_bj"));
    // 极柱高温报警
    setAlertText(ui->text_p2_bj_jzgw, dataPool->getDoubleByIndex(current_cluster_index, "jzgw_bj"));
    // 数据自检故障
    setAlertText(ui->text_p2_gz_sjzj, dataPool->getDoubleByIndex(current_cluster_index, "sjzj_gz"));
    // 与整车通信故障
    setAlertText(ui->text_p2_gz_yzctx, dataPool->getDoubleByIndex(current_cluster_index, "yzctx_gz"));
    // 与bmu通信故障
    setAlertText(ui->text_p2_gz_ybmutx, dataPool->getDoubleByIndex(current_cluster_index, "ybmutx_gz"));
    // 与充电机通信故障
    setAlertText(ui->text_p2_gz_ycdjtx, dataPool->getDoubleByIndex(current_cluster_index, "ycdjtx_gz"));
    // 加热故障
    setAlertText(ui->text_p2_gz_jr, dataPool->getDoubleByIndex(current_cluster_index, "rj_gz"));
    // 风扇故障
    setAlertText(ui->text_p2_gz_fs, dataPool->getDoubleByIndex(current_cluster_index, "fs_gz"));
    // 主正粘连故障
    setAlertText(ui->text_p2_gz_zzzl, dataPool->getDoubleByIndex(current_cluster_index, "zzzl_gz"));
    // 主负粘连故障
    setAlertText(ui->text_p2_gz_zfzl, dataPool->getDoubleByIndex(current_cluster_index, "zfzl_gz"));
    // 预充故障
    setAlertText(ui->text_p2_gz_yc, dataPool->getDoubleByIndex(current_cluster_index, "yc_gz"));
    // 电压传感器故障
    setAlertText(ui->text_p2_gz_dycgq, dataPool->getDoubleByIndex(current_cluster_index, "dycgq_gz"));
    // 温度传感器故障
    setAlertText(ui->text_p2_gz_wdcgq, dataPool->getDoubleByIndex(current_cluster_index, "wdcgq_gz"));

    // page 3
    ui->comboBox->clear();
    int moduleTotal = dataPool->getDoubleByIndex(current_cluster_index, "_MODULE_NUMBER_");
    for (int i = 1; i <= moduleTotal; i++){
        int moduleId = dataPool->getDoubleByIndex(current_cluster_index, i, "_ID_");
        ui->comboBox->addItem(QString::fromUtf8("模块").append(QString::number(i)).append(QString::fromUtf8("(")).append(QString::number(moduleId)).append(QString::fromUtf8(")")));
    }    

    // page 4
    ui->tableWidget_2->clear();
    int maxEventInOnePage = configure->getMaxEventInOnePage();
    int currentPage = configure->getEventCurrentPageNum();
    int initIndexInCurrentPage = (currentPage - 1) * maxEventInOnePage;
    int j = 0;
    for (int i = initIndexInCurrentPage; i < configure->getEventTotal(); i++){
        if (j == maxEventInOnePage){
            break;
        }
        ui->tableWidget_2->setItem(j,0,new QTableWidgetItem(dataPool->events.at(i)->date.toString(QString("yyyy-MM-dd hh:mm:ss"))));
        QTableWidgetItem* item = new QTableWidgetItem(dataPool->events.at(i)->message);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_2->setItem(j,1,item);
        ui->tableWidget_2->setItem(j,2,new QTableWidgetItem(QString::fromUtf8("  查看  ")));
        ui->text_p4_pagenum->setText(QString::number(currentPage));
        j++;
    }

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
