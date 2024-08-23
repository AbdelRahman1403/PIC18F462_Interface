#include "ecu_7_segment.h"

std_ReturnType seven_segment_initialize(const segment_t *segment){
    std_ReturnType ret = E_OK;
    if(segment == NULL){
        ret = E_NOK;
    }
    else{
       ret = gpio_pin_intiailize(&(segment->segment_pins[segment_pin0]));
       ret = gpio_pin_intiailize(&(segment->segment_pins[segment_pin1]));
       ret = gpio_pin_intiailize(&(segment->segment_pins[segment_pin2]));
       ret = gpio_pin_intiailize(&(segment->segment_pins[segment_pin3]));
    }
    return ret;
}

std_ReturnType seven_segment_write_number(const segment_t *segment , uint8 number){
    std_ReturnType ret = E_OK;
    if((segment == NULL) && (number > 9)){
        ret = E_NOK;
    }
    else{
        gpio_pin_write_logic(&(segment->segment_pins[segment_pin0]) , number & 0x01);
        gpio_pin_write_logic(&(segment->segment_pins[segment_pin1]) , (number >> 1) & 0x01);
        gpio_pin_write_logic(&(segment->segment_pins[segment_pin2]) , (number >> 2) & 0x01);
        gpio_pin_write_logic(&(segment->segment_pins[segment_pin3]) , (number >> 3) & 0x01);
    }
    return ret;
}

