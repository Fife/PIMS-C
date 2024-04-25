#include "btconnect.h"
#include "uart3.h"
#include <xc.h>

void bluetooth_init(void) {
        // Assign and configure BT pins
    _ANSELB2 = 0;
    _ANSELB15 = 0;
    TRISBbits.TRISB2 = 0;   // Configure pin 14 port RB2 as an output mapped to PDN in module
    TRISBbits.TRISB15 = 0;  // Configure pin 30 port RB15 as an output mapped to WAKEUP in module
    // Use LATx functionality to drive BT pins HIGH-LOW 
    // Exit Sleep Mode of HM-BT450s
    __delay_ms(2);
    LATBbits.LATB2 = 1;   // Set PDN pin HIGH for HM-BT4502 to exit sleep mode
    __delay_ms(2);   // Delay for module to exit sleep mode
    LATBbits.LATB2 = 0;   // Set PDN pin LOW after exiting sleep mode
    __delay_ms(2);
    //  Wake up HM-BT4502 via function
}

void wakeup_bluetooth(void) {
    // Wake up the HM-BT4502 by sending a falling edge
    __delay_ms(2);
    LATBbits.LATB15 = 1;  // Set WAKEUP pin HIGH to wake up HM-BT4502 module
    __delay_ms(2);
    LATBbits.LATB15 = 0;   // Set WAKEUP pin LOW to wake up HM-BT4502 module
    __delay_ms(2);
}

void bluetooth_sleep(void) {
    __delay_ms(2);
    LATBbits.LATB15 = 0;
    __delay_ms(2);
    LATBbits.LATB15 =1;
    __delay_ms(2);
}

void bt_transmit(uint8_t *data, int size) {
    wakeup_bluetooth();
    UART3_txbuff(data, size);
    bluetooth_sleep();
}