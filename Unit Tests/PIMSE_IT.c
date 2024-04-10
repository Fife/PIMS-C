/*
 * File:   PIMSE_INTERFACE_TEST.c
 * Author: Fife
 *
 * Created on April 3, 2024, 11:03 PM
 */

#include <stdint.h>
#include "PIMSE_IT.h"
#include "../uart1.h"
#include "../uart2.h"
//#include "./../SYSTEM_CONFIG.h"
#include "../interrupts.h"
#include "../PIMSE_INTERFACE/PIMS_E_SHELL.h"
#include "../WIZ_INTERFACE/JSON_CONVERTER.h"

void PIMSE_INTERFACE_TEST(void){
    UART1_Init();
    UART2_Init();
    char out;
    
    while(1){
        out = UART2_rx();
        //PIMS_UART_ISR(out);
        UART1_tx(out);
    }
}

void BAUD_TEST(void){
    UART1_Init();
    while(1){
        UART1_tx('e');
    }
}

void PASSTHRU_TEST(void){
    UART1_Init();
    while(1){
        char i = UART1_rx();
        UART1_tx(i);
    }
}

void U2_INT_TEST(void){
    UART1_Init();
    UART2_Init();
    initInterrupts();
    enableInterrupts();
    
    while(1);
}

