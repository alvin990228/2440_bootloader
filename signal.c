#include"signal.h"

#define GPBDAT (*(volatile unsigned int*) 0x56000014)
#define LED_ON		0x00
#define LED_OFF		0x1E0
#define LED_1		0xE0
#define LED_2       0x160
#define LED_3		0x1A0
#define LED_4		0x1C0

static void delay(unsigned int time){

	while(time > 0) time--;

}


static void shl(){

	unsigned int sig = 0xFFDF; //1110
	int i;
			for(i = 0;i <= 3;i++){

				GPBDAT = sig;
			   	delay(1000000);
					sig <<= 1;

			}

				delay(1000000);

}


static void shr(){


	unsigned int sig = 0xFEFF; //0111
			int i ;
			for(i = 0;i <= 3 ;i++){
				GPBDAT = sig;
			   	delay(1000000);
					sig >>= 1;
			}

}

static void flasher(unsigned int t){
		for(;t > 0;t--){
		
		GPBDAT = LED_ON;
		delay(1000000);

		GPBDAT = LED_OFF;

		delay(1000000);
		
		}

}

static unsigned int sig_init(){
		  unsigned int status = GPBDAT;
			shl();
			shr();

			flasher(2);
		  return status;


}

static unsigned int sig_recover(unsigned int status){


		shr();
		shl();
		flasher(2);

		GPBDAT = status;
		delay(3000000);
		return GPBDAT;

}

static unsigned int sig_1(){
	GPBDAT = LED_1;
	delay(1000000);
	return GPBDAT;

}

static unsigned int sig_2(){
	GPBDAT = LED_2;
	delay(1000000);
	return GPBDAT;

}


static unsigned int sig_3(){
	GPBDAT = LED_3;
	delay(1000000);
	return GPBDAT;
}

static unsigned int sig_4(){
	GPBDAT = LED_4;
	delay(1000000);
	return GPBDAT;
}

unsigned int signal(unsigned int SIG,unsigned int status){

		unsigned int st;


		if(SIG == SIG_INIT)
				st = sig_init();
		else if(SIG == SIG_RECOVER)
				st = sig_recover(status);
		else if(SIG == SIG_1)
				st = sig_1();
		else if(SIG == SIG_2)
				st = sig_2();
		else if(SIG == SIG_3)
				st = sig_3();
		else if(SIG == SIG_4)
			    st = sig_4();
		else 
			    flasher(3);	
			
/*
	switch(SIG){
	
		case 0:
			st = sig_init();
			break;
		case 1:
			st = sig_recover(status);
			break;
		case 2:
			st = sig_1();
			break;
		case 3:
			st = sig_2();
			break;
		case 4:
			st = sig_3();
			break;
		case 5:
			st = sig_4();
			break;		

	default:
			st = sig_init();
	
	}
*/
	return st;

}


