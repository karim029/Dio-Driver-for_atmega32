/*
 * DIO_Program.c
 *
 *  Created on: May 7, 2023
 *      Author: karim
 */


#include "STD_Types.h"
#include "bit_calc.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"



u8 DIO_U8_SetPinValue(u8 copy_U8_Port_ID,u8 copy_U8_Pin_ID, u8 copy_U8_Pin_Val){

	if((copy_U8_Pin_ID>=PIN0) && (copy_U8_Pin_ID <= PIN7) ){
		if((copy_U8_Pin_Val == LOW) || (copy_U8_Pin_Val ==HIGH) ){
	switch(copy_U8_Port_ID){

	case Group_A:
			assign_Bit(DIO_U8_PORTA,copy_U8_Pin_ID,copy_U8_Pin_Val);
		break;

	case Group_B:
		assign_Bit(DIO_U8_PORTB,copy_U8_Pin_ID,copy_U8_Pin_Val);
		break;

	case Group_C:
			assign_Bit(DIO_U8_PORTC,copy_U8_Pin_ID,copy_U8_Pin_Val);
		break;

	case Group_D:
			assign_Bit(DIO_U8_PORTD,copy_U8_Pin_ID,copy_U8_Pin_Val);
		break;



	}

}else{
	return Invalid_Pin_Value;
}

	}else {
		return Invalid_Pin_ID;
	}
}

u8 DIO_U8_GetPinValue(u8 Copy_U8_Port_ID,u8 Copy_U8_Pin_ID){

	// set a local variable for result.
	u8 loc_Result;

	//handler for the function call (port and pin in valid range check)
	if((Copy_U8_Port_ID <= Group_D) && (Copy_U8_Pin_ID <= PIN7)){

		switch (Copy_U8_Port_ID) {
			case Group_A:
				loc_Result = get_Bit(DIO_U8_PINA,Copy_U8_Pin_ID);
				break;
			case Group_B:
				loc_Result = get_Bit(DIO_U8_PINB,Copy_U8_Pin_ID);
				break;
			case Group_C:
				loc_Result = get_Bit(DIO_U8_PINC,Copy_U8_Pin_ID);
				break;
			case Group_D:
				loc_Result = get_Bit(DIO_U8_PIND,Copy_U8_Pin_ID);
				break;
		}
	}else{
		//set var to 0xFF in case of error in func input
		return Invalid_Pin_ID;
	}
	return loc_Result;

}

void DIO_U8_SetPinDirection(u8 Copy_U8_Port_ID,u8 Copy_U8_Pin_ID,u8 Copy_U8_Pin_Dir){
	// handler to check if the port id and pin id in the correct range
	if(Copy_U8_Port_ID <= Group_D && Copy_U8_Pin_ID <= PIN7){

		switch(Copy_U8_Port_ID){

		case Group_A:
			assign_Bit(DIO_U8_DDRA,Copy_U8_Pin_ID,Copy_U8_Pin_Dir);
			break;
		case Group_B:
			assign_Bit(DIO_U8_DDRB,Copy_U8_Pin_ID,Copy_U8_Pin_Dir);
			break;
		case Group_C:
			assign_Bit(DIO_U8_DDRC,Copy_U8_Pin_ID,Copy_U8_Pin_Dir);
			break;
		case Group_D:
			assign_Bit(DIO_U8_DDRD,Copy_U8_Pin_ID,Copy_U8_Pin_Dir);
			break;


		}
	}else{
		//do nothing wrong function parameters were given.
	}

}

void DIO_U8_SetPortDirection(u8 Copy_U8_Port_ID,u8 Copy_u8_Port_Dir){

	switch(Copy_U8_Port_ID){

	case Group_A:
		DIO_U8_DDRA = Copy_u8_Port_Dir;
		break;
	case Group_B:
			DIO_U8_DDRB = Copy_u8_Port_Dir;
		break;
	case Group_C:
			DIO_U8_DDRC = Copy_u8_Port_Dir;
		break;
	case Group_D:
			DIO_U8_DDRD = Copy_u8_Port_Dir;
		break;
	default:
		//wrong function parameters were given.
		break;

	}

}

void DIO_U8_SetPortValue(u8 Copy_U8_Port_ID , u8 Copy_U8_Port_Val){

	switch(Copy_U8_Port_ID){

		case Group_A:
			DIO_U8_PORTA = Copy_U8_Port_Val;
			break;
		case Group_B:
				DIO_U8_PORTB = Copy_U8_Port_Val;
			break;
		case Group_C:
				DIO_U8_PORTC = Copy_U8_Port_Val;
			break;
		case Group_D:
				DIO_U8_PORTD = Copy_U8_Port_Val;
			break;
		default:
			//wrong function parameters were given.
			break;

		}


}
