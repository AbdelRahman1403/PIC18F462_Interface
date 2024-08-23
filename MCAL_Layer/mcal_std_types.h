/* 
 * File:   mcal_std_types.h
 * Author: USER
 *
 * Created on April 16, 2024, 11:25 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H
/*********** Section : Include Libraries          ***********/
#include "std_libraries.h"
//#include <../proc/pic18f4620.h>
#include "compiler.h"
/*********** Section : Data Type Declaration      ***********/
typedef unsigned char         uint8;
typedef unsigned short        uint16;
typedef unsigned int          uint32;
typedef signed char           sint8;
typedef signed short          sint16;
typedef signed int            sint32;
typedef uint8  std_ReturnType;
/*********** Section : Macro Declaration          ***********/


#define STD_HIGH                0x01
#define STD_LOW                 0x00

#define STD_ON                  0x01
#define STD_OFF                 0x00

#define STD_ACTIVE              0x01
#define STD_IDLE                0x00

#define E_OK     (std_ReturnType) 0x01
#define E_NOK    (std_ReturnType) 0x00

/*********** Section : Function Macro Declaration ***********/


/*********** Section : Function Declaration       ***********/
#endif	/* MCAL_STD_TYPES_H */

