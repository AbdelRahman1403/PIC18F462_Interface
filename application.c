/* 
 * File:   application.c
 * Author: AbdelRahman Yassin
 *
 * Created on April 16, 2024, 11:10 AM
 */
#include "application.h"
uint8 pot_1 , pot_2 , pot_3;
adc_config_t adc_1 = {
  .ADC_InttrepputHandler = NULL,
  .adc_channal = ADC_CHANNEL_AN0,
  .adc_acquisition = adc_12_TAD,
  .adc_conversion = adc_conversion_FOSC_div_8,
  .result_format = Right_Format,
  .voltage_format = Voltage_Reference_Enable
};
int main(){
    
    ADC_INIT(&adc_1);
    
    while(1){
        ADC_Get_Conversion_Blocking(&adc_1 , &pot_1 , ADC_CHANNEL_AN0);
        ADC_Get_Conversion_Blocking(&adc_1 , &pot_2 , ADC_CHANNEL_AN1);
        ADC_Get_Conversion_Blocking(&adc_1 , &pot_3 , ADC_CHANNEL_AN2);
        //ADC_Get_Conversion_Blocking(&adc_1 , &pot_1 , ADC_CHANNEL_AN0);
    }
    
    return (EXIT_SUCCESS);
}










/*
 keypad_t keypad = {
  .keypad_row_pins[0].port = PORTC_INDEX , .keypad_row_pins[0].pin = GPIO_pin0 , .keypad_row_pins[0].direction = GPIO_DIRECTION_OUTPUT , .keypad_row_pins[0].logic = GPIO_LOW,  
  .keypad_row_pins[1].port = PORTC_INDEX , .keypad_row_pins[1].pin = GPIO_pin1 , .keypad_row_pins[1].direction = GPIO_DIRECTION_OUTPUT , .keypad_row_pins[1].logic = GPIO_LOW,  
  .keypad_row_pins[2].port = PORTC_INDEX , .keypad_row_pins[2].pin = GPIO_pin2 , .keypad_row_pins[2].direction = GPIO_DIRECTION_OUTPUT , .keypad_row_pins[2].logic = GPIO_LOW,  
  .keypad_row_pins[3].port = PORTC_INDEX , .keypad_row_pins[3].pin = GPIO_pin3 , .keypad_row_pins[3].direction = GPIO_DIRECTION_OUTPUT , .keypad_row_pins[3].logic = GPIO_LOW, 
  
  .keypad_column_pins[0].port = PORTC_INDEX , .keypad_column_pins[0].pin = GPIO_pin4 , .keypad_column_pins[0].direction = GPIO_DIRECTION_INPUT , .keypad_column_pins[0].logic = GPIO_LOW,
  .keypad_column_pins[1].port = PORTC_INDEX , .keypad_column_pins[1].pin = GPIO_pin5 , .keypad_column_pins[1].direction = GPIO_DIRECTION_INPUT , .keypad_column_pins[1].logic = GPIO_LOW,
  .keypad_column_pins[2].port = PORTC_INDEX , .keypad_column_pins[2].pin = GPIO_pin6 , .keypad_column_pins[2].direction = GPIO_DIRECTION_INPUT , .keypad_column_pins[2].logic = GPIO_LOW,
  .keypad_column_pins[3].port = PORTC_INDEX , .keypad_column_pins[3].pin = GPIO_pin7 , .keypad_column_pins[3].direction = GPIO_DIRECTION_INPUT , .keypad_column_pins[3].logic = GPIO_LOW,
};
lcd_4bit_t lcd_4 = {
    .en_pin.port = PORTD_INDEX ,.en_pin.pin = GPIO_pin1 , .en_pin.direction = GPIO_DIRECTION_OUTPUT, .en_pin.logic = GPIO_LOW , 
    .rs_pin.port = PORTD_INDEX ,.rs_pin.pin = GPIO_pin0 , .rs_pin.direction = GPIO_DIRECTION_OUTPUT, .rs_pin.logic = GPIO_LOW ,
    .lcd_pin[0].port = PORTD_INDEX , .lcd_pin[0].pin = GPIO_pin2 , .lcd_pin[0].direction = GPIO_DIRECTION_OUTPUT , .lcd_pin[0].logic = GPIO_LOW,
    .lcd_pin[1].port = PORTD_INDEX , .lcd_pin[1].pin = GPIO_pin3 , .lcd_pin[1].direction = GPIO_DIRECTION_OUTPUT , .lcd_pin[1].logic = GPIO_LOW,
    .lcd_pin[2].port = PORTD_INDEX , .lcd_pin[2].pin = GPIO_pin4 , .lcd_pin[2].direction = GPIO_DIRECTION_OUTPUT , .lcd_pin[2].logic = GPIO_LOW,
    .lcd_pin[3].port = PORTD_INDEX , .lcd_pin[3].pin = GPIO_pin5 , .lcd_pin[3].direction = GPIO_DIRECTION_OUTPUT , .lcd_pin[3].logic = GPIO_LOW,
};
uint8 number_1[4];
uint8 number_2[4];
uint8 res[10];
uint8 operation = '\0' , value = '\0';
void init_array(uint8 numbers[4]);
uint16 convert_char_to_int(uint8 numbers[4]);
uint8 convert_int_to_char(uint16 num);

int main() {
    uint8 counter_Num1 , counter_Spaces , counter_Num2 , counter_Res;
    counter_Num1 = counter_Spaces = counter_Num2 = counter_Res =  0;
    uint8 res[10];
    KeyPad_initialize(&keypad);
    lcd_chr_4bit_intialize(&lcd_4);
    init_array(number_1);
    init_array(number_2);
    
    while(1){
       do{
           KeyPad_get_value(&keypad , &value);
           __delay_ms(100);
       }while(value == '\0');
       if(value == '+' || value == '-' || value == '/' || value == '*'){
           operation = value;
           lcd_chr_4bit_send_data_pos(&lcd_4 , 1 , counter_Spaces + 1 , value);
           value = '\0';
           break;
       }
       else{
        counter_Spaces++;
        number_1[counter_Num1++] = value;
       
        lcd_chr_4bit_send_data_pos(&lcd_4 , 1 , counter_Spaces , value);
        value = '\0';   
       }
    }
    counter_Spaces++;
    while(1){
       do{
           KeyPad_get_value(&keypad , &value);
           __delay_ms(100);
       }while(value == '\0');
       if(value == '='){
           lcd_chr_4bit_send_data_pos(&lcd_4 , 1 , counter_Spaces + 1 , value);
           value = '\0';
           break;
       }
       else{
           counter_Spaces++;
           number_2[counter_Num2++] = value;
           lcd_chr_4bit_send_data_pos(&lcd_4 , 1 , counter_Spaces , value);
           value = '\0';  
       }
    }
    counter_Spaces++;
    uint16 num1 = convert_char_to_int(number_1);
    uint16 num2 = convert_char_to_int(number_2);
    
    switch(operation){
        case '+':
            sprintf(res , "%d" , (num1 + num2));
            break;
        case '-':
            sprintf(res , "%d" , (num1 - num2));
            break;
        case '*':
            sprintf(res , "%d" , (num1 * num2));
            break;
        case '/':
            sprintf(res , "%d" , (num1 / num2));
            break;
    }
    
    lcd_chr_4bit_send_string_pos(&lcd_4 , 2 , 1 , res);
    
    __delay_ms(2000);
    lcd_chr_4bit_send_command(&lcd_4, _LCD_CLEAR);
    return (EXIT_SUCCESS);
}

void init_array(uint8 numbers[4]){
    for(uint8 i = 0 ; i < 4 ; i++){
        numbers[i] = '\0';
    }
}
uint16 convert_char_to_int(uint8 numbers[4]){
    uint16 res = 0;
    uint8 i = 0;
    while(i < 4 && numbers[i] != '\0'){
        
        res = (res * 10) + (numbers[i] - '0');
        i++;
    }
    return res;
}
 */