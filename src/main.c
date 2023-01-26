/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

/* Can use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO CONFIG_BLINK_GPIO
#define GPIO_PIN_4  4
static void config_led(void);
void app_main()
{
    config_led();
    printf("Turning off led\n");
    while(1) {
        /* Blink off (output low) */
	printf("Turning off the LED\n");
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(1500 / portTICK_PERIOD_MS);
        /* Blink on (output high) */
	printf("Turning on the LED\n");
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(1500 / portTICK_PERIOD_MS);
    }
}

static void config_led(void)
{
    gpio_config_t io_config = {};
    io_config.pin_bit_mask = 1ULL<<CONFIG_BLINK_GPIO;
    io_config.mode = GPIO_MODE_OUTPUT;
    io_config.pull_up_en = true;
    io_config.pull_down_en = false;
    io_config.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&io_config);

    io_config.pin_bit_mask = 1ULL<<GPIO_PIN_4;
    io_config.mode = GPIO_MODE_INPUT;
    io_config.pull_up_en = true;
    io_config.pull_down_en = false;
    io_config.intr_type = GPIO_INTR_POSEDGE;
    gpio_config(&io_config);

}