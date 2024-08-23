/* 
 * File:   DC_Motor.h
 * Author: USER
 *
 * Created on June 25, 2024, 4:34 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H
/*********** Section : Include Libraries          ***********/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*********** Section : Macro Declaration          ***********/

#define DC_MOTOR_ON_STATUS  0x01U
#define DC_MOTOR_OFF_STATUS 0x00U

/*********** Section : Function Macro Declaration ***********/

/*********** Section : Data Type Declaration      ***********/

typedef struct{
    pin_config_t Motor_pin[2];
}dc_motor_t;
/*********** Section : Function Declaration       ***********/

std_ReturnType dc_motor_initialize(const dc_motor_t *_dc_motor);
std_ReturnType dc_motor_turn_left(const dc_motor_t *_dc_motor);
std_ReturnType dc_motor_turn_right(const dc_motor_t *_dc_motor);
std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor);

#endif	/* ECU_DC_MOTOR_H */

