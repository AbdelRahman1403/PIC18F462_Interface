/* 
 * File:   ecu_char_lcd.h
 * Author: USER
 *
 * Created on July 8, 2024, 10:37 AM
 */

#ifndef ECU_CHAR_LCD_H
#define	ECU_CHAR_LCD_H

/*********** Section : Include Libraries          ***********/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*********** Section : Macro Declaration          ***********/
#define _LCD_CLEAR                               0x01
#define _LCD_RETURN_HOME                         0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF            0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON             0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF            0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON             0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT              0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT             0x14
#define _LCD_DISPLAY_SHIFT_LEFT                  0x18
#define _LCD_DISPLAY_SHIFT_RIGHT                 0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_Line                    0x38
#define _LCD_4BIT_MODE_2_Line                    0x28

#define _LCD_CGRAM_DEFINE                        0x40
#define _LCD_DDRAM_DEFINE                        0x80

#define ROW_1 1
#define ROW_2 2
#define ROW_3 3
#define ROW_4 4

#define four_bit_pins  4
#define eight_bit_pins 8
/*********** Section : Function Macro Declaration ***********/

/*********** Section : Data Type Declaration      ***********/

typedef struct{
    pin_config_t lcd_pin[four_bit_pins];
    pin_config_t rs_pin;
    pin_config_t en_pin;
}lcd_4bit_t;

typedef struct{
    pin_config_t lcd_pin[eight_bit_pins];
    pin_config_t rs_pin;
    pin_config_t en_pin;
}lcd_8bit_t;

/*********** Section : Function Declaration       ***********/

std_ReturnType lcd_chr_4bit_intialize(const lcd_4bit_t *lcd);
std_ReturnType lcd_chr_4bit_send_command(const lcd_4bit_t *lcd , uint8 command);
std_ReturnType lcd_chr_4bit_send_chr_data(const lcd_4bit_t *lcd , uint8 data);
std_ReturnType lcd_chr_4bit_send_data_pos(const lcd_4bit_t *lcd ,uint8 row,  
                                          uint8 column  , uint8 data);
std_ReturnType lcd_chr_4bit_send_string(const lcd_4bit_t *lcd , uint8 *str);
std_ReturnType lcd_chr_4bit_send_string_pos(const lcd_4bit_t *lcd , uint8 row,  
                                            uint8 column  ,uint8 *str);
std_ReturnType lcd_chr_4bit_send_custom_chr(const lcd_4bit_t *lcd , uint8 row,  
                                            uint8 column  ,const uint8 chr[] , uint8 mem_pos);


std_ReturnType lcd_chr_8bit_intialize(const lcd_8bit_t *lcd);
std_ReturnType lcd_chr_8bit_send_command(const lcd_8bit_t *lcd , uint8 command);
std_ReturnType lcd_chr_8bit_send_command(const lcd_8bit_t *lcd , uint8 command);
std_ReturnType lcd_chr_8bit_send_chr_data(const lcd_8bit_t *lcd , uint8 data);
std_ReturnType lcd_chr_8bit_send_data_pos(const lcd_8bit_t *lcd ,uint8 row,  
                                          uint8 column  , uint8 data);
std_ReturnType lcd_chr_8bit_send_string(const lcd_8bit_t *lcd , uint8 *str);
std_ReturnType lcd_chr_8bit_send_string_pos(const lcd_8bit_t *lcd , uint8 row,  
                                            uint8 column  ,uint8 *str);
std_ReturnType lcd_chr_8bit_send_custom_chr(const lcd_8bit_t *lcd , uint8 row,  
                                            uint8 column  ,const uint8 chr[] , uint8 mem_pos);



#endif	/* ECU_CHAR_LCD_H */

