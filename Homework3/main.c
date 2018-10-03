#include "msp.h"

unsigned short answer;

void twosComp(unsigned short);

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Assign a test value to take the 2's compliment of
	unsigned short num = 7;

	//Find the two's compliment of the number
	twosComp(num);
}

void twosComp(unsigned short arg)
{
    //Flag is 0 if checked bit is 0, 1 if check bit is 1
    int flag = 0;

    int i;
    //Iterate through each bit in the number
    for(i = 0; i < 16; i++)
    {
        //If a previous bit was found to be one, do this part
        if(flag == 1)
        {
            //Invert the current bit
            arg = (arg ^ (1 << i));
        }
        //If a 1 is detected, set flag
        if(1 == (arg & (1 << i)))
        {
            flag = 1;
        }
    }
    answer = arg;
}
