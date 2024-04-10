/*
Jacob Fifield 
MSU Denver CPE Senior Project II
Spring 2024

*/
/*
 DEPRICATED
 * Replaced with UART ISR and Double Buffer
 
#include "PIMS_E_SHELL.h"
#include "../LED.h"
#include "../SYSTEM/uart1.h"

typedef enum ShellState{
    IDLE,
    RECEIVING
} ShellState;

ShellState PIMS_UART_SHELL_STATE = IDLE;
uint16_t DATA_LENGTH = (SHELL_BUFFER_SIZE);

void PIMS_UART_ISR(unsigned char);
bool isValidCommand(unsigned char);
void clearShellBuffer(void);

void clearShellBuffer(){
    for (int i = 0; i < SHELL_BUFFER_SIZE-1; i++){
        PIMSE_SHELL_BUFFER[i] = 0;
    }
    PIMSE_SHELL_OFFSET = 0; 
}
 
bool isValidCommand(unsigned char input){
    return (input == SINGLE_REPORT_TRANSFER);
}

// UART State Machine for gathering shell input
void PIMS_UART_ISR(unsigned char rxByte){
    switch(PIMS_UART_SHELL_STATE){
        case RECEIVING:
            // We are receiving and have reached the end of the buffer
            // Time to process the buffer as a shell input, clear it,
            // and set the Shell State to IDLE
            if(PIMSE_SHELL_OFFSET>(DATA_LENGTH-1)){
                T1CONbits.TON = 0;
                TMR1 = 0;
                
                //pimsEShell(PIMSE_SHELL_BUFFER);
                //clearShellBuffer();

                PIMS_UART_SHELL_STATE = IDLE;
                DATA_LENGTH = SHELL_BUFFER_SIZE;
             
            }

            // We are in the middle of receiving a shell frame,
            // Keep adding characters to the buffer until the offset overflows.
            else{
                PIMSE_SHELL_BUFFER[PIMSE_SHELL_OFFSET] = rxByte;
                PIMSE_SHELL_OFFSET++;
            }
            break;
        case IDLE:
            // We have received a valid command to initiate a shell input transfer. 
            if(isValidCommand(rxByte)){
                PIMS_UART_SHELL_STATE = RECEIVING;
                PIMSE_SHELL_OFFSET = 0;
                PIMSE_SHELL_BUFFER[PIMSE_SHELL_OFFSET] = rxByte;
                PIMSE_SHELL_OFFSET++;
                
                if(rxByte == SINGLE_REPORT_TRANSFER) {
                    DATA_LENGTH = SENSOR_REPORT_SIZE - 4;
                }
                
                //Start transaction timer
                //T1CONbits.TON = 1;
            }
            else{
                /*
                    T1CONbits.TON = 0;
                        TMR1 = 0;
                 */

                clearShellBuffer();
            }
            break;
        default:
            break;
    }
}

/* Example code for Timer1 ISR*/
void __attribute__((__interrupt__, __shadow__)) _T1Interrupt(void)
{
    //Timer is up, the UART transaction is void 
    clearShellBuffer();
    UART1_txbuff("send again\n", 11);
    
    TMR1 = 0;
    T1CONbits.TON = 0;
    IFS0bits.T1IF = 0; //Reset Timer1 interrupt flag and Return from ISR
}
 */