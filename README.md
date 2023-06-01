# Dio-Driver-for_atmega32

-this driver is made for the atmega32 MCU.

the driver contain functions to help you when writing your code and controlling the ports

DIO_Interface.h
contains the function prototypes.
the available functions are:
1) set Pin value 
2) get Pin value
3) set Pin direction
4) set Port value
5) set Port direction

You can configure which ports you want to Use set it in the Interface.h

dont forget to include the bit_calc.h and STD_Types.h for the driver to work correctly 

the bitcalc.h has macro functions for bit operations 

while the STD_Types has  defined data types in C 


