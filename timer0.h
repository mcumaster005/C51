/*****************************************************************
设置TMOD来进行配置 
模式0   13位 少用
模式1 是一个16位的定时器，寄存器TH0和TL0即为T0初值的高8位和低8位，
定时时间为：（65536-T1的初值）*振荡周期*12
模式2 是一个可以自动装载的8位定时器，那么模式二计数的最长时间即为（257-T1的初值）*振荡周期*12
模式3 少用

使用的寄存器  EA ET0 TCON控制模式  、计数、外部的控制  
需要用TR0=1开启定时器,要修改中断！！！

//*****************************************************************
*/
#ifndef	__TIMER0_H__
#define __TIMER0_H__
#include "MyDefine.h"	

extern uint8 Timer0Count;
void SetThTl();
void Timer0Init(uint8 mod);
void Timer0Start(void);
void Timer0Stop(void);
#endif