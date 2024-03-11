/*
Jacob Fifield 
MSU Denver CPE Senior Project II
Spring 2024
*/

#ifndef SENSOR_REPORT_H
#define SENSOR_REPORT_H

//=================== Sensor Report =========================//

typedef struct SensorReport{
    float temperature;
    float windSpeed;
    float accelX;
    float accelY;
    float accelZ;
    char dateTime[32];
} SensorReport;

#define SENSOR_REPORT_SIZE (unsigned char)sizeof(SensorReport)+1

#endif 