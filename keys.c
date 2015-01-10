/******************************************************
*2015.01.10 Alvin+  Keys IRQ handler function
*******************************************************/
#include"s3c2440.h"
#include"led.h"

#define GET_KEY (*(volatile unsigned int *)EINTPEND)
#define GET_IRQ (*(volatile unsigned int *)SRCPND)
#define GET_INTMSK (*(volatile unsigned int *)INTMSK)
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
	led_shr(1);

	unsigned int irq =  GET_IRQ;
	if( KEYS & irq ){    //if IRQ is EINT8_23
	
		unsigned int key =  GET_KEY;
		
				switch(key){
				
						case KEY1:
								k1();
								break;
						case KEY2:
								k2();
								break;
						case KEY3:
								k3();
								break;
						case KEY4:
								k4();
								break;
						case KEY5:
								k5();
								break;
						case KEY6:
								k6();
								break;
						default:
								kdefault();
				}
		GET_KEY = GET_KEY; //clear the EINTPEND
		GET_IRQ = GET_IRQ; //clear the SRCPND
				
									
	}

	led_flash(2);

	GET_INTMSK = 0xFFFFFFFF;  //MASK ALL INTs
/*
	else{

		nokeys();
		GET_IRQ = GET_IRQ; //clear the SRCPND 
	}
*/
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
