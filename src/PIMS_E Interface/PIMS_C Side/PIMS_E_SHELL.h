/*
Jacob Fifield 
MSU Denver CPE Senior Project II
Spring 2024
*/


#include "PIMS_DATA_TYPES.h"
#include "PIMS_E_SHELL_COMMANDS.h"
//====================================================================//

void pimsEShell(unsigned char* shellInput){
    //First input is always a command.
    unsigned char command = shellInput[0];
    //printf("\nCommand: 0x%x ", command);
    switch(command)
    {
        case (SINGLE_REPORT_TRANSFER):{
            //printf("\nPIMS-E is transferring a Sensor Report\n");
            //Currently this decodes displays the incoming bytes:
            //Convert the first 4 bytes after the command to be the temperature
            long x = (long)shellInput[4]<<24|(long)shellInput[3]<<16|shellInput[2]<<8|shellInput[1];
            float*  temperature = (float*) &x; 
            //printf("Temp: %f C\n", *temperature);

            //Convert the next 4 bytes to be the wind 
            x = (long)shellInput[8]<<24|(long)shellInput[7]<<16|shellInput[6]<<8|shellInput[5];
            float*  wind = (float*) &x;
            //printf("Wind: %f K\n", *wind);

            //Convert the next 4 bytes to be the Accelerometer in X
            x = (long)shellInput[12]<<24|(long)shellInput[11]<<16|shellInput[10]<<8|shellInput[9];
            float*  ax = (float*) &x;
           // printf("AccelX: %f m/s^2\n", *ax);

            //Convert the next 4 bytes to be the Accelerometer in X
            x = (long)shellInput[16]<<24|(long)shellInput[15]<<16|shellInput[14]<<8|shellInput[13];
            float*  ay = (float*) &x;
            //printf("AccelY: %f m/s^2\n", *ay);

            //Convert the next 4 bytes to be the Accelerometer in X
            x = (long)shellInput[20]<<24|(long)shellInput[19]<<16|shellInput[18]<<8|shellInput[17];
            float*  az = (float*) &x;
            //printf("AccelZ: %f m/s^2\n", *az);

            //The next 32 bytes are the date and time as a string
            char dateTimeBuffer[32];
            for (int i = 0; i < 32; i++){
                dateTimeBuffer[i] = (char)shellInput[i + 21];
            }
            //printf("Date and Time: %s\n", dateTimeBuffer);
            break;
        }
        default:
            //printf("Error, Command Not Recongnized");
            break;
    }
}