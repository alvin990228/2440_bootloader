/**************LED*****************
 *This file is used to deal with
 *LEDs needs
 * ********************************/
#include"led.h"


//Initialize the led gpio
void led_init(){

	GPBCON = LED_IO;     //set GPB5~8 oupput
	GPBUP  = LED_DISUP;  //disable pull-up  


}


//delay some time 
//!!do not use optimization when compiling
void led_delay(unsigned long time){
	while(time > 0) time--;	
}

//switch on all leds
void led_allon(){
	GPBDAT = LED_ALLON;
}



//switch off
void led_alloff(){
	GPBDAT = LED_ALLOFF;

}


//
void led_non(unsigned int n){
	switch(){
	
		case 1:
			GPBDAT = LED_1ON;
			break;
		case 2:
			GPBDAT = LED_2ON;
			break;
		case 3:
			GPBDAT = LED_3ON;
			break;
		case 4:
			GPBDAT = LED_4ON;
			break;
		default:
			GPBDAT = LED_ALLON;

	
	}	

}


//
void led_noff(unsigned int n){
	switch(){
	
		case 1:
			GPBDAT = LED_1OFF;
			break;
		case 2:
			GPBDAT = LED_2OFF;
			break;
		case 3:
			GPBDAT = LED_3OFF;
			break;
		case 4:
			GPBDAT = LED_4OFF;
			break;
		default:
			GPBDAT = LED_ALLOFF;

	
	}	
}

void led_shl(unsigned int time){
	

}

void led_shr(){


}

void led_flash(unsigned int time){


	
	while( time > 0 ){
		
		GPBDAT = LED_ALLON;

		led_delay(100000);

		GPBDAT = LED_ALLOFF;

		led_delay(100000);

		time--;
	}



}
