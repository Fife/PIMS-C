#include <stdio.h>
#include <stdbool.h>
#include "pimsc.h"

#define REPORT_SIZE 40

//We may not use 4 byte floats, but here is an 
//example of unpacking and transmitting the bytes
//over UART

void pimsEShell(unsigned char* shellInput){
    //First input is always a 
    unsigned char command = shellInput[0];
    printf("\nCommand: %x\n", command);
    switch(command)
    {
        case SINGLE_REPORT_TRANSFER:
            printf("PIMS-E is transferring a Sensor Report\n");
            //Currently this decodes displays the incoming bytes:
            //Convert the first 4 bytes after the command to be the temperature
            long x = (long)shellInput[4]<<24|(long)shellInput[3]<<16|shellInput[2]<<8|shellInput[1];
            float*  temperature = (float*) &x;
            printf("Temp: %f C\n", *temperature);

            //Convert the next 4 bytes to be the wind 
            x = (long)shellInput[8]<<24|(long)shellInput[7]<<16|shellInput[6]<<8|shellInput[5];
            float*  wind = (float*) &x;
            printf("Wind: %f K\n", *wind);

            //The next 32 bytes are the date and time as a string
            char dateTimeBuffer[32];
            for (int i = 0; i < 32; i++){
                dateTimeBuffer[i] = (char)shellInput[i + 9];
            }
            printf("Date and Time: %s\n", dateTimeBuffer);
            break;
        default:
            printf("Error, Command Not Recongnized");
            break;
    }
}


//If we receive a valid start command, then start filling the buffer 
//If we receive an end command, stop filling the buffer and process the
//bytes in the shell. This code would live in the interrupt for the
//UART that the PIMS E lives on.
unsigned char pimsEShellBuffer[255];
bool isReceivingCommand = false;
int receivedByteCounter = 0;

bool isValidCommand(unsigned char input){
    return (input == SINGLE_REPORT_TRANSFER);
}

void processPIMSEUART(unsigned char input){
    if(isValidCommand(input) && !isReceivingCommand){
        isReceivingCommand = true;
        receivedByteCounter = 0;
    }

    if(isReceivingCommand){
        pimsEShellBuffer[receivedByteCounter] = input;
        receivedByteCounter++;
    }

    if(receivedByteCounter> REPORT_SIZE){
        isReceivingCommand = false;
        pimsEShell(pimsEShellBuffer);
        receivedByteCounter = 0;
    }

    //Set Interrupt flag since we've read UART byte
}


//Example of how the PIMS E Would use the Library
//Before this would work, they would have to insert the platform
//Specific UART function that transmits a byte
int main(){
    // PIMS-E Constucts the data structure and uses the provided transmit function.
    struct SensorReport sr1 = {32.52, 2.22, "12/20/2024 10:27:30.576 MST"};
    transmitSensorReport(sr1);
    printf("\n");
    struct SensorReport sr2 = {(float)34.12, (float)1.00, "12/20/2024 10:29:40.926 MST"};
    transmitSensorReport(sr2);
    printf("\n");
    struct SensorReport sr3 = {(float)37.29, (float)0.95, "12/20/2024 10:30:50.016 MST"};
    transmitSensorReport(sr3);
    printf("\n");
    struct SensorReport sr4 = {(float)39.45, (float)0.85, "12/20/2024 10:31:45.126 MST"};
    transmitSensorReport(sr4);
    printf("\n");
    return 1;
}