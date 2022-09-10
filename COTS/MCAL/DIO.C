#include "DIO.h"



/************************************************************************************************
 Function Description : This Function paramters are PORTID and ChannelId
 and returns the value of the channel

************************************************************************************************/	 

DIO_LevelType Dio_ReadChannel(uint32_t PortId,uint8_t PinId) {
	
	uint8_t ChannelState = 0;
	
	
	if(BIT_IS_SET((*((volatile uint32_t *)( PortId + (1<<(PinId+2))))),PinId)) // Base Adreesses of port + bits masking[9-2] bits
			ChannelState = LOGIC_HIGH;
		else
			ChannelState = LOGIC_LOW;
		
		return ChannelState;
	
	
}


/*************************************************************************************************
Function Description : Its paramters are PortId and ChannelId and it Writes the value to the pin

**************************************************************************************************/

void Dio_WriteChannel(uint32_t PortId,uint8_t PinId,DIO_LevelType Level) {
	
	if(Level == LOGIC_HIGH)
			SET_BIT((*((volatile uint32_t *)( PortId + (1<<(PinId+2))))),PinId);
		else
			CLEAR_BIT((*((volatile uint32_t *)( PortId + (1<<(PinId+2))))),PinId);
	

	
}

/**********************************************************************************************
Function Description : Its paramters are PortId and it returns value of port from (0 to 256)

***********************************************************************************************/


Dio_PortLevelType Dio_ReadPort(uint32_t PortId) {
	
	uint8_t value = (*((volatile uint32_t *)(PortId + 0x3FC))) & 0xFF ;
	
	return value;
	

}

/**********************************************************************************************

Function Description : Its paramters are PortId and required value to be written 

***********************************************************************************************/


void Dio_WritePort (uint32_t PortId,Dio_PortLevelType Level) {
	
	
	uint8_t value = Level & 0xFF;
	
	(*((volatile uint32_t *)( PortId + 0x3FC))) = value;
	

}

/************************************************************************************************
Function Description : Its paramters are portid and channel Id and it toogles the pin and return its value;

************************************************************************************************/

void Dio_ToggleChannel(uint32_t PortId,uint8_t PinId) {
	
	TOGGLE_BIT((*((volatile uint32_t *)( PortId + (1<<PinId)))),PinId);
	
	
}






