/************************************
*beep.h  for using beep in mini2440
*Alvin <alvin90228@gmail.com>
*************************************/
#ifndef BEEP_H
#define BEEP_H 1

#include"s3c2440.h"
#include"led.h"	//led & beep share GPBIO in mini2440




void beep_init();
void beep_on();
void beep_off();


#endif















