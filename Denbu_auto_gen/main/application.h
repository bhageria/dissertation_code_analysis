#ifndef APPLICATION
#define APPLICATION

#include "src/aws_iot.h"
#include "src/temperature_snsr.h"
#include "src/LED.h"
void temperature_snsr_event_Handler();
void start_application();
void motion_snsr_Handler();
void button_Handler();
extern QueueHandle_t mqttData_Queue;
#endif /* APPLICATION */
