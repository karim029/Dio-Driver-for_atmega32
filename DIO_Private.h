/*
 * DIO_Private.h
 *
 *  Created on: May 7, 2023
 *      Author: karim
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

// Define Group A registers
#define DIO_U8_DDRA *((volatile u8*)0X3A)
#define DIO_U8_PORTA *((volatile u8*)0X3B)
#define DIO_U8_PINA *((volatile u8*)0X39)

// Define Group B registers
#define DIO_U8_DDRB *((volatile u8*)0X37)
#define DIO_U8_PORTB *((volatile u8*)0X38)
#define DIO_U8_PINB *((volatile u8*)0X36)

// Define Group C registers
#define DIO_U8_DDRC *((volatile u8*)0x34)
#define DIO_U8_PORTC *((volatile u8*)0X35)
#define DIO_U8_PINC *((volatile u8*)0X33)

//Define Group D registers
#define DIO_U8_DDRD *((volatile u8*)0x31)
#define DIO_U8_PORTD *((volatile u8*)0X32)
#define DIO_U8_PIND *((volatile u8*)0X30)



#endif /* DIO_PRIVATE_H_ */
