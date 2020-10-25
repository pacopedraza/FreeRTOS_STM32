/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"

#include "FreeRTOS.h"
#include "task.h"

			
TaskHandle_t xTaskHandle1=NULL;
TaskHandle_t xTaskHandle2=NULL;

// Task functions prototypes
void vTask1_handler(void *params);
void vTask2_handler(void *params);

int main(void)
{
	// 1. Reset the RCC clock configuration to the default reset state.
	RCC_DeInit(); // Makes: HSI ON, PLL OFF, HSE OFF, System Clock = 16MHz, cpu clock = 16MHz
	// 2. Update the System Core Clock variable

	SystemCoreClockUpdate();
	// 3. Create two tasks. Task-1 and Task-2
	xTaskCreate( vTask1_handler,
			"Task-1",
			configMINIMAL_STACK_SIZE,
			NULL,
			2,
			&xTaskHandle1 );

	xTaskCreate( vTask2_handler,
			"Task-2",
			configMINIMAL_STACK_SIZE,
			NULL,
			2,
			&xTaskHandle2 );

	for(;;);
}

void vTask1_handler(void *params)
{
	while(1); // should never return
}

void vTask2_handler(void *params)
{
	while(1);
}
