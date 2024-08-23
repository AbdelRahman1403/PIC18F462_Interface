
/* 
 * File:   ECU_LED.c
 * Author: AbdelRahman Yassin
 *
 * Created on April 16, 2024, 11:30 AM
 */

#include "ECU_LED.h"
/**
 * @brief : Initialize the assigned pin to be OUTPUT and turn the led off.
 * @param led
 * @return status of the function
 *         (E_OK) --> the function done successfully 
 *         (E_NOK) --> the function has issue while performing this action
 */
std_ReturnType led_initialize(const led_t *led){
    std_ReturnType ret = E_OK;
    if(led == NULL){
        ret = E_NOK;
    }
    else{
        pin_config_t pin_obj = {.port = led->port_name,
                                .pin = led->pin,
                                .logic = led->led_status,
                                .direction = GPIO_DIRECTION_OUTPUT};
        gpio_pin_intiailize(&pin_obj);
    }
    return ret;
}
/**
 * @brief Turn the led on
 * @param led
 * @return status of the function
 *         (E_OK) --> the function done successfully 
 *         (E_NOK) --> the function has issue while performing this action  
 */
std_ReturnType led_turn_on(const led_t *led){
    std_ReturnType ret = E_OK;
    if(led == NULL){
        ret = E_NOK;
    }
    else{
         pin_config_t pin_obj = {.port = led->port_name,
                                .pin = led->pin,
                                .logic = led->led_status,
                                .direction = GPIO_DIRECTION_OUTPUT};
         gpio_pin_write_logic(&pin_obj , GPIO_HIGH);
    }
    return ret;
}
/**
 * @brief Turn the led off
 * @param led
 * @return status of the function
 *         (E_OK) --> the function done successfully 
 *         (E_NOK) --> the function has issue while performing this action 
 */
std_ReturnType led_turn_off(const led_t *led){
    std_ReturnType ret = E_OK;
    if(led == NULL){
        ret = E_NOK;
    }
    else{
        pin_config_t pin_obj = {.port = led->port_name,
                                .pin = led->pin,
                                .logic = led->led_status,
                                .direction = GPIO_DIRECTION_OUTPUT};
         gpio_pin_write_logic(&pin_obj , GPIO_LOW);
    }
    return ret;
}
/**
 * @brief Turn the led status
 * @param led
 * @return status of the function
 *         (E_OK) --> the function done successfully 
 */
std_ReturnType led_turn_toggle(const led_t *led){
    std_ReturnType ret = E_OK;
    if(led == NULL){
        ret = E_NOK;
    }
    else{
        pin_config_t pin_obj = {.port = led->port_name,
                                .pin = led->pin,
                                .logic = led->led_status,
                                .direction = GPIO_DIRECTION_OUTPUT};
         gpio_pin_toggle(&pin_obj);
    }
    return ret;
}