#ifndef S3C2440
#define S3C2440

/*CPU Initial SFR*/

#define pWTCON	        0x53000000

#define INTMSK		0x4A000008	/* Interupt-Controller base addresses */
#define INTSUBMSK	0x4A00001C

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











#endif