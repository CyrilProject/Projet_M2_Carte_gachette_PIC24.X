#ifndef USER_H
#define	USER_H

/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/
#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned long
#define s8 signed char
#define s16 signed short
#define s32 signed long



#define SIGNAL_A        0          /* Signal A from the incremental encoder */
#define SIGNAL_B        1          /* Signal B from the incremental encoder */
#define SYS_FREQ        8000000L
#define FCY             SYS_FREQ/2
#define BAUDRATE        9600       /* UART Baudrate */
#define BRGVAL          ((FCY/BAUDRATE)/16)-1


/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/



void InitGPIO(void);         /* I/O and Peripheral Initialization */

void InitUART(void);        /* UART Inititalization */

void InitINT(void);         /* INT2  & CN0 Initialization */

#endif USER_H