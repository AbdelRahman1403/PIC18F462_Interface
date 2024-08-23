
#include "ecu_KeyPad.h"
static const uint8 button_values[4][4] = {
    {'7' , '8' , '9' , '/'},  
    {'4' , '5' , '6' , '*'},  
    {'1' , '2' , '3' , '-'},  
    {'#' , '0' , '=' , '+'},  
};
std_ReturnType KeyPad_initialize(const keypad_t* _keypad){
    std_ReturnType ret = E_OK;
    if(_keypad == NULL){
        ret = E_NOK;
    }
    else{
        uint8 counter_rows = 0 , counter_columns = 0;
        for(counter_rows = 0 ; counter_rows < KEYPAD_ROWS; counter_rows++){
            
            ret |= gpio_pin_intiailize(&(_keypad->keypad_row_pins[counter_rows]));
            
        }
        for(counter_columns = 0 ; counter_columns < KEYPAD_COLUMNS; counter_columns++){
            
            ret |= gpio_pin_intiailize(&(_keypad->keypad_column_pins[counter_columns]));
            
        }
    }
    return ret;
}
std_ReturnType KeyPad_get_value(const keypad_t* _keypad , uint8 *value ){
    
    std_ReturnType ret = E_OK;
    if(_keypad == NULL || value == NULL){
        ret = E_NOK;
    }
    else{
       uint8 l_row_counter = 0, l_column_counter = 0 , l_counter = 0;
        uint8 column_logic = 0;
  
        for(l_row_counter = 0 ; l_row_counter < KEYPAD_ROWS; l_row_counter++){
            
            for(l_counter = 0 ; l_counter < KEYPAD_ROWS; l_counter++){
                ret = gpio_pin_write_logic(&(_keypad->keypad_row_pins[l_counter]),GPIO_LOW);
            }
            
            ret = gpio_pin_write_logic(&(_keypad->keypad_row_pins[l_row_counter]),GPIO_HIGH);
            __delay_ms(5);
            
            for(l_column_counter = 0 ; l_column_counter < KEYPAD_COLUMNS; l_column_counter++){
                
                ret = gpio_pin_read_logic(&(_keypad->keypad_column_pins[l_column_counter]), &column_logic);
                
                if(column_logic == GPIO_HIGH){
                    *value = button_values[l_row_counter][l_column_counter];
                }
            }
        }
    }
    return ret;
}
 /*
  
  
  */