/*
 * File:   uart4.c
 * Author: Fife
 *
 * Created on April 18, 2024, 9:24 AM
 */

#include "uart4.h"

void UART4_Init(void){
    // Disable ADC on UART pins
    _ANSELB8 = 0;
    _ANSELB9 = 0;
    
    //Set Pins as Digital I/O
    _TRISB8 = 1;
    _TRISB9 = 0;
    
    RPINR27bits.U4RXR = 8;
    RPOR4bits.RP9R = 24;
    
   // UART 3 Control Registers 
    U4MODEbits.UEN = 0b00;      // No Flow Control
    U4MODEbits.BRGH = 0b1;      // Standard Speed Mode
    U4MODEbits.PDSEL = 0b00;    // 8 Bit data no parity
    U4MODEbits.RTSMD = 0b1;     // Simplex Mode
    
    //UART 1 Baud Rate Generator 
    U4BRG = (CLOCK_PeripheralFrequencyGet()/(U4BAUD*4UL)) - 1;
    
    // Enable the UART1.
    U4MODEbits.UARTEN = 1;      // Enable UART 1
    U4STAbits.UTXEN = 1;        // Enable UART 1 Transmission
}

char UART4_rx(void){
    while(!(U4STAbits.URXDA == 1));

    if ((U4STAbits.OERR == 1))
    {
        U4STAbits.OERR = 0;
    }
    return U4RXREG;
}

int UART4_available(void){
    return ((!U4STAbits.UTXBF) && U4STAbits.UTXEN);
}

void UART4_tx(char input){
    while (U4STAbits.UTXBF);
    U4TXREG = input;
}

void UART4_txbuff(char *input, int size){
    for (int i=0; i<size; i++){
        while (U4STAbits.UTXBF);
        U4TXREG = input[i];
    }
}

void UART4_txJSON(char *input, int size){
    for (int i=0; i<size; i++){
        if(input[i] != '\0' && input[i] > 33 && input[i] < 127){
            while (U1STAbits.UTXBF);
            U4TXREG = input[i];
        }
        else if(input[i] == '\n' || input[i] == ' '){
            while (U1STAbits.UTXBF);
            U4TXREG = input[i];
        }
    }
}