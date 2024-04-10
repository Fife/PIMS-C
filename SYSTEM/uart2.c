/*
 * File:   uart2.c
 * Author: Fife
 *
 * Created on April 3, 2024, 10:23 PM
 */


//PIMSC/PIMSE UART 2
#include "uart2.h"
#include <xc.h>

void UART2_Init(void){
    // PIMS C/PIMS E UART pin out
    // PIMSE TX -> RP7/RB7 -> PIC RX
    // PIMSE RX -> RP6/RB6 -> PIC TX 
    
    // Disable ADC on UART pins
    _ANSELB7 = 0;
    _ANSELB6 = 0;
    
    //Set Pins as Digital I/O
    _TRISB7 = 1;    //UART RX
    _TRISB6 = 0;    //UART TX
    
    // Configure Input Functions (Table 11-10)
    RPINR19bits.U2RXR = 7;
     
    // Configure Output Functions (Table 11-11)
    RPOR3bits.RP6R = 5;
    
    // UART 2 Control Registers 
    U2MODE = 0;                 // Clear Control Register
    U2MODEbits.UEN = 0b00;      // No Flow Control
    U2MODEbits.BRGH = 0;        // Standard Speed Mode
    U2MODEbits.PDSEL = 0b00;    // 8 Bit data no parity
    U2MODEbits.RTSMD = 0b1;     // Simplex Mode
    U2MODEbits.PDSEL0= 0;

    
    //UART 2 Baud Rate Generator 
    U2BRG = (CLOCK_PeripheralFrequencyGet()/(U2BAUD*16UL)) - 1;
    
    //Enable UART Interrupt for DMA Controller 0
    //Interrupt when char is received
    
    IPC2bits.U1RXIP = 4; // interrupt priority level for receive
    IFS0bits.U1RXIF = 0; // clear receive interrupt flag
    IEC0bits.U1RXIE = 1; // UART receiver interrupt enabled
    
    U2STAbits.URXISEL = 0b01;   //Interrupt on byte transfer
    
    // 2. Enable the UART2.
    U2MODEbits.UARTEN = 1;      // Enable UART 2
    U2STAbits.UTXEN = 1;        // Enable UART 2 TX
    

}

char UART2_rx(void){
    while(!(U2STAbits.URXDA == 1));

    if ((U2STAbits.OERR == 1))
    {
        U2STAbits.OERR = 0;
    }
    return U2RXREG;
}

int UART2_available(void){
    return ((!U2STAbits.UTXBF) && U2STAbits.UTXEN );
}

void UART2_tx(char input){
    while (U2STAbits.UTXBF);
    U2TXREG = input;
}

void UART2_txbuff(char *input, int size){
    for (int i=0; i<size; i++){
        while (U1STAbits.UTXBF);
        U1TXREG = input[i];
    }
}
