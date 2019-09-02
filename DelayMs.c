#include "DelayMs.h"
void DelayMs(uint16 n) 
{
	while(--n);
}
void DelayNHMs(u8 n)
{
	u8 i = 0;
	for(; i < n; i++)
	{
		DelayMs(_100ms);
	}
} 
