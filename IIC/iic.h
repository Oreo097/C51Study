/*
code by Oreo097
time 2020 03 13
*/

#ifndef __IIC_H__
#define __IIC_H__

#ifndef __INTRINS_H__
#include "intrins.h"
#endif

#ifndef sda_pin
sbit sda_pin=P0^0;
sbit scl_pin=P0^1;
#endif

//init iic function
int init_iic(unsigned int sda_pin,unsigned int scl_pin);

//send signal
int write_iic(unsigned char byte);

//receive signal
char read_iic();

//handle ack signal
void handle_ack();

//handle noack signal
void handle_noack();

//check ack signal
int check_ack();

//send ack signal
void ack();

//send noack signal
void noack();

//delay function
void delay(unsigned int time);



#endif