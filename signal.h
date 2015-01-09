/******************************************
*signal.h Alvin 2015.01.03
*signal.h defines signal infor 
*and signal method
********************************************/
#ifndef SIGNAL
#define SIGNAL

#define SIG_INIT 		 0
#define SIG_RECOVER  	 1
#define SIG_1     		 2
#define SIG_2			 3
#define SIG_3			 4
#define SIG_4			 5

unsigned int signal(unsigned int SIG,unsigned int status);


#endif

