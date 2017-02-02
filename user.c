/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__PIC24E__)
    	#include <p24Exxxx.h>
    #elif defined (__PIC24F__)||defined (__PIC24FK__)
	#include <p24Fxxxx.h>
    #elif defined(__PIC24H__)
	#include <p24Hxxxx.h>
    #endif
#endif

#include <stdint.h>          /* For uint32_t definition */
#include <stdbool.h>         /* For true/false definition */

#include "user.h"            /* variables/params used by user.c */

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

/* TODO Initialize User Ports/Peripherals/Project here */

void InitGPIO(void)
{
    /* Setup analog functionality and port direction */

    /* Initialize peripherals */
    //************************************************************
    // Configure Input Functions
    //************************************************************
    
    /* Input Change Notification CN0 (SIGNAL A) SETTINGS*/
   
    TRISAbits.TRISA4 = 1;         /* set RA4 (CN0) as input */
    
    /* Interruption INT2(SIGNAL B) SETTINGS*/
    
    TRISAbits.TRISA6 = 1;         /* set RA6 (INT2) as input */
    
    
    /* UART SETTINGS*/
    
    
    TRISBbits.TRISB15 = 1;         /* set RB15 (Rx) as input */
    
    TRISBbits.TRISB14 = 0;         /* set RB14 (Tx) as output */
    
}




void InitUART(void)
{
    U1MODEbits.STSEL = 0; // 1-Stop bit
    
    U1MODEbits.PDSEL = 0; // No Parity, 8-Data bits
    
    U1MODEbits.ABAUD = 0; // Auto-Baud disabled
    
    U1MODEbits.BRGH = 0; // Standard-Speed mode
    
    U1BRG = BRGVAL; // Baud Rate setting for 9600
    
    U1STAbits.UTXISEL0 = 0; // Interrupt after one TX character is transmitted
    
    U1STAbits.UTXISEL1 = 0;
            
    U1MODEbits.UARTEN = 1; // Enable UART
    
    U1STAbits.UTXEN = 1; // Enable UART TX
}

void InitINT(void)
{
    IEC1bits.INT2IE = 1 ;    /* External Interruption INT2 Enabled */
    
    IPC7bits.INT2IP = 0b111;   /* Highest Priority Level INT2 */
    
    
    
    CNEN1bits.CN0IE = 1;    /* Enable CN0 channel interruption only */
    
    CNPD1bits.CN0PDE = 0;   /* Pull Down Resistor disabled on CN0 */
    CNPU1bits.CN0PUE = 0;   /* Pull Up Resistor disabled on CN0 */
    
    IEC1bits.CNIE = 1;      /* Enable CN Interruption */
    
    IPC4bits.CNIP = 0b111;   /* Highest Priority Level INT2 */
}