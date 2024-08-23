#include "ecu_relay.h"
/**
 * 
 * @param _relay
 * @return 
 */
std_ReturnType reley_initialize(const relay_t *_relay){
    std_ReturnType ret = E_OK;
    if(NULL == _relay){
        ret = E_NOK;
    }
    else{
        pin_config_t pin_config = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .logic = _relay->relay_status,
            .direction = GPIO_DIRECTION_OUTPUT 
        };
        gpio_pin_intiailize(&pin_config);
    }
    return ret;
}
/**
 * 
 * @param _relay
 * @return 
 */
std_ReturnType reley_turn_on(const relay_t *_relay){
    std_ReturnType ret = E_OK;
    if(NULL == _relay){
        ret = E_NOK;
    }
    else{
        pin_config_t pin_config = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .logic = _relay->relay_status,
            .direction = GPIO_DIRECTION_OUTPUT 
        };
        gpio_pin_write_logic(&pin_config , GPIO_HIGH);
    }
    return ret;
}
/**
 * 
 * @param _relay
 * @return 
 */
std_ReturnType reley_turn_off(const relay_t *_relay){
    std_ReturnType ret = E_OK;
    if(NULL == _relay){
        ret = E_NOK;
    }
    else{
        pin_config_t pin_config = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .logic = _relay->relay_status,
            .direction = GPIO_DIRECTION_OUTPUT 
        };
        gpio_pin_write_logic(&pin_config , GPIO_LOW);
    }
    return ret;
}