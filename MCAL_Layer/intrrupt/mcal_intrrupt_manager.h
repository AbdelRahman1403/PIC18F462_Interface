/* 
 * File:   mcal_intrrupt_manager.h
 * Author: USER
 *
 * Created on July 31, 2024, 3:23 AM
 */

#ifndef MCAL_INTRRUPT_MANAGER_H
#define	MCAL_INTRRUPT_MANAGER_H
/*********** Section : Include Libraries          ***********/
#include "mcal_external_intrrupt.h"
/*********** Section : Data Type Declaration      ***********/
/*********** Section : Macro Declaration          ***********/
/*********** Section : Function Macro Declaration ***********/
/*********** Section : Function Declaration       ***********/
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 level);
void RB5_ISR(uint8 level);
void RB6_ISR(uint8 level);
void RB7_ISR(uint8 level);
#endif	/* MCAL_INTRRUPT_MANAGER_H */

