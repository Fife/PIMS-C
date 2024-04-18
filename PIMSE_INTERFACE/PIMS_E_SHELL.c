/*
 * File:   PIMS_E_SHELL.c
 * Author: Fife
 *
 * Created on April 6, 2024, 1:38 PM
 */


#include "PIMS_E_SHELL.h"
#include "../WIZ_INTERFACE/JSON_CONVERTER.h"
#include "../SYSTEM/uart1.h"
#include "../SYSTEM/uart4.h"
#include "../SYSTEM/uart3.h"
#include "../buffers.h"

bool GATEWAY = true;
bool MAINTENANCE_MODE = false; 
char* poleNAME = "00:AA";

SensorReport decodeSR(unsigned char* srt){
   
    //Construct an incoming Sensor Report
    SensorReport incSR;
    
    unsigned char tempByte;
    
    //Load the dateTime
    for (int i = 0; i < 32; i++){
        tempByte = (char)srt[i+1];;
        incSR.dateTime[i] = tempByte;
    }
    
    // Load External Temp
    long x = (long)srt[36]<<24|(long)srt[35]<<16|(long)srt[34]<<8|(long)srt[33];
    float* tF = ((float* ) &x);
    incSR.temperatureExternal = *tF;
    
    x = (long)srt[40]<<24|(long)srt[39]<<16|(long)srt[38]<<8|(long)srt[37];
    tF = ((float* ) &x);
    incSR.humidityExternal = *tF;
    
    x = (long)srt[44]<<24|(long)srt[43]<<16|(long)srt[42]<<8|(long)srt[41];
    tF = ((float* ) &x);
    incSR.temperatureInternal = *tF;
    
    x = (long)srt[48]<<24|(long)srt[47]<<16|(long)srt[46]<<8|(long)srt[45];
    tF = ((float* ) &x);
    incSR.humidityInternal = *tF;
    
    x = (long)srt[52]<<24|(long)srt[51]<<16|(long)srt[50]<<8|(long)srt[49];
    tF = ((float* ) &x);
    incSR.accelXMin = *tF;
    
    x = (long)srt[56]<<24|(long)srt[55]<<16|(long)srt[54]<<8|(long)srt[53];
    tF = ((float* ) &x);
    incSR.accelXMax = *tF;
    
    x = (long)srt[60]<<24|(long)srt[59]<<16|(long)srt[58]<<8|(long)srt[57];
    tF = ((float* ) &x);
    incSR.accelYMin = *tF;
    
    x = (long)srt[64]<<24|(long)srt[63]<<16|(long)srt[62]<<8|(long)srt[61];
    tF = ((float* ) &x);
    incSR.accelYMax = *tF;
    
    x = (long)srt[68]<<24|(long)srt[67]<<16|(long)srt[66]<<8|(long)srt[65];
    tF = ((float* ) &x);
    incSR.accelZMin = *tF;
    
    x = (long)srt[72]<<24|(long)srt[71]<<16|(long)srt[70]<<8|(long)srt[69];
    tF = ((float* ) &x);
    incSR.accelZMax = *tF;
    
    x = (long)srt[76]<<24|(long)srt[75]<<16|(long)srt[74]<<8|(long)srt[73];
    tF = ((float* ) &x);
    incSR.accelXOffset = *tF;
    
    x = (long)srt[80]<<24|(long)srt[79]<<16|(long)srt[78]<<8|(long)srt[77];
    tF = ((float* ) &x);
    incSR.accelYOffset = *tF;
    
    x = (long)srt[84]<<24|(long)srt[83]<<16|(long)srt[82]<<8|(long)srt[81];
    tF = ((float* ) &x);
    incSR.accelZOffset = *tF;
    
    x = (long)srt[88]<<24|(long)srt[87]<<16|(long)srt[86]<<8|(long)srt[85];
    tF = ((float* ) &x);
    incSR.windSpeed = *tF;
    
    x = (long)srt[92]<<24|(long)srt[91]<<16|(long)srt[90]<<8|(long)srt[89];
    tF = ((float* ) &x);
    incSR.ultrasound = *tF;
    
    return incSR;
}


void pimsEShell(uint8_t * shellInput){
    //First input is always a command
    uint8_t command = shellInput[0];
    switch(command)
    {
        case (SINGLE_REPORT_TRANSFER):{
            //Decode Sensor Report and Build PIMS Report
            PIMSReport pr = constructPR(shellInput);
            transmitPIMSReport(pr);
            
            //Maintenance Clause
            if(MAINTENANCE_MODE){
                UART3_txJSON(SensorReportToJSON(pr.sensorReadings), JSON_BUFF_SIZE);
            }
            
            break;
        }
        default:{
            char* err = "Error, Command Not Recognized  \n";
            UART1_txbuff(err, 32);
            
            //Reset Buffer
            PEShellBufferInit();
            
            //Reset Uart2
            U2MODEbits.UARTEN = 0;
            U2MODEbits.UARTEN = 1;
            break;
        }
    }
}

PIMSReport constructPR(uint8_t* shellInput){

    PIMSReport pr;
    //Decode Sensor Report from buffer
    pr.sensorReadings = decodeSR(shellInput);
    
    if(GATEWAY){
        pr.destination = WEB_SERVER;
    }
    
    else{
        pr.destination = LORA;
    }
    
    //Pole ID
    char* ID = "PIMSC-3C:1F";
    for(int i =0; i<12; i++){
        pr.poleID[i] = ID[i];
    }
    
    return pr;
}

void txFloat(float input)
{
    //Cast the address of the float to
    //the address of a character array
    unsigned char *p = (unsigned char*)&input;

    //Loop through array and transmit each byte
    for (int i = 0; i < 4; i++){
        UART4_tx((unsigned char)p[i]);
    }
}

void transmitSensorReport(SensorReport sensorReport){
    //Transmit the Report Transfer Byte
    int counter = 0; 
    UART4_tx(SINGLE_REPORT_TRANSFER);
    counter ++;
    //Transmit the dateTime
    unsigned char tempByte;
    for (int i = 0; i < 32; i++){
        tempByte = sensorReport.dateTime[i];
        UART4_tx(tempByte);
        counter ++;
    }
    
    
    //Transmit the floats from the report, from lsb to msb

    txFloat(sensorReport.temperatureExternal);
    counter +=4;
    txFloat(sensorReport.humidityExternal);
    counter +=4;
    txFloat(sensorReport.temperatureInternal);
    counter +=4;
    txFloat(sensorReport.humidityInternal);
    counter +=4;
    txFloat(sensorReport.accelXMin);
    counter +=4;
    txFloat(sensorReport.accelXMax);
    counter +=4;
    txFloat(sensorReport.accelYMin);
    counter +=4;
    txFloat(sensorReport.accelYMax);
    counter +=4;
    txFloat(sensorReport.accelZMin);
    counter +=4;
    txFloat(sensorReport.accelZMax);
    counter +=4;
    txFloat(sensorReport.accelXOffset);
    counter +=4;
    txFloat(sensorReport.accelYOffset);
    counter +=4;
    txFloat(sensorReport.accelZOffset);
    counter +=4;
    txFloat(sensorReport.windSpeed);
    counter +=4;
    txFloat(sensorReport.ultrasound);
    counter +=4;

    while(counter<256){
        UART4_tx(0xDD);
        counter++;
    }
}

void transmitPIMSReport(PIMSReport pimsReport){
    if(pimsReport.destination == WEB_SERVER){
        UART1_txJSON(PIMSReportToJSON(pimsReport), JSON_BUFF_SIZE);
    }
    
    else if(pimsReport.destination == LORA){
        UART4_txbuff(pimsReport.poleID, 8);
        transmitSensorReport(pimsReport.sensorReadings);
        UART4_txbuff((char *)pimsReport.destination, 4);
    }
}

