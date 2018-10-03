#include "msp.h"

void replace();

char Reg4;
char Reg5;
char Reg6;
char Reg7;

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	// R5 = 9x95
	Reg5 = 0x05;
	// R6 = 0x06
	Reg6 = 0x06;
	// R7 = 0x07
	Reg7 = 0x07;

	replace();

	while(1);

}

void replace()
{
    Reg4 = Reg7;
    Reg7 = Reg6;
    Reg6 = Reg5;
    Reg5 = Reg4;
}
