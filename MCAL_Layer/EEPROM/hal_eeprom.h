/* 
 * File:   hal_eeprom.h
 * Author: USER
 *
 * Created on August 11, 2024, 1:51 AM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/*********** Section : Include Libraries          ***********/
#include "../mcal_std_types.h"
#include "../intrrupt/mcal_internal_intrrupt.h"
#include <pic18f4620.h>
/*********** Section : Data Type Declaration      ***********/

/*********** Section : Macro Declaration          ***********/
#define ACCESS_EEPROM_MEMORY            EECON1bits.EEPGD = 0
#define ACCESS_FLASH_MEMORY             EECON1bits.EEPGD = 1

#define ACCESS_CONFIG_REG               EECON1bits.CFGS = 1      
#define ACCESS_FLASH_EEPROM_MEMORY      EECON1bits.CFGS = 0

#define ALLOW_WRITE_CYCLE_FLAH_EEPROM      EECON1bits.WREN = 1
#define INHABITS_WRITE_CYCLE_FLAH_EEPROM   EECON1bits.WREN = 0

#define Initiates_Write_Control_Bit     EECON1bits.WR = 1
#define Write_Control_Bit_Completed     EECON1bits.WR = 0

#define Initiates_Read_Control_Bit      EECON1bits.RD = 1            
#define Read_Control_Bit_Completed      EECON1bits.RD = 0            
/*********** Section : Function Macro Declaration ***********/


/*********** Section : Function Declaration       ***********/
std_ReturnType EEPROM_DATA_WriteByte(uint16 bADD , uint8 data);
std_ReturnType EEPROM_DATA_ReadByte(uint16 bADD , uint8* data);
#endif	/* HAL_EEPROM_H */

