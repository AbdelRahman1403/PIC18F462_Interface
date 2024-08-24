/* 
 * File:   mcal_internal_intrrupt.h
 * Author: USER
 *
 * Created on July 31, 2024, 3:21 AM
 */

#ifndef MCAL_INTERNAL_INTRRUPT_H
#define	MCAL_INTERNAL_INTRRUPT_H

/*********** Section : Include Libraries          ***********/

#include "mcal_intrrupt_config.h"

/*********** Section : Data Type Declaration      ***********/
/*********** Section : Macro Declaration          ***********/
/*********** Section : Function Macro Declaration ***********/
#if ADC_INTRRUPT_FEATURE_ENABLE == Feture_enable
/* Feature To Disable ADC Interrupt */
#define ADC_INTERRUPT_Enable()         (PIE1bits.ADIE = 1)
/* Feature To Set ADC Interrupt */
#define ADC_INTERRUPT_Disable()        (PIE1bits.ADIE = 0)
/* Feature To Clear Flag ADC Interrupt */
#define ADC_INTERRUPT_Flag_Clear()     (PIR1bits.ADIF = 0)
#if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
/* Enable High Priority Interrupt */
#define ADC_Interrupt_HigherPrioritySet()            (IPR1bits.ADIP = 1)
/* Enable Low Priority Interrupt */
#define ADC_Interrupt_LowerPrioritySet()             (IPR1bits.ADIP = 0)
#endif
#endif

/*********** Section : Function Declaration       ***********/

#endif	/* MCAL_INTERNAL_INTRRUPT_H */

