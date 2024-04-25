/* 
 * File:   btconnect.h
 * Author: msurobotics
 *
 * Created on April 25, 2024, 3:20 PM
 */
#include <stdint.h>

#ifndef BTCONNECT_H
#define	BTCONNECT_H

void bluetooth_init(void);
void wakeup_bluetooth(void);
void bluetooth_sleep(void);
void bt_transmit(uint8_t*, int);

#ifdef	__cplusplus
extern "C" {
#endif
    

#ifdef	__cplusplus
}
#endif

#endif	/* BTCONNECT_H */

