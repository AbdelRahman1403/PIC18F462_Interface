/* 
 * File:   ecu_KeyPad.h
 * Author: USER
 *
 * Created on June 30, 2024, 9:55 AM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/*********** Section : Include Libraries          ***********/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*********** Section : Macro Declaration          ***********/

/*********** Section : Function Macro Declaration ***********/
#define KEYPAD_ROWS    4
#define KEYPAD_COLUMNS 4
/*********** Section : Data Type Declaration      ***********/

typedef struct{
    pin_config_t keypad_row_pins[KEYPAD_ROWS];
    pin_config_t keypad_column_pins[KEYPAD_COLUMNS];
}keypad_t;

/*********** Section : Function Declaration       ***********/

std_ReturnType KeyPad_initialize(const keypad_t* _keypad );
std_ReturnType KeyPad_get_value(const keypad_t* _keypad , uint8 *value );
#endif	/* ECU_KEYPAD_H */

