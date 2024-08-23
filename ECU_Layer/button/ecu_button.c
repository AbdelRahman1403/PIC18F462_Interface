
#include "ecu_button.h"
/**
 * @brief initialize the button to pin of mcu
 * @param btn
 * @return status of the function
 *         (E_OK) --> the function done successfully 
 *         (E_NOK) --> the function has issue while performing this action 

 */
std_ReturnType button_initialize(const button_t *btn){
    std_ReturnType ret = E_OK;
    if(btn == NULL){
        ret = E_NOK;
    }
    else{
        gpio_pin_direction_intiailize(&(btn->button_pin));
    }
    return ret;
}
/**
 * @brief read the state of the button
 * @param btn
 * @param btn_state
 * @return status of the function
 *         (E_OK) --> the function done successfully 
 *         (E_NOK) --> the function has issue while performing this action 
 */
std_ReturnType button_read(const button_t *btn , button_state_t *btn_state){
    std_ReturnType ret = E_OK;
    logic_t bin_state_logic = GPIO_LOW;
    if(btn == NULL){
        ret = E_NOK;
    }
    else{
        gpio_pin_read_logic(&(btn->button_pin),&(bin_state_logic));
        if(BUTTON_ACTIVE_HIGH == &(btn->button_active)) {
            if(bin_state_logic == GPIO_HIGH){
                *btn_state = BUTTON_PRESSED;
            }
            else{
                *btn_state = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == &(btn->button_active)) {
            if(bin_state_logic == GPIO_HIGH){
                *btn_state = BUTTON_RELEASED;
            }
            else{
                *btn_state = BUTTON_PRESSED;
            }
        }
        else{
            /*Nothing*/
        }
    }
    return ret;
}
