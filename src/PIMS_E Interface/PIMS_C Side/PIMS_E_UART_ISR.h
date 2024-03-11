/*
Jacob Fifield 
MSU Denver CPE Senior Project II
Spring 2024

*/

#include "PIMS_E_SHELL.h"

typedef enum ShellState{
    IDLE,
    RECEIVING
} ShellState;

//Shell Buffer, Offset, and Starting State
#define SHELL_BUFFER_SIZE 128
unsigned char PIMSE_SHELL_BUFFER[SHELL_BUFFER_SIZE];
unsigned char PIMSE_SHELL_OFFSET = 0;
ShellState PIMS_UART_SHELL_STATE = IDLE;

bool isValidCommand(unsigned char input){
    return (input == SINGLE_REPORT_TRANSFER);
}

void clearShellBuffer(){
    for (int i = 0; i < SHELL_BUFFER_SIZE-1; i++){
        PIMSE_SHELL_BUFFER[i] = 0;
    }
}

// UART State Machine for gathering shell input
void PIMS_UART_ISR(unsigned char rxByte){
    switch(PIMS_UART_SHELL_STATE){
        case RECEIVING:
            // We are receiving and have reached the end of the buffer
            // Time to process the buffer as a shell input, clear it,
            // and set the Shell State to IDLE
            if(PIMSE_SHELL_OFFSET>SHELL_BUFFER_SIZE-1){
                pimsEShell(PIMSE_SHELL_BUFFER);
                clearShellBuffer();

                // Reset State to be ready for another shell input
                PIMSE_SHELL_OFFSET = 0;
                PIMS_UART_SHELL_STATE = IDLE;
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
            }
            break;
        default:
            break;
    }
}