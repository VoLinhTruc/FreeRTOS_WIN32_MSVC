//System #include - begin ---------------------------------------------------------------
/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

//Utilities
// This utilities.h is just aim to reduce the code complexibility ò the origin FreeRTOS Demo when we look at it
#include "utilities.h"
//System #include - begin ---------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------------------


//User #define - begin-----------------------------------------------------------

//User #define - end-----------------------------------------------------------


//User #include - begin-----------------------------------------------------------
#include "Tree_Back_Model.h"
#include "Tree_Back_Message_Queue.h"

#include "Tree_Back_Managing_Task.h"
#include "Tree_Back_Executing_Task.h"
//User #include - end-----------------------------------------------------------


//User typedef - begin-----------------------------------------------------------

//User typedef - end-----------------------------------------------------------


//User prototype - begin-----------------------------------------------------------

//User prototype - end-----------------------------------------------------------


//User variable - begin-----------------------------------------------------------
void task0(void* pvParameters);
//User variable - end-----------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------------------


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

    //---------------------------------------------------------------------------

    TB_Task_Handle tb_task0 = initTBTask();
    createTBTask(NULL, 5, sizeof(TB_MQ_Handle), NULL, 0, 0, task0, "task0", configMINIMAL_STACK_SIZE, tskIDLE_PRIORITY, &tb_task0);

    TB_Task_Handle tb_task1 = initTBTask();
    createTBTask(NULL, 5, sizeof(TB_MQ_Handle), NULL, 0, 0, task0, "task1", configMINIMAL_STACK_SIZE, tskIDLE_PRIORITY, &tb_task1);

    
    //---------------------------------------------------------------------------

    vTaskStartScheduler();

    for (;;);
    
    return 0;
}


//---------------------------------------------------------------------------------------------------------------------------


//User function definition - begin-----------------------------------------------------------
void task0(void* pvParameters)
{
    for (;;)
    {
        TB_Task_Handle tb_task = (TB_Task_Handle)pvParameters;

        TaskHandle_t internal_task = xTaskGetHandle(pcTaskGetName(tb_task->task));
        printf("Hello from %s \r\n", pcTaskGetName(internal_task));

        if (strcmp(pcTaskGetName(internal_task), "task0") == 0)
        {
            deleteTBTask(&tb_task);
        }

        vTaskDelay(500);
    }
}
//User function definition  - end-----------------------------------------------------------