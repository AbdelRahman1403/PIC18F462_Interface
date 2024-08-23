/* 
 * File:   ecu_relay.h
 * Author: USER
 *
 * Created on June 22, 2024, 7:22 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H
/*********** Section : Include Libraries          ***********/
#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*********** Section : Macro Declaration          ***********/

#define RELAY_ON_STATUS  0x01U
#define RELAY_OFF_STATUS 0x00U

/*********** Section : Function Macro Declaration ***********/

/*********** Section : Data Type Declaration      ***********/
typedef struct{
    uint8 relay_port : 4;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
}relay_t;
/*********** Section : Function Declaration       ***********/
std_ReturnType reley_initialize(const relay_t *_relay);
std_ReturnType reley_turn_on(const relay_t *_relay);
std_ReturnType reley_turn_off(const relay_t *_relay);

#endif	/* ECU_RELAY_H */

