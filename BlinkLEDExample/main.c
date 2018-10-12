#include "msp.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P1SEL0 &= ~BIT4;                    //Select GPIO for P1.4
	P1SEL1 &= ~BIT4;
	P2SEL0 &= ~BIT1;                    //Select GPIO for P2.1
	P2SEL1 &= ~BIT1;
	P1DIR &= ~BIT4;                     //Make P1.4 an input
	P1REN |= BIT4;                      //Connect P1.4 to a pullup resistor
	P1OUT |= BIT4;
	P2DIR |= BIT1;                      //Make P2.1 an output

	while(1)                            //Forever
	{
	    while((P1IN & BIT4) == 0);      //Do nothing if the P4.1 button is not pressed
	    __delay_cycles(300000);         //Once button is pressed wait 10ms (eliminates bounce)
	    while((P1IN & BIT4) == 0);      //Do nothing if the P1.4 button is pressed
	    __delay_cycles(300000);         //Once button is released wait 10ms
	    P2OUT ^= BIT1;                  // Toggle the LED on P2.1
	}
}
