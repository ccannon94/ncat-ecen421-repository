#include "msp.h"

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

    //Bitfield instructions
    // R6 = 0xA12F
	__asm(" MOV R6, #0A12Fh");
	// R6 = 0x2F
    __asm(" BFC R6, #8, #12");
    // R7 = 0x2
    __asm(" SBFX R7, R6, #4, #8");

    //Packing and unpacking instructions
    // R8 = 0xAABB
    __asm(" MOV R8, #0AABBh");
    // R9 = 0xCCDD
    __asm(" MOV R9, #0CCDh");

    // R9 = 0xCCDDAABB
    __asm(" PKHBT R10, R8, R9, LSL #16");
    //R10 = 0xFFFFCCDD
    __asm(" SXTH R11, R10, ROR #16");

    //Misc instructions
    __asm(" NOP \n"
          " DMB \n"
          " DSB \n"
          " MRS R12, APSR \n"
          " NOP \n");
}
