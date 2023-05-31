/*
 * DIO_INTERFACE.h
 *
 *  Created on: May 7, 2023
 *      Author: karim
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

// Port define//
#define Group_A 0
#define Group_B 1
#define Group_C 2
#define Group_D 3

// Pin define//
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//pin direction define//
#define INPUT 0
#define OUTPUT 1

//pin value define//
#define HIGH 1
#define LOW 0

//Handler for error in using the functions
#define Invalid_Pin_Value 0xFF
#define Invalid_Pin_ID 0xFF

//FUNCTIONS FOR PIN OPERATIONS
u8 DIO_U8_SetPinValue(u8 copy_U8_Port_ID,u8 copy_U8_Pin_ID, u8 copy_U8_Pin_Val);

u8 DIO_U8_GetPinValue(u8 Copy_U8_Port_ID,u8 Copy_U8_Pin_ID);

void DIO_U8_SetPinDirection(u8 Copy_U8_Port_ID,u8 Copy_U8_Pin_ID,u8 Copy_U8_Pin_Dir);

//FUNCTIONS FOR PORTS OPERATIONS
void DIO_U8_SetPortDirection(u8 Copy_U8_Port_ID,u8 Copy_u8_Port_Dir);

void DIO_U8_SetPortValue(u8 Copy_U8_Port_ID , u8 Copy_U8_Port_Val);


#endif /* DIO_INTERFACE_H_ */
