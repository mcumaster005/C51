/*****************************************************************
定时器2    自动重装 16位定时器
精确可以常用，
要修改 中断
要重新设置定时器值
*****************************************************************/
#ifndef	__TIMER2_H__
#define __TIMER2_H__
#include "MyDefine.h"
extern uint8 Timer2Count;
void Timer2Init(void);
void Timer2Start(void);
void Timer2Stop(void);

#endif