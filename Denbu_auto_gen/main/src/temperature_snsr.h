#ifndef _TMP_SNSR
    #define _TMP_SNSR
    #include "driver/adc.h"
    #include "esp_adc_cal.h"
    #include "freertos/FreeRTOS.h"
    #include "freertos/task.h"
    #include "driver/gpio.h"
    #include "esp_log.h"
    #include "freertos/queue.h"

    #define TEMPERATURE_SENSOR_ADC_CHANNEL ADC1_CHANNEL_8
    #define temperature_snsr_STACK_SIZE 2048
    #define temperature_snsr_PRIORITY 5


    uint16_t adcDelayinMS;
    void tmpSnsr_init(adc_bits_width_t width, adc1_channel_t channel,adc_atten_t ADC_atten);
    uint16_t read_tmpSnsr();
    void install_temperature_snsr();
#endif