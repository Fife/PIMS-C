#include "MT25TL01GBBB_CS.h"
#include "MT25TL01GBBB_Config.h"

unsigned short SPI_WRAPPER(unsigned short input){
    // Put Platform Specific SPI Code Here.
}

void FlashNonVolatileConfig(){
    SPI_WRAPPER(WRITE_NONVOLATILE_CONFIGURATION_REGISTER);
    SPI_WRAPPER((unsigned short)(NON_VOLATILE_CONFIGURATION_REGISTER_CONFIG >> 8));
    SPI_WRAPPER((unsigned short)(NON_VOLATILE_CONFIGURATION_REGISTER_CONFIG));
}

void FlashRead(unsigned int startingAddress, unsigned short numBytes, unsigned short* buffer){
    SPI_WRAPPER(FOUR_BYTE_READ);
    SPI_WRAPPER(startingAddress);
    for (int i = 0; i < numBytes; i++){
        buffer[i] = SPI_WRAPPER(0);
    }
}

// Writes a 256 Byte Page to the Flash Memory 
// Note that the data must be 256 bytes long or must be padded 

// Programming a Page takes up to 1.8ms, so try to program the memory in down time
void FlashPageProgram(unsigned int startingAddress, unsigned short *buffer)
{
    SPI_WRAPPER(WRITE_ENABLE);
    SPI_WRAPPER(FOUR_BYTE_PAGE_PROGRAM);
    for (int i = 0; i < 256; i++){
        SPI_WRAPPER(buffer[i]);
    }
}

// Programming a Page takes up to 1.8ms per page, so make sure nothing will 
// interrupt the process. This function is meant to program many pages at once
void FlashBulkProgram(unsigned int startingAddress, unsigned short *buffer, unsigned int numBytes)
{
    // Enable Writing to the Flash Memory
    SPI_WRAPPER(WRITE_ENABLE);
    SPI_WRAPPER(FOUR_BYTE_PAGE_PROGRAM);

    //Calculate the number of pages needed

    // 1 Page is 256 Bytes Wide, each address represents 1 bit. 
    int numPages = numBytes / 256;
    unsigned short tempBuffer[256];
    //For all of the pages
    for (int i = 0; i < numPages;i++){
        //For each of the bytes in the selected page
        for(int j = 0; j < 256;j++){
            tempBuffer[j] = buffer[i*256 + j];
        }
        // Program the tempBuffer in the page
        // Each address represents 1 bit, and we are working in pages of bytes
        // That means the address offset will be i * 8 * 256 where i is the page 
        // number.
        FlashPageProgram(startingAddress + i*8*256, tempBuffer);
    }
}

// Software Reset the Flash Memory 
void FlashReset(){
    SPI_WRAPPER(RESET_ENABLE);
    SPI_WRAPPER(RESET_MEMORY);
}

//ID is 20 bytes long
void FlashReadID(unsigned short *idBuffer){
    SPI_WRAPPER(READ_ID);
    for(int i=0; i<20;i++){
        idBuffer[i] = SPI_WRAPPER(0);
    }
}
