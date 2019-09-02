/*
STC单片机串口自动下载功能实现
应该在使用之前进行串口初始化
要求在中断中使用
下载关键的字符为0x1f
*/
#ifndef __AUTODOWN_H__
#define __AUTODOWN_H__

#include "MyDefine.h"
#include "uart.h"

#define AUTODOWNPARAM  0x1F
void AutoDown();

#endif
 
