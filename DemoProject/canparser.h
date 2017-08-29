#ifndef CANPARSER_H
#define CANPARSER_H
#include <qobject.h>
#include "structs.h"
#include "datapool.h"
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>

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

    double maskAndGetValue(char* source, long long mask, int mask_offset, double resol, double offset);
    double visit8BytesArray(char* source, long long mask, int mask_offset, string name, double resol, double offset);
    double visit8BytesArray(int moduleId, char* source, long long mask, int mask_offset, string name, double resol, double offset);

    void processBMS_INF(can_frame frame);
    void processFAU_ALA(can_frame frame);
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

#define CAN_ID_MASK 0x1FFFFFF0

#define BMS_INF   0x18F212F0
#define FAU_ALA   0x18F214F0
#define NOM_PAR   0x181817F0
#define MUN_ID    0x185717F0
#define MNOM_PAR  0x181D17F0
#define MVT_PAR1  0x181E17F0
#define MVT_PAR2  0x181F17F0

#define CELL_V1    0x182417F0
#define CELL_V2    0x182517F0
#define CELL_V3    0x182617F0
#define CELL_V4    0x182717F0
#define CELL_V5    0x182817F0
#define CELL_V6    0x182917F0
#define CELL_V7    0x182A17F0
#define CELL_V8    0x182B17F0
#define CELL_V9    0x182C17F0
#define CELL_V10   0x182D17F0
#define CELL_V11   0x182E17F0
#define CELL_V12   0x182F17F0
#define CELL_V13   0x183017F0
#define CELL_V14   0x183117F0
#define CELL_V15   0x183217F0
#define CELL_V16   0x183317F0

#define CELL_T1    0x184A17F0
#define CELL_T2    0x184B17F0

#define PCBA_6803_1      0x184C17F0
#define PCBA_6803_2      0x184D17F0
#define PCBA_6803_3      0x184E17F0
#define PCBA_6803_4      0x184F17F0


#endif // CANPARSER_H
