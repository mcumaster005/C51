#ifndef  __MYDEFINE_H__
#define  __MYDEFINE_H__
#include "stc89c52.h"
//定义u数据类型 简写
#define u8 unsigned char
#define u16 unsigned int
#define u32 unsigned long
//满足有的定义  少用
#define  i8   signed char
#define  i16   signed int
#define  i32   signed long
//定义比较普通的数据类型  常用
#define uint8 unsigned char
#define uint16 unsigned int
#define uint32 unsigned long
//普通的定义 类型  有用的
#define uchar unsigned char
#define uint  unsigned int


// NOP () macro support
extern void _nop_ (void);
#define nop() _nop_()

//#define FOSC 11059200UL
//#define FOSC 12000000UL
#define FOSC 22118400UL


//为了AutoDown而进行的定义 在不同的芯片里面地址不一样
#define STC89C52
//为了在传统的芯片里面使用自定义的定时器
#define T12

//
#define SetPinIn(x, y) (x) |= 1 << (y)
#define SetPortIn(x) x = 0xFF
#endif  

