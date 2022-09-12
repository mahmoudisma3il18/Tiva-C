/*********************************************************/
/* Author	: Mahmoud Ismail							                 */
/* Date 	: 17 August 2022	      				            	 */		
/* Version  : V01										                     */	
/*********************************************************/

#include "Cpu_Driver.h"
#include "TM4C123GH6PM.h"


/***************************************************************************************************

		Description:
		This function is used to Enables IRQ interrupts by clearing special-purpose register PRIMASK.
    Can only be executed in Privileged modes.
		
*****************************************************************************************************/

void CpuDriver_EnableGlobalInterrupt(void) {
	
	__ASM volatile ("CPSIE i" ::: "memory");
	
}

/***************************************************************************************************

		Description:
		This function is used to Disables IRQ interrupts by setting special-purpose register PRIMASK.
    Can only be executed in Privileged modes.
		
*****************************************************************************************************/

void CpuDriver_DisableGlobalInterrupt(void){
	
	__ASM volatile ("CPSID i" : : : "memory");
	
}


/***************************************************************************************************

		Description:
		This function is used to Enables FIQ interrupts by clearing special-purpose register FAULTMASK.
    Can only be executed in Privileged modes.
		
*****************************************************************************************************/

void CpuDriver_StartCriticalSection(void){
	
	__ASM volatile ("CPSIE f" ::: "memory");
	
}


/***************************************************************************************************

		Description:
		This function is used to Disables FIQ interrupts by setting special-purpose register FAULTMASK.
    Can only be executed in Privileged modes.
		
*****************************************************************************************************/

void CpuDriver_StopCriticalSection(void){
	
	__ASM volatile ("CPSID f" ::: "memory");
	
}

