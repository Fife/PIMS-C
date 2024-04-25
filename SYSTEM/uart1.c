//WIZ S2E Parameters UART 1
#include "uart1.h"
#include <xc.h>

void UART1_Init(void){
    // PIMS C WAN/Debug Interface Pin out 
    // WANTX -> RP18/RB5 (Pin 11) ->PIC RX
    // WANRX -> RP28/RB4 (Pin 12) ->PIC TX
    
    // Disable ADC on UART pins
    _ANSELB5 = 0;
    _ANSELB4 = 0;
    
    //Set Pins as Digital I/O
    _TRISB5 = 1;
    _TRISB4 = 0;
    
    //Peripheral Pin Select Mapping (Table 11-10, page 139)
    RPINR18bits.U1RXR = 18;

    // Assign U1TX To Pin RP28 (Table 11-11, page 140)
    RPOR14bits.RP28R = 3;
    
    // UART 1 Control Registers 
    U1MODEbits.UEN = 0b00;      // No Flow Control
    U1MODEbits.BRGH = 0b1;      // Standard Speed Mode
    U1MODEbits.PDSEL = 0b00;    // 8 Bit data no parity
    U1MODEbits.RTSMD = 0b1;     // Simplex Mode
    
    //UART 1 Baud Rate Generator 
    U1BRG = (CLOCK_PeripheralFrequencyGet()/(U1BAUD*4UL)) - 1;
    
    // Enable the UART1.
    U1MODEbits.UARTEN = 1;      // Enable UART 1
    U1STAbits.UTXEN = 1;        // Enable UART 1 Transmission
}

char UART1_rx(void){
    while(!(U1STAbits.URXDA == 1));

    if ((U1STAbits.OERR == 1))
    {
        U1STAbits.OERR = 0;
    }
    return U1RXREG;
}

int UART1_available(void){
    return ((!U1STAbits.UTXBF) && U1STAbits.UTXEN);
}

void UART1_tx(char input){
    while (U1STAbits.UTXBF);
    U1TXREG = input;
}

void UART1_txbuff(char *input, int size){
    for (int i=0; i<size-1; i++){
        while (U1STAbits.UTXBF);
        U1TXREG = input[i];
    }
}

void UART1_txJSON(char *input, int size){
    for (int i=0; i<size; i++){
        if(input[i] != '\0' && input[i] > 33 && input[i] < 127){
            while (U1STAbits.UTXBF);
            U1TXREG = input[i];
        }
        else if(input[i] == '\n' || input[i] == ' '){
            while (U1STAbits.UTXBF);
            U1TXREG = input[i];
        }
    }
}