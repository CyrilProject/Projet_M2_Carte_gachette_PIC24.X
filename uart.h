/* 
 * File:   uart.h
 * Author: Cyril, Fabian, Vincent
 *
 * Created on February 1st 2017, 09:49AM
 */



// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef UART_H
#define	UART_H


#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>
#include <string.h>
#include "user.h"

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

u8 GetChar();
void PutChar(u8);
void PutString(u8 *);
void PutData16(u16);


#endif	/*  UART_H */

