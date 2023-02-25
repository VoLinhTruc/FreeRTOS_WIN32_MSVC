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

    TB_Task_Handle tb_main_task = initTBTask();
    createTBTask(NULL, 5, sizeof(TB_MQ_Handle), NULL, 0, 0, tbManagingTask, MANAGING_TASK_NAME, configMINIMAL_STACK_SIZE, tskIDLE_PRIORITY, &tb_main_task);
    
    //---------------------------------------------------------------------------

    vTaskStartScheduler();
    for (;;);
    return 0;
}


//---------------------------------------------------------------------------------------------------------------------------


//User function definition - begin-----------------------------------------------------------

//User function definition  - end-----------------------------------------------------------