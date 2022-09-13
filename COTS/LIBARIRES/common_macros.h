/*********************************************************/
/* Author	: Mahmoud Ismail							                 */
/* Date 	: 11 Sep. 2022	      				              	 */		
/* Version  : V02										                     */	
/*********************************************************/
#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H

/*---------------------------------DEFINITIONS---------------------------------------------------------*/

#define  SET_BIT(REG,BIT)         ((REG) |=  (BIT))

#define  CLEAR_BIT(REG,BIT)       ((REG) &=  ~ (BIT))

#define TOGGLE_BIT(REG,BIT)       ((REG) ^=  (BIT))

#define BIT_IS_SET(REG,BIT)       ((REG) & (BIT))

#define BIT_IS_CLEAR(REG,BIT)     (!(REG & (BIT)))

#define ACCESS_REG(REG_BASE,OFFSET)  (*((volatile uint32 *)(REG_BASE + OFFSET)))
	
//#define GET_BIT(REG,BIT)          ((REG & (BIT))>>(BIT))


#endif /*common_macros.h*/
