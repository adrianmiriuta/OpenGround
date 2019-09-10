#pragma once

#include <stdint.h>

#include "frsky.h"

#define STORAGE_VERSION_ID 0x03
#define STORAGE_MODEL_NAME_LEN 11
#define STORAGE_MODEL_MAX_COUNT 10

void storage_init(void);
// static void storage_init_memory(void);
// void storage_write_to_flash(void);
// static void storage_read_from_flash(void);
void storage_save(void);
void storage_load(void);
void storage_mode_set_name(uint8_t index, char *str);
/*static void storage_write(uint8_t *buffer, uint16_t len);
static void storage_read(uint8_t *storage_ptr, uint16_t len);*/

// model description
typedef struct {
    // name of the model
    char name[STORAGE_MODEL_NAME_LEN];
    // timer
    uint16_t timer;
    // scale
    uint8_t stick_scale;
    // add further data here...
} MODEL_DESC;

// our storage struct contains all data that has to be stored on flash
typedef struct {
    // version id
    uint8_t version;
    // persistent storage for frsky
    uint8_t frsky_txid[2];
    uint8_t frsky_hop_table[FRSKY_HOPTABLE_SIZE];
    int8_t  frsky_freq_offset;
    // stick calibration data
    uint16_t stick_calibration[4][3];
    // model settings
    uint8_t current_model;
    MODEL_DESC model[STORAGE_MODEL_MAX_COUNT];
    // new data should be placed BEFORE the checksum...
    //
    // checksum
    uint16_t checksum;
} STORAGE_DESC;

// rounded up
#define SIZEOF_STORAGE_IN_16BIT ((sizeof(storage) + 1) / 2)

extern STORAGE_DESC storage;
