#include "msp.h"


void SysTick_Init(void)
{
    SYSTICK_STCSR = 0;          // 1) disable SysTick during setup
    SYSTICK_STRVR = 0x00FFFFFF; // 1) maximum reload value
    SYSTICK_STCVR = 0;          // 2) any write to current clears it
    SYSTICK_STCSR = 0x00000005; // 4) enable SysTick with core clock
}

/**
 * The delay parameter is in units of the 48 MHz clock. (20.83ns)
 * You can change the system clock frequency in the system_msp432p401r.c file
 */
void SysTick_Wait(uint32_t delay)
{
    SYSTICK_STRVR = delay - 1;              // number of counts to wait
    SYSTICK_STCVR = 0;                      // any value written to counter clears
    while((SYSTICK_STCSR&0x00010000)==0)    // wait for count flag
    {
    }

}

/**
 * delay with 10ms units
 */
void SysTick_Wait10ms(uint32_t delay)
{
 uint32_t i;
 for(i=0; i<delay; i++){
   SysTick_Wait(480000);  // wait 10ms
 }


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
}
