#include "gpio.h"


/***************************************************************************************************

Function Description : Gets the direction and mode of a pin.

*****************************************************************************************************/

GPIO_PinDirectionType GPIO_GetPinDirection (uint32_t PortId,uint8_t PinId) {
	
	    uint8_t PinState = 0;
	
	
			if(BIT_IS_SET((*((volatile uint32_t *)(PortId + 0x400))),PinId))
				PinState =  PIN_OUTPUT;
			else
				PinState = PIN_INPUT;
			
			return PinState;
			
	
}



/***************************************************************************************************

Function Description : Sets the direction and mode of the specified pin(s).

*****************************************************************************************************/

void GPIO_SetPinDirection (uint32_t PortId,uint8_t PinId,GPIO_PinDirectionType PinDirection) {
	
	if(PinDirection == PIN_INPUT)
				CLEAR_BIT((*((volatile uint32_t *)(PortId + 0x400))),PinId);
			else
				SET_BIT((*((volatile uint32_t *)(PortId + 0x400))),PinId);
	

}

/***************************************************************************************************

			Function Description : Sets the pad configuration for the specified pin(s).


			Description:
			This function sets the drive strength and type for the specified pin(s) on the selected GPIO
			port. For pin(s) configured as input ports, the pad is configured as requested, but the only real
			effect on the input is the configuration of the pull-up or pull-down termination

*****************************************************************************************************/

void GPIO_SetPadConfig(uint32_t PortId,uint8_t PinId,GPIO_PinStrength PinStrength,GPIO_PinType PinType){
	
	if(PinStrength == GPIO_PIN_STRENGTH_2MA)
				SET_BIT((*((volatile uint32_t *)(PortId + 0x500))),PinId);
			else if(PinStrength == GPIO_PIN_STRENGTH_4MA)
				SET_BIT((*((volatile uint32_t *)(PortId + 0x504))),PinId);
			else
				SET_BIT((*((volatile uint32_t *)(PortId + 0x508))),PinId);
			
			if(PinType == GPIO_PIN_TYPE_PDR){
				GPIO_UnlockPin(PortId,PinId);
			  SET_BIT((*((volatile uint32_t *)(PortId + 0x514))),PinId);
			}	
			else if (PinType == GPIO_PIN_TYPE_PUR){
				GPIO_UnlockPin(PortId,PinId);
				SET_BIT((*((volatile uint32_t *)(PortId + 0x510))),PinId);
			}	
			else if(PinType == GPIO_PIN_TYPE_OD){
				GPIO_TypeDigital(PortId,PinId);
				SET_BIT((*((volatile uint32_t *)(PortId + 0x50C))),PinId);
			}
			else;
	
	
	

}


/***************************************************************************************************

			Function Description : Enable Pins as digital

*****************************************************************************************************/

void GPIO_TypeDigital(uint32_t PortId,uint8_t PinId){
	
	
	SET_BIT((*((uint32_t *)(PortId + 0x51C))),PinId);
	

	
}

/***************************************************************************************************

					Parameters:
		PortId is the base address of the GPIO port.
		PinId is the bit-packed representation of the pin(s).
		
		Description:
		This function is used to unlock pins which were locked for specific functionality such as JTAG
		operation. To be able to use pins which have been locked, the following procedure is required
		to unlock the pin and commit the change. This function will have no effect on pins which are
		not protected by the GPIOCR register.

*****************************************************************************************************/

void GPIO_UnlockPin(uint32_t PortId,uint8_t PinId) {
	
	(*((volatile uint32_t *)(PortId + 0x520))) = 0x4C4F434B;
	SET_BIT((*((volatile uint32_t *)(PortId + 0x524))),PinId);
	

}



