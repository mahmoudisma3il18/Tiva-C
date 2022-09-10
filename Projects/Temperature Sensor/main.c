#include "TM4C123.h"

int main(void) {
	
	
	
	
	 volatile int temperature;
 
    /* enable clocks */
    SYSCTL->RCGCADC |=1;;       /* enable clock to ADC0 */
    SYSCTL->RCGCWTIMER |=1;;    /* enable clock to WTimer Block 0 */
    
    /* initialize ADC0 */
    ADC0->ACTSS  &= ~8;          /* disable SS3 during configuration */
    ADC0->EMUX &= ~0xF000;
    ADC0->EMUX |= 0x5000;       /* timer trigger conversion seq 0 */
    ADC0->SSMUX3 = 0;           /* get input from channel 0 */
    ADC0->SSCTL3 |= 0x0E;       /* take chip temperature, set flag at 1st sample */
    ADC0->ACTSS |= 8;           /* enable ADC0 sequencer 3 */
 
    /* initialize wtimer 0 to trigger ADC at 1 sample/sec */
    WTIMER0->CTL = 0;           /* disable WTimer before initialization */
    WTIMER0->CFG = 0x04;        /* 32-bit option */
    WTIMER0->TAMR = 0x02;       /* periodic mode and down-counter */
    WTIMER0->TAILR = 16000000;  /* WTimer A interval load value reg (1 s) */
    WTIMER0->CTL |= 0x20;       /* timer triggers ADC */
    WTIMER0->CTL |= 0x01;       /* enable WTimer A after initialization */
 
    while(1) {
        while((ADC0->RIS & 8) == 0)
            ;                    /* wait for conversion complete */
        temperature = 147 - (247 * ADC0->SSFIFO3) / 4096;
        ADC0->ISC = 8;          /* clear completion flag */
    }
	
	
}

