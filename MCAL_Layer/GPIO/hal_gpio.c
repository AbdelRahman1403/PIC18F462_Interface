/* 
 * File:   hal_gpio.c
 * Author: AbdelRahman Yassin
 *
 * Created on April 16, 2024, 11:10 AM
 */

#include "hal_gpio.h"

/* In TRIS register , know the register is input or output */
volatile uint8 *tris_register[] = {&TRISA , &TRISB , &TRISC , &TRISD , &TRISE};
/* In PORT register , know the statues of the port  */
volatile uint8 *port_register[] = {&PORTA , &PORTB , &PORTC , &PORTD , &PORTE};
/* In LAT register , send zero voltage or 5 voltage */
volatile uint8 *lat_register[] = {&LATA , &LATB , &LATC , &LATD , &LATE};

/**
 * @breif go to port X in pin X to set direction it (output or input)
 * @param pin_config_t
 * @return 
 */
std_ReturnType gpio_pin_direction_intiailize(const pin_config_t *pin_config_t){
    std_ReturnType ret = E_OK;
    if(pin_config_t == NULL){
     ret = E_NOK;   
    }
    else{
        switch(pin_config_t->direction){
            case GPIO_DIRECTION_OUTPUT:
                CLEAR_BIT(*tris_register[pin_config_t->port] , pin_config_t->pin);
                break;
            case GPIO_DIRECTION_INPUT:
                SET_BIT(*tris_register[pin_config_t->port] , pin_config_t->pin);
                break;
            default: ret = E_NOK ;
        }
    }
    return ret;
}
/**
 * know what is direction of the pin (input / output)
 * @param pin_config_t
 * @param dic_status
 * @return 
 */
std_ReturnType gpio_pin_direction_status(const pin_config_t *pin_config_t ,direction_t *dic_status ){
    std_ReturnType ret = E_OK;
    if(pin_config_t == NULL || dic_status == NULL){
     ret = E_NOK;   
    }
    else{
       *dic_status =  READ_BIT(*tris_register[pin_config_t->port] , pin_config_t->pin);
    }
    
    return ret;
}
/**
 * @brief write data from X pin
 * @param pin_config_t
 * @param logic
 * @return 
 */
std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config_t , logic_t logic){
    std_ReturnType ret = E_OK;
    if(pin_config_t == NULL ){
     ret = E_NOK;   
    }
    else{
        switch(logic){
            case GPIO_LOW :
                CLEAR_BIT(*lat_register[pin_config_t->port] , pin_config_t->pin);
                break;
            case GPIO_HIGH:
                SET_BIT(*lat_register[pin_config_t->port] , pin_config_t->pin);
                break;
            default: ;
        }
    }
    
    return ret;
}
/**
 * when put a push button you need read the status of the button
 * @param pin_config_t
 * @param logic
 * @return 
 */
std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config_t , logic_t *logic){
    std_ReturnType ret = E_OK;
    if(pin_config_t == NULL){
     ret = E_NOK;   
    }
    else{
       *logic = READ_BIT(*port_register[pin_config_t->port] , pin_config_t->pin);
    }
    
    return ret;
}
/**
 * 
 * @param pin_config_t
 * @return 
 */
std_ReturnType gpio_pin_toggle(const pin_config_t *pin_config_t){
    std_ReturnType ret = E_OK;
    if(pin_config_t == NULL){
     ret = E_NOK;   
    }
    else{
        TOGGLE_BIT(*lat_register[pin_config_t->port] , pin_config_t->pin);
    }
    
    return ret;
}
std_ReturnType gpio_pin_intiailize(const pin_config_t *pin_config_t){
    std_ReturnType ret = E_OK;
    if(pin_config_t == NULL){
     ret = E_NOK;   
    }
    else{
       gpio_pin_direction_intiailize(pin_config_t);
       gpio_pin_write_logic(pin_config_t , pin_config_t->logic);
    }
    return ret;
}
/**
 * 
 * @param port
 * @param dicrection
 * @return 
 */
std_ReturnType gpio_port_direction_intiailize(port_index_t port , uint8 direction){
    std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
     ret = E_NOK;   
    }
    else{
        *tris_register[port] = direction;
    }
    
    return ret;
}
/**
 * 
 * @param port
 * @param dic_status
 * @return 
 */
std_ReturnType gpio_port_direction_status(port_index_t port ,uint8 *dic_status ){
    std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1 && dic_status == NULL){
     ret = E_NOK;   
    }
    else{
        *dic_status = *tris_register[port];
    }
    
    return ret;
}
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
std_ReturnType gpio_port_write_logic(port_index_t port , uint8 logic){
    std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
     ret = E_NOK;   
    }
    else{
       *lat_register[port] = logic;
    }
    
    return ret;
}
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
std_ReturnType gpio_port_read_logic(port_index_t port , uint8 *logic){
    std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1 || logic == NULL){
     ret = E_NOK;   
    }
    else{
        *logic = lat_register[port];
    }
    
    return ret;
}
/**
 * 
 * @param port
 * @return 
 */
std_ReturnType gpio_port_toggle(port_index_t port){
    std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
     ret = E_NOK;   
    }
    else{
        *lat_register[port] ^= PORT_MASK;
    }
    
    return ret;
}