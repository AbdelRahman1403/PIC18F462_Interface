

#include"ecu_DC_Motor.h"

pin_config_t Motor_pin1;
pin_config_t Motor_pin2;

std_ReturnType dc_motor_initialize(const dc_motor_t *_dc_motor){
    std_ReturnType ret = E_OK;
    if(NULL == _dc_motor){
        ret = E_NOK;
    }
    else{
        gpio_pin_intiailize(&(_dc_motor->Motor_pin[0]));
        gpio_pin_intiailize(&(_dc_motor->Motor_pin[1]));
    }
    return ret;
}

std_ReturnType dc_motor_turn_left(const dc_motor_t *_dc_motor){
    std_ReturnType ret = E_OK;
    if(_dc_motor == NULL){
        ret = E_NOK;
    }
    else{
        gpio_pin_write_logic(&(_dc_motor->Motor_pin[0]) , GPIO_HIGH);
        gpio_pin_write_logic(&(_dc_motor->Motor_pin[1]) , GPIO_LOW);
    }
        return ret;
}
std_ReturnType dc_motor_turn_right(const dc_motor_t *_dc_motor){
    std_ReturnType ret = E_OK;
    if(_dc_motor == NULL){
        ret = E_NOK;
    }
    else{
       gpio_pin_write_logic(&(_dc_motor->Motor_pin[0]) , GPIO_LOW);
       gpio_pin_write_logic(&(_dc_motor->Motor_pin[1]) , GPIO_HIGH); 
    }
        return ret;
}
    

std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor){
    std_ReturnType ret = E_OK;
    if(_dc_motor == NULL){
        ret = E_NOK;
    }
    else{
    gpio_pin_write_logic(&(_dc_motor->Motor_pin[0]) , GPIO_LOW);
    gpio_pin_write_logic(&(_dc_motor->Motor_pin[1]), GPIO_LOW); 
    }
    return ret;
}
