/*
 * File:   interrupts.c
 * Author: Fife
 *
 * Created on April 6, 2024, 12:53 PM
 */

#include "interrupts.h"
#include "../buffers.h"

void enableInterrupts(void)
{
    /* Enable level 1-7 interrupts */
    /* No restoring of previous CPU IPL state performed here */
    INTCON2bits.GIE = 1;
    return;
}

void disableInterrupts(void)
{
    /* Disable level 1-7 interrupts */
    /* No saving of current CPU IPL setting performed here */
    INTCON2bits.GIE = 0;
    return;
}
void initInterrupts(void)
{
    /* Interrupt nesting enabled here */
    INTCON1bits.NSTDIS = 0;

    /* Set UART2 interrupt priority to 6 (level 7 is highest) */
    IPC7bits.U2RXIP = 6;

    /* Enable UART 2 Interrupts*/
    IEC1bits.U2RXIE= 1;
    
    //Reset the UART 2 Interrupt Flag
    IFS1bits.U2RXIF=0;
    
    /*
    T1CON = 0x00; //Stops the Timer1 and reset control reg.
    TMR1 = 0x00; //Clear contents of the timer register
    PR1 = 50000;   //Load the Period register with the value 80 (10uS)
    IPC0bits.T1IP = 0x01; //Setup Timer1 interrupt for desired priority level
    // (This example assigns level 1 priority)
    IFS0bits.T1IF = 0; //Clear the Timer1 interrupt status flag
    IEC0bits.T1IE = 1; //Enable Timer1 interrupts
    */
    
    return;
}

void __attribute__((interrupt,auto_psv)) _U2RXInterrupt(void)              
{  
    //While there are characters to RX, write them to the shell buffer
    while (U2STAbits.URXDA){
        char input = U2RXREG;
        WritePEShellBuffer(input);
    }
    
    //Clear Interrupt Flag
    IFS1bits.U2RXIF = 0;
    return;
}
