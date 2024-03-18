// Server Should contain the last 10 PIMS Readings for each device on the network. 

// In practice, the PIMS readings could be piped out to an external database, 
// so that the bridge device wouldn't need tons of memory. 

// For our demonstration the device will be serving a webpage of the stats
// from the last 10 PIMS Readings.
#include "SENSOR_REPORT.h"
#define MAX_NETWORK_SIZE 2
#define HISTORY_SIZE 10

typedef struct PIMSDevice {
    int id;
    SensorReport sensorReport[HISTORY_SIZE];
} PIMSDevice;

PIMSDevice PIMS_NETWORK[MAX_NETWORK_SIZE];

// We need to change the PIMS_NETWORK into a CSV, and store the file in the 
// Flash Memory. We will serve that file to the connected client via the UART
// Connection, and then, using the transmitted client side java script the 
// information is graphed. 

// A static section in flash memory will hold the files that the web server will need.
// We will associate a list of pointers in the flash memory with each file.


