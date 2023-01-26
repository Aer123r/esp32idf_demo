#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

void myTask1(void *pvParam)
{
    while (1)
    {
        printf("Task1 -- 111\r\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
void myTask2(void *pvParam)
{
    while (1)
    {
        printf("Task2 -- 222\r\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
void app_main()
{
    TaskHandle_t pHandle;
    xTaskCreate(myTask1, "myTask1", 2048, NULL, 1, &pHandle);
    xTaskCreate(myTask2, "myTask2", 2048, NULL, 2, NULL);

    vTaskSuspend(pHandle);
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    vTaskResume(pHandle);
    
}
