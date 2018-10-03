#include "msp.h"

volatile int *memlock;
volatile int *synclock;

void lock(volatile int *l);
void unlock(volatile int *l);

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	*memlock = 0;
	*synclock = 0;

	//Bitfield instructions
	// R6 = 0xA12F
	char Reg6 = 0x0A12F;
	//Clear bits 8 - 20 by anding them with 0
	Reg6 & 0xFF000FF;

	//Extract bits 4 - 12 from Reg6
	char Reg7 = 0x8000FF0 & Reg6;

	//Packing and unpacking instructions
	// R8 = 0xAABB
	char Reg8 = 0xAABB;
	// R9 = 0xCCDD
	char Reg9 = 0xCCD;

	// R10 = 0xCCDDAABB
	char operandOne = 0x0000FFFF & Reg8;
	char operandTwo = 0x0000FFFF & Reg9;
	operandTwo = operandTwo << 0xF;
	char Reg10 =  operandOne & operandTwo;

	// R11 = 0xFFFFCCDD
	char Reg11 = Reg10 >> 0xF;

	// Misc instructions
	// NOP does nothing
	//Lock a memory register
	lock(*memlock);
	lock(*synclock);

	char Reg12 = ASPR;

	unlock(*memlock);
	unlock(*synclock);
}

void lock(volatile int *l)
{
    while(*l) {}
    *l = 1;
}

void unlock(volatile int *l)
{
    *l = 0;
}
