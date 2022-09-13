/*********************************************************/
/* Author	: Mahmoud Ismail							                 */
/* Date 	: 11 Sep. 2022	        				            	 */		
/* Version  : V02										                     */	
/*********************************************************/
#ifndef   SYSTICK_H_
#define   SYSTICK_H_

/*-----------------------------INCLUDES-----------------------------------------*/

#include "std_types.h"
#include "common_macros.h"
#include "MCAL_Pheriphals.h"

/*-----------------------------Enums--------------------------------------------*/

typedef enum {
	
	PIOSC = 0x0,         // System Clock Divided by 4
	SYSTEM_CLOCK = 0x01  // Clock Of Core
	
}SysTick_Source;


/*---------------------------- Function Delecrations -----------------------------*/


/*----------------------------------------------------------------------------------
[Function Name] : void SysTick_Disable
[Descriptio] :This function stops the SysTick counter. If an interrupt handler has been registered
, it is not called until SysTick is restarted.
-----------------------------------------------------------------------------------*/
void SysTick_Disable(void) ;


/*-------------------------------------------------------------------------------
[Function Name] : void SysTick_Enable
[Description] :This function starts the SysTick counter. If an interrupt handler has been registered, it is called
when the SysTick counter rolls over
----------------------------------------------------------------------------------*/
void SysTick_Enable (void) ;


/*--------------------------------------------------------------------------------------
[Function Name] : void SysTick_IntDisable
[Description] :This function disables the SysTick interrupt, preventing it from being reflected to the processor.
------------------------------------------------------------------------------------------*/
void SysTick_IntDisable (void) ;


/*----------------------------------------------------------------------------------
[Function Name] : void SysTick_IntEnable 
[Description] : This function enables the SysTick interrupt, allowing it to be reflected to the processor.
---------------------------------------------------------------------------------------*/
void SysTick_IntEnable (void) ;


/*----------------------------------------------------------------------------------
[Function Name] : uint32 SysTick_PeriodGet
[Description] :This function returns the rate at which the SysTick counter wraps, which equates to the number
of processor clocks between interrupts.
-----------------------------------------------------------------------------------*/
uint32 SysTick_PeriodGet(void) ;



/*--------------------------------------------------------------------------------
[Function Name]:void SysTick_PeriodSet
[Description] :This function sets the rate at which the SysTick counter wraps, which equates to the number
of processor clocks between interrupts.
----------------------------------------------------------------------------------*/
void SysTick_PeriodSet(uint32 Ticks);


/*------------------------------------------------------------------------------------
[Function Name] : uint32 SysTick_ValueGet
[Description] : This function returns the current value of the SysTick counter, which is a value between the
period - 1 and zero, inclusive.
-------------------------------------------------------------------------------------*/
uint32 SysTick_ValueGet(void) ;


/*------------------------------------------------------------------------------
[Function Name] : void SysTick_SetClockSource
[Parameters]:SysTick_source is the source of clock to SysTick
[Description ]:This function sets the Source of clock of SysTick.
-----------------------------------------------------------------------------------*/
void SysTick_SetClockSource(SysTick_Source SysTick_source);


/*-------------------------------------------------------------------------------
[Function Name] void SysTick_Wait: 
[Description] :This function makes a software delay .
--------------------------------------------------------------------------------*/
void SysTick_Wait(uint32 Ticks);




#endif



