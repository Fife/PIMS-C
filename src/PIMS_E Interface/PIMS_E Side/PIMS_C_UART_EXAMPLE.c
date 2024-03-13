/*
Jacob Fifield 
MSU Denver CPE Senior Project II
Spring 2024
*/

#include <stdio.h>
#include "PIMS_C_UART.h"

//Example of how the PIMS E Would use the Library
//Before this would work, they would have to insert the platform
//Specific UART function that transmits a byte
int main(){
    // PIMS-E Constucts the data structure and uses the provided transmit function.
    
    SensorReport sr1 = {"12/20/2024 10:27:30", 32, 2.2, 22, 2.1, -1, 1, -2, 2, -3, 3, 0.1, 0.2, 0.3, 0.25, 0.6};
    transmitSensorReport(sr1);


    return 1;
}