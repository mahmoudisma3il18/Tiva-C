#include "FreeRTOS.h"
#include "TM4C123.h"
#include "task.h"


TaskHandle_t LED1;
TaskHandle_t LED2;
TaskHandle_t LED3;

void LED1_TASK(void *pv) {
	
	
	while(1) {
		
		GPIOF->DATA = 0x02; // turn on red LED
		vTaskDelay(80);
	}
	
}

void LED2_TASK(void *pv) {
	
	
	while(1) {
		
		GPIOF->DATA = 0x04; // turn on red LED
		vTaskDelay(100);
	}
	
}

void LED3_TASK(void *pv) {
	
	
	while(1) {
		
		GPIOF->DATA = 0x08; // turn on red LED
		vTaskDelay(120);
	}
	
}

int main(void) {
	
	SYSCTL->RCGCGPIO = 0x20;
	GPIOF->DIR = 0x0E;
  GPIOF->DEN = 0x0E;	
	
	xTaskCreate(LED1_TASK,"LED1",100,(void*)1,2,&LED1);
	xTaskCreate(LED2_TASK,"LED2",100,(void*)1,2,&LED2);
	xTaskCreate(LED3_TASK,"LED3",100,(void*)1,2,&LED3);
	vTaskStartScheduler();
	
	
	
}

