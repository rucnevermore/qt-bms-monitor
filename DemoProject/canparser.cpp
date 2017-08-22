#include "canparser.h"

CanParser::CanParser()
{

}

// parse the can data and store into the data pool according to the can id.
void CanParser::parse(CanFrame frame){
    int id = frame.can_id;
    if (id == CAN_ID_1){
        log(QString("receive can package ").append(QString::number(CAN_ID_1)));
    }else{
        log(QString("receive unknown can package ").append(QString::number(CAN_ID_1)));
    }
}
