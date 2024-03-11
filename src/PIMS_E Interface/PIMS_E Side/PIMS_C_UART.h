/*
Jacob Fifield 
MSU Denver CPE Senior Project II
Spring 2024
*/

#include <stdio.h>
#include "PIMS_DATA_TYPES.h"
#include "PIMS_C_SHELL_COMMANDS.h"

// Remove at some point

unsigned char mockRXBuffer[SENSOR_REPORT_SIZE];
int mockRXCounter = 0;
void MOCK_UART_TX(unsigned char inputByte){
    printf("%x ", inputByte);
    mockRXBuffer[mockRXCounter] = inputByte;
    mockRXCounter++;
    if (mockRXCounter > SENSOR_REPORT_SIZE-1){
        mockRXCounter = 0;
    }
}


//Read in the bytes until the UART Message is complete
//Construct an input to the shell from the UART Message bytes

//Instruction byte will be first, followed by data bytes

//To send a Sensor report, the sensor report struct has to be created
//on the PIMS E side. Then the method can be called to transmit the 
//Sensor report in a pre-determeined way:
void UART_TX_WRAPPER(unsigned char inputByte){
    //Place Platform Specific UART T_X Function for platform here:
    
    //Code below is for testing
    MOCK_UART_TX(inputByte);
}

void txFloat(float input)
{
    //Cast the address of the float to
    //the address of a character array
    unsigned char *p = (unsigned char*)&input;

    //Loop through array and transmit each byte
    for (int i = 0; i < 4; i++){
        UART_TX_WRAPPER((unsigned char)p[i]);
    }
}

//Read in the bytes until the UART Message is complete
//Construct an input to the shell from the UART Message bytes

//Instruction byte will be first, followed by data bytes

//To send a Sensor report, the sensor report struct has to be created
//on the PIMS E side. Then the method can be called to transmit the 
//Sensor report in a pre-determeined way:
void transmitSensorReport(SensorReport sensorReport){
    //Transmit the Report Transfer Byte
    UART_TX_WRAPPER(SINGLE_REPORT_TRANSFER);

    //Transmit the floats from the report, from lsb to msb
    txFloat(sensorReport.temperature);
    txFloat(sensorReport.windSpeed);
    txFloat(sensorReport.accelX);
    txFloat(sensorReport.accelY);
    txFloat(sensorReport.accelZ);

    //Transmit the dateTime
    unsigned char tempByte;
    for (int i = 0; i < 32; i++){
        tempByte = sensorReport.dateTime[i];
        UART_TX_WRAPPER(tempByte);
    }
}
