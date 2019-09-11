#ifndef __DELAYMS_H__
#define __DELAYMS_H__
#include "MyDefine.h"
#ifdef T12  // 定义12倍的速度才有用 只有在这个速度下才准确
//计算 _ms = (ms *FOSC/12/ 1000 - 6)/8;
#if FOSC == 22118400UL
#define _1ms    230 
#define _5ms    1151
#define _10ms   2093
#define _50ms   11519
#define _100ms  23039
#elif FOSC == 12000000UL
#define _1ms    124
#define _5ms    624
#define _10ms  1249 
#define _50ms  6249
#define _100ms 12499
#elif FOSC == 11059200UL
#define _1ms    114 
#define _5ms    575
#define _10ms   1151
#define _50ms   5759
#define _100ms  11519 
#elif FOSC == 8000000UL
#define _1ms    82
#define _5ms    415
#define _10ms  832 
#define _50ms  4165
#define _100ms 8332
#endif	

void DelayMs(uint16 ); //使用的是6+n*8个周期
void DelayNHMs(u8 n);
#endif
#endif
