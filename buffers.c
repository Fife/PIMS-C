/*
 * File:   buffers.c
 * Author: Fife
 *
 * Created on April 9, 2024, 9:28 PM
 */


#include "buffers.h"

DoubleBuffer PIMS_E_SHELL_DB;
DoubleBuffer LORA_DB;

bool isCommand(uint8_t input){
    bool output = false; 
    switch(input){
        case SINGLE_REPORT_TRANSFER:
            output = true;
            break;
        default:
            break;
    }
    return output; 
}

void WritePEShellBuffer(uint8_t input){
    //first check the current buffer select
    
    // buffer Select = 1; Buffer A is being written to
    if(PIMS_E_SHELL_DB.bufferSelect == 1 && PIMS_E_SHELL_DB.aState != NEW){
        if(PIMS_E_SHELL_DB.counter > DB_SIZE-1){
            PIMS_E_SHELL_DB.counter = 0;
            PIMS_E_SHELL_DB.bufferSelect = 0;
            PIMS_E_SHELL_DB.aState = NEW;
            if(isCommand(input)){
                PIMS_E_SHELL_DB.bufferB[PIMS_E_SHELL_DB.counter] = input;
                PIMS_E_SHELL_DB.counter++;
            }
        }
        else{
            PIMS_E_SHELL_DB.aState = WRITING;
            if(PIMS_E_SHELL_DB.counter != 0){
                PIMS_E_SHELL_DB.bufferA[PIMS_E_SHELL_DB.counter] = input;
                PIMS_E_SHELL_DB.counter++;
            }
            else{
                if(isCommand(input)){
                    PIMS_E_SHELL_DB.bufferA[PIMS_E_SHELL_DB.counter] = input;
                    PIMS_E_SHELL_DB.counter++;
                }
            }
        }
    }
    else if (PIMS_E_SHELL_DB.bufferSelect == 0 && PIMS_E_SHELL_DB.bState != NEW){
        if(PIMS_E_SHELL_DB.counter > DB_SIZE-1){
            PIMS_E_SHELL_DB.counter = 0;
            PIMS_E_SHELL_DB.bufferSelect = 1;
            PIMS_E_SHELL_DB.bState = NEW; 
            
            if(isCommand(input)){
                PIMS_E_SHELL_DB.bufferA[PIMS_E_SHELL_DB.counter] = input;
                PIMS_E_SHELL_DB.counter++;
            }
        }
        else{
            PIMS_E_SHELL_DB.bState = WRITING;
            if(PIMS_E_SHELL_DB.counter != 0){
                PIMS_E_SHELL_DB.bufferB[PIMS_E_SHELL_DB.counter] = input;
                PIMS_E_SHELL_DB.counter++;
            }
            else{
                if(isCommand(input)){
                    PIMS_E_SHELL_DB.bufferB[PIMS_E_SHELL_DB.counter] = input;
                    PIMS_E_SHELL_DB.counter++;
                }
            }

        }
    } 
    return;
}

bool IsNewPEShellBuffer(void){
    return (PIMS_E_SHELL_DB.aState == NEW || PIMS_E_SHELL_DB.bState == NEW);
}

void CopyPEShellBuffer(uint8_t * destBuffer){
    if (PIMS_E_SHELL_DB.aState == NEW){
        for(int i = 0; i<DB_SIZE;i++){
            destBuffer[i] = PIMS_E_SHELL_DB.bufferA[i];
        }
        PIMS_E_SHELL_DB.aState = READY;
        return;
    }
    else if (PIMS_E_SHELL_DB.bState == NEW){
        for(int i = 0; i<DB_SIZE;i++){
            destBuffer[i] = PIMS_E_SHELL_DB.bufferB[i];
        }
        PIMS_E_SHELL_DB.bState = READY;
        return;
    }
}

void PEShellBufferInit(void){
    PIMS_E_SHELL_DB.counter = 0;
    PIMS_E_SHELL_DB.aState = READY;
    PIMS_E_SHELL_DB.bState = READY;
    PIMS_E_SHELL_DB.bufferSelect = 1;
    for(int i = 0; i<DB_SIZE; i++){
        PIMS_E_SHELL_DB.bufferA[i] = 0;
        PIMS_E_SHELL_DB.bufferB[i] = 0;
    }
    
}


void WriteLORABuffer(uint8_t input){
    //first check the current buffer select
    
    // buffer Select = 1; Buffer A is being written to
    if(LORA_DB.bufferSelect == 1 && LORA_DB.aState != NEW){
        if(LORA_DB.counter > DB_SIZE-1){
            LORA_DB.counter = 0;
            LORA_DB.bufferSelect = 0;
            LORA_DB.aState = NEW;
            if(isCommand(input)){
                LORA_DB.bufferB[LORA_DB.counter] = input;
                LORA_DB.counter++;
            }
        }
        else{
            LORA_DB.aState = WRITING;
            if(LORA_DB.counter != 0){
                LORA_DB.bufferA[LORA_DB.counter] = input;
                LORA_DB.counter++;
            }
            else{
                if(isCommand(input)){
                    LORA_DB.bufferA[LORA_DB.counter] = input;
                    LORA_DB.counter++;
                }
            }
        }
    }
    else if (LORA_DB.bufferSelect == 0 && LORA_DB.bState != NEW){
        if(LORA_DB.counter > DB_SIZE-1){
            LORA_DB.counter = 0;
            LORA_DB.bufferSelect = 1;
            LORA_DB.bState = NEW; 
            
            if(isCommand(input)){
                LORA_DB.bufferA[LORA_DB.counter] = input;
                LORA_DB.counter++;
            }
        }
        else{
            LORA_DB.bState = WRITING;
            if(LORA_DB.counter != 0){
                LORA_DB.bufferB[LORA_DB.counter] = input;
                LORA_DB.counter++;
            }
            else{
                if(isCommand(input)){
                    LORA_DB.bufferB[LORA_DB.counter] = input;
                    LORA_DB.counter++;
                }
            }

        }
    } 
    return;
}

void LORABufferInit(void){
    LORA_DB.counter = 0;
    LORA_DB.aState = READY;
    LORA_DB.bState = READY;
    LORA_DB.bufferSelect = 1;
    for(int i = 0; i<DB_SIZE; i++){
        LORA_DB.bufferA[i] = 0;
        LORA_DB.bufferB[i] = 0;
    }
    
}

void CopyLORABuffer(uint8_t * destBuffer){
    if (LORA_DB.aState == NEW){
        for(int i = 0; i<DB_SIZE;i++){
            destBuffer[i] = LORA_DB.bufferA[i];
        }
        LORA_DB.aState = READY;
        return;
    }
    else if (LORA_DB.bState == NEW){
        for(int i = 0; i<DB_SIZE;i++){
            destBuffer[i] = LORA_DB.bufferB[i];
        }
        LORA_DB.bState = READY;
        return;
    }
}

bool IsNewLORABuffer(void){
    return (LORA_DB.aState == NEW || LORA_DB.bState == NEW);
}