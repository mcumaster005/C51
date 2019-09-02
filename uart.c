#include "uart.h"
//串口初始化  参数波特率
void UartInit(u16 BAUD)
{
	//定时器1设置
	TMOD |= 0x20;	                // 定时器1方式2       8位自动重新加载 使用或不改变其他的数据
	TH1 = TL1 = -(FOSC/12/32/BAUD); //th1 tl1
	TR1 = 1;                          // 定时器1 开启
	//模式设置   允许接收
	SM0=0;		 //
	SM1=1;		 //模式1
	REN=1;		 //接收使能
	//中断设置 开启串口中断 开启总中断
	ES=1;		 //串口中断允许
	PS= 1;       //串口优先级设置
	EA=1;		 //interrupt enable
}
//输出字符  参数字符
char putchar (char c)  
{
	//关闭串口中断
	ES = 0;
	SBUF = c ;
	while(!TI);     //TI=0 表示没有发送完成
	TI = 0;         //复位中断
	ES = 1;         //回复串口中断
	return (c);
}

//输出字符串      参数要输出的字符串
void PutString(unsigned char *Str)
{
    while(*Str != '\0'){
        putchar(*Str++);
    }
} 
//输出数据       实际还是输出字符
//参数1 最大255 参数2 进制  
void PutData(u16 value, u16 jinzi)
{
	u8 bai = 0, shi = 0, ge = 0;
	if(jinzi == 10)
	{
		bai = value / 100;
		shi = value % 100 / 10;
		ge = value % 10;
		bai += '0';
		shi += '0';
		ge  += '0';
		putchar(bai);
		putchar(shi);
		putchar(ge);
		putchar('\r');
		putchar('\n');
	}else if(jinzi == 16)
	{
		shi = value / 16;
		ge = value % 16;
		
		if(ge < 10)
			ge	+= 0x30;
		else if(ge == 10)
			ge = 'A';
		else if(ge == 11)
			ge = 'B';
		else if(ge == 12)
			ge = 'C';
		else if(ge == 13)
			ge = 'D';
		else if(ge == 14)
			ge = 'E';
		else if(ge == 15)
			ge = 'F';
			
		if(shi < 10)
			shi += 0x30;
		else if(shi == 10)
			shi = 'A';
		else if(shi == 11)
			shi = 'B';
		else if(shi == 12)
			shi = 'C';
		else if(shi == 13)
			shi = 'D';
		else if(shi == 14)
			shi = 'E';
		else if(shi == 15)
			shi = 'F';

		
		putchar('0');
		putchar('X');
		putchar(shi);
		putchar(ge);
	}	
}

//输出浮点数 
//设定为小数3位 整数3位
void PutFloat(float value)
{
	u32 temp = value * 1000;
	u16 inter  = temp / 1000;
	u16 xiaosu = 123456 % 1000;
	PutData(inter, 10);
	putchar('.');
	PutData(xiaosu, 10);
}
/*
void serial() interrupt 4
{
	if(RI)
	{
		RI = 0;
	}
	//else{
	//	TI = 0;
	//}
}
*/
