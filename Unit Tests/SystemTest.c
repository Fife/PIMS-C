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
    
    //Check to see if PIMS is equipped with a WAN 
    MODULE_TYPE mode;
    _TRISF0 = 1;
    
    if (!PORTFbits.RF0){
        mode = GATEWAY;
    }
    else{
        mode = NODE;
    }
    
    while(1){
        //Round Robin, Low priority interrupt-able tasks
        //Operation of PIMS E Shell
        if(IsNewPEShellBuffer()){
            LED_ON();
            CopyPEShellBuffer(shellInput);
            pimsEShell(shellInput, mode);
            LED_OFF();
        }
        if(IsNewLORABuffer()){
            LED_ON();
            CopyLORABuffer(shellInput);
            PIMSReport pr = constructPR(shellInput, LORA);
            UART1_txJSON(PIMSReportToJSON(pr),JSON_BUFF_SIZE);
            LED_OFF();
        }

    } 
}

void UART3_TEST(void){
    Init_System();
    _ANSELB2 = 0;   //PWRDWN
    _ANSELB15 = 0;  //WAKEUP
    
    __delay_ms(100);
    
    //Exit Sleep mode Falling Edge
    LATBbits.LATB15 = 1;    
    LATBbits.LATB15 = 0;
    __delay_ms(2);
    
    //Wakeup the bluetooth module for a TTM command
    LATBbits.LATB2 = 1;
    LATBbits.LATB2 = 0;
    __delay_ms(2);

    UART3_txbuff("TTM:REN-PIMS-C-001\r\n\0", 21);
    LATBbits.LATB2 = 1;
    __delay_ms(2);
    __delay_ms(100);

    
    while(1){
        //Wakeup the bluetooth module for a TTM command
        LATBbits.LATB2 = 1;
        LATBbits.LATB2 = 0;
        __delay_ms(2);

        UART3_txbuff("TTM:REN-PIMS-C-001\r\n\0", 21);
        LATBbits.LATB2 = 1;
        __delay_ms(2);
        __delay_ms(100);

    }
}