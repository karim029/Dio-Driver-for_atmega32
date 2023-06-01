
/*
 * DIO_CONFIG.h
 *
 *  Created on: May 6, 2023
 *      Author: karim
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

//FUNCTIONS FOR PIN OPERATIONS
u8 DIO_U8_SetPinValue(u8 copy_U8_Port_ID,u8 copy_U8_Pin_ID, u8 copy_U8_Pin_Val);

u8 DIO_U8_GetPinValue(u8 Copy_U8_Port_ID,u8 Copy_U8_Pin_ID);

void DIO_U8_SetPinDirection(u8 Copy_U8_Port_ID,u8 Copy_U8_Pin_ID,u8 Copy_U8_Pin_Dir);

//FUNCTIONS FOR PORTS OPERATIONS
void DIO_U8_SetPortDirection(u8 Copy_U8_Port_ID,u8 Copy_u8_Port_Dir);

void DIO_U8_SetPortValue(u8 Copy_U8_Port_ID , u8 Copy_U8_Port_Val);



#endif /* DIO_CONFIG_H_ */



