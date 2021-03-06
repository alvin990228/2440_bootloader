/******************************************************
*2015.01.10 Alvin+  Keys IRQ handler function
*******************************************************/
#include"s3c2440.h"
#include"led.h"
#include"uart.h"

#define GET_KEY (*(volatile unsigned int *)EINTPEND)
#define GET_IRQ (*(volatile unsigned int *)SRCPND)
#define GET_INTMSK (*(volatile unsigned int *)INTMSK)
#define GET_INTPND  (* (volatile unsigned int *)INTPND)
#define KEYS  (1<<5)  //EINT8_23  SRCPND[5]  
#define KEY1  	(1<<8)
#define KEY2	(1<<11)
#define KEY3    (1<<13)
#define KEY4	(1<<14)
#define KEY5	(1<<15)
#define KEY6	(1<<19)

void nokeys();
void k1();
void k2();
void k3();
void k4();
void k5();
void k6();
void kdefault();

void irqhandler(){
	
	unsigned int status = GET_GPBDAT;  //store the GPBDAT status

	led_alloff();
	
	unsigned int irq =  GET_IRQ;
	
	if( KEYS & irq ){    //if IRQ is EINT8_23
	
		unsigned int key =  GET_KEY;
		
				switch(key){
				
						case KEY1:
								uart_send("\r\nNow Key_1 is pressed!\n");
								k1();
								break;
								
						case KEY2:
								uart_send("\r\nNow Key_2 is pressed!\n");
								k2();
								break;
								
						case KEY3:
 								uart_send("\r\nNow Key_3 is pressed!\n");
								k3();
								break;
								
						case KEY4:
								uart_send("\r\nNow Key_4 is pressed!\n");
								k4();
								break;
								
						case KEY5:
								uart_send("\r\nNow Key_5 is pressed!\n");
								k5();
								break;
								
						case KEY6:
								uart_send("\r\nNow Key_6 is pressed!\n");
								k6();
								break;
						default:
								kdefault();
				}
		
				
									
	}

	

	else{

		nokeys();
		GET_IRQ = GET_IRQ; //clear the SRCPND 
	}

		GET_GPBDAT = status;  //recover the  GPBDAT
		GET_KEY = GET_KEY;    //clear the EINTPEND
		GET_IRQ = GET_IRQ;    //clear the SRCPND
		GET_INTPND = GET_INTPND; //clear the INTPND

}



void nokeys(){
      led_flash(2);
	  led_delay(15);
	  led_shr(2);
	  led_delay(15);
	  led_shl(2);
	  led_delay(10);

}
void k1(){
		int i = 2;
		while(i > 0){
		led_non(1);
		led_delay(30);
		led_noff(1);
		led_delay(20);

		i--;
		}

}
void k2(){

		int i = 2;
		while(i > 0){
		led_non(2);
		led_delay(30);
		led_noff(2);
		led_delay(20);

		i--;
		}

}
void k3(){

		int i = 2;
		while(i > 0){
		led_non(1);
		led_non(2);
		led_delay(30);
		led_noff(1);
		led_noff(2);
		led_delay(20);

		i--;
		}
}

void k4(){

		int i = 2;
		while(i > 0){
		led_non(3);
		led_delay(30);
		led_noff(3);
		led_delay(20);

		i--;
		}
}

void k5(){

		int i = 2;
		while(i > 0){
		led_non(1);
		led_non(3);
		led_delay(30);
		led_noff(1);
		led_noff(3);
		led_delay(20);

		i--;
		}
}

void k6(){

		int i = 2;
		while(i > 0){
		led_non(2);
		led_non(3);
		led_delay(30);
		led_noff(2);
		led_noff(3);
		led_delay(20);

		i--;
		}

}

void kdefault(){
		led_non(2);
		led_non(4);

		led_delay(30);

		led_noff(2);
		led_noff(4);

}
