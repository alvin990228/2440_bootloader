/**************LED*****************
 *This file is used to deal with
 *LEDs needs
 * ********************************/
#include"led.h"


//Initialize the led gpio
void led_init(){

	GPBCON |= LED_IO;     //set GPB5~8 oupput
	GPBUP  |= LED_DISUP;  //disable pull-up  


}


//delay some time 
//!!do not use optimization when compiling
void led_delay(unsigned long time){
	    unsigned int n;
		while(time > 0) {
			
			n = 100000;

				while(n >  0)n--;
	
			time--;
	}	
}

//switch on all leds
void led_allon(){
	GPBDAT &= LED_ALLON;
}



//switch off
void led_alloff(){
	GPBDAT |= LED_ALLOFF;

}


//switch on  led n
void led_non(unsigned int n){
	switch(n){
	
		case 1:
			GPBDAT &= LED_1ON;
			break;
		case 2:
			GPBDAT &= LED_2ON;
			break;
		case 3:
			GPBDAT &= LED_3ON;
			break;
		case 4:
			GPBDAT &= LED_4ON;
			break;
		default:
			GPBDAT &= LED_ALLON;

	
	}	

}


//switch off led n
void led_noff(unsigned int n){
	switch(n){
	
		case 1:
			GPBDAT |= LED_1OFF;
			break;
		case 2:
			GPBDAT |= LED_2OFF;
			break;
		case 3:
			GPBDAT |= LED_3OFF;
			break;
		case 4:
			GPBDAT |= LED_4OFF;
			break;
		default:
			GPBDAT |= LED_ALLOFF;

	
	}	
}

//switch on leds by shifting lift
void led_shl(unsigned int time){
		while(time > 0 ){
			GPBDAT = LED_1ON;
			led_delay(10);
			GPBDAT = LED_2ON;
			led_delay(10);
			GPBDAT = LED_3ON;
			led_delay(10);
			GPBDAT = LED_4ON;
			led_delay(10);

			time--;
		}
}

//switch on leds by shifting right
void led_shr(unsigned int time){
	while(time > 0){
			GPBDAT = LED_4ON;
			led_delay(10);
			GPBDAT = LED_3ON;
			led_delay(10);
			GPBDAT = LED_2ON;
			led_delay(10);
			GPBDAT = LED_1ON;
			led_delay(10);

			time--;
	}

}

void led_flash(unsigned int time){


	
	while( time > 0 ){
		
		GPBDAT &= LED_ALLON;

		led_delay(10);

		GPBDAT |= LED_ALLOFF;

		led_delay(10);

		time--;
	}



}
