#include "mcal_external_intrrupt.h"
/* Pointer to function to hold the callbacks for INTx */
static void (*INT0_IntrruptHandler)(void) = NULL;
static void (*INT1_IntrruptHandler)(void) = NULL;
static void (*INT2_IntrruptHandler)(void) = NULL;

static void (*RB4_IntrruptHandler_High)(void) = NULL;
static void (*RB4_IntrruptHandler_Low) (void) = NULL;
static void (*RB5_IntrruptHandler_High)(void) = NULL;
static void (*RB5_IntrruptHandler_Low) (void) = NULL;
static void (*RB6_IntrruptHandler_High)(void) = NULL;
static void (*RB6_IntrruptHandler_Low) (void) = NULL;
static void (*RB7_IntrruptHandler_High)(void) = NULL;
static void (*RB7_IntrruptHandler_Low) (void) = NULL;

static std_ReturnType Intrrupt_INTx_Enable(const intrrupt_INTx_t *obj);
static std_ReturnType Intrrupt_INTx_Disable(const intrrupt_INTx_t *obj);
static std_ReturnType Intrrupt_INTx_Priority_Init(const intrrupt_INTx_t *obj);
static std_ReturnType Intrrupt_INTx_Edge_Init(const intrrupt_INTx_t *obj);
static std_ReturnType Intrrupt_INTx_Pin_Init(const intrrupt_INTx_t *obj);
static std_ReturnType Intrrupt_INTx_Clear_Flag(const intrrupt_INTx_t *obj);

static std_ReturnType INT0_SetIntrruptHandler(void (*IntrruptHandler)(void));
static std_ReturnType INT1_SetIntrruptHandler(void (*IntrruptHandler)(void));
static std_ReturnType INT2_SetIntrruptHandler(void (*IntrruptHandler)(void));
static std_ReturnType Intrrupt_INTx__SetIntrruptHandler(const intrrupt_INTx_t *obj);

static std_ReturnType Intrrupt_RBx_Enable(const intrrupt_RPx_t *obj_rbx);
static std_ReturnType Intrrupt_RBx_Disable(const intrrupt_RPx_t *obj_rbx);
static std_ReturnType Intrrupt_RBx_Priority_init(const intrrupt_RPx_t *obj_rbx);
static std_ReturnType Intrrupt_RBx_Pin_init(const intrrupt_RPx_t *obj_rbx);

std_ReturnType Intrrupt_INTx_Init(const intrrupt_INTx_t *obj){
    std_ReturnType ret = E_NOK;
    if(obj == NULL){
        ret = E_NOK;
    }
    else{
        /* Disable the external interrupt */
        ret |= Intrrupt_INTx_Disable(obj);
        /* Clear Flag the external interrupt */
        ret |= Intrrupt_INTx_Clear_Flag(obj);
        /* Configure interrupt external edge */
        ret |= Intrrupt_INTx_Edge_Init(obj);
        #if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
        /* Configure interrupt external priority */
        ret |= Intrrupt_INTx_Priority_Init(obj);
        #endif
        /* Configure interrupt external edge */
        ret |= Intrrupt_INTx_Pin_Init(obj);
        /* Configure Defualt interrupt callback */
        ret |= Intrrupt_INTx__SetIntrruptHandler(obj);
        /* Enable the external interrupt */
        ret |= Intrrupt_INTx_Enable(obj);
    }
    return ret;
}

void INT0_ISR(void){
    /* The INT0 external interrupt (must be cleared) */
    EXT_INT0_IntrruptFlagClear();
    /* Code */
    
    /* CallBack function must call back */
    if(INT0_IntrruptHandler){
        INT0_IntrruptHandler();
    }
    
}
void INT1_ISR(void){
    /* The INT0 external interrupt (must be cleared) */
    EXT_INT1_IntrruptFlagClear();
    /* Code */
    
    /* CallBack function must call back */
    if(INT1_IntrruptHandler){
        INT1_IntrruptHandler();
    }
    else {/* Nothing */}
}
void INT2_ISR(void){
    /* The INT0 external interrupt (must be cleared) */
    EXT_INT2_IntrruptFlagClear();
    /* Code */
    
    /* CallBack function must call back */
    if(INT2_IntrruptHandler){
        INT2_IntrruptHandler();
    }
    else {/* Nothing */}
}

void RB4_ISR(uint8 level){
    // Clear Flag 
    EXT_RPx_IntrruptFlagClear();
    
    // Code
    
    //Priority Level
    if(level == 0){
        RB4_IntrruptHandler_Low();
    }
    else if (level == 1){
        RB4_IntrruptHandler_High();
    }
    else {/* Nothing */}
}
 
void RB5_ISR(uint8 level){
    // Clear Flag 
    EXT_RPx_IntrruptFlagClear();
    
    // Code
    
    //Priority Level
    if(level == 0){
        RB5_IntrruptHandler_Low();
    }
    else if (level == 1){
        RB5_IntrruptHandler_High();
    }
    else {/* Nothing */}
}
 
void RB6_ISR(uint8 level){
    // Clear Flag 
    EXT_RPx_IntrruptFlagClear();
    
    // Code
    
    //Priority Level
    if(level == 0){
        RB6_IntrruptHandler_Low();
    }
    else if (level == 1){
        RB6_IntrruptHandler_High();
    }
    else {/* Nothing */}
}
 
void RB7_ISR(uint8 level){
    // Clear Flag 
    EXT_RPx_IntrruptFlagClear();
    
    // Code
    
    //Priority Level
    if(level == 0){
        RB7_IntrruptHandler_Low();
    }
    else if (level == 1){
        RB7_IntrruptHandler_High();
    }
    else {/* Nothing */}
}
 

std_ReturnType Intrrupt_INTx_Deinit(const intrrupt_INTx_t *obj){
    std_ReturnType ret = E_NOK;
    if(obj == NULL){
        ret = E_NOK;
    }
    else{
        
    }
    return ret;
}

std_ReturnType Intrrupt_RBx_Init(const intrrupt_INTx_t *obj){
    std_ReturnType ret = E_NOK;
    if(obj == NULL){
        ret = E_NOK;
    }
    else{
        
    }
    return ret;
}

std_ReturnType Intrrupt_RBx_Deinit(const intrrupt_INTx_t *obj){
    std_ReturnType ret = E_NOK;
    if(obj == NULL){
        ret = E_NOK;
    }
    else{
        
    }
    return ret;
}
 
static std_ReturnType Intrrupt_INTx_Enable(const intrrupt_INTx_t *obj){
    std_ReturnType ret = E_NOK;
    if(obj == NULL){
        ret |= E_NOK;
    }
    else{
        switch(obj->src){
            
            case intrrupt_INTX_0:
#if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
                INTRRUTPT_GlobalIntrruptHighEnable();
#else
                INTRRUTPT_Global_IntrruptEnable();
                INTRRUTPT_Peripheral_Intrrupt_Enable();
#endif
                EXT_INT0_IntrruptEnable();
                ret |= E_OK;
                break;
            case intrrupt_INTX_1: 
#if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
            INTRRUTPT_Priority_Levels_Enable();
            if(intrrupt_high_prioity == obj->priority){
            INTRRUTPT_GlobalIntrruptHighEnable();
            }
            else if(intrrupt_low_prioity == obj->priority){
            INTRRUTPT_GlobalIntrruptLowerEnable();
            }
            else {/* Nothing */}
#else
                INTRRUTPT_Global_IntrruptEnable();
                INTRRUTPT_Peripheral_Intrrupt_Enable();
#endif
                EXT_INT1_IntrruptEnable();
                ret |= E_OK;
                break;
            case intrrupt_INTX_2: 
#if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
            INTRRUTPT_Priority_Levels_Enable();
            if(intrrupt_high_prioity == obj->priority){
            INTRRUTPT_GlobalIntrruptHighEnable();
            }
            else if(intrrupt_low_prioity == obj->priority){
            INTRRUTPT_GlobalIntrruptLowerEnable();
            }
            else {/* Nothing */}
#else
                INTRRUTPT_Global_IntrruptEnable();
                INTRRUTPT_Peripheral_Intrrupt_Enable();
#endif 
                EXT_INT2_IntrruptEnable();
                ret |= E_OK;
                break;
        }
        ret |= E_OK;
    }
    return ret;
}
 
static std_ReturnType Intrrupt_INTx_Disable(const intrrupt_INTx_t *obj){
    std_ReturnType ret = E_NOK;
    if(obj == NULL){
        ret = E_NOK;
    }
    else{
        switch(obj->src){
        case intrrupt_INTX_0: 
            EXT_INT0_IntrruptDisable();
            ret |= E_OK;
            break;
        case intrrupt_INTX_1: 
            EXT_INT1_IntrruptDisable();
            ret |= E_OK;
            break;
        case intrrupt_INTX_2: 
            EXT_INT2_IntrruptDisable();
            ret |= E_OK;
            break;
        }
        ret |= E_OK;
    }
    return ret;
}
 #if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
static std_ReturnType Intrrupt_INTx_Priority_Init(const intrrupt_INTx_t *obj){
    std_ReturnType ret = E_NOK;
    if(obj == NULL){
        ret = E_NOK;
    }
    else{
        switch(obj->src){
        case intrrupt_INTX_1: 
            if(intrrupt_low_prioity == obj->priority){
                EXT_INT1_LowerPrioritySet();
            }
            else if(intrrupt_high_prioity == obj->priority){
                EXT_INT1_HigherPrioritySet();
            }
            else {/* Nothing */}
            ret |= E_OK;
            break;
            
        case intrrupt_INTX_2: 
            if(intrrupt_low_prioity == obj->priority){
                EXT_INT2_HigherPrioritySet();
            }
            else if(intrrupt_high_prioity == obj->priority){
                EXT_INT2_LowerPrioritySet();
            }
            ret |= E_OK;
            break;
            
            default: 
                ret |= E_NOK;
                break;
        }
        ret |= E_OK;
    }
    return ret;
}
#endif
 
static std_ReturnType Intrrupt_INTx_Edge_Init(const intrrupt_INTx_t *obj){
    std_ReturnType ret = E_NOK;
    if(obj == NULL){
        ret = E_NOK;
    }
    else{
        switch(obj->src){
        case intrrupt_INTX_0:
            if(intrrupt_RISING_EDGE == obj->edge){
                EXT_INT0_RisingEdgeSet();
            }
            else if(intrrupt_FALLING_EDGE == obj->edge){
                EXT_INT0_FillingSet();
            }
            else {/* Nothing */}
            ret |= E_OK;
            break;
        case intrrupt_INTX_1: 
            if(intrrupt_RISING_EDGE == obj->edge){
                EXT_INT1_RisingEdgeSet();
            }
            else if(intrrupt_FALLING_EDGE == obj->edge){
                EXT_INT1_FillingSet();
            }
            else {/* Nothing */}
            ret |= E_OK;
            break;
            
        case intrrupt_INTX_2: 
            if(intrrupt_RISING_EDGE == obj->edge){
                EXT_INT2_RisingEdgeSet();
            }
            else if(intrrupt_FALLING_EDGE == obj->edge){
                EXT_INT2_FillingEdgeSet();
            }
            else {/* Nothing */}
            ret |= E_OK;
            break;
            
            default: 
                ret |= E_NOK;
                break;
        }
    }
    return ret;
}
 
static std_ReturnType Intrrupt_INTx_Pin_Init(const intrrupt_INTx_t *obj){
    std_ReturnType ret = E_NOK;
    if(obj == NULL){
        ret = E_NOK;
    }
    else{
        ret |= gpio_pin_intiailize(&(obj->mcu_pin));
    }
    return ret;
}
 
static std_ReturnType Intrrupt_INTx_Clear_Flag(const intrrupt_INTx_t *obj){
    std_ReturnType ret = E_NOK;
    if(obj == NULL){
        ret = E_NOK;
    }
    else{
    switch(obj->src){
        case intrrupt_INTX_0: 
            EXT_INT0_IntrruptFlagClear();
            ret |= E_OK;
            break;
        case intrrupt_INTX_1: 
            EXT_INT1_IntrruptFlagClear();
            ret |= E_OK;
            break;
        case intrrupt_INTX_2: 
            EXT_INT2_IntrruptFlagClear();
            ret |= E_OK;
            break;
        }
        ret |= E_OK;
    }
    return ret;
}
 
static std_ReturnType INT0_SetIntrruptHandler(void (*IntrruptHandler)(void)){
    std_ReturnType ret = E_NOK;
    if(IntrruptHandler == NULL){
        ret = E_NOK;
    }
    else{
        INT0_IntrruptHandler = IntrruptHandler;
    }
    return ret;
}
 
static std_ReturnType INT1_SetIntrruptHandler(void (*IntrruptHandler)(void)){
    std_ReturnType ret = E_NOK;
    if(IntrruptHandler == NULL){
        ret = E_NOK;
    }
    else{
        INT1_IntrruptHandler = IntrruptHandler;
    }
    return ret;
}
 
static std_ReturnType INT2_SetIntrruptHandler(void (*IntrruptHandler)(void)){
    std_ReturnType ret = E_NOK;
    if(IntrruptHandler == NULL){
        ret = E_NOK;
    }
    else{
        INT2_IntrruptHandler = IntrruptHandler;
    }
    return ret;
}
 
static std_ReturnType Intrrupt_INTx__SetIntrruptHandler(const intrrupt_INTx_t *obj){
    std_ReturnType ret = E_NOK;
    if(obj == NULL){
        ret = E_NOK;
    }
    else{
    switch(obj->src){
        case intrrupt_INTX_0: 
            ret |= INT0_SetIntrruptHandler(obj->EXT_IntrruptHandeler);
            break;
        case intrrupt_INTX_1: 
            ret |= INT1_SetIntrruptHandler(obj->EXT_IntrruptHandeler);
            break;
        case intrrupt_INTX_2: 
            ret |= INT2_SetIntrruptHandler(obj->EXT_IntrruptHandeler);
            break;
        }
        ret |= E_OK;
    }
    return ret;
}
 

static std_ReturnType Intrrupt_RBx_Enable(const intrrupt_RPx_t *obj_rbx){
    std_ReturnType ret = E_NOK;
    if(obj_rbx == NULL){
        ret = E_NOK;
    }
    else{
        EXT_RPx_IntrruptDisable();
        EXT_RPx_IntrruptFlagClear();
#if INTRRUPT_PRIORITY_LEVELS_ENABLE == Feture_enable
        INTRRUTPT_Priority_Levels_Enable();
      if(intrrupt_high_prioity == obj_rbx->priority){
        INTRRUTPT_GlobalIntrruptHighEnable();
        
        EXT_RPx_HigherPrioritySet();
         }
       else if(intrrupt_low_prioity == obj_rbx->priority){
         INTRRUTPT_GlobalIntrruptLowerEnable();
         EXT_RPx_LowerPrioritySet();
         }
            else {/* Nothing */}
#else
                INTRRUTPT_Global_IntrruptEnable();
                INTRRUTPT_Peripheral_Intrrupt_Enable();
#endif
        ret |= gpio_pin_direction_intiailize(&(obj_rbx->mcu_pin));
        switch(obj_rbx->mcu_pin.pin){
           case GPIO_pin4:
               RB4_IntrruptHandler_High = obj_rbx->EXT_IntrruptHandeler_High;
               RB4_IntrruptHandler_Low = obj_rbx->EXT_IntrruptHandeler_Low;
                break;
           case GPIO_pin5:
               RB5_IntrruptHandler_High = obj_rbx->EXT_IntrruptHandeler_High;
               RB5_IntrruptHandler_Low = obj_rbx->EXT_IntrruptHandeler_Low;
                break;
           case GPIO_pin6:
               RB6_IntrruptHandler_High = obj_rbx->EXT_IntrruptHandeler_High;
               RB6_IntrruptHandler_Low = obj_rbx->EXT_IntrruptHandeler_Low;
                break;
           case GPIO_pin7:
               RB7_IntrruptHandler_High = obj_rbx->EXT_IntrruptHandeler_High;
               RB7_IntrruptHandler_Low = obj_rbx->EXT_IntrruptHandeler_Low;
                break;  
            default:
                break;
        }
        EXT_RPx_IntrruptEnable();
    }
    return ret;
}
 
static std_ReturnType Intrrupt_RBx_Disable(const intrrupt_RPx_t *obj_rbx){
    
}
static std_ReturnType Intrrupt_RBx_Priority_init(const intrrupt_RPx_t *obj_rbx){
    
}
static std_ReturnType Intrrupt_RBx_Pin_init(const intrrupt_RPx_t *obj_rbx){
    
}
