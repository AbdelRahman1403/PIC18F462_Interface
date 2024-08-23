#include "hal_eeprom.h"

std_ReturnType EEPROM_DATA_WriteByte(uint16 bADD , uint8 data){
    std_ReturnType ret = E_OK;
    //Check if there are interrupt or No (Must there are no interrupt durring write data)
    uint8 Global_Interrupt = INTCONbits.GIE;
    //Update Address Registers 
    EEADRH = (uint8)((bADD >> 8) & 0x03); // 00000111 00000000 ==> 0000000 00000111 & 00000011 ==> 00000011
    EEADR = (uint8)(bADD & 0xFF);
    //Update Data Registers
    EEDATA = data;
    //Select Access Data Memory
    ACCESS_EEPROM_MEMORY;
    ACCESS_FLASH_EEPROM_MEMORY;
    //Allow Write Cycle Flash/EEPROM Memory
    ALLOW_WRITE_CYCLE_FLAH_EEPROM;
    //Disable All Interrupts
    INTCONbits.GIE = 0;  
    //Sequence Write 
    EECON2 = 0x55;
    EECON2 = 0xAA;
    //Initiates Erase/Write cycle 
    Initiates_Write_Control_Bit;
    //Process Write Data
    while(EECON1bits.WR);
    // Write Data Completed
    INHABITS_WRITE_CYCLE_FLAH_EEPROM;
    //Restore The Status of the interrupt
    INTCONbits.GIE = Global_Interrupt;
    return ret;
}

std_ReturnType EEPROM_DATA_ReadByte(uint16 bADD , uint8* data){
    std_ReturnType ret = E_NOK;
    if(data == NULL){
        ret = E_NOK;
    }
    else{
        //Update Address Register
        EEADRH = (uint8)((bADD >> 8) & 0x03); // 00000111 00000000 ==> 0000000 00000111 & 00000011 ==> 00000011
        EEADR = (uint8)(bADD & 0xFF);
        //Select Access Data Memory
        ACCESS_EEPROM_MEMORY;
        ACCESS_FLASH_EEPROM_MEMORY;
        //Allow Read From EEPROM
        Initiates_Read_Control_Bit;
        NOP();
        NOP();
        // Read Data
        *data = EEDATA;
    }
    return ret;
}

