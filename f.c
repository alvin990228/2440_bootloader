/***************************************
*This is the first C file that will be executed
* After some assamble code in boot.S
*So this file is usually used to test some new 
*functions.
*2015.01.17 Alvin  <alvin99022@gmail.com>
****************************************/
#include"s3c2440.h"
#include"led.h"
#include"uart.h"
//#include<stdlib.h>
void f(){ 
	led_init();  //initialize the LEDs
	uart_init(115200, EIGHT_DATA, NO_PARITY, ONE_STOP); //initialize the uart system
	
	//char string[20] = "Hello World!";
	//string[20] = NULL;

	uart_send('A');
	
	
	

	

	while(1){

		led_shr(1);
		led_shl(1);		
	}

        



}
