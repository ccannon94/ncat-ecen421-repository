#include "msp.h"


unsigned short twosComp(unsigned short);

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	unsigned short num = 7;
	unsigned short twosCompNum = twosComp(num);
}

unsigned short twosComp(unsigned short arg)
{
    int flag = 0;
    int i;
    for(i = 0; i < 16; i++)
    {
        if(flag == 1)
        {
            arg = (arg ^ (1 << i));
            flag = 0;
        }
        if(1 == (arg & (1 << i)))
        {
            flag = 1;
        }
    }
    return arg;
}
