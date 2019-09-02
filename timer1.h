/*****************************************************************
主要作为串口使用
*****************************************************************/
#ifndef	__TIMER1_H__
#define __TIMER1_H__
#include "MyDefine.h"
extern u8 Timer1Count;
void Timer1Init(void);
void Timer1Start(void);
void Timer1Stop(void);

#endif