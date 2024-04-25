/*
Jacob Fifield 
MSU Denver CPE Senior Project II
Spring 2024

The PIMS E Shell Creates the PIMS Report and places it in the appropriate output buffer.
*/

#ifndef PINS_E_SHELL_H
#define PINS_E_SHELL_H

#include "PIMS_DATA_TYPES.h"
#include "PIMS_E_SHELL_COMMANDS.h"
#include "../LED.h"
#include "../buffers.h"
#include <stdbool.h>
//====================================================================//
typedef enum MODULE_TYPE {
    NODE,
    GATEWAY
} MODULE_TYPE;

typedef struct PimsShell{
    uint8_t* shellInput[DB_SIZE];
    MODULE_TYPE mode;  
    bool maintenanceFlag; 
}PimsShell;

SensorReport decodeSR(unsigned char* srt);
void pimsEShell(unsigned char*, MODULE_TYPE);
void transmitPIMSReport(PIMSReport);
int transmitSensorReportLora(SensorReport);
void txFloat(float);
PIMSReport constructPR(uint8_t*, Destination dest);
#endif