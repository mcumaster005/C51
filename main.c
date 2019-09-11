#include "MyDefine.h"
#include "uart.h"
#include "autodown.h"
#include "timer2.h"
#include "delayms.h"
void Delay500ms();
//led1
#define LED1  P22
#define LED1ON  LED1 = 0;
#define LED1OFF LED1 = 1;
//led2
#define LED2  P21
#define LED2ON  LED2 = 0;
#define LED2OFF LED2 = 1;


#define OutPutHigh(x, y) (x) |= 1 << (y)
#define OutPutLow(x, y)  (x) &= ~(1 << (y))
void main(void)
{	
	UartInit(9600);
//	Timer2Init();
//	Timer2Start();
	while(1)
	{
//		P2 |= 1 << 0;
//		LED1ON;
		OutPutHigh(P2, 0);
		DelayNHMs(2);
		OutPutLow(P2, 0);
		Delay500ms();
		LED1OFF;
//		Delay500ms();
		DelayNHMs(2);
//		LED2ON;
//		Delay500ms();
//		LED2OFF;
//		Delay500ms();
	}
}


void serial() interrupt 4
{
	if(RI)
	{
		RI = 0;
		AutoDown();
	}
	//else{
	//	TI = 0;
	//}
}


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





//=======================Delay============================
void Delay500ms()		//@22.1184MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

