#ifndef CANPARSER_H
#define CANPARSER_H
#include <qobject.h>
#include "structs.h"
#include "datapool.h"

class CanParser : public QObject
{
        Q_OBJECT
public:
    CanParser();
    void parse(CanFrame frame);
signals:
    void log(QString str);

private:
    DataPool* dataPool;

    double visit8BytesArray(QString source, long long mask, int mask_offset, string name, double resol, double offset);

    void processBMS_INF(CanFrame frame);


};

#define CAN_ID_1 0x01020304

#define BMS_INF   0x18F212F3
#define FAU_ALA   0x18F214F3
#define NOM_PAR   0x181817F3
#define MUN_ID    0x185717F3
#define MNOM_PAR  0x181D17F3
#define MVT_PAR1  0x181E17F3
#define MVT_PAR2  0x181F17F3

#define CELL_V1    0x182417F3
#define CELL_V2    0x182517F3
#define CELL_V3    0x182617F3
#define CELL_V4    0x182717F3
#define CELL_V5    0x182817F3
#define CELL_V6    0x182917F3
#define CELL_V7    0x182A17F3
#define CELL_V8    0x182B17F3
#define CELL_V9    0x182C17F3
#define CELL_V10   0x182D17F3
#define CELL_V11   0x182E17F3
#define CELL_V12   0x182F17F3
#define CELL_V13   0x183017F3
#define CELL_V14   0x183117F3
#define CELL_V15   0x183217F3
#define CELL_V16   0x183317F3

#define CELL_T    0x184A17F3

#define PCBA_6803_1      0x184C17F3
#define PCBA_6803_2      0x184D17F3
#define PCBA_6803_3      0x184E17F3
#define PCBA_6803_4      0x184F17F3


#endif // CANPARSER_H
