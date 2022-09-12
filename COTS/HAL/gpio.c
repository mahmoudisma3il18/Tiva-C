/*********************************************************/
/* Author	: Mahmoud Ismail							                 */
/* Date 	: 12 Sep. 2022	      			  	            	 */		
/* Version  : V02										                     */	
/*********************************************************/

/*----------------------------------------- INCLUDES ----------------------------------------------------*/


#include "gpio.h"


/*--------------------------------------- FUNCTIONS ------------------------------------------------------*/


/*---------------------------------------------------------------------------------------------------
[Description] : Inialtize Clock for GPIO Port.
[Paramters]   : Specifed Port
----------------------------------------------------------------------------------------------------*/
void GPIO_Init(uint8 PORT_ID) {
	
	ACCESS_REG(SYSTEM_CONTROL_BLOCK_BASE,RCGCGPIO_OFFSET) = PORT_ID;
	
}


/*---------------------------------------------------------------------------------------------------
[Description] : Gets the direction and mode of a pin.
[Paramters]   : Port and Pin number
----------------------------------------------------------------------------------------------------*/
GPIO_PinDirection GPIO_GetPinDirection (uint32 PortBase,uint8 PinId) {
	
	    uint8 PinState = 0;
	
	
			if(BIT_IS_SET(ACCESS_REG(PortBase,GPIODIR_OFFSET),PinId))
				PinState =  PIN_OUTPUT;
			else
				PinState = PIN_INPUT;
			
			return PinState;
			
	
}



/*---------------------------------------------------------------------------------------------------
Function Description : Sets the direction and mode of the specified pin(s).
[Paramters]   : Port ,Pin and Direction
----------------------------------------------------------------------------------------------------*/
void GPIO_SetPinDirection (uint32 PortBase,uint8 PinId,GPIO_PinDirection PinDirection) {
	
	if(PinDirection == PIN_INPUT)
				CLEAR_BIT(ACCESS_REG(PortBase,GPIODIR_OFFSET),PinId);
			else
				SET_BIT(ACCESS_REG(PortBase,GPIODIR_OFFSET),PinId);
	
			GPIO_TypeDigital(PortBase,PinId);

}


/*------------------------------------------------------------------------------------------------------
[Description]: This function sets the drive strength and type for the specified pin(s) on the selected GPIO
port. For pin(s) configured as input ports, the pad is configured as requested, but the only real
effect on the input is the configuration of the pull-up or pull-down termination
--------------------------------------------------------------------------------------------------------*/
void GPIO_SetPadConfig(uint32 PortBase,uint8 PinId,GPIO_PinStrength PinStrength,GPIO_PinType PinType){
	
	    if(PinStrength == GPIO_PIN_STRENGTH_2MA)
				SET_BIT(ACCESS_REG(PortBase,GPIODR2R_OFFSET),PinId);
			else if(PinStrength == GPIO_PIN_STRENGTH_4MA)
				SET_BIT(ACCESS_REG(PortBase,GPIODR4R_OFFSET),PinId);
			else
				SET_BIT(ACCESS_REG(PortBase,GPIODR8R_OFFSET),PinId);
			
			
			if(PinType == GPIO_PIN_TYPE_PDR){
				GPIO_UnlockPin(PortBase,PinId);
			  SET_BIT(ACCESS_REG(PortBase,GPIOPDR_OFFSET),PinId);
			}	
			else if (PinType == GPIO_PIN_TYPE_PUR){
				GPIO_UnlockPin(PortBase,PinId);
				SET_BIT(ACCESS_REG(PortBase,GPIOPUR_OFFSET),PinId);
			}	
			else if(PinType == GPIO_PIN_TYPE_OD){
				GPIO_TypeDigital(PortBase,PinId);
				SET_BIT(ACCESS_REG(PortBase,GPIOODR_OFFSET),PinId);
			}
			else;
		

}



/*---------------------------------------------------------------------------------------------------
[Description] : Enable Pins as digital
------------------------------------------------------------------------------------------------------*/
static void GPIO_TypeDigital(uint32 PortBase,uint8 PinId){
	
	
	SET_BIT(ACCESS_REG(PortBase,GPIODEN_OFFSET),PinId);
	

	
}


/*------------------------------------------------------------------------------------------------------
[Description] : This function is used to unlock pins which were locked for specific functionality such as JTAG
operation. To be able to use pins which have been locked, the following procedure is required
to unlock the pin and commit the change. This function will have no effect on pins which are
not protected by the GPIOCR register.	
[Parameters] : PortId is the base address of the GPIO port.
PinId is the bit-packed representation of the pin(s).
-------------------------------------------------------------------------------------------------------*/
void GPIO_UnlockPin(uint32 PortBase,uint8 PinId) {
	
	ACCESS_REG(PortBase,GPIOLOCK_OFFSET) = 0x4C4F434B;
	SET_BIT(ACCESS_REG(PortBase,GPIOCR_OFFSET),PinId);
	

}



 /*------------------------------------------------------------------------------------------------------
[Description] : This function is used to read the value of required pin (HIGH or LOW).	
[Parameters] : PortId is the base address of the GPIO port.
PinId is the bit-packed representation of the pin(s).
-------------------------------------------------------------------------------------------------------*/
GPIO_Level GPIO_ReadPin(uint32 PortBase,uint8 PinId) {

	uint8 ChannelState = 0;
	
	
	if(BIT_IS_SET(ACCESS_REG(PortBase,((PinId)<<2)),PinId)) // Base Adreesses of port + bits masking[9-2] bits
			ChannelState = LOGIC_HIGH;
		else
			ChannelState = LOGIC_LOW;
		
		return ChannelState;
	
	
}



/*------------------------------------------------------------------------------------------------------
[Description] : This function is used to write the value to required pin (HIGH or LOW).	
[Parameters] : PortId is the base address of the GPIO port.
PinId is the bit-packed representation of the pin(s).
-------------------------------------------------------------------------------------------------------*/
void GPIO_WritePin(uint32 PortBase,uint8 PinId,GPIO_Level Level) {
	
	if(Level == LOGIC_HIGH)
			SET_BIT(ACCESS_REG(PortBase,((PinId)<<2)),PinId);
		else
			CLEAR_BIT(ACCESS_REG(PortBase,((PinId)<<2)),PinId);
	

	
}



GPIO_PortLevel GPIO_ReadPort(uint32 PortBase) {
	
	uint8 value = (ACCESS_REG(PortBase,0x3FC)) & 0xFF ;
	
	return value;
	

}


/*------------------------------------------------------------------------------------------------------
[Description] : Its paramters are PortBase and required value to be written	
-------------------------------------------------------------------------------------------------------*/
void GPIO_WritePort (uint32 PortBase,GPIO_PortLevel Level) {
	
	
	uint8 value = Level & 0xFF;
	
	ACCESS_REG(PortBase,0x3FC) = value;
	

}


/*------------------------------------------------------------------------------------------------------
[Description] : Its paramters are portid and channel Id and it toogles the pin and return its value;	
-------------------------------------------------------------------------------------------------------*/
void GPIO_TogglePin(uint32 PortBase,uint8 PinId) {
	
	TOGGLE_BIT(ACCESS_REG(PortBase,((PinId)<<2)),PinId);
	
	
}










