/*********************************************************/
/* Author	: Mahmoud Ismail							                 */
/* Date 	: 11 Sep. 2022	        				            	 */		
/* Version  : V02										                     */	
/*********************************************************/

#ifndef   GPIO_H_
#define   GPIO_H_


/*---------------------------------------- INCLUDES----------------------------------------------------*/


#include "std_types.h"
#include "common_macros.h"
#include "HAL_Pheriphals.h"


/*--------------------------------- Definitions and configurtions -----------------------------------------*/


#define  PIN_ID0         0x01
#define  PIN_ID1         0x02
#define  PIN_ID2         0x04
#define  PIN_ID3         0x08
#define  PIN_ID4         0x10
#define  PIN_ID5         0x20
#define  PIN_ID6         0x40
#define  PIN_ID7         0x80


#define PORTA_ID           0x01
#define PORTB_ID           0x02
#define PORTC_ID           0x04
#define PORTD_ID           0x08
#define PORTE_ID           0x10
#define PORTF_ID           0x20


typedef uint8 GPIO_PortLevel;


/*--------------------------------------ENUMS----------------------------------------------------------*/


typedef enum {
	
	PIN_INPUT  = 0x0,
	PIN_OUTPUT = 0x1
	
}GPIO_PinDirection;


typedef enum {
	
	GPIO_PIN_STRENGTH_2MA,
	GPIO_PIN_STRENGTH_4MA,
	GPIO_PIN_STRENGTH_8MA,
	
}GPIO_PinStrength;


typedef enum {
	
	GPIO_PIN_TYPE_STD, // Standrd
	GPIO_PIN_TYPE_PUR, // Internal Pull-up Resistor 
	GPIO_PIN_TYPE_PDR, // Internal Pull-Down Resistor
	GPIO_PIN_TYPE_OD, // Open Drain
	
}GPIO_PinType;


typedef enum {
	
	LOGIC_LOW = 0,
	LOGIC_HIGH = 1
	
}GPIO_Level;



/*-----------------------------------FUNCTIONN DECLRATIONS ---------------------------------------------*/


/*---------------------------------------------------------------------------------------------------
[Function Name] : void GPIO_Init 
[Description] : Inialtize Clock for GPIO Port.
[Paramters]   : Specifed Port (PORT_F,PORT_A)
----------------------------------------------------------------------------------------------------*/
void GPIO_Init(uint8 PORT_ID);


/*---------------------------------------------------------------------------------------------------
[Function Name] :GPIO_PinDirectionType GPIO_GetPinDirection
[Description] : Gets the direction and mode of a pin.
[Paramters]   : Port and Pin number
----------------------------------------------------------------------------------------------------*/
GPIO_PinDirection GPIO_GetPinDirection (uint32 PortBase,uint8 PinId) ;


/*---------------------------------------------------------------------------------------------------
[Function Name] :void GPIO_SetPinDirection
Function Description : Sets the direction and mode of the specified pin(s).
[Paramters]   : Port ,Pin and Direction
----------------------------------------------------------------------------------------------------*/
void GPIO_SetPinDirection (uint32 PortBase,uint8 PinId,GPIO_PinDirection PinDirection);


/*------------------------------------------------------------------------------------------------------
[Function Name] :void GPIO_SetPadConfig
[Description]: This function sets the drive strength and type for the specified pin(s) on the selected GPIO
port. For pin(s) configured as input ports, the pad is configured as requested, but the only real
effect on the input is the configuration of the pull-up or pull-down termination
--------------------------------------------------------------------------------------------------------*/
void GPIO_SetPadConfig(uint32 PortBase,uint8 PinId,GPIO_PinStrength PinStrength,GPIO_PinType PinType);


/*---------------------------------------------------------------------------------------------------
[Function Name] : void GPIO_TypeDigital
[Description] : Enable Pins as digital
------------------------------------------------------------------------------------------------------*/
static void GPIO_TypeDigital(uint32 PortBase,uint8 PinId);


/*------------------------------------------------------------------------------------------------------
[Function Name] : void GPIO_UnlockPin
[Description] : This function is used to unlock pins which were locked for specific functionality such as JTAG
operation. To be able to use pins which have been locked, the following procedure is required
to unlock the pin and commit the change. This function will have no effect on pins which are
not protected by the GPIOCR register.	
[Parameters] : PortId is the base address of the GPIO port.
PinId is the bit-packed representation of the pin(s).
-------------------------------------------------------------------------------------------------------*/
void GPIO_UnlockPin(uint32 PortBase,uint8 PinId);


/*------------------------------------------------------------------------------------------------------
[Function Name] : GPIO_LevelType GPIO_ReadPin
[Description] : This function is used to read the value of required pin (HIGH or LOW).	
[Parameters] : PortId is the base address of the GPIO port.
PinId is the bit-packed representation of the pin(s).
-------------------------------------------------------------------------------------------------------*/
GPIO_Level GPIO_ReadPin(uint32 PortBase,uint8 PinId);                


/*------------------------------------------------------------------------------------------------------
[Function Name] :void GPIO_WritePin
[Description] : This function is used to write the value to required pin (HIGH or LOW).	
[Parameters] : PortId is the base address of the GPIO port.
PinId is the bit-packed representation of the pin(s).
-------------------------------------------------------------------------------------------------------*/
void GPIO_WritePin(uint32 PortBase,uint8 PinId,GPIO_Level Level);    


/*------------------------------------------------------------------------------------------------------
[Function Name] : GPIO_PortLevelType GPIO_ReadPort
[Description] : This function is used to read the value of the Port.	
[Parameters] : PortBase is the base address of the GPIO port.
-------------------------------------------------------------------------------------------------------*/
GPIO_PortLevel GPIO_ReadPort(uint32 PortBase); 


/*------------------------------------------------------------------------------------------------------
[Function Name] : void GPIO_WritePort
[Description] : Its paramters are PortBase and required value to be written	
-------------------------------------------------------------------------------------------------------*/
void GPIO_WritePort(uint32 PortBase,GPIO_PortLevel Level);        


/*------------------------------------------------------------------------------------------------------
[Function Name] : void GPIO_TogglePin
[Description] : Its paramters are portid and channel Id and it toogles the pin and return its value;	
-------------------------------------------------------------------------------------------------------*/
void GPIO_TogglePin(uint32 PortBase,uint8 PinId);               




#endif /*gpio.h*/

