#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QString>
#include <QSettings>

class Configure
{
public:
    static Configure* newInstance();
    int getClusterNum();
    int getMaxEventNum();
    void setClusterIndex(int clusterId);
    int getClusterIndex();
    int getMaxEventInOnePage();
    int getEventCurrentPageNum();
    void setEventCurrentPageNum(int num);
    int getCurrentModuleSelected(int clusterIndex);
    void setCurrentModuleSelected(int clusterIndex, int moduleIndex);

    QString print();

    int GLOBAL_DATA_NUM;
    int CLUSTER_NUM;
    int CLUSTER_DATA_NUM;
    int MODULE_NUM;
    int MODULE_DATA_NUM;
    int MAX_EVENT_NUM;
    int MAX_EVENT_IN_ONE_PAGE;
private:
    Configure();
    ~Configure();
    static Configure* instance_;
//    int max_event_number;
    int* current_module_selected;
//    int max_num_in_one_page;
    int current_event_page;
    int current_cluster_index;
};

//global level
#define g_xtdy 1
#define g_xtdl 2
#define g_xtsoc 3
#define g_xtzt 4
#define g_zgdy 5
#define g_zddy 6
#define g_zgwd 7
#define g_zdwd 8
#define g_zgdy_zh 9
#define g_zgdy_mkh 10
#define g_zgdy_wz 11
#define g_zddy_zh 12
#define g_zddy_mkh 13
#define g_zddy_wz 14
#define g_zgsoc 15
#define g_zgsoc_xh 16
#define g_zgwd_zh 17
#define g_zgwd_mkh 18
#define g_zgwd_wz 19
#define g_zdwd_zh 20
#define g_zdwd_mkh 21
#define g_zdwd_wz 22
#define g_zdsoc 23
#define g_zdsoc_xh 24
//cluster level
#define zdy 1
#define zdl 2
#define soc 3
#define ver 4
#define xtgz 5
#define xtyxzt 6
#define dtzgdy 7
#define dtzddy 8
#define dtzgwd 9
#define dtzdwd 10
#define soh 11
#define jyzz 12
#define dtgy_bj 13
#define dtqy_bj 14
#define xtgy_bj 15
#define xtqy_bj 16
#define xtyc_bj 17
#define xtwc_bj 18
#define xtgw_bj 19
#define xtdw_bj 20
#define fdgl_bj 21
#define cdgl_bj 22
#define socg_bj 23
#define socd_bj 24
#define xtjy_bj 25
#define jzgw_bj 26
#define sjzj_gz 27
#define yzctx_gz 28
#define ybmutx_gz 29
#define ycdjtx_gz 30
#define jr_gz 31
#define fs_gz 32
#define zzzl_gz 33
#define zfzl_gz 34
#define yc_gz 35
#define dycgq_gz 36
#define wdcgq_gz 37
#define zgdywz 38
#define zddywz 39
#define zgwdwz 40
#define zdwdwz 41
#define zgdyxh 42
#define zddyxh 43
#define zgwdxh 44
#define zdwdxh 45
#define xdczbh 46
#define xdcxtmkzsl 47
#define xdccdcs 48
#define dccdzt 49
#define xdcsrscgl 50
#define smzq 51
#define wybhxx 52
#define zdyxcddl 53
#define zdyxfddl 54
//module level
#define mkndtdcs 1
#define mknwdcyds 2
#define mksoc 3
#define mkcdcs 4
#define mkzdl 5
#define mkzdy 6
#define mknzgwd 7
#define zgwdcydh 8
#define mknzdwd 9
#define zdwdcydh 10
#define nbtxgz 11
#define mkndtzgdy 12
#define dyzgdth 13
#define mkndtzddy 14
#define dyzddth 15
#define dcdy_1 16
#define dcdy_2 17
#define dcdy_3 18
#define dcdy_4 19
#define dcdy_5 20
#define dcdy_6 21
#define dcdy_7 22
#define dcdy_8 23
#define dcdy_9 24
#define dcdy_10 25
#define dcdy_11 26
#define dcdy_12 27
#define dcdy_13 28
#define dcdy_14 29
#define dcdy_15 30
#define dcdy_16 31
#define dcdy_17 32
#define dcdy_18 33
#define dcdy_19 34
#define dcdy_20 35
#define dcdy_21 36
#define dcdy_22 37
#define dcdy_23 38
#define dcdy_24 39
#define dcdy_25 40
#define dcdy_26 41
#define dcdy_27 42
#define dcdy_28 43
#define dcdy_29 44
#define dcdy_30 45
#define dcdy_31 46
#define dcdy_32 47
#define dcdy_33 48
#define dcdy_34 49
#define dcdy_35 50
#define dcdy_36 51
#define dcdy_37 52
#define dcdy_38 53
#define dcdy_39 54
#define dcdy_40 55
#define dcdy_41 56
#define dcdy_42 57
#define dcdy_43 58
#define dcdy_44 59
#define dcdy_45 60
#define dcdy_46 61
#define dcdy_47 62
#define dcdy_48 63
#define cywd_1 64
#define cywd_2 65
#define cywd_3 66
#define cywd_4 67
#define cywd_5 68
#define cywd_6 69
#define cywd_7 70
#define cywd_8 71
#define cywd_9 72
#define cywd_10 73
#define cywd_11 74
#define cywd_12 75
#define zjzcywd 76
#define fjzcywd 77
#define d_6803_1_pcba1wd 78
#define d_6803_1_pcba2wd 79
#define d_6803_1_pcba3wd 80
#define d_6803_1_pcba4wd 81
#define d_6803_2_pcba1wd 82
#define d_6803_2_pcba2wd 83
#define d_6803_2_pcba3wd 84
#define d_6803_2_pcba4wd 85
#define d_6803_3_pcba1wd 86
#define d_6803_3_pcba2wd 87
#define d_6803_3_pcba3wd 88
#define d_6803_3_pcba4wd 89
#define d_6803_4_pcba1wd 90
#define d_6803_4_pcba2wd 91
#define d_6803_4_pcba3wd 92
#define d_6803_4_pcba4wd 93


#endif // CONFIGURE_H
