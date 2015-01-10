#ifndef LED_H
#define LED_H

/**************************************
 *in mini2440 
 * 4 LEDs  LED_1:GPB5,LED_2:PGB6
 *         LED_2:GPB7,LED_4:GPB8
 * ***********************************/
#include"s3c2440.h"

#define GET_GPBCON  (*(volatile unsigned int *)GPBCON)
#define GET_GPBDAT  (*(volatile unsigned int *)GPBDAT)
#define GET_GPBUP   (*(volatile unsigned int *)GPBUP)

#define LED_IO    ((1<<10)|(1<<12)|(1<<14)|(1<<16)) //set GPB5-8 output
#define LED_DISUP  ((1<<5)|(1<<6)|(1<<7)|(1<<8))    //diable GPB5-8 pull-up 
#define LED_1OFF    (1<<5)
#define LED_2OFF    (1<<6)
#define LED_3OFF    (1<<7)
#define LED_4OFF    (1<<8)

#define LED_1ON    ~(1<<5)
#define LED_2ON    ~(1<<6)
#define LED_3ON    ~(1<<7)
#define LED_4ON    ~(1<<8)
#define LED_13   ~((1<<5)|(1<<7))
#define LED_24   ~((1<<6)|(1<<8))
#define LED_ALLOFF  ((1<<5)|(1<<6)|(1<<7)|(1<<8))
#define LED_ALLON   ~LED_ALLOFF


void led_init();
void led_delay(unsigned long time);
void led_allon();
void led_alloff();
void led_non(unsigned int n);
void led_noff(unsigned int n);
void led_shl(unsigned int time);
void led_shr(unsigned int time);
void led_flash(unsigned int time);


#endif
