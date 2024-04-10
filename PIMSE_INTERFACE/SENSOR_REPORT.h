/*
Jacob Fifield 
MSU Denver CPE Senior Project II
Spring 2024
*/

#include <stdio.h>

#ifndef SENSOR_REPORT_H
#define SENSOR_REPORT_H

//=================== Sensor Report =========================//

typedef struct SensorReport{
    char dateTime[32];
    float temperatureExternal;
    float humidityExternal;
    float temperatureInternal;
    float humidityInternal;
    float accelXMin;
    float accelXMax;
    float accelYMin;
    float accelYMax;
    float accelZMin;
    float accelZMax;
    float accelXOffset;
    float accelYOffset;
    float accelZOffset;
    float windSpeed;
    float ultrasound;
} SensorReport;


#define SENSOR_REPORT_SIZE (unsigned char)sizeof(SensorReport)
#define SR_NUM_FIELDS 16

#define SRT_SIZE (SENSOR_REPORT_SIZE + 1)

#endif 