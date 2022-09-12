/*********************************************************/
/* Author	: Mahmoud Ismail							                 */
/* Date 	: 11 Sep. 2022	         				            	 */		
/* Version  : V02										                     */	
/*********************************************************/

#include "systick.h"

/*********************************************************************************

Description :
This function stops the SysTick counter. If an interrupt handler has been registered
, it is not called until SysTick is restarted.

**************************************************************************************/

void SysTick_Disable(void) {
	
	SYSTICK_STCTRL.BF.ENABLE = 0x00;
	
}

/*********************************************************************************

Description :
This function starts the SysTick counter. If an interrupt handler has been registered, it is called
when the SysTick counter rolls over

**************************************************************************************/

void SysTick_Enable (void)  {
	
	SYSTICK_STCTRL.BF.ENABLE  = 0x01;
	SYSTICK_STCTRL.BF.CLK_SRC = 0x01; 
	
}


/*********************************************************************************

Description :
This function disables the SysTick interrupt, preventing it from being reflected to the processor.

**************************************************************************************/

void SysTick_IntDisable (void) {
	
	SYSTICK_STCTRL.BF.INTEN = 0x00;
	
}


/*********************************************************************************

Description :
This function enables the SysTick interrupt, allowing it to be reflected to the processor.

**************************************************************************************/

void SysTick_IntEnable (void) {
	
	SYSTICK_STCTRL.BF.INTEN = 0x01;
	
}


/*********************************************************************************

Parameters:
ui32Period is the number of clock ticks in each period of the SysTick counter and must be
between 1 and 16, 777, 216, inclusive.

Description :
This function sets the rate at which the SysTick counter wraps, which equates to the number
of processor clocks between interrupts.

**************************************************************************************/

void SysTick_PeriodSet(uint32 Ticks) {
	
	//To check if ticks are 24 - bits 
	if((Ticks > 0)  && (Ticks <= 16777216))  
		SYSTICK_STRELOAD = Ticks - 1;

	else {
		// Do nothing 	
	}
	
}



/*********************************************************************************

Description :
This function returns the rate at which the SysTick counter wraps, which equates to the number
of processor clocks between interrupts.

**************************************************************************************/

uint32 SysTick_PeriodGet(void)  {
	
	uint32 value = (SYSTICK_STRELOAD & 0xFFFFFF) + 1;
	return value;
	
}


/*********************************************************************************

Description :
scription:
This function returns the current value of the SysTick counter, which is a value between the
period - 1 and zero, inclusive.

**************************************************************************************/

uint32 SysTick_ValueGet(void) {
	
	uint32 value = (SYSTICK_STCURRENT & 0xFFFFFF);
	return value;
	
}


/*********************************************************************************

Parameters:
SysTick_source is the source of clock to SysTick

Description :
This function sets the Source of clock of SysTick.

**************************************************************************************/

void SysTick_SetClockSource(SysTick_Source SysTick_source) {
	
	SYSTICK_STCTRL.BF.CLK_SRC = SysTick_source ;
	
}


/*********************************************************************************

Description :
This function makes a software delay .

**************************************************************************************/

void SysTick_Wait(uint32 Ticks) {
	
	SysTick_PeriodSet(Ticks);
	while( SYSTICK_STCTRL.BF.COUNT == 0x00 ); 
	
}





