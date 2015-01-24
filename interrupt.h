/*******************************************
*interrupt.h  handle interrupts
*2015.01.23 Alvin <avlin990228@gmal.cim>
********************************************/

#ifndef INTERRUPT_H
#define INTERRUPT_H 1

#include"s3c2440.h"


#define GET_EINTPEND	(*(volatile unsigned int *)EINTPEND)
#define GET_SRCPND		(*(volatile unsigned int *)SRCPND)
#define GET_INTMSK		(*(volatile unsigned int *)INTMSK)
#define GET_INTPND		(*(volatile unsigned int *)INTPND)


#define EINT8_23 	 (1 << 5 ) 

#define INT_UART0	 (1 << 28)
#define INT_UART1	 (1 << 23)
#define INT_UART2	 (1 << 15)

#define INT_TIMER0	 (1 << 10)
#define INT_TIMER1	 (1 << 11)
#define INT_TIMER2	 (1 << 12)
#define INT_TIMER3	 (1 << 13)
#define INT_TIMER4	 (1 << 14)








void irqhandler();		//handle IRQs
void int_keys();
void int_timer();
void int_uart();







#endif





