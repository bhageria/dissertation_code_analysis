#include "application.h"

void start_application()
{
	install_temperature_snsr();
	install_LED();
	install_button();
	install_motion_snsr();
	xTaskCreate(temperature_snsr_event_Handler, "temperature_snsr_Handler", temperature_snsr_STACK_SIZE, NULL, temperature_snsr_PRIORITY, NULL);
}

void temperature_snsr_event_Handler()
{
	str_temperature_snsr_event_t temperature_snsr_msg;
	str_LED_event_t LED_msg;
	mqttData_str_t mqttData_e;
	while(1)
	{
		while(!xQueueReceive(q_temperature_snsr_event,&temperature_snsr_msg,portMAX_DELAY));
		switch(temperature_snsr_msg.msg_id)
		{
			case TEMPERATURE_THRESHOLD_CROSSED:
				LED_msg.msg_id = LED_ON;
				xQueueSend(q_LED_event, &LED_msg, (TickType_t)0 );
				mqttData_str_t mqttData_e;
				mqttData_e.data = temperature_snsr_msg.data;
				xQueueSend(mqttData_Queue, &mqttData_e , (TickType_t)0 );
				break;
			case TEMPERATURE_THRESHOLD_NOT_CROSSED:
				LED_msg.msg_id = LED_OFF;
				xQueueSend(q_LED_event, &LED_msg, (TickType_t)0 );
				mqttData_e.data = temperature_snsr_msg.data;
				xQueueSend(mqttData_Queue, &mqttData_e , (TickType_t)0 );
				break;
			default:
				break;
		}
	}
}

void motion_snsr_Handler()
{
	str_motion_snsr_event_t motion_snsr_msg;
	mqttData_str_t mqttData_e;
	while(1)
	{
		while(!xQueueReceive(q_motion_snsr_event,&motion_snsr_msg,portMAX_DELAY));
		switch(motion_snsr_msg.msg_id)
		{
			case MOTION_DETECTED:
				LED_msg.msg_id = LED_ON;
				xQueueSend(q_LED_event, &LED_msg, (TickType_t)0 );
				mqttData_e.data = motion_snsr_msg.data;
				xQueueSend(mqttData_Queue, &mqttData_e , (TickType_t)0 );
				break;
			default:
				break;
		}
	}
}

void button_Handler()
{
	str_button_event_t button_msg;
	mqttData_str_t mqttData_e;
	while(1)
	{
		while(!xQueueReceive(q_button_event,&button_msg,portMAX_DELAY));
		switch(button_msg.msg_id)
		{
			case BUTTON_DETECTED:
				LED_msg.msg_id = LED_ON;
				xQueueSend(q_LED_event, &LED_msg, (TickType_t)0 );
				mqttData_e.data = button_msg.data;
				xQueueSend(mqttData_Queue, &mqttData_e , (TickType_t)0 );
				break;
			default:
				break;
		}
	}
}