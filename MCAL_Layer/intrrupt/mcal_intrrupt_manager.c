#include "mcal_intrrupt_manager.h"
volatile uint8 RB4_flag;
volatile uint8 RB5_flag;
volatile uint8 RB6_flag;
volatile uint8 RB7_flag;
#if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
void __interrupt() Intrrupt_Manager_Higer_Priority(){
    if((INTCONbits.INT0IE == INTRRUPT_ENABLE) && (INTCONbits.INT0IF == INTRRUPT_OCCUR)){
        INT0_ISR();
    }
    else { /* Nothing */ }
    if((INTCON3bits.INT1IE == INTRRUPT_ENABLE) && (INTCON3bits.INT1IF == INTRRUPT_OCCUR)){
        INT1_ISR();
    }
    else { /* Nothing */ }
}

void __interrupt(low_priority) Intrrupt_Manager_Lower_Priority(){
    if((INTCON3bits.INT2IE == INTRRUPT_ENABLE) && (INTCON3bits.INT2IF == INTRRUPT_OCCUR)){
        INT2_ISR();
    }
    else { /* Nothing */ }
}
#else
void __interrupt() Intrrupt_Manager_Priority(){
    #if EXTERNAL_INTRRUPT_INTx_FEATURE_ENABLE  == Feture_enable
    if((INTCONbits.INT0IE == INTRRUPT_ENABLE) && (INTCONbits.INT0IF == INTRRUPT_OCCUR)){
        INT0_ISR();
    }
    else { /* Nothing */ }
    if((INTCON3bits.INT1IE == INTRRUPT_ENABLE) && (INTCON3bits.INT1IF == INTRRUPT_OCCUR)){
        INT1_ISR();
    }
    else { /* Nothing */ }
    if((INTCON3bits.INT2IE == INTRRUPT_ENABLE) && (INTCON3bits.INT2IF == INTRRUPT_OCCUR)){
        INT2_ISR();
    }
    else { /* Nothing */ }
    #endif
    #if EXTERNAL_INTRRUPT_OnChange_FEATURE_ENABLE == Feture_enable
    if((INTCONbits.RBIE == INTRRUPT_ENABLE) && (INTCONbits.RBIF == INTRRUPT_OCCUR) &&
        (PORTBbits.RB4 = GPIO_HIGH) && (RB4_flag == 1)){
        RB4_flag = 0;
        RB4_ISR(1);
    }
    else { /* Nothing */ }
    if((INTCONbits.RBIE == INTRRUPT_ENABLE) && (INTCONbits.RBIF == INTRRUPT_OCCUR) &&
        (PORTBbits.RB4 = GPIO_LOW) && (RB4_flag == 0)){
        RB4_flag = 1;
        RB4_ISR(0);
    }
    else { /* Nothing */ }
    if((INTCONbits.RBIE == INTRRUPT_ENABLE) && (INTCONbits.RBIF == INTRRUPT_OCCUR) &&
        (PORTBbits.RB5 = GPIO_HIGH) && (RB5_flag == 1)){
        RB5_flag = 0;
        RB5_ISR(1);
    }
    else { /* Nothing */ }
    if((INTCONbits.RBIE == INTRRUPT_ENABLE) && (INTCONbits.RBIF == INTRRUPT_OCCUR) &&
        (PORTBbits.RB5 = GPIO_LOW) && (RB5_flag == 0)){
        RB5_flag = 1;
        RB5_ISR(0);
    }
    else { /* Nothing */ }
    if((INTCONbits.RBIE == INTRRUPT_ENABLE) && (INTCONbits.RBIF == INTRRUPT_OCCUR) &&
        (PORTBbits.RB6 = GPIO_HIGH) && (RB6_flag == 1)){
        RB6_flag = 0;
        RB6_ISR(1);
    }
    else { /* Nothing */ }
    if((INTCONbits.RBIE == INTRRUPT_ENABLE) && (INTCONbits.RBIF == INTRRUPT_OCCUR) &&
        (PORTBbits.RB6 = GPIO_LOW) && (RB6_flag == 0)){
        RB6_flag = 1;
        RB6_ISR(0);
    }
    else { /* Nothing */ }
    
    if((INTCONbits.RBIE == INTRRUPT_ENABLE) && (INTCONbits.RBIF == INTRRUPT_OCCUR) &&
        (PORTBbits.RB7 = GPIO_HIGH) && (RB7_flag == 1)){
        RB7_flag = 0;
        RB7_ISR(1);
    }
    else { /* Nothing */ }
    if((INTCONbits.RBIE == INTRRUPT_ENABLE) && (INTCONbits.RBIF == INTRRUPT_OCCUR) &&
        (PORTBbits.RB7 = GPIO_LOW) && (RB7_flag == 0)){
        RB7_flag = 1;
        RB7_ISR(0);
    }
    else { /* Nothing */ }
    #endif
    #if ADC_INTRRUPT_FEATURE_ENABLE == Feture_enable
    if((PIE1bits.ADIE = INTRRUPT_ENABLE) && (PIR1bits.ADIF = INTRRUPT_OCCUR))
    {
        ADC_ISR();
    }
    else { /* Nothing */ }
    #endif
    
}
#endif
