/*
 * File:   uart3.c
 * Author: Fife
 *
 * Created on April 11, 2024, 5:16 PM
 */


#include "uart3.h"

void UART3_Init(void){
    TRISFbits.TRISF4 = 0;
    TRISFbits.TRISF5 = 1;
    
    RPINR17bits.U3RXR = 17;
    RPOR5bits.RP10R = 22;
    
   // UART 3 Control Registers 
    U3MODEbits.UEN = 0b00;      // No Flow Control
    U3MODEbits.BRGH = 0b1;      // Standard Speed Mode
    U3MODEbits.PDSEL = 0b00;    // 8 Bit data no parity
    U3MODEbits.RTSMD = 0b1;     // Simplex Mode
    
    //UART 1 Baud Rate Generator 
    U3BRG = (CLOCK_PeripheralFrequencyGet()/(U3BAUD*4UL)) - 1;
    
    // Enable the UART1.
    U3MODEbits.UARTEN = 1;      // Enable UART 1
    U3STAbits.UTXEN = 1;        // Enable UART 1 Transmission
}

char UART3_rx(void){
    while(!(U3STAbits.URXDA == 1));

    if ((U3STAbits.OERR == 1))
    {
        U3STAbits.OERR = 0;
    }
    return U3RXREG;
}

int UART3_available(void){
    return ((!U3STAbits.UTXBF) && U3STAbits.UTXEN);
}

void UART3_tx(char input){
    while (U3STAbits.UTXBF);
    U3TXREG = input;
}

void UART3_txbuff(char *input, int size){
    for (int i=0; i<size; i++){
        while (U3STAbits.UTXBF);
        U3TXREG = input[i];
    }
}
