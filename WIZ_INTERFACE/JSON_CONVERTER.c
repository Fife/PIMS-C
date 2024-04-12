/*
 * File:   JSON_CONVERTER.c
 * Author: Fife
 *
 * Created on April 9, 2024, 8:31 PM
 */

#include "JSON_CONVERTER.h"

const char* SensorReportFields[SR_NUM_FIELDS] = {"dateTime","temperatureExternal","humidityExternal","temperatureInternal","humidityInternal","accelXMin","accelXMax","accelYMin","accelYMax","accelZMin","accelZMax","accelXOffset","accelYOffset","accelZOffset","windSpeed","ultrasound"};
const int SensorReportFieldSizes[SR_NUM_FIELDS] = {8,19,16,19,16, 9,9,9,9,9,9,12,12,12, 9, 10};

const char JSON_PUNCT_INB[4] = {'\"', ' ', ':', '\"'};
const char JSON_PUNCT_END[3] = {'\"', ',' ,'\n'};

static char floatBuff[8];
float val;
char outputJSON[JSON_BUFF_SIZE];

char* SensorReportToJSON(SensorReport incSR){
    //Calculate Size of JSON and Allocate Space
    
    outputJSON[0] = '{';
    outputJSON[1] = '\n';
    
    unsigned int offset = 2;
    //For Each Field in the Sensor Report
    for (int i=0; i<SR_NUM_FIELDS; i++){
        outputJSON[offset] = '\"';
        offset++;
        
        for (int j=0; j< SensorReportFieldSizes[i]; j++){
            outputJSON[offset] = SensorReportFields[i][j];
            offset++;
        }
        
        // End Quotation Mark, Colon and Begin Quotation Mark
        for (int j=0; j< sizeof(JSON_PUNCT_INB); j++){
            outputJSON[offset] = JSON_PUNCT_INB[j];
            offset++;
        }
        
        // The Data Itself
        switch(i){
            //The Date Time String
            case 0:
                for (int j=0; j< sizeof(incSR.dateTime); j++){
                    outputJSON[offset] = incSR.dateTime[j];
                    offset++;
                }
                break;
            case 1: 
                val = incSR.temperatureExternal;
                sprintf(floatBuff, "%.4f" , (double)val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 2: 
                val = incSR.humidityExternal;
                sprintf(floatBuff, "%.4f" , (double)val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 3: 
                val = incSR.temperatureInternal;
                sprintf(floatBuff, "%.4f" ,(double) val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 4: 
                val = incSR.humidityInternal;
                sprintf(floatBuff, "%.4f" ,(double) val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 5:
                val = incSR.accelXMin;
                sprintf(floatBuff, "%.4f" ,(double) val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 6: 
                val = incSR.accelXMax;
                sprintf(floatBuff, "%.4f" ,(double)val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 7: 
                val = incSR.accelYMin;
                sprintf(floatBuff, "%.4f" ,(double) val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 8: 
                val = incSR.accelYMax;
                sprintf(floatBuff, "%.4f" , (double)val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 9: 
                val = incSR.accelZMin;
                sprintf(floatBuff, "%.4f" , (double)val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 10: 
                val = incSR.accelZMax;
                sprintf(floatBuff, "%.4f" ,(double) val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 11: 
                val = incSR.accelXOffset;
                sprintf(floatBuff, "%.4f" , (double)val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 12: 
                val = incSR.accelYOffset;
                sprintf(floatBuff, "%.4f" , (double)val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 13: 
                val = incSR.accelZOffset;
                sprintf(floatBuff, "%.4f" , (double)val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 14: 
                val = incSR.windSpeed;
                sprintf(floatBuff, "%.4f" , (double)val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            case 15: 
                val = incSR.ultrasound;
                sprintf(floatBuff, "%.2f" , (double)val);
                for (int j=0; j< sizeof(floatBuff); j++){
                    outputJSON[offset] = floatBuff[j];
                    offset++;
                }
                break;
            default:
                break;
        }
        
        // End Quotation Mark, Comma and Newline
        for (int j=0; j< sizeof(JSON_PUNCT_END); j++){
            outputJSON[offset] = JSON_PUNCT_END[j];
            offset++;
        }
    }
    outputJSON[offset-2] = ' ';
    outputJSON[offset] = '}';
    return outputJSON;
}