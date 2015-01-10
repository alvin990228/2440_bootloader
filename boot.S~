/********************************************************************************************
 *Alvin-boot 2015.01.02 writen by Alvin
 *Versin:0.1.0
 *Functions:
 *1.initalize the cpu and memory controler
 *2.set stack at SDRAM
 *3.set the NandFlash Controler
 *4.Copy code from NandFlash to SDRAM
 *5.Run Code on the SDRAM
 *6.Add LED Signal for Debug*********r6 register use to send signal!!
 *
 *2015.01.09
 *Now this project is Managed By GitHub @github.com:alvin990228/2440_bootloader.git
**********************************************************************************************/

#include"s3c2440.h"

.section .text
.global _start
_start:
/*Exception Vectors*/
	/*0x00 Reset*/
	b reset
	
		/* 0x04: Undefined instruction  */
HandleUndef:
    b   HandleUndef 
 
		/* 0x08:  SWI */
HandleSWI:
    b   HandleSWI

  	/* 0x0c: Abort prefech */
HandlePrefetchAbort:
    b   HandlePrefetchAbort

		/* 0x10: Abort data */
HandleDataAbort:
    b   HandleDataAbort

		/* 0x14: Reserved */
HandleNotUsed:
    b   HandleNotUsed

		/* 0x18: IRQ*/
    b   HandleIRQ

		/* 0x1c: FIQ */
HandleFIQ:
    b   HandleFIQ
	
	
	
	
reset:
  
/**********************************************
*Set cpu at SVC mode
***********************************************/
#define SVC
#ifdef SVC
	mrs	r0, cpsr
	bic	r0, r0, #0x1f
	orr	r0, r0, #0xd3
	msr	cpsr, r0
#endif

/***********************************************
*Turn off the watchdog
************************************************/

	ldr	r0, =pWTCON
	mov	r1, #0x0
	str	r1, [r0]


/***********************************************
*Musk all IRQs & FIQs
************************************************/
#define IRQ
#ifdef IRQ
	mov	r1, #0xffffffff
	ldr	r0, =INTMSK
	str	r1, [r0]
	
	ldr	r1, =0x7fff	
	ldr	r0, =INTSUBMSK
	str	r1, [r0]
#endif


/***************SET IRQ STACK*******************
*set IRQ stack for IRQ handling
************************************************/

		msr cpsr_c, #0xd2       @ Alvin+ : Enter the IRQ mode
    		ldr sp, =IRQSTACK       @ Alvin+ : now the sp is irq_sp 

   	        msr cpsr_c, #0xd3       @ Alvin+ : Return to the SVC mode






/***********************************************
*Set CPU Clock
***********************************************/
#define CLOCK
#ifdef CLOCK
   /*MPLL=405Mhz  FCLK:HCLK:PCLK = 1:4:8 */
	ldr	r0, =CLKDIVN
	mov	r1, #5
	str	r1, [r0]
	
	mrc	p15, 0, r1, c1, c0, 0	
	orr	r1, r1, #0xc0000000		
	mcr	p15, 0, r1, c1, c0, 0	
	
	

	
	mov	r1, #CLK_CTL_BASE	
	mov	r2, #MDIV_405	
	add	r2, r2, #PSDIV_405	
	str	r2, [r1, #0x04]		


#endif
/**********************************************
*flush v4 I/D caches & diable MMU
***********************************************/
#define MMU
#ifdef MMU

	/*
	 * flush v4 I/D caches
	 */
	mov	r0, #0
	mcr	p15, 0, r0, c7, c7, 0	/* flush v3/v4 cache */
	mcr	p15, 0, r0, c8, c7, 0	/* flush v4 TLB */

	/*
	 * disable MMU stuff and caches
	 */
	mrc	p15, 0, r0, c1, c0, 0
	bic	r0, r0, #0x00002300	@ clear bits 13, 9:8 (--V- --RS)
	bic	r0, r0, #0x00000087	@ clear bits 7, 2:0 (B--- -CAM)
	orr	r0, r0, #0x00000002	@ set bit 2 (A) Align
	orr	r0, r0, #0x00001000	@ set bit 12 (I) I-Cache
	mcr	p15, 0, r0, c1, c0, 0
#endif

/****************Initialize the LED Signal********************/	

	ldr r0, =0x15400  @set GPB5~GPB8 pin output  
	ldr r1, =GPBCON
	str r0, [r1]

	ldr r0, =0xff
	ldr r1, =GPBUP    @disable pull up
	str r0, [r1]


	ldr r0, =LED_ON   @turn on all LEDs
	ldr r1, =GPBDAT
	str r0, [r1]


/**************Use LED_1 Signal*****************/
	ldr r0, =LED_OFF
	str r0, [r1]
	ldr r6, =LED_1
	 bl led


/**********************************************
*Initialize the Memory Controler
*@Have Bugs@
***********************************************/
#define MEM 
#ifdef MEM

lowlevel_init:

	/* memory control configuration */
	/* make r0 relative the current location so that it */
	/* reads SMRDATA out of FLASH rather than memory ! */
	ldr r0, =SMRDATA
        ldr	r1, =lowlevel_init
	sub	r0, r0, r1
	adr	r3, lowlevel_init		/* r3 <- current position of code   */
	add     r0, r0, r3
	ldr	r1, =BWSCON	/* Bus Width Status Controller */
	add     r2, r0, #13*4
0:
	ldr     r3, [r0], #4
	str     r3, [r1], #4
	cmp     r2, r0
	bne     0b


	@.ltorg /*Use this will regard following code as data  Alvin+*/
.align 4
/* the literal pools origin */

SMRDATA:
    .word (0+(B1_BWSCON<<4)+(B2_BWSCON<<8)+(B3_BWSCON<<12)+(B4_BWSCON<<16)+(B5_BWSCON<<20)+(B6_BWSCON<<24)+(B7_BWSCON<<28))
    .word ((B0_Tacs<<13)+(B0_Tcos<<11)+(B0_Tacc<<8)+(B0_Tcoh<<6)+(B0_Tah<<4)+(B0_Tacp<<2)+(B0_PMC))
    .word ((B1_Tacs<<13)+(B1_Tcos<<11)+(B1_Tacc<<8)+(B1_Tcoh<<6)+(B1_Tah<<4)+(B1_Tacp<<2)+(B1_PMC))
    .word ((B2_Tacs<<13)+(B2_Tcos<<11)+(B2_Tacc<<8)+(B2_Tcoh<<6)+(B2_Tah<<4)+(B2_Tacp<<2)+(B2_PMC))
    .word ((B3_Tacs<<13)+(B3_Tcos<<11)+(B3_Tacc<<8)+(B3_Tcoh<<6)+(B3_Tah<<4)+(B3_Tacp<<2)+(B3_PMC))
    .word ((B4_Tacs<<13)+(B4_Tcos<<11)+(B4_Tacc<<8)+(B4_Tcoh<<6)+(B4_Tah<<4)+(B4_Tacp<<2)+(B4_PMC))
    .word ((B5_Tacs<<13)+(B5_Tcos<<11)+(B5_Tacc<<8)+(B5_Tcoh<<6)+(B5_Tah<<4)+(B5_Tacp<<2)+(B5_PMC))
    .word ((B6_MT<<15)+(B6_Trcd<<2)+(B6_SCAN))
    .word ((B7_MT<<15)+(B7_Trcd<<2)+(B7_SCAN))
    .word ((REFEN<<23)+(TREFMD<<22)+(Trp<<20)+(Trc<<18)+(Tchr<<16)+REFCNT)
    .word 0xb1 /*Alvin+ : in mini2440 BK76MAP 64MB/64MB*/
    .word 0x30
    .word 0x30
	

#endif

/*****************Use LED_2 Signal************/

	ldr r6, =LED_2
	bl led

/**********************************************
*Copy from to SDRAM
*Now the SDRAM is fine ,we can copy the code
*from Steppinstone to SDRAM 
***********************************************/

/*Alvin+ : when copy code from NandFlash 
  *to SDRAM this code should be commented!!
*/
@#define CS
#ifdef CS
	
 
    mov r1, #0
    ldr r2, =SDRAM_BASE
    mov r3, #4*1024
1:  
    ldr r4, [r1],#4     
    str r4, [r2],#4    
    cmp r1, r3          
    bne 1b             
         


#endif

/**********************************************
*Set Stack for copying NandFlash
***********************************************/


	ldr	sp, =SVCSTACK	@ setup stack pointer
	mov	fp, #0   	@ no previous frame, so fp=0

/***********************************************
*Copy code from NandFlash to SDRAM
************************************************/
#define NAND
#ifdef NAND
	bl nand_init
	ldr r0, = SDRAM_BASE  	@nand_read buf
	ldr r1, = 4096			@nand_read start_address
	ldr r2, = 12288			@nand_read size  6*2K
@	bl copyToSDRAM			@**here cannot use ldr pc,=
	bl nand_read
#endif

/***************Use LED_3 Signal******************/
		ldr r6, =LED_3
		bl led



/***********************************************
*Rest Stack for Run C file on the SDRAM
************************************************/

	ldr sp, =SVCSTACK
	mov fp, #0


/************************************************
*Initialize the Interrupt Controler and
*enable the IRQs
*for Using INTs
*************************************************/
	
	
/*Initialize the interrupt*/
	ldr r0, =GPGCON
	ldr r1, =0x80A882  @SET GPIO0,3,5,6,7,11 EINT
	str r1, [r0]
	
	ldr r0, =GPGUP
	ldr r1, =0x8E9    @Disable pull-up
	str r1, [r0]
	
	ldr r0, =EINTMASK
	ldr r1, =0xFFF716FF  @disable masking interrupts
	str r1, [r0]
     	 
	ldr r0, =INTMSK 
    	ldr r1, =0xFFFFFFDF  @EINT8_23 service avaliable
	str r1, [r0]
	

        msr cpsr_c, #0x53       @enable the IRQ in CPSR in SVC mode
/**********************************************
*Everything is fine now,Ready run on the SDRAM
**********************************************/

/******************Use LED_4 Siglan************/
	ldr r6, =LED_4
	bl led

	ldr pc, _f

	_f:
		.word f

@	ldr pc, =f
@	bl f
/************************************************
 *LED Signal used to show program status
 ************************************************/
#define DEBUG
#ifdef DEBUG
led:
	ldr r5, =GPBDAT
	ldr r7, [r5]


	and r6, r6, r7
	str r6, [r5]    @*****r6 use to send led signal only!
	bx lr	

#endif

/***********************************************
*Interrupt Handle
************************************************/



/*******************IRQ*************************/
#define IRQHANDLE
#ifdef  IRQHANDLE


HandleIRQ:
    @sub lr, lr, #4                  @configure the return addr
	ldr lr, _f
    stmdb   sp!,    { r0-r12,lr }   @store the regs in irq stack
                                    
                                    
    
     ldr lr, _int_return               
     ldr pc, _irqhandler    		@invoke irq handler           

_int_return:
	.word int_return
_irqhandler:
	.word irqhandler

int_return:

    ldmia   sp!,  { r0-r12,pc }^      @ ^ means restore the cpsr

	

#endif


/*********************FIQ************************/

#define FIQHANDLE
#ifdef  FIQHANDLE




#endif
