/*
这个文件主要是计时器设置
包含延迟ms和延迟us以及延迟s
Oreo编辑于2020/02/23
用于STC89C52
*/
/*
51单片机内部两个寄存器T0、T1（80c52有3个）
TMOD  89H     工作模式配置寄存器
GATE C/T M1 M0 GATE C/T M1 M0
TCON  88H~8FH 控制寄存器
TF1 TR1 TF0 TR0 IE1 IT1 IE0 IT0
88H 89H 8AH 8BH 8CH 8DH 8EH 8FH
TH0 TL0
高8位 低8位（2^8=256）
*/
/*
计时器中断级别为1
*/


#ifndef __REG52_H__
#include <reg52.h>
#endif
#ifndef uint
#define uint unsigned int
#endif


//使用T1进行延迟
void timer_inter(int us)


