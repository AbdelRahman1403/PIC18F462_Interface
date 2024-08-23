/* 
 * File:   ECU_LED.h
 * Author: USER
 *
 * Created on April 16, 2024, 11:30 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H
/*********** Section : Include Libraries          ***********/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"
/*********** Section : Macro Declaration          ***********/

/*********** Section : Function Macro Declaration ***********/

/*********** Section : Data Type Declaration      ***********/
typedef enum{
    LED_OFF,
    LED_ON 
}led_status_t;

typedef struct{
    uint8 port_name : 3;
    uint8 pin : 3;
    uint8 led_status : 1;
}led_t;

/*********** Section : Function Declaration       ***********/
std_ReturnType led_initialize(const led_t *led);
std_ReturnType led_turn_on(const led_t *led);
std_ReturnType led_turn_off(const led_t *led);
std_ReturnType led_turn_toggle(const led_t *led);


#endif	/* ECU_LED_H */

