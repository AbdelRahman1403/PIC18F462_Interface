/* 
 * File:   hal_gpio.h
 * Author: USER
 *
 * Created on April 16, 2024, 11:21 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H
/*********** Section : Include Libraries          ***********/
#include "../mcal_std_types.h"
#include "../device_config.h"
#include <pic18f4620.h>
/*********** Section : Data Type Declaration      ***********/

typedef enum{
    GPIO_LOW,
    GPIO_HIGH
}logic_t;

typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX , 
    PORTC_INDEX ,        
    PORTD_INDEX ,
    PORTE_INDEX 
}port_index_t;

typedef enum{
    GPIO_pin0 = 0,
    GPIO_pin1,
    GPIO_pin2,
    GPIO_pin3,
    GPIO_pin4,
    GPIO_pin5,
    GPIO_pin6,
    GPIO_pin7,
}pin_index_t;

typedef enum{
    GPIO_DIRECTION_OUTPUT = 0,
    GPIO_DIRECTION_INPUT    
}direction_t;

typedef struct{
    uint8 port      : 3;
    uint8 pin       : 3; 
    uint8 direction : 1;
    uint8 logic     : 1; 
}pin_config_t;

/*********** Section : Macro Declaration          ***********/

#define BIT_MASK             (uint8)1

#define PORT_PIN_MAX_NUMBER     8
#define PORT_MAX_NUMBER         5

#define PORT_MASK            0xFF

/*********** Section : Function Macro Declaration ***********/

#define HWREG8(_x)                  (*((uint8 *)(_x)))
#define SET_BIT(REG , BIT_POSS)     (REG |= (BIT_MASK << BIT_POSS))
#define CLEAR_BIT(REG , BIT_POSS)   (REG &= ~(BIT_MASK << BIT_POSS))
#define TOGGLE_BIT(REG , BIT_POSS)  (REG ^= (BIT_MASK << BIT_POSS))
#define READ_BIT(REG , BIT_POSS)    ((REG >> BIT_POSS) & BIT_MASK)

/*********** Section : Function Declaration       ***********/

std_ReturnType gpio_pin_direction_intiailize(const pin_config_t *pin_config_t);
std_ReturnType gpio_pin_direction_status(const pin_config_t *pin_config_t ,direction_t *dic_status );
std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config_t , logic_t logic);
std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config_t , logic_t *logic);
std_ReturnType gpio_pin_toggle(const pin_config_t *pin_config_t);
std_ReturnType gpio_pin_intiailize(const pin_config_t *pin_config_t);

std_ReturnType gpio_port_direction_intiailize(port_index_t port , uint8 dicrection);
std_ReturnType gpio_port_direction_status(port_index_t port ,uint8 *dic_status );
std_ReturnType gpio_port_write_logic(port_index_t port , uint8 logic);
std_ReturnType gpio_port_read_logic(port_index_t port , uint8 *logic);
std_ReturnType gpio_port_toggle(port_index_t port);
#endif	/* HAL_GPIO_H */

