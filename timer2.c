#include "timer2.h"
uint8 Timer2Count = 0;
//每次使用要自己设置！！！
static void SetTimer2ThTl()
{
	RCAP2L = TL2 = 0x00;            //初始化 计数器寄存器  已经重载 寄存器
    RCAP2H = TH2 = 0xB8;            //
}
//默认是10ms

void Timer2Init(void)
{
	SetTimer2ThTl();
    ET2 = 1;                        //开启定时中断2
    EA = 1;                         //开启全局中断
}
void Timer2Start(void)
{    
	TR2 = 1;						//timer2 start running
}
void Timer2Stop(void)
{
    TR2 = 0;
}

/*
void Timer2Isr() interrupt 5
{
	TF2 = 0;
	Timer2Stop();
	Timer2Count++;
	if(100 == Timer2Count){
        Timer2Count = 0;
        LED1 ^= 0x01;
	}	
	Timer2Start();
}

*/


