/* 
 * File:   mcal_external_intrrupt.h
 * Author: USER
 *
 * Created on July 31, 2024, 3:22 AM
 */

#ifndef MCAL_EXTERNAL_INTRRUPT_H
#define	MCAL_EXTERNAL_INTRRUPT_H

/*********** Section : Include Libraries          ***********/
#include "mcal_intrrupt_config.h"
/*********** Section : Data Type Declaration      ***********/
typedef enum{
    intrrupt_FALLING_EDGE = 0,
    intrrupt_RISING_EDGE 
}intrruct_INTx_edge;
typedef enum{
    intrrupt_INTX_0 = 0,
    intrrupt_INTX_1,
    intrrupt_INTX_2
}intrruct_INTx_source;


typedef struct{
    void (* EXT_IntrruptHandeler)(void);
    pin_config_t mcu_pin;
    intrrupt_priority_cfg priority;
    intrruct_INTx_edge edge;
    intrruct_INTx_source src;
}intrrupt_INTx_t;

typedef struct{
    void (* EXT_IntrruptHandeler_High)(void);
    void (* EXT_IntrruptHandeler_Low)(void);
    pin_config_t mcu_pin;
    intrrupt_priority_cfg priority;
}intrrupt_RPx_t;
/*********** Section : Macro Declaration          ***********/
/*********** Section : Function Macro Declaration ***********/
#if EXTERNAL_INTRRUPT_INTx_FEATURE_ENABLE == Feture_enable
#define EXT_INT0_IntrruptDisable()             (INTCONbits.INT0IE = 0)
#define EXT_INT0_IntrruptEnable()              (INTCONbits.INT0IE = 1)
#define EXT_INT0_IntrruptFlagClear()           (INTCONbits.INT0IF = 0)
#define EXT_INT0_RisingEdgeSet()               (INTCON2bits.INTEDG0 = 1)
#define EXT_INT0_FillingSet()                  (INTCON2bits.INTEDG0 = 0)

#define EXT_INT1_IntrruptDisable()             (INTCON3bits.INT1IE = 0)
#define EXT_INT1_IntrruptEnable()              (INTCON3bits.INT1IE = 1)
#define EXT_INT1_IntrruptFlagClear()           (INTCON3bits.INT1IF = 0)
#define EXT_INT1_RisingEdgeSet()               (INTCON2bits.INTEDG1 = 1)
#define EXT_INT1_FillingSet()                  (INTCON2bits.INTEDG1 = 0)

#define EXT_INT2_IntrruptDisable()             (INTCON3bits.INT2IE = 0)
#define EXT_INT2_IntrruptEnable()              (INTCON3bits.INT2IE = 1)
#define EXT_INT2_IntrruptFlagClear()           (INTCON3bits.INT2IF = 0)
#define EXT_INT2_RisingEdgeSet()               (INTCON2bits.INTEDG2 = 1)
#define EXT_INT2_FillingEdgeSet()              (INTCON2bits.INTEDG2 = 0)

#if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
#define EXT_INT1_HigherPrioritySet()           (INTCON3bits.INT1IP = 1)
#define EXT_INT1_LowerPrioritySet()            (INTCON3bits.INT1IP = 0)
#define EXT_INT2_HigherPrioritySet()           (INTCON3bits.INT2IP = 1)
#define EXT_INT2_LowerPrioritySet()            (INTCON3bits.INT2IP = 0)
#endif
#endif

#if EXTERNAL_INTRRUPT_OnChange_FEATURE_ENABLE == Feture_enable

#define EXT_RPx_IntrruptDisable()              (INTCONbits.RBIE = 0)
#define EXT_RPx_IntrruptEnable()               (INTCONbits.RBIE = 1)
#define EXT_RPx_IntrruptFlagClear()            (INTCONbits.RBIF = 1)

#if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
#define EXT_RPx_HigherPrioritySet()            (INTCON2bits.RBIP = 1)
#define EXT_RPx_LowerPrioritySet()             (INTCON2bits.RBIP = 0)
#endif
#endif



/*********** Section : Function Declaration       ***********/

std_ReturnType Intrrupt_INTx_Init(const intrrupt_INTx_t *obj);
std_ReturnType Intrrupt_INTx_Deinit(const intrrupt_INTx_t *obj);
std_ReturnType Intrrupt_RBx_Init(const intrrupt_INTx_t *obj);
std_ReturnType Intrrupt_RBx_Deinit(const intrrupt_INTx_t *obj);

#endif	/* MCAL_EXTERNAL_INTRRUPT_H */

