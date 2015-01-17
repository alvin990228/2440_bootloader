/*****************************************************
*uart.h  inlcudes  some uart methods  for using uart 
*2015.01.17 Alvin
******************************************************/

#ifndef UART_HEAD
#define UART_HEAD
#include"s3c2440.h"

//data length
#define FIVE_DATA   0x00
#define SIX_DTAT	0x01
#define SEVEN_DATA  0x02
#define EIGHT_DATA	0x03

//stop bit
#define ONE_STOP  0x0
#define TWO_STOP  0x1

//parity mode
#define NO_PARITY 	0x0
#define ODD_PARITY	0x4
#define EVEN_PARITY 0x5




/*
*initialize the uart TxD & RxD port 
*config uart's baud rate and data frame
*/
void uart_init(unsigned int baud_rate, unsigned int data_length, unsigned int parity_mode, unsigned int stop_length);

/*
*send data by TxD
*/
void uart_send(char* str);

/*
*reveive data from uart RxD
*/
unsigned char uart_receive();




#endif
















