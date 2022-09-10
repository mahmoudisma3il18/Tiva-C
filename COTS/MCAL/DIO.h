#ifndef DIO_H_
#define DIO_H_

#include "stdint.h"
#include "common_macros.h"
#include "gpio.h"

typedef enum {
	
	LOGIC_LOW = 0,
	LOGIC_HIGH = 1
	
}DIO_LevelType;




typedef uint8_t Dio_PortLevelType;


/************************************************************************************************
                                         Function Prototypes
*************************************************************************************************/

DIO_LevelType Dio_ReadChannel(uint32_t PortId,uint8_t PinId);                // Returns the value of pin

void Dio_WriteChannel(uint32_t,uint8_t PinId,DIO_LevelType Level);    // Write the value to the pin

Dio_PortLevelType Dio_ReadPort(uint32_t PortId);                     //Reads the value of port

void Dio_WritePort(uint32_t PortId,Dio_PortLevelType Level);        // Write required value on port

void Dio_ToggleChannel(uint32_t PortId,uint8_t PinId);               //Toggle the pin and return its value




#endif
