#ifndef YCAPI_H
#define YCAPI_H

//#include "ycapi_global.h"
//#include <QtCore/qglobal.h>
#include <linux/input.h>

#if defined(YCAPI_LIBRARY)
#  define YCAPISHARED_EXPORT Q_DECL_EXPORT
#else
#  define YCAPISHARED_EXPORT Q_DECL_IMPORT
#endif

#define IO_POLLING_MODE 0
#define IO_INTR_MODE    1

#define IO_INTR_LOW_LEVEL_TRIGGERED    0
#define IO_INTR_HIGH_LEVEL_TRIGGERED   1
#define IO_INTR_FALLING_EDGE_TRIGGERED 2
#define IO_INTR_RISING_EDGE_TRIGGERED  3
#define IO_INTR_BOTH_EDGE_TRIGGERED    4

//YCAPISHARED_EXPORT
class  Ycapi {
public:
    Ycapi();

    bool BeepOn(bool bStatus);

    bool SetLed(bool bStatus);

    bool SetWDog(int interval);
    bool StartWDog();
    bool FeedWDog();
    bool StopWDog();

    bool WriteEEPROM(int addr,char *buf);
    bool ReadEEPROM(int addr,char *buf);

    bool SetIO( unsigned char level , unsigned char ioNum);
    bool SetIoMode(int ioNum,int ioMode ,int triggeredMode);
    unsigned char GetIO(unsigned char * level ,unsigned char ioNum);
    bool GetIoBlockMode( unsigned char * level,unsigned char ioNum);

    bool UpdateLogo(char * logoPath);

    bool CopyDir(char * dstDir,char * srcDir);

    bool TouchBeepCtrl(bool flag);
    bool GetTouchBeep();

    void SetBacklightOn(int BakLevel);
    bool SetBacklightTimeOut(int timeValue);
    void SetDefaultBackLightLevel(int level);
    bool EnableBackLightAuto(bool flag);
    bool GetEnableBackLightAuto();
    int    GetDefaultBackLightLevel();
    int    GetBacklightTimeOut();
    void SendStartBackligtSignal();
    void SendStopBackligtSignal();

    bool GetStartProgressBarStatus();
    bool SetStartProgressBarStatus(bool bStatus);

    bool SetNetWork(int num,bool isDhcp,char * ip,char * subnetmask,char * gateway,char *dns);
    bool GetNetWorkCfg(int num,bool *isDhcp,char * ip,char * subnetmask,char * gateway,char *dns,char *macAddr);
    bool SetMacAddr(int num,char * macAddr);
    bool GetMacAddr(int num,char * macAddr);
     void RandomSetMacAddr();

    bool SetAutoStartPath(char * path);
    bool GetAutoStartPath(char * path);
    bool RunAutoStartPath();

    bool ReadTouchEvent();

    bool GetPassword(char * pwd);
    bool SetPassword(char * pwd);

    bool CopyNetWork(int num,char * dstPath,char  * srcPath);
    bool CopyBakParam(char * dstPath,char  * srcPath);
   bool  CopyAutoStartPath(char * dstPath,char  * srcPath);
    bool CopyTouchBeepCtrl(char * dstPath,char  * srcPath);
    bool CopyProgressBar(char * dstPath,char  * srcPath);

    bool LoadSystemParam(char * path);
    bool BackSystemParam(char * path);
    bool RestoreSystemParam();

     bool BootLoadSystemParam();

    bool TouchDisable(bool flag);

    bool ReadAdc(int channel,double *data);

    int    GetWifiName(char wifiname[512][512]);
    void InitWifi();
    void CfgWifiIpGw(char * ip,char * gateway);
    void CfgWifiSsidPwd(char * ssid,char * pwd);
    void ConnectWifi();
    void DisconnectWifi();
    bool GetWifiSsidPwd(char * ssid,char * pwd);
    bool GetWifiIpGw(char * ip,char *gateway);

    bool CopySetWifi(char * dstPath,char  * srcPath);

    void OpenCan(int baudrate);
    void WriteCan(int can_id,unsigned char *data,unsigned char  dlc);
    void ReadCan(unsigned int  *can_id,unsigned char  *can_dlc,unsigned char *data);
    void CloseCan();

     bool Connect3G() ;
     bool Disconnect3G();
};

#endif // YCAPI_H
