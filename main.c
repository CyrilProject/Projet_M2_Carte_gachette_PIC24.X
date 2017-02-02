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

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include "uart.h"
/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

u8 count = 0;
u8 flag = 0;


/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int16_t main(void)
{

    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitGPIO();
    
    /* Initializes Interruptions */
    InitINT();
    
    /* Initialization of the UART */

    InitUART();
    
    
    
    while(1)
    {
        
        Sleep();
        if (RCONbits.SLEEP == 1)
        {
            PutChar(count);
        }
        
    }
}
