#pragma once

#include <stdint.h>
#include "adc.h"

#define GUI_PREV_CLICK_X 10
#define GUI_NEXT_CLICK_X (LCD_WIDTH - GUI_PREV_CLICK_X)
#define GUI_PAGE_MAIN     0
#define GUI_PAGE_STICKS   1
#define GUI_PAGE_SETTINGS 2
#define GUI_MAX_PAGE GUI_PAGE_SETTINGS
#define GUI_STATUSBAR_FONT font_tomthumb3x5


#define GUI_LOOP_DELAY_MS 100
#define GUI_SHUTDOWN_PRESS_S 2.0
#define GUI_SHUTDOWN_PRESS_COUNT_FROM_MS(_ms) ((_ms)/GUI_LOOP_DELAY_MS)
#define GUI_SHUTDOWN_PRESS_COUNT (GUI_SHUTDOWN_PRESS_COUNT_FROM_MS(1000*GUI_SHUTDOWN_PRESS_S))

// touch function pointer
typedef void (*f_ptr_t)(void);
typedef void (*f_ptr_32_32_t)(uint32_t x, uint32_t y);

// touch callback
typedef struct {
    // defines the touch sensitive rect
    uint8_t xs;
    uint8_t xe;
    uint8_t ys;
    uint8_t ye;
    // and the callback to run
    f_ptr_t callback;
} touch_callback_entry_t;

#define GUI_TOUCH_CALLBACK_COUNT 10


#define GUI_PAGE_CONFIG_FLAG        0x80
#define GUI_PAGE_CONFIG_OPTION_FLAG 0x40
#define GUI_PAGE_SETUP_FLAG         0x20
#define GUI_PAGE_NOFLAGS (~(GUI_PAGE_CONFIG_FLAG|GUI_PAGE_CONFIG_OPTION_FLAG|GUI_PAGE_SETUP_FLAG))


#define GUI_PAGE_SETUP_MAIN       (GUI_PAGE_SETUP_FLAG | 0)
#define GUI_PAGE_SETUP_CLONETX    (GUI_PAGE_SETUP_FLAG | 1)
#define GUI_PAGE_SETUP_BIND       (GUI_PAGE_SETUP_FLAG | 2)
#define GUI_PAGE_SETUP_BOOTLOADER (GUI_PAGE_SETUP_FLAG | 3)

#define GUI_PAGE_CONFIG_MAIN            (GUI_PAGE_CONFIG_FLAG | 0)
#define GUI_PAGE_CONFIG_STICK_CAL       (GUI_PAGE_CONFIG_FLAG | 1)
#define GUI_PAGE_CONFIG_MODEL_SETTINGS  (GUI_PAGE_CONFIG_FLAG | 2)


#define GUI_SUBPAGE_SETTING_MODEL_NAME  0
#define GUI_SUBPAGE_SETTING_MODEL_SCALE 1
#define GUI_SUBPAGE_SETTING_MODEL_TIMER 2

void gui_init(void);
void gui_loop(void);

uint32_t gui_running(void);
