/*
 * File:   SystemTest.c
 * Author: Fife
 *
 * Created on April 6, 2024, 9:37 PM
 */

#include "SystemTest.h"

uint8_t shellInput[DB_SIZE];

void PROGRAM_PROTOTYPE(void){
    Init_System();
    LED_INIT();
    
    while(1){
        //Round Robin, Low priority interrupt-able tasks
        //Operation of PIMS E Shell
        if(IsNewPEShellBuffer()){
            LED_ON();
            CopyPEShellBuffer(shellInput);
            pimsEShell(shellInput);
            LED_OFF();
        }
    }
    return;
}




