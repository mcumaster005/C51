#include "timer1.h"
uint8 Timer1Count = 0;
void Timer1Init(void)
{
	TMOD|=0x10;   //模式1默认用的
	TH1 = 0x3c;//(65536-50000)/256;  //自己计算
	TL1 = 0xb0;//(65536-50000)%256;
	ET1=1;
	EA = 1;
}
void Timer1Start(void)
{
    TR1 = 1;
}
void Timer1Stop(void)
{
    TR1 = 0;
}
/*
void timer1() interrupt 3
{
	TH1 = 0x3c;//(65536-50000)/256;  //自己计算
	TL1 = 0xb0;//(65536-50000)%256;
	Timer1Count++;
}
*/