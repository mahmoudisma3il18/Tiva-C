/*********************************************************/
/* Author	: Mahmoud Ismail							                 */
/* Date 	: 11 Sep. 2022	      				              	 */		
/* Version  : V02										                     */	
/*********************************************************/

#ifndef _STD_TYPES_H__
#define _STD_TYPES_H__

typedef enum {

    FALSE = 0,
    TRUE = 1

}bool;


typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;



#endif
