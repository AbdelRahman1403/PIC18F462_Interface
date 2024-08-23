
#include "ecu_char_lcd.h"
static std_ReturnType lcd_send_data_command_4bit(const lcd_4bit_t *lcd ,uint8 _data_command);

static std_ReturnType lcd_4bit_send_enable(const lcd_4bit_t *lcd);
static std_ReturnType lcd_8bit_send_enable(const lcd_8bit_t *lcd);

static std_ReturnType lcd_chr_8bit_set_cursor(const lcd_8bit_t *lcd , uint8 row , uint8 column);
static std_ReturnType lcd_chr_4bit_set_cursor(const lcd_4bit_t *lcd , uint8 row , uint8 column);

std_ReturnType lcd_chr_4bit_intialize(const lcd_4bit_t *lcd){
    std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        uint8 l_pin_lcd_counter = 0;
        ret |= gpio_pin_intiailize(&(lcd->en_pin));
        ret |= gpio_pin_intiailize(&(lcd->rs_pin));
        for(l_pin_lcd_counter = 0 ; l_pin_lcd_counter < four_bit_pins ; l_pin_lcd_counter++){
        ret = gpio_pin_intiailize(&(lcd->lcd_pin[l_pin_lcd_counter]));  
        }
        __delay_ms(20);
        ret |= lcd_chr_4bit_send_command(lcd , _LCD_8BIT_MODE_2_Line);
        __delay_ms(5);
        ret |= lcd_chr_4bit_send_command(lcd , _LCD_8BIT_MODE_2_Line);
        __delay_us(150);
        ret |= lcd_chr_4bit_send_command(lcd , _LCD_8BIT_MODE_2_Line);
        
        lcd_chr_4bit_send_command(lcd , _LCD_CLEAR);
        lcd_chr_4bit_send_command(lcd , _LCD_RETURN_HOME);
        lcd_chr_4bit_send_command(lcd , _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        lcd_chr_4bit_send_command(lcd , _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON);
        lcd_chr_4bit_send_command(lcd , _LCD_4BIT_MODE_2_Line);
        lcd_chr_4bit_send_command(lcd , 0x80);
        
    }
    return ret;
}
std_ReturnType lcd_chr_4bit_send_command(const lcd_4bit_t *lcd , uint8 command){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        ret |= gpio_pin_write_logic(&(lcd->rs_pin) , GPIO_LOW);
        ret |= lcd_send_data_command_4bit(lcd , command >> 4);
        ret |= lcd_4bit_send_enable(lcd);
        ret |= lcd_send_data_command_4bit(lcd , command); 
        ret |= lcd_4bit_send_enable(lcd);
    }
    return ret;
}
std_ReturnType lcd_chr_4bit_send_chr_data(const lcd_4bit_t *lcd , uint8 data){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        ret |= gpio_pin_write_logic(&(lcd->rs_pin), GPIO_HIGH);
        ret |= lcd_send_data_command_4bit(lcd , data >> 4);
        ret |= lcd_4bit_send_enable(lcd);
        ret |= lcd_send_data_command_4bit(lcd , data); 
        ret |= lcd_4bit_send_enable(lcd);
    }
    return ret;
}

std_ReturnType lcd_chr_4bit_send_data_pos(const lcd_4bit_t *lcd ,uint8 row,  
                                          uint8 column  , uint8 data){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        lcd_chr_4bit_set_cursor(lcd , row , column);
        lcd_chr_4bit_send_chr_data(lcd , data);
    }
    return ret;
}
std_ReturnType lcd_chr_4bit_send_string(const lcd_4bit_t *lcd , uint8 *str){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        while(*str){
            lcd_chr_4bit_send_chr_data(lcd , *str++);
        }
    }
    return ret;
}
std_ReturnType lcd_chr_4bit_send_string_pos(const lcd_4bit_t *lcd , uint8 row,  
                                            uint8 column  ,uint8 *str){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        lcd_chr_4bit_set_cursor(lcd , row , column);
        lcd_chr_4bit_send_string(lcd , str);
    }
    return ret;
}
std_ReturnType lcd_chr_4bit_send_custom_chr(const lcd_4bit_t *lcd , uint8 row,  
                                            uint8 column  ,const uint8 chr[] , uint8 mem_pos){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
    }
    return ret;
}




std_ReturnType lcd_chr_8bit_intialize(const lcd_8bit_t *lcd){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        uint8 l_pin_lcd_counter = 0;
        ret = gpio_pin_intiailize(&(lcd->en_pin));
        ret = gpio_pin_intiailize(&(lcd->rs_pin));
        for(l_pin_lcd_counter = 0 ; l_pin_lcd_counter < eight_bit_pins ; l_pin_lcd_counter++){
        ret = gpio_pin_intiailize(&(lcd->lcd_pin[l_pin_lcd_counter]));  
        }
        __delay_ms(20);
        ret |= lcd_chr_8bit_send_command(lcd , _LCD_8BIT_MODE_2_Line);
        __delay_ms(5);
        ret |= lcd_chr_8bit_send_command(lcd , _LCD_8BIT_MODE_2_Line);
        __delay_us(150);
        ret |= lcd_chr_8bit_send_command(lcd , _LCD_8BIT_MODE_2_Line);
        
        lcd_chr_8bit_send_command(lcd , _LCD_CLEAR);
        lcd_chr_8bit_send_command(lcd , _LCD_RETURN_HOME);
        lcd_chr_8bit_send_command(lcd , _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        lcd_chr_8bit_send_command(lcd , _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        lcd_chr_8bit_send_command(lcd , _LCD_8BIT_MODE_2_Line);
        lcd_chr_8bit_send_command(lcd , 0x80);
    }
    return ret;
}
std_ReturnType lcd_chr_8bit_send_command(const lcd_8bit_t *lcd , uint8 command){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        ret |= gpio_pin_write_logic(&(lcd->rs_pin) , GPIO_LOW);
        uint8 l_counter = 0;
        for(l_counter = 0 ; l_counter < eight_bit_pins; l_counter++){
            ret |= gpio_pin_write_logic(&(lcd->lcd_pin[l_counter]) , (command >> l_counter) & (uint8)0x01);
        }
        ret |= lcd_8bit_send_enable(lcd);
    }
    return ret;
}
std_ReturnType lcd_chr_8bit_send_chr_data(const lcd_8bit_t *lcd , uint8 data){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        ret |= gpio_pin_write_logic(&(lcd->rs_pin) , GPIO_HIGH);
        uint8 l_counter = 0;
        for(l_counter = 0 ; l_counter < eight_bit_pins; l_counter++){
            ret |= gpio_pin_write_logic(&(lcd->lcd_pin[l_counter]) , (data >> l_counter) & (uint8)0x01);
            
        }
        ret |= lcd_8bit_send_enable(lcd);
    }
    return ret;
}
std_ReturnType lcd_chr_8bit_send_data_pos(const lcd_8bit_t *lcd ,uint8 row,  
                                          uint8 column  , uint8 data){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        ret |= lcd_chr_8bit_set_cursor(lcd , row , column);
        ret |= lcd_chr_8bit_send_chr_data(lcd , data);
    }
    return ret;
}
std_ReturnType lcd_chr_8bit_send_string(const lcd_8bit_t *lcd , uint8 *str){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        while(*str != '\0'){
            lcd_chr_8bit_send_chr_data(lcd , *str++);
        }
    }
    return ret;
}
std_ReturnType lcd_chr_8bit_send_string_pos(const lcd_8bit_t *lcd , uint8 row,  
                                            uint8 column  ,uint8 *str){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
        lcd_chr_8bit_set_cursor(lcd , row , column);
        lcd_chr_8bit_send_string(lcd , str);
    }
    return ret;
}
std_ReturnType lcd_chr_8bit_send_custom_chr(const lcd_8bit_t *lcd , uint8 row,  
                                            uint8 column  ,const uint8 chr[] , uint8 mem_pos){
    std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOK;
    }
    else{
    }
    return ret;
}

static std_ReturnType lcd_send_data_command_4bit(const lcd_4bit_t *lcd ,uint8 _data_command){
    std_ReturnType ret = E_OK;
    
    ret |= gpio_pin_write_logic(&(lcd->lcd_pin[0]) , (_data_command >> 0) & (uint8)0x01);
    ret |= gpio_pin_write_logic(&(lcd->lcd_pin[1]) , (_data_command >> 1) & (uint8)0x01);
    ret |= gpio_pin_write_logic(&(lcd->lcd_pin[2]) , (_data_command >> 2) & (uint8)0x01);
    ret |= gpio_pin_write_logic(&(lcd->lcd_pin[3]) , (_data_command >> 3) & (uint8)0x01);
    return ret;
}

static std_ReturnType lcd_4bit_send_enable(const lcd_4bit_t *lcd){
    std_ReturnType ret = E_OK;
    
    ret |= gpio_pin_write_logic(&(lcd->en_pin) , GPIO_HIGH);
    
    __delay_us(5);
    ret |= gpio_pin_write_logic(&(lcd->en_pin) , GPIO_LOW);
    
    return ret;
}

static std_ReturnType lcd_8bit_send_enable(const lcd_8bit_t *lcd){
    std_ReturnType ret = E_OK;
    
    ret |= gpio_pin_write_logic(&(lcd->en_pin) , GPIO_HIGH);
    
    __delay_us(5);
    ret |= gpio_pin_write_logic(&(lcd->en_pin) , GPIO_LOW);
    
    return ret;
}

static std_ReturnType lcd_chr_8bit_set_cursor(const lcd_8bit_t *lcd , uint8 row , uint8 column){
    std_ReturnType ret = E_OK;
    if(lcd == NULL || row > 5){
        ret = E_NOK;
    }
    else{
        column--;
        switch(row){
            case ROW_1: lcd_chr_8bit_send_command(lcd , (0x80 + column)); break;
            case ROW_2: lcd_chr_8bit_send_command(lcd , (0xC0 + column)); break;
            case ROW_3: lcd_chr_8bit_send_command(lcd , (0x94 + column)); break;
            case ROW_4: lcd_chr_8bit_send_command(lcd , (0xd4 + column)); break;
            deafult: ;
        }
    }
    return ret;
}
static std_ReturnType lcd_chr_4bit_set_cursor(const lcd_4bit_t *lcd , uint8 row , uint8 column){
    std_ReturnType ret = E_OK;
    if(lcd == NULL || row > 5){
        ret = E_NOK;
    }
    else{
        column--;
        switch(row){
            case ROW_1: lcd_chr_4bit_send_command(lcd , (0x80 + column)); break;
            case ROW_2: lcd_chr_4bit_send_command(lcd , (0xC0 + column)); break;
            case ROW_3: lcd_chr_4bit_send_command(lcd , (0x94 + column)); break;
            case ROW_4: lcd_chr_4bit_send_command(lcd , (0xd4 + column)); break;
            deafult: ;
        }
    }
    return ret;
}

