#include"led.h"

void f(){ 
	led_init();

	while(1){

			led_allon();

			led_delay(10);

			led_noff(2);

			led_delay(10);

			led_noff(3);
		
			led_delay(10);

			led_noff(1);
			
			led_delay(10);

			led_noff(4);
			
			led_delay(15);

			led_flash(3);
			led_delay(20);

			led_shr(2);

			led_delay(13);

			led_shl(4);		
	}

        



}
