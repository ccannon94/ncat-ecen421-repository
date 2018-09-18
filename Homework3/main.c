#include "msp.h"


unsigned short twosComp(unsigned short);

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Assign a test value to take the 2's compliment of
	unsigned short num = 7;

	//Returns the two's compliment of the number
	unsigned short twosCompNum = twosComp(num);
}

unsigned short twosComp(unsigned short arg)
{
    //Flag is 0 if checked bit is 0, 1 if check bit is 1
    int flag = 0;

    int i;
    //Iterate through each bit in the number
    for(i = 0; i < 16; i++)
    {
        //If the previous bit was found to be one, do this part
        if(flag == 1)
        {
            //Invert the current bit
            arg = (arg ^ (1 << i));
            //Set flag back to 0
            flag = 0;
        }
        //If a 1 is detected, set flag
        if(1 == (arg & (1 << i)))
        {
            flag = 1;
        }
    }
    return arg;
}
