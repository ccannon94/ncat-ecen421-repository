#include "msp.h"

int d = 0;

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	int a = 1;
	float b = -255.25;
	char c = 'c';

	d = d+1;

	while(1);
}
