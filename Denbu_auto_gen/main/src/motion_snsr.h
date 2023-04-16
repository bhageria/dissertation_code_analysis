#ifndef MOTION_SNSR
#define MOTION_SNSR

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#define MOTION_SNSR_PIN 10
#define MOTION_SNSR_TRIGGER_LEVEL GPIO_INTR_POSEDGE	//Set whethet interrupt should trigger at positive or negative edge
#define motion_snsr_PRIORITY 10
#define motion_snsr_STACK_SIZE 2048

uint8_t motion_detected;

void install_motion_snsr();
void IRAM_ATTR motion_snsr_ISR();

#endif /* MOTION_SNSR */
