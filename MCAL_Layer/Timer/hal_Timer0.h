/* 
 * File:   hal_Timer0.h
 * Author: USER
 *
 * Created on September 1, 2024, 3:09 AM
 */

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H
/*********** Section : Include Libraries          ***********/
#include "../mcal_std_types.h"
#include "../intrrupt/mcal_internal_intrrupt.h"
#include <pic18f4620.h>
/*********** Section : Macro Declaration          ***********/

#define PRESCALER_STATUS_ENABLE_CFG   1
#define PRESCALER_STATUS_DISABLE_CFG  0

#define TIMER0_FAILLING_EDGE_CFG  1         
#define TIMER0_RAISING_EDGE_CGF   0

#define TIMER0_TIMER_MODE_CFG       0
#define TIMER0_COUNTER_MODE_CFG     1

#define TIMER0_8_BIT_CFG    1
#define TIMER0_16_BIT_CFG   0
/*********** Section : Function Macro Declaration ***********/

#define PRESCALER_STATUS_ENABLE()    (T0CONbits.PSA = 0)
#define PRESCALER_STATUS_DISABLE()   (T0CONbits.PSA = 1)
//????
#define TIMER0_FAILLING_EDGE()       (T0CONbits.T0SE = 1)     
//???
#define TIMER0_RAISING_EDGE()        (T0CONbits.T0SE = 0)

#define TIMER0_TIMER_MODE()            (T0CONbits.T0CS = 0)
#define TIMER0_COUNTER_MODE()          (T0CONbits.T0CS = 1)    

#define TIMER0_8_BIT()                 (T0CONbits.T08BIT = 1)
#define TIMER0_16_BIT()                (T0CONbits.T08BIT = 0)

#define TIMER0_ENABLE()                (T0CONbits.TMR0ON = 1)
#define TIMER0_DISABLE()               (T0CONbits.TMR0ON = 0)

/*********** Section : Data Type Declaration      ***********/

typedef enum{
    Prescaler_2_val = 0,
    Prescaler_4_val,     
    Prescaler_8_val,     
    Prescaler_16_val,     
    Prescaler_32_val,     
    Prescaler_64_val,     
    Prescaler_128_val,     
    Prescaler_256_val,     
}timer0_prescaler_select_t;

typedef struct{
#if TIMER0_INTRRUPT_FEATURE_ENABLE == Feture_enable
    void (*_Timer0_InterruptHandler)(void);
    intrrupt_priority_cfg priority;
#endif
    timer0_prescaler_select_t prescaler_val;
    uint16 timer0_Preload_val;
    uint8 prescaler_status : 1;
    uint8 timer0_edge : 1;
    uint8 timer0_mode : 1; /* @ref : TIMER0_TIMER_MODE / TIMER0_COUNTER_MODE */
    uint8 timer0_bits : 1; /* @ref : 8 bit mode or 16 bit mode */
}timer0_t;

/*********** Section : Function Declaration       ***********/
std_ReturnType TIMER0_INIT(const timer0_t *timer);
std_ReturnType TIMER0_DeINIT(const timer0_t *timer);
std_ReturnType TIMER0_Read(const timer0_t *timer , uint16 *Read_data);
std_ReturnType TIMER0_Write(const timer0_t *timer , uint16 Write_data);


#endif	/* HAL_TIMER0_H */

