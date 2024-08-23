/* 
 * File:   ecu_7_segment.h
 * Author: USER
 *
 * Created on June 30, 2024, 5:16 AM
 */

#ifndef ECU_7_SEGMENT_H
#define	ECU_7_SEGMENT_H

/*********** Section : Include Libraries          ***********/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*********** Section : Macro Declaration          ***********/

#define segment_pin0 0
#define segment_pin1 1
#define segment_pin2 2
#define segment_pin3 3

/*********** Section : Function Macro Declaration ***********/
/*********** Section : Data Type Declaration      ***********/
typedef enum{
    SEGMENT_COMMON_ANODE = 0,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct{
    pin_config_t segment_pins[4];
    segment_type_t segment_type;
    
}segment_t;
/*********** Section : Function Declaration       ***********/

std_ReturnType seven_segment_initialize(const segment_t *segment);
std_ReturnType seven_segment_write_number(const segment_t *segment , uint8 number);
#endif	/* ECU_7_SEGMENT_H */

