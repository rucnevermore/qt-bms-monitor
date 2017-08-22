#ifndef STRUCTS_H
#define STRUCTS_H

struct can_frame {
        unsigned int     can_id;  /* 32 bit CAN_ID + EFF/RTR/ERR flags */
        unsigned char    can_dlc; /* data length code: 0 .. 8 */
        unsigned char    data[8];
};

typedef struct can_frame CanFrame;

#endif // STRUCTS_H
