#include "application.h"

void start_application()
{
	char temperature_val[50];
	mqttData_str_t mqttData_e;
	uint16_t temperature;
	install_temperature_snsr();
	install_LED();
	
	while(1)
	{
		temperature = read_tmpSnsr();
		if(temperature > 2000)
		{
			sprintf(temperature_val,"TEMPERATURE_THRESHOLD_CROSSED - %u",temperature);
			set_LED(1);
			mqttData_e.data = temperature_val;
			xQueueSend(mqttData_Queue, &mqttData_e , (TickType_t)0 );
		}
		else
		{
			sprintf(temperature_val,"TEMPERATURE_THRESHOLD_NOT_CROSSED - %u",temperature);
			set_LED(0);
			mqttData_e.data = temperature_val;
			xQueueSend(mqttData_Queue, &mqttData_e , (TickType_t)0 );
		}
		 vTaskDelay(5000/ portTICK_PERIOD_MS);
	}
}