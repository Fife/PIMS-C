/*
 * File:   PIMS_E_SHELL.c
 * Author: Fife
 *
 * Created on April 6, 2024, 1:38 PM
 */


#include "PIMS_E_SHELL.h"
#include "../WIZ_INTERFACE/JSON_CONVERTER.h"
#include "../SYSTEM/uart1.h"

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
    long x = (long)srt[36]<<24|(long)srt[35]<<16|srt[34]<<8|srt[33];
    float* tF = ((float* ) &x);
    incSR.temperatureExternal = *tF;
    
    x = (long)srt[40]<<24|(long)srt[39]<<16|srt[38]<<8|srt[37];
    tF = ((float* ) &x);
    incSR.humidityExternal = *tF;
    
    x = (long)srt[44]<<24|(long)srt[43]<<16|srt[42]<<8|srt[41];
    tF = ((float* ) &x);
    incSR.temperatureInternal = *tF;
    
    x = (long)srt[48]<<24|(long)srt[47]<<16|srt[46]<<8|srt[45];
    tF = ((float* ) &x);
    incSR.humidityInternal = *tF;
    
    x = (long)srt[52]<<24|(long)srt[51]<<16|srt[50]<<8|srt[49];
    tF = ((float* ) &x);
    incSR.accelXMin = *tF;
    
    x = (long)srt[56]<<24|(long)srt[55]<<16|srt[54]<<8|srt[53];
    tF = ((float* ) &x);
    incSR.accelXMax = *tF;
    
    x = (long)srt[60]<<24|(long)srt[59]<<16|srt[58]<<8|srt[57];
    tF = ((float* ) &x);
    incSR.accelYMin = *tF;
    
    x = (long)srt[64]<<24|(long)srt[63]<<16|srt[62]<<8|srt[61];
    tF = ((float* ) &x);
    incSR.accelYMax = *tF;
    
    x = (long)srt[68]<<24|(long)srt[67]<<16|srt[66]<<8|srt[65];
    tF = ((float* ) &x);
    incSR.accelZMin = *tF;
    
    x = (long)srt[72]<<24|(long)srt[71]<<16|srt[70]<<8|srt[69];
    tF = ((float* ) &x);
    incSR.accelZMax = *tF;
    
    x = (long)srt[76]<<24|(long)srt[75]<<16|srt[74]<<8|srt[73];
    tF = ((float* ) &x);
    incSR.accelXOffset = *tF;
    
    x = (long)srt[80]<<24|(long)srt[79]<<16|srt[78]<<8|srt[77];
    tF = ((float* ) &x);
    incSR.accelYOffset = *tF;
    
    x = (long)srt[84]<<24|(long)srt[83]<<16|srt[82]<<8|srt[81];
    tF = ((float* ) &x);
    incSR.accelZOffset = *tF;
    
    x = (long)srt[88]<<24|(long)srt[87]<<16|srt[86]<<8|srt[85];
    tF = ((float* ) &x);
    incSR.windSpeed = *tF;
    
    return incSR;
}

void pimsEShell(uint8_t * shellInput){
    //First input is always a command
    uint8_t command = shellInput[0];
    switch(command)
    {
        case (SINGLE_REPORT_TRANSFER):{
            //Decode Sensor Report and Build PIMS Report
            PIMSReport pr;
            pr.sensorReadings = decodeSR(shellInput);
            
            //At the moment, the logic is not there
            //to pick between options of where to send
            //it based on the setup of the PIMSC
            
            pr.destination = WEB_SERVER;
            for(int i =0; i<8; i++){
                pr.idstring[i] = (char)(i + 33);
            }
            UART1_txbuff(SensorReportToJSON(pr.sensorReadings), 1000);
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
