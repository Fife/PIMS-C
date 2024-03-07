#define SINGLE_REPORT_TRANSFER 0x5F
#include <stdio.h>
typedef struct SensorReport{
    float temperature;
    float windSpeed;
    char dateTime[32];
} SensorReport;

//Read in the bytes until the UART Message is complete
//Construct an input to the shell from the UART Message bytes

//Instruction byte will be first, followed by data bytes

//To send a Sensor report, the sensor report struct has to be created
//on the PIMS E side. Then the method can be called to transmit the 
//Sensor report in a pre-determeined way:
void UART_TX(unsigned char inputByte)
{
    //Place UART T_X Function for platform here.
    printf("%x ", inputByte);
}

void txFloat(float input)
{
    //Cast the address of the float to
    //the address of a character array
    unsigned char *p = (unsigned char*)&input;

    //Loop through array and transmit each byte
    for (int i = 0; i < 4; i++){
        UART_TX((unsigned char)p[i]);
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
    UART_TX(SINGLE_REPORT_TRANSFER);
    unsigned char tempByte;
    //Transmit the float, from lsb to msb
    txFloat(sensorReport.temperature);
    txFloat(sensorReport.windSpeed);

    //Transmit the dateTime
    for (int i = 0; i < 32; i++){
        tempByte = sensorReport.dateTime[i];
        UART_TX(tempByte);
    }
}
