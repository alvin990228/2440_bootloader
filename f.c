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
#include"beep.h"
#include"timer.h"
void f(){ 
	led_init();  //initialize the LEDs
	uart_init(115200, EIGHT_DATA, NO_PARITY, ONE_STOP); //initialize the uart system
	beep_init();
	timer_init(0, 255, MUX8);

	beep_on();
	led_delay(2);
	beep_off();

	/*these messages will be printed at the begining of the bootloaer start!*/
	uart_send("\n\r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>2440_Bootloader<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\
		         \r*Created by Alvin <alvin990228@gmail.com>*\n\
		         \r*Time:2015.01.17\n\
		         \r*Mini2440 platform CPU:S3C2440, SDRAM:64M, NandFlash:256M, NorFlash:2M\n\
		         \r*Now This bootloader includes some simple but interesting functions.\n\
		         \r*1).Initialize the cpu(s3c2440),set CPU clock at 405Mhz\n\
		         \r*2).Initialize the Memory Controler and SDRAM ship \n\
		         \r*3).Initialzie the NAND Flash and copy code from Flash to RAM\n\
		         \r*4).Initialize the LEDs ,you can see leds turned on shiftly\n\
		         \r*5).Initialize the Interrupt controler and you can use keys!\n\
		         \r*6).Initialize the UART as you can see some messages are printed!\n\
		         \r>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\r");
	
	

	while(1){
		
		led_shl(1);
		led_shr(1);
	
	}

        

}
