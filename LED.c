/*
 * File:   LED.c
 * Author: Fife
 *
 * Created on April 6, 2024, 1:09 PM
 */


#include "LED.h"

void LED_INIT(){
    _TRISE3 = 0;
    _ANSELE3 = 0;
}
void LED_ON(void){
    _LATE3 = 1;
}
void LED_OFF(void){
    _LATE3 = 0;
}
void LED_TOGGLE(void){
    _LATE3 ^= 1;
}
