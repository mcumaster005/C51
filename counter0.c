#include "counter0.h"

void Counter0Init(uint8 mod)
{
	TMOD|= 0x04; 				//counter 0
	TMOD |= mod;
	TH0 = 0xff;//(65536-50000)/256;  //自己计算
	TL0 = (65533 % 256);//(65536-50000)%256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;

}
//void Counter0() interrupt 1
//{
//	TH0 = 10;
//}
