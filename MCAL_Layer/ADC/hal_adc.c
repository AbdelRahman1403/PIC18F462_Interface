#include "hal_adc.h"
static inline void select_input_pin_channel(adc_channel_select_t channel);
static inline void select_Result_Formant(adc_config_t *adc);
static inline void select_Voltage_Refernce(adc_config_t *adc);
/**
 * 
 * @param _adc
 * @return 
 */
std_ReturnType ADC_INIT(adc_config_t *_adc){
    std_ReturnType ret = E_NOK;
    if(_adc == NULL){
        ret = E_NOK;
    }
    else{
        /* Disable A/D Converter */
        ADC_MODULE_DISABLE();
        /* Configure The Acquesion Time */
        ADCON2bits.ACQT = _adc->adc_acquisition;
        /* Configure The Conversion Clock */
        ADCON2bits.ADCS = _adc->adc_conversion;
        /* Configure the input channel */
        ADCON0bits.CHS = _adc->adc_channal;
        select_input_pin_channel(_adc->adc_channal);
        /* Configure Voltage Format */
        select_Voltage_Refernce(_adc);
        /* select Result Format */
        select_Result_Formant(_adc);
        /* Enable A/D Converter */
        ADC_MODULE_ENABLE();
        
        ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param _adc
 * @return 
 */
std_ReturnType ADC_De_INIT(adc_config_t *_adc){
    std_ReturnType ret = E_NOK;
    if(_adc == NULL){
        ret = E_NOK;
    }
    else{
        /* Disable A/D Converter */
        ADC_MODULE_DISABLE();
        /* Disable A/D Converter Interrupt */
        
        ret = E_OK;
    }
    return ret;
}
 /**
  * 
  * @param _adc
  * @param adc_channel
  * @return 
  */
/*  */
std_ReturnType ADC_Select_Channel(adc_config_t *_adc , adc_channel_select_t adc_channel){
    std_ReturnType ret = E_NOK;
    if(_adc == NULL){
        ret = E_NOK;
    }
    else{
        ADCON0bits.CHS = adc_channel;
        select_input_pin_channel(adc_channel);
        ret = E_OK;
    }
    return ret;
}
 /**
  * 
  * @param _adc
  * @return 
  */
std_ReturnType ADC_Start_Conversion(adc_config_t *_adc){
    std_ReturnType ret = E_NOK;
    if(_adc == NULL){
        ret = E_NOK;
    }
    else{
        ADC_START_CONVERSION();
        ret = E_OK;
    }
    return ret;
}
 /**
  * 
  * @param _adc
  * @param Conversion_status
  * @return 
  */
std_ReturnType ADC_Is_Conversion_Done(adc_config_t *_adc , uint8 *Conversion_status){
    std_ReturnType ret = E_NOK;
    if((_adc == NULL) || (Conversion_status == NULL)){
        ret = E_NOK;
    }
    else{
        *Conversion_status = (uint8)(!(ADCON0bits.GO_nDONE)); // The (!) to tell me The Conversion Process is Idle 
                                                                //If status = 1 --> the conversion is done so the A/D is idle --> so !(1) = 0
        ret = E_OK;
    }
    return ret;
}
 /**
  * 
  * @param _adc
  * @param Conversion_Result
  * @return 
  */
std_ReturnType ADC_Get_Conversion_Result(adc_config_t *_adc , uint16 *Conversion_Result){
    std_ReturnType ret = E_NOK;
    if((_adc == NULL) || (Conversion_Result == NULL)){
        ret = E_NOK;
    }
    else{
         if(_adc->result_format == Right_Format){
            *Conversion_Result = (uint16)((ADRESH << 8) + ADRESL);
        }
        else if(_adc->result_format == Left_Format){
            *Conversion_Result = (uint16)(((ADRESH << 8) + ADRESL) >> 6);
        }
        else{
            *Conversion_Result = (uint16)((ADRESH << 8) + ADRESL);
        }
        ret = E_OK;
    }
    return ret;
}
 /**
  * 
  * @param _adc
  * @param Conversion_Result
  * @param adc_channel
  * @return 
  */
std_ReturnType ADC_Get_Conversion_Blocking(adc_config_t *_adc , uint16 *Conversion_Result ,
                                  adc_channel_select_t adc_channel){
    std_ReturnType ret = E_NOK;
    if((_adc == NULL) || (Conversion_Result == NULL)){
        ret = E_NOK;
    }
    else{
        /* Select Channel Analog Input */
        ADC_Select_Channel(_adc , adc_channel);
        /* Start The Conversion Process From Analog To Digital */
        ADC_Start_Conversion(_adc);
        /* Same Delay To Stop process to complete the conversion */
        while(ADCON0bits.GO_nDONE);
        ret = ADC_Get_Conversion_Result(_adc , Conversion_Result);
        
        ret = E_OK;
    }
    return ret;
}
 
static inline void select_input_pin_channel(adc_channel_select_t channel){
    switch(channel){
        case ADC_AN0_ANALOG_FUNCTIONLITY :  SET_BIT(TRISA , _TRISA_RA0_POSN); break;
        case ADC_AN1_ANALOG_FUNCTIONLITY :  SET_BIT(TRISA , _TRISA_RA1_POSN); break;
        case ADC_AN2_ANALOG_FUNCTIONLITY :  SET_BIT(TRISA , _TRISA_RA2_POSN); break;
        case ADC_AN3_ANALOG_FUNCTIONLITY :  SET_BIT(TRISA , _TRISA_RA3_POSN); break;
        case ADC_AN4_ANALOG_FUNCTIONLITY :  SET_BIT(TRISA , _TRISA_RA5_POSN); break;
        case ADC_AN5_ANALOG_FUNCTIONLITY :  SET_BIT(TRISE , _TRISE_RE0_POSN); break;
        case ADC_AN6_ANALOG_FUNCTIONLITY :  SET_BIT(TRISE , _TRISE_RE1_POSN); break;
        case ADC_AN7_ANALOG_FUNCTIONLITY :  SET_BIT(TRISE , _TRISE_RE2_POSN); break;
        case ADC_AN8_ANALOG_FUNCTIONLITY :  SET_BIT(TRISB , _TRISB_RB2_POSN); break;
        case ADC_AN9_ANALOG_FUNCTIONLITY :  SET_BIT(TRISB , _TRISB_RB3_POSN); break;
        case ADC_AN10_ANALOG_FUNCTIONLITY : SET_BIT(TRISB , _TRISB_RB1_POSN); break;
        case ADC_AN11_ANALOG_FUNCTIONLITY : SET_BIT(TRISB , _TRISB_RB4_POSN); break;
        case ADC_AN12_ANALOG_FUNCTIONLITY : SET_BIT(TRISB , _TRISB_RB0_POSN); break;
    }
}

static inline void select_Result_Formant(adc_config_t *adc){
    if(adc->result_format == Right_Format){
        ADC_Result_Format_Right();
    }
    else if(adc->result_format == Left_Format){
        ADC_Result_Format_Left();
    }
    else{
        ADC_Result_Format_Right();
    }
}

static inline void select_Voltage_Refernce(adc_config_t *adc){
    if(adc->voltage_format == Voltage_Reference_Enable){
        ADC_ENABLE_VOLTAGE_REF();
    }
    else if(adc->voltage_format == Voltage_Reference_Disable){
        ADC_DISABLE_VOLTAGE_REF();
    }else{
        
    }
}