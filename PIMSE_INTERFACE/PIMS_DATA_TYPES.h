/*
Jacob Fifield 
MSU Denver CPE Senior Project II
Spring 2024

PIMS UART Shell State Machine 

This file contains the UART ISR and Shell State Machine
*/

#ifndef PIMS_DATA_TYPES_H
#define PIMS_DATA_TYPES_H

#include "SENSOR_REPORT.h"

//======================PIMS Report=========================//

typedef enum Destination{
    BLUETOOTH,
    WEB_SERVER,
    LORA
} Destination;


typedef struct PIMSReport{
    char poleID[12];
    SensorReport sensorReadings;
    Destination destination;
} PIMSReport;

#define PIMS_REPORT_SIZE (unsigned char)sizeof(PIMSReport)

//=======================Global Buffers=======================//

/*
Sending a sensor report to the PIMS C:
    PIMS E Constructs a Sensor Report data structure from Sensor Data
    PIMS E Sends the SINGLE_REPORT_TRANSFER command to the PIMS C via UART
    PIMS E Sends the Shell Input to the PIMS C via UART
    PIMS C Responds with an DATA_RECEIVED Byte
*/

#endif 