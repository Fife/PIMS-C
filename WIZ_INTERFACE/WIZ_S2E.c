/*
 * File:   WIZ_S2E.c
 * Author: Fife
 *
 * Created on April 11, 2024, 7:31 PM
 */


#include "WIZ_S2E.h"

void WIZ_S2E_Init(void){
    
    //Setup Hardware Trigger Signal
    _ANSELG6 = 0;
    TRISGbits.TRISG6 = 0;
    _LATG6 = 1;
    
    _ANSELG8 = 0;
    TRISGbits.TRISG8 = 0;
    _LATG8 = 1;
    //Boot in Data Transmission Mode
    

    UART1_txbuff("EX\r\n", 4);
    __delay_ms(500);
    
}
