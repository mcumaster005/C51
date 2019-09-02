//*****************************************************************
/*
串口有4种模式
模式0    同步移位寄存器
模式1    10位 波特率可变
模式2    11位 波特率不可变
模式3    11位 波特率可变

常用的是模式1  
模式2 模式3多用在多机通讯 

使用的寄存器 SCON SM0 SM1 SM2 REN TB8 RB8 TI RI
PCON SMOD 波特率加倍
EA ES
使用定时器1 作为波特率发生器 
*/

//*****************************************************************
#ifndef __SER_H__
#define __SER_H__
#include "MyDefine.h"


void UartInit(uint16);
//输出共计4个函数   分别为
// 输出字符
//输出字符串
//输出数据  
//输出浮点数
char putchar (char c);
void PutString(unsigned char *str);
void PutData(u16 value, u16 jinzi);
void PutFloat(float value);


#endif
