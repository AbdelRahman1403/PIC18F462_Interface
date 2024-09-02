#include "hal_Timer0.h"
#if TIMER0_INTRRUPT_FEATURE_ENABLE == Feture_enable
void (*Timer0_InterruptHandler)(void) = NULL;
#endif

static uint16 preload_val;

static inline void timer0_mode_func(const timer0_t * timer);
static inline void timer0_prescaler_func(const timer0_t *timer);
static inline void timer0_register_size_func(const timer0_t *timer);
std_ReturnType TIMER0_INIT(const timer0_t *timer){
    std_ReturnType ret = E_OK;
    if(timer == NULL){
        ret = E_NOK;
    }
    else{
        /* Disable Timer0  */
        TIMER0_DISABLE();
        /* Select the Prescaler */
        timer0_prescaler_func(timer);
        /* Select Timer mode or Counter Mode */
        timer0_mode_func(timer);
        /* Select timer0 register size */
        timer0_register_size_func(timer);
        TMR0H = (timer->timer0_Preload_val) >> 8;
        TMR0L = (uint8)(timer->timer0_Preload_val);
        preload_val = timer->timer0_Preload_val;
        /* Enable Timer0 Interrupt */
#if TIMER0_INTRRUPT_FEATURE_ENABLE == Feture_enable
        TIMER0_INTERRUPT_Enable();
        TIMER0_INTERRUPT_Flag_Clear();
        Timer0_InterruptHandler = timer->_Timer0_InterruptHandler;
        
#if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
        INTRRUTPT_Priority_Levels_Enable();
        if(intrrupt_high_prioity == timer->priority){
            INTRRUTPT_GlobalIntrruptHighEnable();
            TIMER0_Interrupt_HigherPrioritySet();
        }
        else if(intrrupt_high_prioity == timer->priority){
            INTRRUTPT_GlobalIntrruptLowerEnable();
            TIMER0_Interrupt_LowerPrioritySet();
        }
        else{ /* Nothing */ }
#else
    INTRRUTPT_Global_IntrruptEnable();
    INTRRUTPT_Peripheral_Intrrupt_Enable();
#endif
#endif
        /* Enable Timer0  */
        TIMER0_ENABLE();
        ret = E_OK;
    }
    return ret;
}

std_ReturnType TIMER0_DeINIT(const timer0_t *timer){
    std_ReturnType ret = E_OK;
    if(timer == NULL){
        ret = E_NOK;
    }
    else{
        
        ret = E_OK;
    }
    return ret;
}

std_ReturnType TIMER0_Read(const timer0_t *timer , uint16 *Read_data){
    std_ReturnType ret = E_OK;
    if(timer == NULL || Read_data == NULL){
        ret = E_NOK;
    }
    else{
        
        ret = E_OK;
    }
    return ret;    
}
std_ReturnType TIMER0_Write(const timer0_t *timer , uint16 Write_data){
    
    std_ReturnType ret = E_OK;
    if(timer == NULL){
        ret = E_NOK;
    }
    else{
        TMR0H = (Write_data) >> 8;
        TMR0L = (uint8)(Write_data);
        ret = E_OK;
    }
    return ret;    
}

static inline void timer0_prescaler_func(const timer0_t *timer){
    if(timer->prescaler_status == PRESCALER_STATUS_ENABLE_CFG){
            T0CONbits.T0PS  = timer->prescaler_val;
            PRESCALER_STATUS_ENABLE();
        }
        else if(timer->prescaler_status == PRESCALER_STATUS_DISABLE_CFG){
            PRESCALER_STATUS_DISABLE();
        }
        else{ /* Nothing */ }
}

static inline void timer0_mode_func(const timer0_t * timer){
    if(TIMER0_TIMER_MODE_CFG == timer->timer0_mode){
        TIMER0_TIMER_MODE();
    }
    else if(TIMER0_COUNTER_MODE_CFG == timer->timer0_mode){
        TIMER0_COUNTER_MODE();
        if(TIMER0_FAILLING_EDGE_CFG == timer->timer0_edge){
            TIMER0_FAILLING_EDGE();
        }
        else if(TIMER0_RAISING_EDGE_CGF == timer->timer0_edge){
            TIMER0_COUNTER_MODE();
        }
        else{ /* Nothing */ }
    }
    else{ /* Nothing */ }  
}

static inline void timer0_register_size_func(const timer0_t *timer){
    if(timer->timer0_bits == TIMER0_8_BIT_CFG){
        TIMER0_8_BIT();
    }
    else if(timer->timer0_bits == TIMER0_16_BIT_CFG){
        TIMER0_16_BIT();
    }
    else{ /* Nothing */ }
}


#if TIMER0_INTRRUPT_FEATURE_ENABLE == Feture_enable
void TIMER0_ISR(){
    TIMER0_INTERRUPT_Flag_Clear();
    TMR0H = (preload_val >> 8) ;
    TMR0L = (uint8)(preload_val);
    if(Timer0_InterruptHandler){
        Timer0_InterruptHandler();
    }
}
#endif
