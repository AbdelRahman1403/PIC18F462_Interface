/* 
 * File:   hal_adc.h
 * Author: USER
 *
 * Created on August 18, 2024, 2:32 AM
 */
#ifndef HAL_ADC_H
#define	HAL_ADC_H
/*********** Section : Include Libraries          ***********/
#include "../mcal_std_types.h"
#include "hal_adc_cfg.h"
#include "../intrrupt/mcal_internal_intrrupt.h"
#include "../GPIO/hal_gpio.h"
#include "pic18f4620.h"
/*********** Section : Data Type Declaration      ***********/

typedef enum{
    ADC_CHANNEL_AN0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7,
    ADC_CHANNEL_AN8,
    ADC_CHANNEL_AN9,
    ADC_CHANNEL_AN10,
    ADC_CHANNEL_AN11,
    ADC_CHANNEL_AN12,
}adc_channel_select_t;
/**
 @breif : adc_acquisition_time
 @Note  : Acquisition time (sampling Time) is the time required to the ADC
 *       To capture the voltage during sampling (Charge the ????????) 
 */
typedef enum{
    adc_0_TAD = 0,
    adc_2_TAD,
    adc_4_TAD,
    adc_6_TAD,
    adc_8_TAD,
    adc_12_TAD,
    adc_16_TAD,
    adc_20_TAD,
}adc_acquisition_time_t;

typedef enum{
    adc_conversion_FOSC_div_2 = 0,
    adc_conversion_FOSC_div_8,
    adc_conversion_FOSC_div_32,  
    adc_conversion_FRC,
    adc_conversion_FOSC_div_4,
    adc_conversion_FOSC_div_16,
    adc_conversion_FOSC_div_64,
}adc_conversion_time_t;

typedef struct{
#if ADC_INTRRUPT_FEATURE_ENABLE == Feture_enable
    void (* ADC_InttrepputHandler)(void);
    intrrupt_priority_cfg priority;
#endif
    adc_channel_select_t adc_channal;
    adc_acquisition_time_t adc_acquisition;
    adc_conversion_time_t adc_conversion;
    uint8 voltage_format : 1;
    uint8 result_format  : 1;
    uint8 reseved_bits   : 6;
}adc_config_t;
/*********** Section : Macro Declaration          ***********/
/* @Note : When you increment the pins of analog (AN0 , AN1 , ...) You will access N-1 pins
 * Access AN2 --> Access AN2 , AN1 , AN0
 * Access AN3 --> Access AN3 , AN2 , AN1 , AN0
 * Access AN4 --> Access AN4 , AN3 , AN2 , AN1 , AN0 
 * And so On ....
 *  */
#define ADC_ALL_ANALOG_FUNCTIONLITY    0x00
#define ADC_ALL_DIGITAL_FUNCTIONLITY   0x0f
#define ADC_AN0_ANALOG_FUNCTIONLITY    0x0E
#define ADC_AN1_ANALOG_FUNCTIONLITY    0x0D
#define ADC_AN2_ANALOG_FUNCTIONLITY    0x0C
#define ADC_AN3_ANALOG_FUNCTIONLITY    0x0B
#define ADC_AN4_ANALOG_FUNCTIONLITY    0x0A
#define ADC_AN5_ANALOG_FUNCTIONLITY    0x09
#define ADC_AN6_ANALOG_FUNCTIONLITY    0x08
#define ADC_AN7_ANALOG_FUNCTIONLITY    0x07
#define ADC_AN8_ANALOG_FUNCTIONLITY    0x06
#define ADC_AN9_ANALOG_FUNCTIONLITY    0x05
#define ADC_AN10_ANALOG_FUNCTIONLITY   0x04
#define ADC_AN11_ANALOG_FUNCTIONLITY   0x03
#define ADC_AN12_ANALOG_FUNCTIONLITY   0x02

#define Right_Format 0x01u
#define Left_Format  0x00u

#define Voltage_Reference_Enable  0x01u
#define Voltage_Reference_Disable 0x00u

#define Conversion_Status_Done   0
#define Conversion_Status_N_Done 1

/*********** Section : Function Macro Declaration ***********/
/**
 @breif : Analog to Digital .
 @Note : Enable or Disable The ADC Module
 */
#define ADC_MODULE_ENABLE()           (ADCON0bits.ADON = 1) 
#define ADC_MODULE_DISABLE()          (ADCON0bits.ADON = 0) 
/**
 @breif : Analog to Digital .
 @Note : Chick The ADC Progress / Status (In progress or Idle)
 */
#define ADC_Conversion_Status()       (ADCON0bits.GO_nDONE)
#define ADC_START_CONVERSION()        (ADCON0bits.GODONE = 1)
/**
 @breif : Status of Voltage Reference
 @Note  : Check The Status Of The Voltage Reference .
 *      Enable --> Connect The External Voltage To MCU.
 *      Disable --> Independ on The Internal Voltage in MCU.
 */
#define ADC_ENABLE_VOLTAGE_REF()    do{ADCON1bits.VCFG1 = 1;\
                                       ADCON1bits.VCFG0 = 1;\
                                    }while(0);
#define ADC_DISABLE_VOLTAGE_REF()   do{ADCON1bits.VCFG1 = 0;\
                                       ADCON1bits.VCFG0 = 0;\
                                    }while(0);
#define ADC_DIGITAL_ANALOG_PINS_CONFIG(_Config)     (ADCON1bits.PCFG = _Config)

#define ADC_Result_Format_Right()        (ADCON2bits.ADFM = 1)
#define ADC_Result_Format_Left()         (ADCON2bits.ADFM = 0)
/*********** Section : Function Declaration       ***********/

std_ReturnType ADC_INIT(adc_config_t *_adc);
std_ReturnType ADC_De_INIT(adc_config_t *_adc);
std_ReturnType ADC_Select_Channel(adc_config_t *_adc , adc_channel_select_t adc_channel);
std_ReturnType ADC_Start_Conversion(adc_config_t *_adc);
std_ReturnType ADC_Is_Conversion_Done(adc_config_t *_adc , uint8 *Conversion_status);
std_ReturnType ADC_Get_Conversion_Result(adc_config_t *_adc , uint16 *Conversion_Result);
std_ReturnType ADC_Get_Conversion_Blocking(adc_config_t *_adc , uint16 *Conversion_Result ,
                                  adc_channel_select_t adc_channel);
std_ReturnType ADC_Start_Conversion_Interrupt(adc_config_t *_adc ,adc_channel_select_t adc_channel);

#endif	/* HAL_ADC_H */

