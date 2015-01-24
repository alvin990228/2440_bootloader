/*************************************
*timer.h for using PWM timer in mini2440
*2015.01.23 Alvin <alvin990228@gmail.com>
**************************************/
#ifndef TIMER_H
#define TIMER_H

#include"s3c2440.h"


#define GET_TCFG0 (*(volatile unsigned int*)TCFG0)
#define GET_TCFG1 (*(volatile unsigned int*)TCFG1)
#define GET_TCON  (*(volatile unsigned int*)TCON)


#define GET_TCNTB0  (*(volatile unsigned int*)TCNTB0)
#define GET_TCMPB0  (*(volatile unsigned int*)TCMPB0)
#define GET_TCNTO0  (*(volatile unsigned int*)TCNTO0)


#define GET_TCNTB1  (*(volatile unsigned int*)TCNTB1)
#define GET_TCMPB1  (*(volatile unsigned int*)TCMPB1)
#define GET_TCNTO1  (*(volatile unsigned int*)TCNTO1)


#define GET_TCNTB2  (*(volatile unsigned int*)TCNTB2)
#define GET_TCMPB2  (*(volatile unsigned int*)TCMPB2)
#define GET_TCNTO2  (*(volatile unsigned int*)TCNTO2)


#define GET_TCNTB3  (*(volatile unsigned int*)TCNTB3)
#define GET_TCMPB3  (*(volatile unsigned int*)TCMPB3)
#define GET_TCNTO3  (*(volatile unsigned int*)TCNTO3)


//no PWM in for timer4
#define GET_TCNTB4  (*(volatile unsigned int*)TCNTB4)
#define GET_TCNTO4  (*(volatile unsigned int*)TCNTO4)


//MUX
#define MUX2	0X0  // 1/2
#define MUX4	0X1	 //  1/4
#define MUX8	0x2	 // 1/8
#define MUX16	0x3	 // 1//16
#define MUXE	0x4	// Extetnal clock







void timer_init(unsigned int n, unsigned int p, unsigned int m );  //init timer n  ,n=1/2/3/4/5,
void timer_start(unsigned int n, unsigned int t, unsigned int p );	//n for timer n, t for counter timers, p for PWM  , p <= t, if  n is 5 ,p wiil be ignored
void timer_stop(unsigned int n); //stop timer n
unsigned int timer_cnto(unsigned int n); 		//return TCONOn observation reg







#endif
















