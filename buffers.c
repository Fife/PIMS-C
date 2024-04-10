/*
 * File:   buffers.c
 * Author: Fife
 *
 * Created on April 9, 2024, 9:28 PM
 */


#include "buffers.h"

DoubleBuffer PIMS_E_SHELL_DB;

void WritePEShellBuffer(uint8_t input){
    //first check the current buffer select
    
    // buffer Select = 1; Buffer A is being written to
    if(PIMS_E_SHELL_DB.bufferSelect == 1 && PIMS_E_SHELL_DB.aState != NEW){
        if(PIMS_E_SHELL_DB.counter > DB_SIZE-1){
            PIMS_E_SHELL_DB.counter = 0;
            PIMS_E_SHELL_DB.bufferSelect = 0;
            PIMS_E_SHELL_DB.aState = NEW; 
            PIMS_E_SHELL_DB.bufferB[PIMS_E_SHELL_DB.counter] = input;
            PIMS_E_SHELL_DB.counter++;
        }
        else{
            PIMS_E_SHELL_DB.aState = WRITING;
            PIMS_E_SHELL_DB.bufferA[PIMS_E_SHELL_DB.counter] = input;
            PIMS_E_SHELL_DB.counter++;
        }
        PIMS_E_SHELL_DB.bufferA[PIMS_E_SHELL_DB.counter] = input;
    }
    else if (PIMS_E_SHELL_DB.bufferSelect == 0 && PIMS_E_SHELL_DB.bState != NEW){
        if(PIMS_E_SHELL_DB.counter > DB_SIZE-1){
            PIMS_E_SHELL_DB.counter = 0;
            PIMS_E_SHELL_DB.bufferSelect = 1;
            PIMS_E_SHELL_DB.bState = NEW; 
            PIMS_E_SHELL_DB.bufferA[PIMS_E_SHELL_DB.counter] = input;
            PIMS_E_SHELL_DB.counter++;
        }
        else{
            PIMS_E_SHELL_DB.bState = WRITING;
            PIMS_E_SHELL_DB.bufferB[PIMS_E_SHELL_DB.counter] = input;
            PIMS_E_SHELL_DB.counter++;
        }
        PIMS_E_SHELL_DB.bufferB[PIMS_E_SHELL_DB.counter] = input;
    }
    return;
}

bool IsNewPEShellBuffer(void){
    if (PIMS_E_SHELL_DB.aState == NEW || PIMS_E_SHELL_DB.bState == NEW){
        return true; 
    }
    return false;
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
}