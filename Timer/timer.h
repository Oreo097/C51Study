/*
这个文件主要是设置各种延迟
包含延迟ms和延迟us以及延迟s
Oreo编辑于2020/02/23
用于STC89C52
*/
/*
51单片机内部两个寄存器T0、T1（80c52有3个）
TMOD  工作模式配置寄存器
TCON  控制寄存器
*/

#ifndef __REG52_H__
#include <reg52.h>
#endif
#ifndef uint
#define uint unsigned int
#endif




//延迟微秒
void delay_us(uint us);

//延迟毫秒
void delay_ms(uint ms);

//延迟秒
void delay_s(uint s);

