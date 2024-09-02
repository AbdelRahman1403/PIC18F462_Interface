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
#if EXTERNAL_INTRRUPT_INTx_FEATURE_ENABLE  == Feture_enable
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
#endif
#if EXTERNAL_INTRRUPT_OnChange_FEATURE_ENABLE == Feture_enable
void RB4_ISR(uint8 level);
void RB5_ISR(uint8 level);
void RB6_ISR(uint8 level);
void RB7_ISR(uint8 level);
#endif
#if ADC_INTRRUPT_FEATURE_ENABLE == Feture_enable
void ADC_ISR(void);
#endif
#if TIMER0_INTRRUPT_FEATURE_ENABLE == Feture_enable
void TIMER0_ISR();
#endif
#endif	/* MCAL_INTRRUPT_MANAGER_H */

