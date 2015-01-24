/********************************
*timer.c  contains some functions
*for using  timer in mini2440
*2015.01.23 Alvin <alvin990228@gmail.com>
********************************/
#include"timer.h"
#include"led.h"




/*tiemr initialization function
*n:initialization for timer n,0~4
*p: prescaler0&1 0 for timer0~1, 1 for timer2~4
*m: MUX0~4
*/
void timer_init(unsigned int n, unsigned int p, unsigned int MUX )
{

	if(n < 0 || n > 4) //if n is an invalid value n will be set a default 0
		n = 0;

	if(n <= 1){	//set  prescaler0 for timer 0&1
	
		GET_TCFG0 &= ~255; //clear the perscaler0
		GET_TCFG0 |= (p << 0);
		
	}else{  //set prescaler1 for timer2~4
	
		GET_TCFG0 &= ~(255 << 8); 
		GET_TCFG0 |= (p << 8); 	
	}

	
	GET_TCFG1 &= ~(15 << (n*4));	//clean MUX
	GET_TCFG1 |= (MUX << (n*4));//set MUX
	
	
}


//n for timer n, t for counter timers, p for PWM  , p <= t, if  n is 5 ,p wiil be ignored
void timer_start(unsigned int n, unsigned int t, unsigned int p )	
{
	if(n < 0 || n > 4) //if n is an invalid value n will be set a default 0
		n = 0;

		
		unsigned int offsite = 0;

		switch(n){	//set timer n

			case 0:
				GET_TCNTB0 = t ;
			    GET_TCMPB0 = p;
				offsite = 0;
				break;
			case 1:
				GET_TCNTB1 = t ;
			    GET_TCMPB1 = p;
				offsite = 8;
				break;
			case 2:
				GET_TCNTB2 = t ;
			    GET_TCMPB2 = p;
				offsite = 12;
				break;
			case 3:
				GET_TCNTB3 = t ;
			    GET_TCMPB3 = p;
				offsite = 16;
				break;
			case 4:
				GET_TCNTB4 = t ;
			   //no PWM compare buffer reg for timer4
				offsite = 20;
				break;
				
			default:	
				GET_TCNTB0 = t;
				GET_TCMPB0 = p;
				offsite = 0;
				

		}


		GET_TCON &= ~(1 << 4 ); //disable  Dad Zone 

		GET_TCON &= ~(1 << (offsite + 2));	//disable invert

		GET_TCON |= (1 << (offsite + 3));  	//enale aout-reloade

		GET_TCON |= (1 << (offsite + 1));  	//update the count&compare reg  manually 

		GET_TCON |= (1 << offsite );  	//TIMER START NOW !

		GET_TCON &= ~(1 << (offsite + 1));  	//disable manual after load  start value

		


}
void timer_stop(unsigned int n) //stop timer n
{

	unsigned int offsite = 0;

		switch(n){	//set timer n

			case 0:
				
				offsite = 0;
				break;
			case 1:
				
				offsite = 8;
				break;
			case 2:
				
				offsite = 12;
				break;
			case 3:
				
				offsite = 16;
				break;
			case 4:
				
				offsite = 20;
				break;
				
			default:	
				
				offsite = 0;
				

		}


		GET_TCON &= ~(1 << offsite );  	//TIMER STOP NOW !

}


unsigned int timer_cnto(unsigned int n)		//return TCONOn observation reg
{

	 unsigned int num;

	switch(n){	//set timer n

			case 0:
				num = GET_TCNTO0;
			case 1:
				num = GET_TCNTO1;
				break;
			case 2:
				num = GET_TCNTO2;
				break;
			case 3:
				num = GET_TCNTO3;
				break;
			case 4:
				num = GET_TCNTO4;
				break;
				
			default:	
				num = GET_TCNTO0;
		}


	return num;
				

		


}










