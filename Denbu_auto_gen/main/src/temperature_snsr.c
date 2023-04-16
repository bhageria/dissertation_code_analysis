#include "temperature_snsr.h"

extern uint16_t adcDelayinMS=1000;

void tmpSnsr_init(adc_bits_width_t width, adc1_channel_t channel,adc_atten_t ADC_atten)
{
    adc1_config_width(width);
    adc1_config_channel_atten(channel,ADC_atten);
}

/* Read the temperature sensor value and write into buffer */
uint16_t read_tmpSnsr()
{
    uint16_t val = adc1_get_raw(TEMPERATURE_SENSOR_ADC_CHANNEL);
    return val;
}


void install_temperature_snsr()
{
    tmpSnsr_init(ADC_WIDTH_BIT_12,TEMPERATURE_SENSOR_ADC_CHANNEL,ADC_ATTEN_DB_11);
}