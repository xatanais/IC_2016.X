/*
 * File:   timer0.c
 * Author: Nathan
 *
 * Created on 14 de Dezembro de 2015, 10:49
 */


#include <xc.h>
#include "config.h"
#include "timer0.h"

/*
 Configuring the timer to 16 bits counter with 64 presacaler with interruption.
 The cycle of the timer is approximately 839ms = 0,839s
 */


void configTimer(){
    T0CONbits.T0CS = 0;//clock interno
    T0CONbits.T0SE = 0;
    T0CONbits.PSA = 0;//timer 0 com pre scaler
    T0CONbits.T08BIT = 0; //contador de 8 bit

    //pre scaler 1:64
    T0CONbits.T0PS2 = 1;
    T0CONbits.T0PS1 = 0;
    T0CONbits.T0PS0 = 1;

    TMR0IP = 1;

    INTCONbits.TMR0IF = 0;//flag
    INTCONbits.TMR0IE = 1;//enable
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;    
}

