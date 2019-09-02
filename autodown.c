#include "autodown.h"
//xdata u8 AutoDownCount;
//221184 延时 500ms
void DownDelay(void)
{
	unsigned char i, j, k;
	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);

}


void AutoDown()
{
    uint8 k = 0;
    k = SBUF;
    if(k == AUTODOWNPARAM)
    {        
		DownDelay();
		#ifdef STC89C52
        	ISP_CONTR = 0x60;
		k = 0;
    }  
    //下面是a00a来启动下载功能
//	if(SBUF == 0xa0)
//	{
//		AutoDownCount ++;
//		return;
//	}
//	if(AutoDownCount > 0)
//	{
//		if(SBUF == 0x0a)
//		{
//			DownDelay();
//			ISP_CONTR = 0x60;
//		}
//		AutoDownCount = 0;
//	}
}
