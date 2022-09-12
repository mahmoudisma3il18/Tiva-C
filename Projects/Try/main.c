#include "TM4C123.h"
#include "gpio.h"

int main(void) {
	
	GPIO_Init(PORT_F);
	GPIO_SetPinDirection(PORTF_APB_BASE,PIN_ID1|PIN_ID2|PIN_ID3,PIN_OUTPUT);
	GPIO_WritePin(PORTF_APB_BASE,PIN_ID1|PIN_ID2|PIN_ID3,LOGIC_HIGH);
	
	
}