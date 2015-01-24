#ifndef S3C2440_HEAD
#define S3C2440_HEAD

/*UNIVERSIAL DATA TYPE DEFINE*/
#define NULL 0x0 


/*GENGRAL STATUS REGISTER*/

#define GSTATU0 0X560000AC  //EXTERNAL PIN STATUS
#define GSTATU1 0X560000B0  //CHIP ID
#define GSTATU2 0X560000B4  //RESET STATUS
#define GSTATU3 0X560000B8  //INFORM REG
#define GSTATU4 0X560000BC  //INFORM REG


/*CPU Initial SFR*/

#define pWTCON	        0x53000000


#define CLKDIVN		0x4C000014	/* clock divisor register */


#define CLK_CTL_BASE	0x4C000000
#define MDIV_405	0x7f << 12	
#define PSDIV_405	0x21		
#define MDIV_200	0xa1 << 12	
#define PSDIV_200	0x31	

/*SET STACK */

#define SVCSTACK  0x33f00000  /*Alvin+ : set stack at the end of SDRAM(SDRAM size is 64M)*/
#define IRQSTACK  0x33000000  /*Alvin+ : set irq stack at the 0x33000000 of the SDRAM    */
 

/*MEMCONTROL SFR  lowlevel_init */


#define SDRAM_BASE  0x30000000	/*Alvin+ :Start address of the SDRAM*/

#define BOOT_SIZE   4096	/*Alvin+ : regard code size as 4K which is enough now*/


#define BWSCON	0x48000000
/* BWSCON */
#define DW8			(0x0)
#define DW16			(0x1)
#define DW32			(0x2)
#define WAIT			(0x1<<2)
#define UBLB			(0x1<<3)

#define B1_BWSCON		(DW16)
#define B2_BWSCON		(DW16)
#define B3_BWSCON		(DW16 + WAIT + UBLB)
#define B4_BWSCON		(DW16)   /*Alvin+  :in mini2440 Bank4 for DM9000*/
#define B5_BWSCON		(DW16)
#define B6_BWSCON		(DW32)   /*Alinv + :in mini2440 Bank6 for SDRAM*/
#define B7_BWSCON		(DW32)

#define B0_Tacs			0x0
#define B0_Tcos			0x0
#define B0_Tacc			0x7
#define B0_Tcoh			0x0
#define B0_Tah			0x0
#define B0_Tacp			0x0
#define B0_PMC			0x0

#define B1_Tacs			0x0
#define B1_Tcos			0x0
#define B1_Tacc			0x7
#define B1_Tcoh			0x0
#define B1_Tah			0x0
#define B1_Tacp			0x0
#define B1_PMC			0x0

#define B2_Tacs			0x0
#define B2_Tcos			0x0
#define B2_Tacc			0x7
#define B2_Tcoh			0x0
#define B2_Tah			0x0
#define B2_Tacp			0x0
#define B2_PMC			0x0

#define B3_Tacs			0xc
#define B3_Tcos			0x7
#define B3_Tacc			0xf
#define B3_Tcoh			0x1
#define B3_Tah			0x0
#define B3_Tacp			0x0
#define B3_PMC			0x0

#define B4_Tacs			0x0
#define B4_Tcos			0x0
#define B4_Tacc			0x7
#define B4_Tcoh			0x0
#define B4_Tah			0x0
#define B4_Tacp			0x0
#define B4_PMC			0x0

#define B5_Tacs			0xc
#define B5_Tcos			0x7
#define B5_Tacc			0xf
#define B5_Tcoh			0x1
#define B5_Tah			0x0
#define B5_Tacp			0x0
#define B5_PMC			0x0

#define B6_MT			0x3	/* SDRAM */
#define B6_Trcd			0x1
#define B6_SCAN			0x1	/* 9bit */

#define B7_MT			0x3	/* SDRAM */
#define B7_Trcd			0x1	/* 3clk */
#define B7_SCAN			0x1	/* 9bit */

/* REFRESH parameter */
#define REFEN			0x1	/* Refresh enable */
#define TREFMD			0x0	/* CBR(CAS before RAS)/Auto refresh */
#define Trc			0x3	/* 7clk */
#define Tchr			0x2	/* 3clk */


#define Trp			0x2	/* 4clk */
#define REFCNT			1322    /*ALvin+ --1012 ++1322 */



/* LED GPIO SFR */

#define GPBCON   0x56000010  /*For LED Signal*/
#define GPBDAT   0x56000014
#define GPBUP    0x56000018
#define LED_ON   0x00
#define LED_OFF  0x1E0
#define LED_1    0x1C0
#define LED_2    0x1A0
#define LED_3    0x160
#define LED_4    0x0E0
/* External Interrupt GPIO 
 * in mini2440 4keys INTS:
 * k1:EINT8,GPG0 k2:EINT11,GPG3 k3:EINT13,GPG5 
 * k4:EINT14,GPG6 k5:EINT15,GPG7 k6:EINT19,GPG11
 */
#define GPGCON  0x56000060    
#define GPGDAT  0x56000064
#define GPGUP   0x56000068

/*Interrupt Controler SRF*/

	
#define SRCPND 0X4A000000  //point the interrupt surce
#define INTMOD 0X4A000004  //SET FIQ INT
#define INTMSK 0X4A000008  //MAKS INT
#define PRIORITY 0X4A00000C //SET INTS PRIORITY
#define INTPND   0X4A000010 //SHOW INT WAIT FOR SERVICE
#define INTOFFSET 0X4A000014 //SHOWS WHICH INTERTUPT REQUEST OF IRQ 
#define SUBSRCPAND 0X4A000018 //SRCPND OF SUB-INT
#define INTSUBMSK 0X4A00001C //INTMSK OF SUB0-INT

//EXTERNAL INT SIGNAL SFR
#define EXTINT0  0X56000088 //SET ENT0-7 SIGNALING
#define EXTINT1  0X5600008C //SET ENT8-15 SIGNALING & FILTER 
#define EXTINT2  0X65000090 //SET ENT16-23 SIGNALING & FILTER
#define EINTFLT0 0X56000094 //RESERVED
#define EINTFLT1 0X56000098 //RESERVED
#define EINTFLT2 0X5600009C	//FILTER CLOCK SET
#define EINTFLT3 0X560000A0 //FILTER CLOCL SET
#define EINTMASK 0X560000A4 //EXINT4-23 MASK CONTROL
#define EINTPEND 0X560000A8 //EXINT4-23 PANDING CONTROL

/*UART SFR*/
#define ULCON0 0X50000000   //UART CHANNEL0 LINE CONTROL REG
#define ULCON1 0X50004000   //UART CHANNEL1 LINE CONTROL REG
#define ULCON2 0X50008000   //UART CHANNEL2 LINE CONTROL REG

#define UCON0  0X50000004   //USART CHANNEL0 CONTROL REG
#define UCON1  0X50004004   //USART CHANNEL1 CONTROL REG
#define UCCON2 0X50008004   //USART CHANNEL2 CONTROL REG

#define UFCON0 0X50000008   //UART FIFO CONTROL CH0
#define UFCON1 0X50004008   //CH1
#define UFCON2 0X50008008   //CH2

#define UMCON0   0X5000000C   //UART MODE CONTROL CH0
#define UMCON1   0X5000400C   //CH1
#define Reserved 0X5000800C   //RESERVED

#define UTRSTAT0 0X50000010   //UART Tx/Rx STATUS CH0
#define UTRSTAT1 0X50004010   //CH1
#define UTRSTAT2 0X50008010   //CH2


#define UERSTAT0  0X50000014   //UART Rx ERROR STATUS CH0
#define UERSTAT1  0X50004014   //CH1
#define UERSTAT2  0X50008014   //CH2

#define UFSTATU0  0X50000018   //UART FIFO STATUS CH0
#define UFSTATU1  0X50004018   //CH1
#define UFSTATU2  0X50008018   //CH2

#define UMSTAT0    0X5000001C    //UART MODE STATUS REG CH0
#define UMSTAT1    0X5000401C    //CH1
#define RESERVED   0X5000801C    //RESERVED

#define UTXH0L  0X50000020   //UART TRANSMIT REG CH0 Little edian
#define UTXH0B  0X50000023	 //CH0 Big edian	
#define UTXH1L  0X50004020   //CH1L
#define UTXH1B  0X50004023	 //CH1B	
#define UTXH2L  0X50008020   //CH2L
#define UTXH2B  0X50008023	 //CH2B

#define URXH0L  0X50000024   //UART  RECVIVE BUF REG CH0L
#define URXH0B  0X50000027   //CH0B
#define URXH1L  0X50004024   //CH1L
#define URXH1B  0X50004027   //CH1B
#define URXH2L  0X50008024   //CH2L 
#define URXH2B  0X50008027   //CH2B


#define UBRDIV0  0X50000028  //UART Baud Rate Divisor REG CH0
#define UBRDIV1  0X50000028  //CH1
#define UBRDIV2  0X50000028  //CH2


/********Uart Port**********************
* in mini2440 TxD0: GPH2, RxD0:GPH3
**************************************/

#define GPHCON 0X560000700
#define GPHDAT 0X56000074
#define GPHUP  0X56000078

/********PWM Timer******************
in mini2440 TOUT0~TOUT3:GPB0~GPB3
************************************/

//timer set regs
#define TCFG0 	0X51000000	//prescaer0,prescaler1,DeadZone Length
#define TCFG1 	0X51000004	//MUX0~4 ,DMA
#define TCON  	0X51000008	//load control

//timer1 with PWM
#define TCNTB0	0X5100000c	//timer count buffer	
#define TCMPB0	0X51000010	//timer compare buffer
#define TCNTO0	0X51000014	//count observation

//timer2 with PWM
#define TCNTB1	0X51000018	
#define TCMPB1	0X5100001c
#define TCNTO1	0X51000020

//timer3 with PWM
#define TCNTB2	0X51000024	
#define TCMPB2	0X51000028
#define TCNTO2	0X5100002c

//timer4 with PWM
#define TCNTB3	0X51000030	
#define TCMPB3	0X51000034
#define TCNTO3	0X51000038

//timer5 without PWM
#define TCNTB4	0X5100003c	
#define TCNTO4	0X51000040






#endif
