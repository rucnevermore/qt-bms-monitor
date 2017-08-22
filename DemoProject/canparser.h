#ifndef CANPARSER_H
#define CANPARSER_H
#include <qobject.h>
#include "structs.h"

class CanParser : public QObject
{
        Q_OBJECT
public:
    CanParser();
    void parse(CanFrame frame);
signals:
    void log(QString str);
};

#define CAN_ID_1 0x01020304

#endif // CANPARSER_H
