/******************************************************
*2015.01.10 Alvin+  Keys IRQ handler function
*******************************************************/
#include"s3c2440.h"
#include"led.h"
#include"uart.h"
#include"timer.h"
#include"keys.h"
#include"beep.h"



void nokeys(){
      led_flash(2);
	  led_delay(15);
	  led_shr(2);
	  led_delay(15);
	  led_shl(2);
	  led_delay(10);

}
void k1(){
	
	uart_send("\rTimer0:  START !\n\r");

	led_delay(7);  //delay some time for  filter
		
	timer_start(0, 65535, 0);
	

}
void k2(){

		uart_send("\rTimer0  STOP !\n\r");
		led_delay(5);  //delay some time for  filter
		timer_stop(0);

}
void k3(){

		uart_send("\rBEEP: Bee.....!\n\r");

		led_delay(7);  //delay some time for  filter

		beep_on();
}

void k4(){

		uart_send("\rBEEP: STOP !\n\r");

		led_delay(7);  //delay some time for  filter

		beep_off();
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
