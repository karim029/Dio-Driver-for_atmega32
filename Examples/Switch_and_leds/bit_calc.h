/*
 * bit_calc.h
 *
 *  Created on: May 5, 2023
 *      Author: karim
 */

#ifndef BIT_CALC_H_
#define BIT_CALC_H_
#define set_Bit(var,bit_no) (var) |= (1<<(bit_no))
#define clear_Bit(var,bit_no) (var) &= (~(1<<(bit_no)))
#define toggle_Bit(var,bit_no) (var) ^= (1<<(bit_no))
#define get_Bit(var,bit_no) ((var)>>(bit_no) &(1))



#endif /* BIT_CALC_H_ */
