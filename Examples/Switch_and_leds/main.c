/*
 * main.c

 *
 *  Created on: May 6, 2023
 *      Author: karim
 */



#include "bit_calc.h"
#include "avr/delay.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

//The following code is checking if the button is pressed or not
// if it is pressed the 7 segment count from 0 to 9
// if not it will count from 9-0

int main(){

	DIO_U8_SetPinDirection(Group_A, PIN0, INPUT); // make pin A0 as input
	DIO_U8_SetPinValue(Group_A, PIN0, HIGH); // activate mcu internal pull up resistor (5v)



		DIO_U8_SetPortDirection(Group_B, Max_Port_Value); // SET PORTB AS OUTPUT

		//ARRAY CONTAINING 0-9 FOR 7 SEGMENT (COMMON ANODE)
	char arr[10]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};

	while(1){

		if(DIO_U8_GetPinValue(Group_A, PIN0) == 0){

			for(int i=0;i<10;i++){
				DIO_U8_PORTB = arr[i];
				_delay_ms(1000);
			}

		}else{
			for(int i=9;i>=0;i--){

				DIO_U8_PORTB = arr[i];
				_delay_ms(1000);
			}
		}

	}



return 0;

}
