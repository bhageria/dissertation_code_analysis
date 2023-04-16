#ifndef LED
#define LED
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#define LED_PIN 13
#define LED_STACK_SIZE 2048
#define LED_PRIORITY 5

void set_LED(uint8_t);
void install_LED();

#endif /* LED */
