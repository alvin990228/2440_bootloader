/**************LED*****************
 *This file is used to deal with
 *LEDs needs
 * ********************************/
#include"led.h"


//Initialize the led gpio
void led_init(){

	GET_GPBCON |= LED_IO;     //set GPB5~8 oupput
	GET_GPBUP  |= LED_DISUP;  //disable pull-up  


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
	GET_GPBDAT &= LED_ALLON;
}



//switch off
void led_alloff(){
	GET_GPBDAT |= LED_ALLOFF;

}


//switch on  led n
void led_non(unsigned int n){
	switch(n){
	
		case 1:
			GET_GPBDAT &= LED_1ON;
			break;
		case 2:
			GET_GPBDAT &= LED_2ON;
			break;
		case 3:
			GET_GPBDAT &= LED_3ON;
			break;
		case 4:
			GET_GPBDAT &= LED_4ON;
			break;
		default:
			GET_GPBDAT &= LED_ALLON;

	
	}	

}


//switch off led n
void led_noff(unsigned int n){
	switch(n){
	
		case 1:
			GET_GPBDAT |= LED_1OFF;
			break;
		case 2:
			GET_GPBDAT |= LED_2OFF;
			break;
		case 3:
			GET_GPBDAT |= LED_3OFF;
			break;
		case 4:
			GET_GPBDAT |= LED_4OFF;
			break;
		default:
			GET_GPBDAT |= LED_ALLOFF;

	
	}	
}

//switch on leds by shifting lift
void led_shl(unsigned int time){
		led_alloff();	//cleat all leds
		
		while(time > 0 ){

			led_non(1);
			led_delay(10);
			led_noff(1);
			
			
			led_non(2);
			led_delay(10);
			led_noff(2);
			
			
			led_non(3);
			led_delay(10);
			led_noff(3);

			
			led_non(4);
			led_delay(10);
			led_noff(4);
			led_delay(10);
			
			time--;
		}
}

//switch on leds by shifting right
void led_shr(unsigned int time){
	led_alloff();	//clear all leds
	while(time > 0){
			led_non(4);
			led_delay(10);
			led_noff(4);
			
			
			led_non(3);
			led_delay(10);
			led_noff(3);
			
			
			led_non(2);
			led_delay(10);
			led_noff(2);
			
			
			led_non(1);
			led_delay(10);
			led_noff(1);
			led_delay(10);
			
			time--;
	}

}

void led_flash(unsigned int time){


	
	while( time > 0 ){
		
		GET_GPBDAT &= LED_ALLON;

		led_delay(10);

		GET_GPBDAT |= LED_ALLOFF;

		led_delay(10);

		time--;
	}



}





