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

#define false 0
#define true  1

//YCAPISHARED_EXPORT

    int BeepOn(int bStatus);

    int SetLed(int bStatus);

    int SetWDog(int interval);
    int StartWDog();
    int FeedWDog();
    int StopWDog();

    int WriteEEPROM(int addr,char *buf);
    int ReadEEPROM(int addr,char *buf);

    int SetIO( unsigned char level , unsigned char ioNum);
    int SetIoMode(int ioNum,int ioMode ,int triggeredMode);
    unsigned char GetIO(unsigned char * level ,unsigned char ioNum);
    int GetIoBlockMode( unsigned char * level,unsigned char ioNum);

    int UpdateLogo(char * logoPath);

    int CopyDir(char * dstDir,char * srcDir);

    int TouchBeepCtrl(int flag);
    int GetTouchBeep();

    void SetBacklightOn(int BakLevel);
    int SetBacklightTimeOut(int timeValue);
    void SetDefaultBackLightLevel(int level);
    int EnableBackLightAuto(int flag);
    int GetEnableBackLightAuto();
    int    GetDefaultBackLightLevel();
    int    GetBacklightTimeOut();
    void SendStartBackligtSignal();
    void SendStopBackligtSignal();

    int GetStartProgressBarStatus();
    int SetStartProgressBarStatus(int bStatus);

    int SetNetWork(int num,int isDhcp,char * ip,char * subnetmask,char * gateway,char *dns);
    int GetNetWorkCfg(int num,int *isDhcp,char * ip,char * subnetmask,char * gateway,char *dns,char *macAddr);
    int SetMacAddr(int num,char * macAddr);
    int GetMacAddr(int num,char * macAddr);

    int SetAutoStartPath(char * path);
    int GetAutoStartPath(char * path);
    int RunAutoStartPath();

    int ReadTouchEvent();

    int GetPassword(char * pwd);
    int SetPassword(char * pwd);


    int TouchDisable(int flag);

    int ReadAdc(int channel,double *data);

    void OpenCan(int baudrate);
    void WriteCan(int can_id,unsigned char *data,unsigned char  dlc);
    void ReadCan(unsigned int  *can_id,unsigned char  *can_dlc,unsigned char *data);
    void CloseCan();

    int Connect3G() ;
    int Disconnect3G();




#endif // YCAPI_H
