#ifndef BUTTON
#define BUTTON

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#define button_PIN 11
#define button_TRIGGER_LEVEL GPIO_INTR_POSEDGE	//Set whethet interrupt should trigger at positive or negative edge
#define button_PRIORITY 10
#define button_STACK_SIZE 2048

uint8_t button_detected;

void install_button();

void IRAM_ATTR button_ISR();

#endif /* BUTTON */
