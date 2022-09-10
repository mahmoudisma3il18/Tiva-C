#ifndef   GPIO_H_
#define   GPIO_H_


#include "stdint.h"
#include "common_macros.h"

/*****************************************************************************************************
                           GPIO Port Base Adresse
******************************************************************************************************/													 

#define  PORT_A         0x40004000
#define  PORT_B         0x40005000
#define  PORT_C         0x40006000
#define  PORT_D         0x40007000
#define  PORT_E         0x40024000
#define  PORT_F         0x40025000


/****************************************************************************************************
                               GPIO Pins
****************************************************************************************************/

#define  PIN_ID0         0x00
#define  PIN_ID1         0x01
#define  PIN_ID2         0x02
#define  PIN_ID3         0x03
#define  PIN_ID4         0x04
#define  PIN_ID5         0x05
#define  PIN_ID6         0x06
#define  PIN_ID7         0x07





typedef enum {
	
	PIN_INPUT  = 0x00,
	PIN_OUTPUT = 0x01
	
}GPIO_PinDirectionType;



typedef enum {
	
	GPIO_PIN_STRENGTH_2MA,
	GPIO_PIN_STRENGTH_4MA,
	GPIO_PIN_STRENGTH_8MA,
	
	
}GPIO_PinStrength;

typedef enum {
	
	GPIO_PIN_TYPE_STD,
	GPIO_PIN_TYPE_PUR,
	GPIO_PIN_TYPE_PDR,
	GPIO_PIN_TYPE_OD,
	
}GPIO_PinType;




/****************************************************************************************************
             
                                 Function Prototypes

****************************************************************************************************/


/***************************************************************************************************

Function Description : Gets the direction and mode of a pin.

*****************************************************************************************************/

GPIO_PinDirectionType GPIO_GetPinDirection (uint32_t PortId,uint8_t PinId) ;


/***************************************************************************************************

Function Description : Sets the direction and mode of the specified pin(s).

*****************************************************************************************************/

void GPIO_SetPinDirection (uint32_t PortId,uint8_t PinId,GPIO_PinDirectionType PinDirection);

/***************************************************************************************************

			Function Description : Sets the pad configuration for the specified pin(s).


			Description:
			This function sets the drive strength and type for the specified pin(s) on the selected GPIO
			port. For pin(s) configured as input ports, the pad is configured as requested, but the only real
			effect on the input is the configuration of the pull-up or pull-down termination

*****************************************************************************************************/

void GPIO_SetPadConfig(uint32_t PortId,uint8_t PinId,GPIO_PinStrength PinStrength,GPIO_PinType PinType);

/***************************************************************************************************

			Function Description : Enable Pins as digital

*****************************************************************************************************/

void GPIO_TypeDigital(uint32_t PortId,uint8_t PinId);

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

void GPIO_UnlockPin(uint32_t PortId,uint8_t PinId);












#endif

