/*
 * main.c
 *
 *  Created on: May 9, 2023
 *      Author: karim
 *
 *
 *
 */
#include "avr/delay.h"
#include "bit_calc.h"
#include "STD_Types.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"

// 8 CASES LED USING 3 OF THE 8 DIP SWITCH VALUES 000 TO 111 (8 CASES)

void flash(){
	DIO_U8_PORTA = Max_Port_Value;
	_delay_ms(500);
	DIO_U8_PORTA = 0X00;
	_delay_ms(500);
}

void shift_left(){
	u8 temp = 0b00000001;
	for(u8 i = 0; i<8;i++){
		DIO_U8_PORTA = temp;
		temp <<=1;
		_delay_ms(250);
	}

}

void shift_right(){
	u8 temp = 0b10000000;
	for(u8 i = 0; i<8;i++){
		DIO_U8_PORTA = temp;
		temp >>=1;
		_delay_ms(250);
	}

}

void converging(){
	DIO_U8_PORTA = 0b10000001;
	u8 temp[4] = {0b10000001,0b01000010,0b00100100,0b00011000};
	for(u8 i = 0; i<5;i++){
		DIO_U8_PORTA = temp[i];
		_delay_ms(300);

	}
}

void diverging(){
	DIO_U8_PORTA = 0b00011000;
	u8 temp[4]= {0b00011000, 0b00100100, 0b01000010, 0b10000001};
	for(u8 i = 0; i<5;i++){
		DIO_U8_PORTA = temp[i];
		_delay_ms(300);
	}

}
void pingpong(){
	u8 temp = 0b00000001;
	for(u8 i = 1; i<8;i++){
		DIO_U8_PORTA = temp;
		temp = temp << i;
		_delay_ms(250);
	}
	for(u8 i = 8; i>0;i--){
		DIO_U8_PORTA = temp;
		temp = temp>>i;
		_delay_ms(250);

	}

}
void snake(){
	u8 temp = 0b00000001;
	DIO_U8_PORTA = temp;
	for(u8 i = 1; i<8;i++){
		set_Bit(DIO_U8_PORTA,i);
		_delay_ms(300);
	}
}
void two_leds_conv_div(){
	converging();
	diverging();

}



int main(){

	DIO_U8_DDRA = 0XFF;

	for(u8 i =0; i<3;i++){
		clear_Bit(DIO_U8_DDRB,i);
		set_Bit(DIO_U8_PORTB,i); // activate the internal pullup resistor for pins in port B
	}

	while(1){



		u8 dip_Value = (DIO_U8_PINB & 0b00000111);

		switch(dip_Value){

		case 0:
			flash();
			break;
		case 1:
			shift_left();
			break;
		case 2:
			shift_right();
			break;
		case 3:
			converging();
			break;
		case 4:
			diverging();
			break;
		case 5:
			pingpong();
			break;
		case 6:
			snake();
			break;
		case 7:
			two_leds_conv_div();

			break;
		default:
			DIO_U8_PORTA = 0X00;
			break;

		}

	}



}
