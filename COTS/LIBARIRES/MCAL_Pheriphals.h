/*********************************************************/
/* Author	: Mahmoud Ismail							                 */
/* Date 	: 11 Sep. 2022	      				              	 */		
/* Version  : V02										                     */	
/*********************************************************/

#ifndef     MCHARDWARE_PER_H
#define     MCHARDWARE_PER_H

#include "std_types.h"

/***********************************************************************************************************
															  	Global Constant Macros
***********************************************************************************************************/		


#define CORTEXM4_BASE_ADDRESS             0xE000E000


/***********************************************************************************************************
																Global DataTypes and Structs
***********************************************************************************************************/

typedef struct 
{

	uint32 ENABLE   : 1  ;
	uint32 INTEN    : 1  ;
	uint32 CLK_SRC  : 1  ;
	uint32          : 13 ;
  uint32 COUNT    : 1  ;
  uint32	        : 15 ;
	

}SYSTICK_STCTRL_BF ;	

typedef union 
{
	uint32 R;
	SYSTICK_STCTRL_BF BF;
	
}SYSTICK_STCTRL_Tag;







       /*********************************************************************************
			 *************************  SysTick Registers ************************************
			 ************************* *****************************************************/





#define SYSTICK_STCTRL       (*((volatile SYSTICK_STCTRL_Tag *)(CORTEXM4_BASE_ADDRESS + 0x010 )))
#define SYSTICK_STRELOAD     (*((volatile uint32 *)(CORTEXM4_BASE_ADDRESS + 0x014 )))
#define SYSTICK_STCURRENT    (*((volatile uint32 *)(CORTEXM4_BASE_ADDRESS + 0x018 )))	
 



#endif
