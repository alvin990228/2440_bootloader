/***************************************
*beep.c including functions to use
*beep in mini2440 platform
*Alvin 2015.01.23 <alvin99022@gmail.com>
****************************************/
#include"beep.h"


void beep_init(){

	GET_GPBUP  |= (1<<0);	//disable GPB-UP for GPB0
	GET_GPBCON |= (1<<0);	//set BPG0 output
	GET_GPBDAT &= ~(1<<0);	//trun off the beep

	
	
		

}
void beep_on(){

	GET_GPBDAT |= (1<<0);	//turn on the beep

}
void beep_off(){

	GET_GPBDAT &= ~(1<<0);	//trun off the beep
}













