/*********************************************************/
/* Author	: Mahmoud Ismail							                 */
/* Date 	: 17 August 2022	      				            	 */		
/* Version  : V01										                     */	
/*********************************************************/

#ifndef _CPU_DRIVER_H_
#define _CPU_DRIVER_H_


/***************************************************************************************************

		Description:
		This function is used to Enables IRQ interrupts by clearing special-purpose register PRIMASK.
    Can only be executed in Privileged modes.
		
*****************************************************************************************************/

void CpuDriver_EnableGlobalInterrupt(void);


/***************************************************************************************************

		Description:
		This function is used to Disables IRQ interrupts by setting special-purpose register PRIMASK.
    Can only be executed in Privileged modes.
		
*****************************************************************************************************/

void CpuDriver_DisableGlobalInterrupt(void);


/***************************************************************************************************

		Description:
		This function is used to Enables FIQ interrupts by clearing special-purpose register FAULTMASK.
    Can only be executed in Privileged modes.
		
*****************************************************************************************************/

void CpuDriver_StartCriticalSection(void);


/***************************************************************************************************

		Description:
		This function is used to Disables FIQ interrupts by setting special-purpose register FAULTMASK.
    Can only be executed in Privileged modes.
		
*****************************************************************************************************/

void CpuDriver_StopCriticalSection(void);



#endif
