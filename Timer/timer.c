#include "timer.h"

void timer_inter(uint us){
    //配置TMOD寄存器地址为89H，无法直接寻址
    TMOD=0x01;
    //配置起始位置寄存器
    TH1=220;
    TL1=0;
    //开关总中断
    EA=0; 
    //配置TCON 地址为88H~8FH，可寻址，单独配置
    TF1=0;
    TR1=0;
}