#ifndef APPLICATION
#define APPLICATION

#include "src/aws_iot.h"
#include "src/temperature_snsr.h"
#include "src/LED.h"
void start_application();
extern QueueHandle_t mqttData_Queue;
#endif /* APPLICATION */