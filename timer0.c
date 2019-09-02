/*
定时器0源文件
包括中断程序
中断程序可以复制到主程序里面
*/
#include "timer0.h"
uint8 Timer0Count = 0;
//设定TH TL函数       默认10ms
void SetThTl()
{
	TL0 = 0x00;		//设置定时初值
	TH0 = 0xB8;		//设置定时初值
}
//共有4种模式 分别从0-3  模式1 是16位定时器

void Timer0Init(uint8 mod)
{
	
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= mod;       //设定模式	
	SetThTl();
	//开启定时器中断 总中断
	EA = 1;
	ET0 = 1;
}

void Timer0Start(void)
{
    TR0 = 1;
}
void Timer0Stop(void)
{
    TR0 = 0;
}
/*

void timer0() interrupt 1
{	
	Timer0Stop();

	SetThTl();
	Timer0Count++;
	if(100 == Timer0Count){
        Timer0Count = 0;
        LED1 ^= 0x01; 
	}
	
	Timer0Start();
}

*/
