/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include <stdio.h>
#include <stdint.h>

#include "stm32f4xx.h"

#include "FreeRTOS.h"
#include "task.h"

			
TaskHandle_t xTaskHandle1=NULL;
TaskHandle_t xTaskHandle2=NULL;

// Task functions prototypes
void vTask1_handler(void *params);
void vTask2_handler(void *params);

// Used for semihosting
extern void initialise_monitor_handles();

int main(void)
{
	initialise_monitor_handles();
	printf("Hello workd example code!");
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
	// 4. Start the Scheduler
	vTaskStartScheduler();

	// Will never return here
	for(;;);
}

void vTask1_handler(void *params)
{
	while(1)
	{
		printf("Hello-World: From Task-1\n");
	}
}

void vTask2_handler(void *params)
{
	while(1)
	{
		printf("Hello-World: From Task-2\n");
	}
}
