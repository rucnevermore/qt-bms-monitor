#ifndef CANPARSER_H
#define CANPARSER_H
#include <qobject.h>
#include "structs.h"
#include "datapool.h"
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>

#define MOTOROLA 1
#define INTEL 2
#define CAN_MODE MOTOROLA

class CanParser : public QObject
{
        Q_OBJECT
public:
    CanParser();
    void parse(can_frame frame);
signals:
    void log(QString str);
private:
    DataPool* dataPool;

    void debugFrame(can_frame frame);
    double maskAndGetValue(char* source, long long mask, int mask_offset, double resol, double offset, bool multiBytes);
    double visit8BytesArray(char* source, long long mask, int mask_offset, string name, double resol, double offset, bool multiBytes);
    double visit8BytesArray(int clusterId, char* source, long long mask, int mask_offset, string name, double resol, double offset, bool multiBytes);
    double visit8BytesArray(int clusterId, int moduleId, char* source, long long mask, int mask_offset, string name, double resol, double offset, bool multiBytes);

    void processBAMS_INF1(can_frame frame);
    void processBAMS_INF2(can_frame frame);
    void processBAMS_INF3(can_frame frame);
    void processBAMS_INF4(can_frame frame);
    void processBMS_INF(can_frame frame);
    void processBMS_INF1(can_frame frame);
    void processFAU_ALA(can_frame frame);
    void processBMS_INF2(can_frame frame);
    void processNOM_PAR(can_frame frame);
    void processMUN_ID(can_frame frame);
    void processMNOM_PAR(can_frame frame);
    void processMVT_PAR1(can_frame frame);
    void processMVT_PAR2(can_frame frame);
    void processCELL_V(int index, can_frame frame);
    void processCELL_T1(can_frame frame);
    void processCELL_T2(can_frame frame);
    void processPCBA(int index, can_frame frame);
};

#define CAN_ID_1 0x01020304

#define CLUSTER_ID_MASK 0x000000FF
#define CAN_ID_MASK 0x1FFFFF00

#define BAMS_INF1   0x18013100
#define BAMS_INF2   0x18023100
#define BAMS_INF3   0x18033100
#define BAMS_INF4   0x18043100

#define BMS_INF   0x18003000
#define BMS_INF1  0x18013000
#define FAU_ALA   0x18023000
#define BMS_INF2  0x18033000
#define NOM_PAR   0x18043000
#define MUN_ID    0x18053000
#define MNOM_PAR  0x18103000
#define MVT_PAR1  0x18113000
#define MVT_PAR2  0x18123000

#define CELL_V1    0x18203000
#define CELL_V2    0x18213000
#define CELL_V3    0x18223000
#define CELL_V4    0x18233000
#define CELL_V5    0x18243000
#define CELL_V6    0x18253000
#define CELL_V7    0x18263000
#define CELL_V8    0x18273000
#define CELL_V9    0x18283000
#define CELL_V10   0x18293000
#define CELL_V11   0x182A3000
#define CELL_V12   0x182B3000
#define CELL_V13   0x182C3000
#define CELL_V14   0x182D3000
#define CELL_V15   0x182E3000
#define CELL_V16   0x182F3000

#define CELL_T1    0x18603000
#define CELL_T2    0x18613000

#define PCBA_6803_1      0x18623000
#define PCBA_6803_2      0x18633000
#define PCBA_6803_3      0x18643000
#define PCBA_6803_4      0x18653000

#define BCU_CTRL      0x18E03000

#endif // CANPARSER_H
