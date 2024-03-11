#include <stdio.h>
#include "PIMS_C_UART.h"


//Example of how the PIMS E Would use the Library
//Before this would work, they would have to insert the platform
//Specific UART function that transmits a byte
int main(){
    // PIMS-E Constucts the data structure and uses the provided transmit function.
    struct SensorReport sr1 = {32.52, 2.22, 0.01, 0.1, 0.12, "12/20/2024 10:27:30.576 MST"};
    printf("\nTransmitting over UART: ");
    transmitSensorReport(sr1);
    
    return 1;
}