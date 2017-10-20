#include "widget.h"
#include <ctime>
#include "alerteventlistener.h"
#include <QListWidget>
#include <QFile>
#include <QTextStream>

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
//    dataPool->store("max_event_number", 100);
//    dataPool->store("cluster_number", 10);

    // de-serialize the event list.
    deserializeEvent();

    configure = Configure::newInstance();
    configure->setEventCurrentPageNum(1);
//    configure->setMaxEventInOnePage(10);
    log(configure->print());
    // start the display thread.
    log(QString::fromStdString("start display thread..."));
    displayThread = new DisplayThread();
    connect(displayThread,SIGNAL(display()),this,SLOT(display()));
    connect(displayThread,SIGNAL(log(QString)),this,SLOT(log(QString)));
    displayThread->start();

    // start the collection thread.
    log(QString::fromStdString("start collection thread..."));
    int collectionThreadNumber = 1;
    for (int i = 0; i < collectionThreadNumber; i++){
        CollectionThread* cThread = new CollectionThread();
        connect(cThread,SIGNAL(log(QString)),this,SLOT(log(QString)));
        cThread->start();
    }
//    collectionThread = new CollectionThread();
//    connect(collectionThread,SIGNAL(log(QString)),this,SLOT(log(QString)));
//    collectionThread->start();

    // start the parse thread.
//    log(QString::fromStdString("start parse thread..."));
//    int parseThreadNumber = 50;
//    for (int i = 0; i < parseThreadNumber; i++){
//        ParseThread* pThread = new ParseThread();
//        connect(pThread,SIGNAL(log(QString)),this,SLOT(log(QString)));
//        pThread->start();
//    }

//    parseThread = new ParseThread();
//    connect(parseThread,SIGNAL(log(QString)),this,SLOT(log(QString)));
//    parseThread->start();

    connect(ui->pbutton_left,SIGNAL(clicked()),this,SLOT(decreaseCluster()));
    connect(ui->pbutton_right,SIGNAL(clicked()),this,SLOT(increaseCluster()));

    connect(ui->pbutton_left_2,SIGNAL(clicked()),this,SLOT(decreaseCluster()));
    connect(ui->pbutton_right_2,SIGNAL(clicked()),this,SLOT(increaseCluster()));

    connect(ui->pbutton_up,SIGNAL(clicked()),this,SLOT(lastPage()));
    connect(ui->pbutton_down,SIGNAL(clicked()),this,SLOT(nextPage()));

    connect(ui->comboBox, SIGNAL(activated(const QString &)), this, SLOT(onIndexChanged(const QString &)));

    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(display()));

    configure->setClusterIndex(1);
}

void Widget::deserializeEvent(){
    QFile f("./serialization.txt");
    f.open(QIODevice::ReadWrite);
    QDataStream ds(&f);
    QDateTime date;
    QString message;
    while(!ds.atEnd())
    {
        ds >> date;
        ds >> message;
        AlertEvent* event = new AlertEvent(date, message);
        dataPool->events->append(event);
    }
    f.close();
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
        configure->setClusterIndex(configure->getClusterNum() - 1);
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
    int eventTotal = dataPool->getEventTotal();
    int maxEventInOnePage = configure->getMaxEventInOnePage();

    if ((currentPage * maxEventInOnePage) >= eventTotal){
        return;
    }else{
        configure->setEventCurrentPageNum(currentPage + 1);
        this->display();
    }
}

void Widget::onIndexChanged(const QString &){
    int currentClusterIndex = configure->getClusterIndex();
    configure->setCurrentModuleSelected(currentClusterIndex, ui->comboBox->currentIndex());
}


// set alert value and change color accordingly.
void setAlertText(QTextBrowser* textBrowser, double value){
    if (value == 0){
//        textBrowser->setText(QString::fromUtf8("正常"));
        textBrowser->setStyleSheet("border-image: url(/yctek/app/images/green.png);border: 0px;");
    }else if (value == 1){
//        textBrowser->setText(QString::fromUtf8("一级"));
        textBrowser->setStyleSheet("border-image: url(/yctek/app/images/yellow.png);border: 0px;");
    }else if (value == 2){
//        textBrowser->setText(QString::fromUtf8("二级"));
        textBrowser->setStyleSheet("border-image: url(/yctek/app/images/pink.png);border: 0px;");
    }else if (value == 3){
//        textBrowser->setText(QString::fromUtf8("三级"));
        textBrowser->setStyleSheet("border-image: url(/yctek/app/images/red.png);border: 0px;");
    }else{
//        textBrowser->setText(QString::fromUtf8("未知"));
    }
}

// set alert value and change color accordingly.
void setAlertText2(QTextBrowser* textBrowser, double value){
    if (value == 0){
//        textBrowser->setText(QString::fromUtf8("正常"));
        textBrowser->setStyleSheet("border-image: url(/yctek/app/images/green.png);border: 0px;");
    }else if (value == 1){
//        textBrowser->setText(QString::fromUtf8("一级"));
        textBrowser->setStyleSheet("border-image: url(/yctek/app/images/red.png);border: 0px;");
    }else{
//        textBrowser->setText(QString::fromUtf8("未知"));
    }
}

//void Widget::setAlertItems(QMap<string, QTableWidgetItem*> alertItemMap){
//    this->alertItemMap = alertItemMap;
//}

void Widget::display()
{
//    return;
    int currentPage = ui->tabWidget->currentIndex();
    // page 1

//    // 总电压
//    ui->lcd_zdy->display(dataPool->getDouble("g_xtdy"));
//    // 总电流
//    ui->lcd_zdl->display(dataPool->getDouble("g_xtdl"));
//    // SOC
//    ui->lcd_soc->display(dataPool->getDouble("g_xtsoc"));
//    ui->pBar_soc->setValue(dataPool->getDouble("g_xtsoc"));
//    // 最大压差
//    ui->lcd_zdyc->display(dataPool->getDouble("zdyc"));
//    // 最大温差
//    ui->lcd_zdwc->display(dataPool->getDouble("zdwc"));
//    // 最大电压
//    ui->lcd_zddy->display(dataPool->getDouble("g_zgdy"));
//    ui->lcd_zddy_loc_1->display(dataPool->getDouble("g_zgdy_zh"));
//    ui->lcd_zddy_loc_2->display(dataPool->getDouble("g_zgdy_mkh"));
//    ui->lcd_zddy_loc_3->display(dataPool->getDouble("g_zgdy_wz"));
//    // 最小电压
//    ui->lcd_zxdy->display(dataPool->getDouble("g_zgdy"));
//    ui->lcd_zxdy_loc_1->display(dataPool->getDouble("g_zddy_zh"));
//    ui->lcd_zxdy_loc_2->display(dataPool->getDouble("g_zddy_mkh"));
//    ui->lcd_zxdy_loc_3->display(dataPool->getDouble("g_zddy_wz"));
//    // 最高温度
//    ui->lcd_zgwd->display(dataPool->getDouble("g_zgwd"));
//    ui->lcd_zgwd_loc_1->display(dataPool->getDouble("g_zgwd_zh"));
//    ui->lcd_zgwd_loc_2->display(dataPool->getDouble("g_zgwd_mkh"));
//    ui->lcd_zgwd_loc_3->display(dataPool->getDouble("g_zgwd_wz"));
//    // 最低温度
//    ui->lcd_zdwd->display(dataPool->getDouble("g_zdwd"));
//    ui->lcd_zdwd_loc_1->display(dataPool->getDouble("g_zdwd_zh"));
//    ui->lcd_zdwd_loc_2->display(dataPool->getDouble("g_zdwd_mkh"));
//    ui->lcd_zdwd_loc_3->display(dataPool->getDouble("g_zdwd_wz"));
//
//    // 平均电压
//    // 系统状态
//    ui->text_value_xtzt->setText(QString::number(dataPool->getDouble("g_xtzt")));

    int currentClusterIndex = configure->getClusterIndex();
    // page 2
    if (currentPage == 0){
        // 最高电压
        ui->lcd_p2_zgdy->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, dtzgdy), 'f', 2));
        ui->lcd_p2_zgdy_loc_1->display(dataPool->getDoubleByIndex(currentClusterIndex, zgdyxh));
        ui->lcd_p2_zgdy_loc_2->display(dataPool->getDoubleByIndex(currentClusterIndex, zgdywz));
        // 最低电压
        ui->lcd_p2_zddy->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, dtzddy), 'f', 2));
        ui->lcd_p2_zddy_loc_1->display(dataPool->getDoubleByIndex(currentClusterIndex, zddyxh));
        ui->lcd_p2_zddy_loc_2->display(dataPool->getDoubleByIndex(currentClusterIndex, zddywz));
        // 最高温度
        ui->lcd_p2_zgwd->display(dataPool->getDoubleByIndex(currentClusterIndex, dtzgwd));
        ui->lcd_p2_zgwd_loc_1->display(dataPool->getDoubleByIndex(currentClusterIndex, zgwdxh));
        ui->lcd_p2_zgwd_loc_2->display(dataPool->getDoubleByIndex(currentClusterIndex, zgwdwz));
        // 最低温度
        ui->lcd_p2_zdwd->display(dataPool->getDoubleByIndex(currentClusterIndex, dtzdwd));
        ui->lcd_p2_zdwd_loc_1->display(dataPool->getDoubleByIndex(currentClusterIndex, zdwdxh));
        ui->lcd_p2_zdwd_loc_2->display(dataPool->getDoubleByIndex(currentClusterIndex, zdwdwz));

        // 系统总压
        ui->lcd_p2_xtzy->display(dataPool->getDoubleByIndex(currentClusterIndex, zdy));
        // 系统状态
        int value = dataPool->getDoubleByIndex(currentClusterIndex, xtyxzt);
        if (value == 0){
            ui->text_p2_xtzt->setText(QString::fromUtf8("正常"));
    //    }else if (value == 1){
    //        ui->text_p2_xtzt->setText(QString::fromUtf8("直流充电"));
    //    }else if (value == 2){
    //        ui->text_p2_xtzt->setText(QString::fromUtf8("交流充电"));
    //    }else if (value == 3){
    //        ui->text_p2_xtzt->setText(QString::fromUtf8("放电"));
        }else{
            ui->text_p2_xtzt->setText(QString::fromUtf8("故障"));
        }
        // 电流
        ui->lcd_p2_dl->display(dataPool->getDoubleByIndex(currentClusterIndex, zdl));
        // SOC
        ui->lcd_p2_soc->display(dataPool->getDoubleByIndex(currentClusterIndex, soc));
        // SOH
        ui->lcd_p2_soh->display(dataPool->getDoubleByIndex(currentClusterIndex, soh));
        // 故障状态
        value = dataPool->getDoubleByIndex(currentClusterIndex, xtgz);
        if (value == 0){
            ui->text_p2_gzzt->setText(QString::fromUtf8("正常"));
    //    }else if (value == 1){
    //        ui->text_p2_gzzt->setText(QString::fromUtf8("一级"));
    //    }else if (value == 2){
    //        ui->text_p2_gzzt->setText(QString::fromUtf8("二级"));
    //    }else if (value == 3){
    //        ui->text_p2_gzzt->setText(QString::fromUtf8("三级"));
        }else{
            ui->text_p2_gzzt->setText(QString::fromUtf8("故障"));
        }
        // 功率
        ui->lcd_p2_gl->display(dataPool->getDoubleByIndex(currentClusterIndex, xdcsrscgl));
        // 子模数量
        ui->lcd_p2_zmsl->display(dataPool->getDoubleByIndex(currentClusterIndex, xdcxtmkzsl));
        // 充电次数
        ui->lcd_p2_cdcs->display(dataPool->getDoubleByIndex(currentClusterIndex, xdccdcs));
        // 电池状态
        value = dataPool->getDoubleByIndex(currentClusterIndex, dccdzt);
        if (value == 1){
            ui->text_p2_dczt->setText(QString::fromUtf8("充电"));
        }else if (value == 0){
            ui->text_p2_dczt->setText(QString::fromUtf8("放电"));
        }else{
            ui->text_p2_dczt->setText(QString::fromUtf8("未知"));
        }
        // 绝缘阻值
        ui->lcd_p2_jyzz->display(dataPool->getDoubleByIndex(currentClusterIndex, jyzz));
        // 生命周期
        ui->lcd_p2_smzq->display(dataPool->getDoubleByIndex(currentClusterIndex, smzq));
        // 软件版本号
        ui->lcd_p2_rjbbh->display(dataPool->getDoubleByIndex(currentClusterIndex, ver));

        // 单体过压报警
        setAlertText(ui->text_p2_bj_dtgy, dataPool->getDoubleByIndex(currentClusterIndex, dtgy_bj));
        // 单体欠压报警
        setAlertText(ui->text_p2_bj_dtqy, dataPool->getDoubleByIndex(currentClusterIndex, dtqy_bj));
        // 系统过压报警
        setAlertText(ui->text_p2_bj_xtgy, dataPool->getDoubleByIndex(currentClusterIndex, xtgy_bj));
        // 系统欠压报警
        setAlertText(ui->text_p2_bj_xtqy, dataPool->getDoubleByIndex(currentClusterIndex, xtqy_bj));
        // 系统压差报警
        setAlertText(ui->text_p2_bj_xtyc, dataPool->getDoubleByIndex(currentClusterIndex, xtyc_bj));
        // 系统温差报警
        setAlertText(ui->text_p2_bj_xtwc, dataPool->getDoubleByIndex(currentClusterIndex, xtwc_bj));
        // 系统过温报警
        setAlertText(ui->text_p2_bj_xtgw, dataPool->getDoubleByIndex(currentClusterIndex, xtgw_bj));
        // 系统低温报警
        setAlertText(ui->text_p2_bj_xtdw, dataPool->getDoubleByIndex(currentClusterIndex, xtdw_bj));
        // 放电过流报警
        setAlertText(ui->text_p2_bj_fdgl, dataPool->getDoubleByIndex(currentClusterIndex, fdgl_bj));
        // 充电过流报警
        setAlertText(ui->text_p2_bj_cdgl, dataPool->getDoubleByIndex(currentClusterIndex, cdgl_bj));
        // SOC高报警
        setAlertText(ui->text_p2_bj_socg, dataPool->getDoubleByIndex(currentClusterIndex, socg_bj));
        // SOC低报警
        setAlertText(ui->text_p2_bj_socd, dataPool->getDoubleByIndex(currentClusterIndex, socd_bj));
        // 系统绝缘报警
        setAlertText(ui->text_p2_bj_xtjy, dataPool->getDoubleByIndex(currentClusterIndex, xtjy_bj));
        // 极柱高温报警
        setAlertText(ui->text_p2_bj_jzgw, dataPool->getDoubleByIndex(currentClusterIndex, jzgw_bj));

        // 数据自检故障
        setAlertText2(ui->text_p2_gz_sjzj, dataPool->getDoubleByIndex(currentClusterIndex, sjzj_gz));
        // 与整车通信故障
        setAlertText2(ui->text_p2_gz_yzctx, dataPool->getDoubleByIndex(currentClusterIndex, yzctx_gz));
        // 与bmu通信故障
        setAlertText2(ui->text_p2_gz_ybmutx, dataPool->getDoubleByIndex(currentClusterIndex, ybmutx_gz));
        // 与充电机通信故障
        setAlertText2(ui->text_p2_gz_ycdjtx, dataPool->getDoubleByIndex(currentClusterIndex, ycdjtx_gz));
        // 加热故障
        setAlertText2(ui->text_p2_gz_jr, dataPool->getDoubleByIndex(currentClusterIndex, jr_gz));
        // 风扇故障
        setAlertText2(ui->text_p2_gz_fs, dataPool->getDoubleByIndex(currentClusterIndex, fs_gz));
        // 主正粘连故障
        setAlertText2(ui->text_p2_gz_zzzl, dataPool->getDoubleByIndex(currentClusterIndex, zzzl_gz));
        // 主负粘连故障
        setAlertText2(ui->text_p2_gz_zfzl, dataPool->getDoubleByIndex(currentClusterIndex, zfzl_gz));
        // 预充故障
        setAlertText2(ui->text_p2_gz_yc, dataPool->getDoubleByIndex(currentClusterIndex, yc_gz));
        // 电压传感器故障
        setAlertText2(ui->text_p2_gz_dycgq, dataPool->getDoubleByIndex(currentClusterIndex, dycgq_gz));
        // 温度传感器故障
        setAlertText2(ui->text_p2_gz_wdcgq, dataPool->getDoubleByIndex(currentClusterIndex, wdcgq_gz));
    }

    // page 3
    if (currentPage == 1){
        ui->comboBox->clear();
        int moduleTotal = configure->MODULE_NUM;
    //    for (int i = 0; i < moduleTotal; i++){
    //        ComboboxItem* item = new ComboboxItem(this);
    //        int moduleId = dataPool->getDoubleByIndex(currentClusterIndex, i, "_ID_");
    //        item->setLabelContent(QString::fromUtf8("模块").append(QString::number(i+1)).append(QString::fromUtf8("(")).append(QString::number(moduleId)).append(QString::fromUtf8(")")));
    //        connect(item, SIGNAL(chooseAccount(const QString&)), this, SLOT(onIndexChanged(const QString&)));
    //        QListWidgetItem* widgetItem = new QListWidgetItem(m_listWidget);
    //        m_listWidget->setItemWidget(widgetItem, item);
    //    }
        QIcon itemIcon ("/yctek/app/images/item.png");
        for (int i = 1; i <= moduleTotal; i++){
            int moduleId = i;
            ui->comboBox->addItem(itemIcon, QString::fromUtf8("模块").append(QString::number(i)).append(QString::fromUtf8("(")).append(QString::number(moduleId)).append(QString::fromUtf8(")")));
        }
        int currentModuleSelected = configure->getCurrentModuleSelected(currentClusterIndex);
        ui->comboBox->setCurrentIndex(currentModuleSelected);
        currentModuleSelected = currentModuleSelected + 1;

        // 模块总压
        ui->lcd_p3_mkzy->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, mkzdy));
        // 单体串数
        ui->lcd_p3_dtcs->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, mkndtdcs));
        // 温度个数
        ui->lcd_p3_wdgs->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, mknwdcyds));

        // 最高温度
        ui->lcd_p3_zgwd->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, mknzgwd));
        ui->lcd_p3_zgwd_loc_2->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, zgwdcydh));
        // 最低温度
        ui->lcd_p3_zdwd->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, mknzdwd));
        ui->lcd_p3_zdwd_loc_2->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, zdwdcydh));
        // 最大电压
        ui->lcd_p3_zddy->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, mkndtzgdy), 'f', 3));
        ui->lcd_p3_zddy_loc_2->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dyzgdth));
        // 最小电压
        ui->lcd_p3_zxdy->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, mkndtzddy), 'f', 3));
        ui->lcd_p3_zxdy_loc_2->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dyzddth));

        // 温度1-8
        ui->lcd_p3_wd_1->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, cywd_1));
        ui->lcd_p3_wd_2->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, cywd_2));
        ui->lcd_p3_wd_3->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, cywd_3));
        ui->lcd_p3_wd_4->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, cywd_4));
        ui->lcd_p3_wd_5->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, cywd_5));
        ui->lcd_p3_wd_6->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, cywd_6));
        ui->lcd_p3_wd_7->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, cywd_7));
        ui->lcd_p3_wd_8->display(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, cywd_8));
        // 电压1-24
        ui->lcd_p3_dy_1->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_1), 'f', 3));
        ui->lcd_p3_dy_2->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_2), 'f', 3));
        ui->lcd_p3_dy_3->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_3), 'f', 3));
        ui->lcd_p3_dy_4->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_4), 'f', 3));
        ui->lcd_p3_dy_5->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_5), 'f', 3));
        ui->lcd_p3_dy_6->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_6), 'f', 3));
        ui->lcd_p3_dy_7->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_7), 'f', 3));
        ui->lcd_p3_dy_8->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_8), 'f', 3));
        ui->lcd_p3_dy_9->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_9), 'f', 3));
        ui->lcd_p3_dy_10->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_10), 'f', 3));
        ui->lcd_p3_dy_11->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_11), 'f', 3));
        ui->lcd_p3_dy_12->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_12), 'f', 3));
        ui->lcd_p3_dy_13->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_13), 'f', 3));
        ui->lcd_p3_dy_14->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_14), 'f', 3));
        ui->lcd_p3_dy_15->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_15), 'f', 3));
        ui->lcd_p3_dy_16->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_16), 'f', 3));
        ui->lcd_p3_dy_17->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_17), 'f', 3));
        ui->lcd_p3_dy_18->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_18), 'f', 3));
        ui->lcd_p3_dy_19->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_19), 'f', 3));
        ui->lcd_p3_dy_20->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_20), 'f', 3));
        ui->lcd_p3_dy_21->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_21), 'f', 3));
        ui->lcd_p3_dy_22->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_22), 'f', 3));
        ui->lcd_p3_dy_23->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_23), 'f', 3));
        ui->lcd_p3_dy_24->display(QString::number(dataPool->getDoubleByIndex(currentClusterIndex, currentModuleSelected, dcdy_24), 'f', 3));
    }

    if (currentPage == 2){
        // page 4
        ui->tableWidget_2->clearContents();
        int maxEventInOnePage = configure->getMaxEventInOnePage();
        int currentPage = configure->getEventCurrentPageNum();
        int initIndexInCurrentPage = (currentPage - 1) * maxEventInOnePage;
        int j = 0;
        for (int i = initIndexInCurrentPage; i < dataPool->getEventTotal(); i++){
            if (j == maxEventInOnePage){
                break;
            }
            ui->tableWidget_2->setItem(j,0,new QTableWidgetItem(dataPool->events->at(i)->date.toString(QString("yyyy-MM-dd hh:mm:ss"))));
            QTableWidgetItem* item = new QTableWidgetItem(dataPool->events->at(i)->message);
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_2->setItem(j,1,item);
    //        ui->tableWidget_2->setItem(j,2,new QTableWidgetItem(QString::fromUtf8("  查看  ")));
    //        ui->text_p4_pagenum->setAlignment(Qt::AlignCenter);
            ui->text_p4_pagenum->setPlainText(QString::number(currentPage));
            j++;
        }
    }
}
void Widget::log(QString str)
{
//    ui->text_log->append(str);
    QFile f("/yctek/app/log.txt");
    f.open(QIODevice::Append);
    QTextStream in(&f);
    in << QDateTime::currentDateTime().toString(QString("yyyy-MM-dd hh:mm:ss"))<<"\t" << str << "\n";
    f.close();
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
