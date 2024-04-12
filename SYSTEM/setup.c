/*
 * File:   setup.c
 * Author: Fife
 *
 * Created on April 9, 2024, 11:10 PM
 */


#include "setup.h"

int Init_System(void){
    CLOCK_Initialize();
    UART1_Init();
    UART2_Init();
    UART3_Init();
    
    WIZ_S2E_Init();
    PEShellBufferInit();
    
    initInterrupts();
    enableInterrupts();
    //Successful Initialization
    return 0;
}