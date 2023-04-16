#include "LED.h"

void set_LED(uint8_t value)
{
    gpio_set_level(LED_PIN, value);
}


void install_LED(void)
{
  gpio_pad_select_gpio(LED_PIN);
  gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
}

