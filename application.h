/* 
 * File:   application.h
 * Author: USER
 *
 * Created on April 16, 2024, 11:34 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H
/*********** Section : Include Libraries          ***********/
/* Ecu Layer */
#include "ECU_Layer/LED/ECU_LED.h"
#include "ECU_Layer/button/ecu_button.h"
#include "ECU_Layer/DC_Motor/ecu_DC_Motor.h"
#include "ECU_Layer/Relay/ecu_relay.h"
#include "ECU_Layer/7_segment/ecu_7_segment.h"
#include "ECU_Layer/char_LCD/ecu_char_lcd.h"
#include "ECU_Layer/KeyPad/ecu_KeyPad.h"

/* MCAL Layer */
#include "MCAL_Layer/intrrupt/mcal_external_intrrupt.h"
#include "MCAL_Layer/EEPROM/hal_eeprom.h"
#include "MCAL_Layer/ADC/hal_adc.h"
/*********** Section : Function Declaration          ***********/
void int_app(void);
#endif	/* APPLICATION_H */

