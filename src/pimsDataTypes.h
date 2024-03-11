//=================== Sensor Reports =========================//

#define SINGLE_REPORT_TRANSFER 0xFA
#define DATA_RECEIVED 0x0E

typedef struct SensorReport{
    float temperature;
    float windSpeed;
    float accelX;
    float accelY;
    float accelZ;
    char dateTime[32];
} SensorReport;

#define SENSOR_REPORT_SIZE (unsigned char)sizeof(SensorReport)+1

//======================PIMS Report=========================//

typedef enum Destination{
    BLUETOOTH,
    WEB_SERVER,
    LORA
} Destination;

typedef struct PIMSReport{
    char idstring[8];
    SensorReport sensorReadings;
    Destination destination;
} PIMSReport;

#define PIMS_REPORT_SIZE (unsigned char)sizeof(PIMSReport)+1

//=======================Global Buffers=======================//

//PIMS Report Buffer
#define PIMS_REPORT_BUFFER_SIZE 16
#define SENSOR_REPORT_BUFFER_SIZE 16
PIMSReport PIMS_REPORT_BUFFER[PIMS_REPORT_BUFFER_SIZE];
SensorReport SENSOR_REPORT_BUFFER[SENSOR_REPORT_BUFFER_SIZE];

/*
Sending a sensor report to the PIMS C:
    PIMS E Constructs a Sensor Report data structure from Sensor Data
    PIMS E Sends the SINGLE_REPORT_TRANSFER command to the PIMS C via UART
    PIMS E Sends the Shell Input to the PIMS C via UART
    PIMS C Responds with an DATA_RECEIVED Byte
*/

