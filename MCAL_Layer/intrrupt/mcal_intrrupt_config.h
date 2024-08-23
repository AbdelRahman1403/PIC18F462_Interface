/* 
 * File:   mcal_intrrupt_config.h
 * Author: USER
 *
 * Created on July 31, 2024, 3:24 AM
 */

#ifndef MCAL_INTRRUPT_CONFIG_H
#define	MCAL_INTRRUPT_CONFIG_H

/*********** Section : Include Libraries          ***********/

#include "../mcal_std_types.h"
#include "mcal_intrrupt_gen_config.h"
#include <pic18f4620.h>
#include "../GPIO/hal_gpio.h"


/*********** Section : Data Type Declaration      ***********/

typedef enum{
    intrrupt_low_prioity = 0,
    intrrupt_high_prioity
}intrrupt_priority_cfg;

/*********** Section : Macro Declaration          ***********/
#define INTRRUPT_ENABLE           1
#define INTRRUPT_DISABLE          0
#define INTRRUPT_OCCUR            1
#define INTRRUPT_NOT_OCCUR        0
#define INTRRUPT_PRIORITY_ENABLE  1
#define INTRRUPT_PRIORITY_DISABLE 0
/*********** Section : Function Macro Declaration ***********/
/*
 * When intrrupt priority enable :
 *                                --> Enable high intrrupt
 *                                --> Disnable Low intrrupt
 *                                OR
 *                                --> Enable Low intrrupt
 *                                --> Disnable High intrrupt
 
 */
#if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
/*Enable Priority intrrupt */
#define INTRRUTPT_Priority_Levels_Enable()       (RCONbits.IPEN = 1)
/*Disable Priority intrrupt */
#define INTRRUTPT_Priority_Levels_Disnable()     (RCONbits.IPEN = 0)
/*Enable High Priority Global Intrrupt */
#define INTRRUTPT_GlobalIntrruptHighEnable()     (INTCONbits.GIEH = 1)
/*Disable High Priority Global Intrrupt */
#define INTRRUTPT_GlobalIntrruptHighDisable()    (INTCONbits.GIEH = 0)
/*Enable Low Priority Global Intrrupt */
#define INTRRUTPT_GlobalIntrruptLowerEnable()     (INTCONbits.GIEL = 1)
/*Disable Low Priority Global Intrrupt */
#define INTRRUTPT_GlobalIntrruptLowerDisable()    (INTCONbits.GIEL = 0)
#else
//when Disable priority levels --> When intrrupt occured the PEIE reg is open until CPU process the intrrupt 
/*Enable peripheral Intrrupt */
#define INTRRUTPT_Global_IntrruptEnable()                 (INTCONbits.GIE = 1)
/*Disable peripheral Intrrupt */
#define INTRRUTPT_Global_IntrruptDisable()                (INTCONbits.GIE = 0)
/*Enable peripheral Intrrupt */
#define INTRRUTPT_Peripheral_Intrrupt_Enable()            (INTCONbits.PEIE = 1)
/*Disable peripheral Intrrupt */
#define INTRRUTPT_Peripheral_Intrrupt_Disable()           (INTCONbits.PEIE = 0)
#endif

/*********** Section : Function Declaration       ***********/

#endif	/* MCAL_INTRRUPT_CONFIG_H */

