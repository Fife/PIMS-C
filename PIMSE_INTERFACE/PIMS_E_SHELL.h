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
//====================================================================//

SensorReport decodeSR(unsigned char* srt);
void pimsEShell(unsigned char* shellInput);

#endif