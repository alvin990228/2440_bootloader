#include"led.h"

void f(){ 
	led_init();

	while(1){

		led_shr(1);
		led_shl(1);		
	}

        



}
