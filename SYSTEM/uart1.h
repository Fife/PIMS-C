//This is the configuration for UART 1
//which is connected to the WIZ S2E Module
#ifndef UART1_H
#define UART1_H

#include "clock.h"

#define U1BAUD 9600
#define DB 8
#define PARITY 0
#define FLOW 0

void UART1_Init(void);
void UART1_tx(char);
char UART1_rx(void);
int UART1_available(void);
void UART1_txbuff(char*, int);


#endif