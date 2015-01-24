/************************************
*Uart.c provies  uart functions
*2015.01.17 Alvin
************************************/
#include"s3c2440.h"
#include"uart.h"
#include"led.h"






//test transmit buffer sataus
static unsigned char trans_ready()
{
	return GET_UTRSATA0 & (1 << 2); 
}


//test receive buffer status
static unsigned char  rec_ready()
{
	return GET_UTRSATA0 & (1 << 0);
}


/*
*initialize the uart TxD & RxD port 
*config uart's baud rate and data frame
*/
void uart_init(unsigned int baud_rate, unsigned int data_length, unsigned int parity_mode, unsigned int stop_length)
{	

	GET_GPHCON |= ((1<<5)|(1<<7));  //set  GPH2 TxD GPH3 RxD function
	
	GET_GPHUP  &=~((1<<2)|(1<<3));  //enable pull-up for TxD & RxD

	

	
	GET_ULCON0 = ((data_length << 0)|(parity_mode << 3)|(stop_length << 2));  //set uart data  bit ,parity mode , stop length

	GET_UCON0 = 0x05; //use PCLK  send & get data by  polling  or interrupt

	GET_UFOCN0 = 0x00;//disable FIFO
	GET_UMCON0 = 0x00;//disable flow control



	GET_UBRDIV0 = 26; //set baud rate ,now the MPLL is 405Mhz ,PCLK is 50626000hz,in this UBRDIV0 should be 26~27

	

}
/*
*send data by TxD
*/
void uart_send(char* str)
{
	char* p = str;


	while( *p != NULL ){

		
		while(!(trans_ready())); //wait untile trans buffer is ready!
		
			GET_UTXH0 = *p++;
			
			
		
	}
	

}


/*
*reveive data from uart RxD
*/
unsigned char uart_receive()
{

	char ch ;
	

	while(!(rec_ready())); //wait untile trans buffer is ready!
		
			ch = GET_URXH0 ;

			
	char str[2] ={ch, NULL};

			uart_send(str);
			


}










