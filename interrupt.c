/*************************************
*interrupt.c  including some IRQs handler
*2015.01.23 Alvin <alvin990228@gmai.com>
**************************************/
#include"s3c2440.h"
#include"uart.h"
#include"led.h"
#include"timer.h"
#include"interrupt.h"
#include"keys.h"



void irqhandler()		//handle IRQs
{
		
		
	  	switch(GET_INTPND){
			case EINT8_23:
							int_keys();	//keys IRQ
							GET_SRCPND |= EINT8_23; //clear eint8_23 bit in SRCPND reg
							break;
			case INT_UART0:
							GET_SRCPND |= INT_UART0;
							break;
			case INT_UART1:
							GET_SRCPND |= INT_UART1;
							break;
			case INT_UART2:
							GET_SRCPND |= INT_UART2;
							break;				
			case INT_TIMER0:
							int_timer(); // timer IRQ
							GET_SRCPND |= INT_TIMER0;	
							break;
			case INT_TIMER1:
							int_timer(); // timer IRQ
							GET_SRCPND |= INT_TIMER1;
							break;
			case INT_TIMER2:
							int_timer(); // timer IRQ
							GET_SRCPND |= INT_TIMER2;
							break;
			case INT_TIMER3:
							int_timer(); // timer IRQ
							GET_SRCPND |= INT_TIMER3;
							break;
			case INT_TIMER4:
							int_timer(); // timer IRQ
							GET_SRCPND |= INT_TIMER4;
							break;

			default:
					GET_SRCPND = GET_SRCPND; //clear all bits in SRCPND reg
				
		}  
			

		GET_INTPND = GET_INTPND; //clear the INTPND

}

void int_keys(){

		
	unsigned int key =  GET_EINTPEND;
	
				switch(key){
				
						case KEY1:
								
								k1();
								GET_EINTPEND |= KEY1; //clear eint8_23 bit in SRCPND reg
								break;
								
						case KEY2:
								
								k2();
								GET_EINTPEND |= KEY2; //clear the EINTPND bit
								break;
								
						case KEY3:
 								
								k3();
								GET_EINTPEND |= KEY3; //clear the EINTPND bit
								break;
								
						case KEY4:
								
								k4();
								GET_EINTPEND |= KEY4; //clear the EINTPND bit
								break;
								
						case KEY5:
								uart_send("\r\nNow Key_5 is pressed!\n\r");
								k5();
								GET_EINTPEND |= KEY5; //clear the EINTPND bit
								break;
								
						case KEY6:
								uart_send("\r\nNow Key_6 is pressed!\n\r");
								k6();
								GET_EINTPEND |= KEY6; //clear the EINTPND bit
								break;
						default:
								kdefault();
								GET_EINTPEND |= (KEY1|KEY2|KEY3|KEY4|KEY5|KEY6); //clear all keys bits int the EINTPND 
				}

		
}
void int_timer(){

		uart_send("\rTime0: COUNT OVER!\n\r");
		led_flash(3);

}
void int_uart(){




}










