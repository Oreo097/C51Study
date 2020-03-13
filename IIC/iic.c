#include "iic.h"

//delay function
void delay(unsigned int time)
{
    uchar i;
    for (i = 0; i < (time - 2); i++)
    {
        _nop_();
    }
}

//init iic function
int init_iic(unsigned int sda_pin, unsigned int scl_pin)
{
    sda_pin = 1;
    scl_pin = 1;
    delya(10); //wait more than 4us
    sda_pin = 0;
    delay(10); //wait more than 4us

    scl_pin = 0; //control scl pin let iic bus unable
    delay(10);   //wait more than 4us
}

//check ack signal
int check_ack()
{
    sda_pin = 1;
    scl_pin = 1;
    delay(10);
    if (sda_pin == 0)
    {
        scl_pin = 0;
        return 1;
    }
    else
    {
        scl_pin = 0;
        return 0;
    }
}

//send signal
int write_iic(unsigned char byte)
{
    uchar i;
    for (i = 0; i < 8; i++)
    {
        sda_pin = byte & 0x80;
        delay(4);
        scl_pin = 1;
        delay(10);
        scl_pin = 0;
        delay(10);
        byte <<= 1;
    }
    if (check_ack == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//receive signal
char read_iic()
{
    char byte;
    unsigned char i;
    byte = 0X00;
    sda_pin = 1;
    for (i = 0; i < 8; i++)
    {
        scl_pin = 0;
        delay(4);
        scl_pin = 1;
        delay(4);
        byte <<= 1;
        if (sda_pin == 1)
        {
            byte += 1;
        }
    }
    scl_pin = 0;
    return byte;
}

//send ack signal
void ack()
{
    sda_pin = 0;
    scl_pin = 1;
    delay(10);
    scl_pin = 0;
}

//send noack signal
void noack()
{
    sda_pin = 1;
    scl_pin = 1;
    delay(10);
    scl_pin = 0;
}
