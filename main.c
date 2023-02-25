/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Utilities */
#include "utilities.h"

/*-----------------------------------------------------------*/

void task0(void* pvParameters);

/*-----------------------------------------------------------*/

int main( void )
{
    /* This demo uses heap_5.c, so start by defining some heap regions.  heap_5
     * is only used for test and example reasons.  Heap_4 is more appropriate.  See
     * http://www.freertos.org/a00111.html for an explanation. */
    prvInitialiseHeap();

    /* Initialise the trace recorder.  Use of the trace recorder is optional.
     * See http://www.FreeRTOS.org/trace for more information. */
    configASSERT( xTraceInitialize() == TRC_SUCCESS );
    configASSERT( xTraceEnable(TRC_START) == TRC_SUCCESS );

    /*-----------------------------------------------------------*/

    xTaskCreate(task0,			/* The function that implements the task. */
        "Rx", 							/* The text name assigned to the task - for debug only as it is not used by the kernel. */
        configMINIMAL_STACK_SIZE, 		/* The size of the stack to allocate to the task. */
        NULL, 							/* The parameter passed to the task - not used in this simple case. */
        tskIDLE_PRIORITY + 2,/* The priority assigned to the task. */
        NULL);

    vTaskStartScheduler();

    for (;;);

    return 0;
}

/*-----------------------------------------------------------*/

void task0(void* pvParameters)
{
    (void)pvParameters;

    for (;; )
    {
        taskENTER_CRITICAL();
        printf("Hello \r\n");
        vTaskDelay(500);
        taskEXIT_CRITICAL();
    }
}
