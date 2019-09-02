#ifndef __DELAYUS_H__
#define __DELAYUS_H__
#include "mydefine.h"

//一定要阅读头文件的说明 需要先在程序里面把要进
//行计数的数值计算出来然后才看带如delay_us函数
//_us = us * 1.0 * FOSC / 169 /12/ 10000/ 1.2 - 1.33
#if FOSC == 22118400UL
#define _10us  7
#define _100us  89
#elif FOSC == 12000000UL
#define _10us  3 
#define _100us 48
#elif FOSC == 11059200UL
#define _10us  3 
#define _100us 44
#endif
void DelayUs(uint8 n);
#endif