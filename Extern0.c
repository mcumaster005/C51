#include "extern0.h"
void Extern0Init() //
{
	IT0 = 1;      //0低电平有效 1下降沿有效
	EX0 = 1;      //开启外部中断
	EA  = 1;
}
//可以复制到主程序 
/*
void extern0() interrupt 0
{
	
}
*/
