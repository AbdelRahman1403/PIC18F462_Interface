/* 
 * File:   ecu_button.h
 * Author: USER
 *
 * Created on May 1, 2024, 5:17 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H
/*********** Section : Include Libraries          ***********/
#include "ecu_button_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*********** Section : Macro Declaration          ***********/

/*********** Section : Function Macro Declaration ***********/

/*********** Section : Data Type Declaration      ***********/

typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW        
}button_active_t;

typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_active;
}button_t;

/*********** Section : Function Declaration       ***********/

std_ReturnType button_initialize(const button_t *btn);
std_ReturnType button_read(const button_t *btn , button_state_t *btn_state);

#endif	/* ECU_BUTTON_H */

