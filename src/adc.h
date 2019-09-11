#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "main.h"

void adc_init(void);
void adc_test(void);

void adc_process(void);

uint16_t adc_get_channel(uint32_t id);
int32_t  adc_get_channel_rescaled(uint8_t idx);
uint16_t adc_get_channel_packetdata(uint8_t idx);
uint32_t adc_get_battery_voltage(void);

// internal channel ordering. we will always use AETR0123 internally
typedef enum {
  CHANNEL_ID_AILERON = 0,
  CHANNEL_ID_ELEVATION,
  CHANNEL_ID_THROTTLE,
  CHANNEL_ID_RUDDER,
  CHANNEL_ID_CH0,
  CHANNEL_ID_CH1,
  CHANNEL_ID_CH2,
  CHANNEL_ID_CH3,
  CHANNEL_ID_CH4,
  CHANNEL_ID_SIZE
} channel_id_t;

char *adc_get_channel_name(uint8_t i, bool short_descr);


// rescaled data goes from -3200 to 3200
// set zero threshold to 10% movement from absolute zero
#define ADC_RESCALED_ABSOLUTE_MIN        -3200
#define ADC_RESCALED_ABSOLUTE_MAX         3200
#define ADC_RESCALED_ZERO_THRESHOLD      (ADC_RESCALED_ABSOLUTE_MIN + 0.1 * (ADC_RESCALED_ABSOLUTE_MAX - ADC_RESCALED_ABSOLUTE_MIN))
