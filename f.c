#define GPBCON  (*(volatile unsigned int *)(0x56000010))
#define GPBDAT  (*(volatile unsigned int *)(0x56000014))
#define GPBUP   (*(volatile unsigned int *)(0x56000018))
#define LED_5    ~(1<<5)
#define LED_6    ~(1<<6)
#define LED_7    ~(1<<7)
#define LED_8    ~(1<<8)
#define LED_57   ~((1<<5)|(1<<7))
#define LED_68   ~((1<<6)|(1<<8))
#define LED_OFF  0xFF
#define LED_ON   0x00




static void delay(unsigned long time){

	while(time > 0) time--;


}

static void shL(){
     unsigned int ledon = 0;

	 for(;ledon <= 15;ledon++){
	 
	 		GPBDAT = (ledon<<5); 
			
					delay(300000);
	 }



}
void f(){ 

	GPBCON |=(1<<10)|(1<<12)|(1<<14)|(1<<16);

	GPBUP   =0xff;
	while(1){
/*
 		GPBDAT  = LED_68;

      		delay(300000);
		
		GPBDAT = LED_OFF;
	
		delay(2000000);
		GPBDAT = LED_57;
		
		delay(100000);
		GPBDAT = LED_OFF;
*/
	shL();		

	}

        



}
