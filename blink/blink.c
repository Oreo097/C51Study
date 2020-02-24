#include <reg52.h>

sbit p0^1 LED;

void delay()
{
}

void main()
{
    int a=0;
    LED=0;
    while(true){
        for (;a<1000;a++);
        LED=-LED;
    }
}