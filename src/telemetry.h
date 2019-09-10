#pragma once

#include <stdint.h>
#include "fifo.h"

void telemetry_init(void);
void telemetry_enqueue(uint8_t byte);
void telemetry_process(void);

uint16_t telemetry_get_voltage(void);
uint16_t telemetry_get_current(void);
uint16_t telemetry_get_mah(void);

// FrSky telemetry stream state machine
typedef enum {
  TELEMETRY_IDLE = 0,   // waiting for 0x5e frame marker
  TELEMETRY_DATA_ID,    // waiting for dataID
  TELEMETRY_DATA_LOW,   // waiting for data low byte
  TELEMETRY_DATA_HIGH,  // waiting for data high byte
  TELEMETRY_DATA_END,   // waiting for 0x5e end of frame marker
  TELEMETRY_XOR = 0x80  // decode stuffed byte
} telemetry_state_t;
