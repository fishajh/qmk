/* Copyright 2020 zvecr <git@zvecr.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include "quantum.h"
#include "version.h"

#include "via.h" // only for EEPROM address
#define EEPROM_ENABLED_ENCODER_MODES (VIA_EEPROM_CUSTOM_CONFIG_ADDR)
#define EEPROM_CUSTOM_BACKLIGHT (VIA_EEPROM_CUSTOM_CONFIG_ADDR+1)
#define EEPROM_DEFAULT_OLED (VIA_EEPROM_CUSTOM_CONFIG_ADDR+2)
#define EEPROM_CUSTOM_ENCODER (VIA_EEPROM_CUSTOM_CONFIG_ADDR+3)

/* screen off after this many milliseconds */
//#define ScreenOffInterval 0 /* milliseconds */


// Start these at the USER code range in VIA
enum my_keycodes {
  ENC_PRESS = 0x5F80,
  CLOCK_SET,
  OLED_TOGG,
  VRSN
};

enum h65_keyboard_value_id {
  id_encoder_modes = 0x80,
  id_oled_default_mode,
  id_encoder_custom,
  id_oled_mode
};

enum encoder_modes {
  ENC_MODE_VOLUME,
  ENC_MODE_MEDIA,
  ENC_MODE_SCROLL,
  ENC_MODE_BRIGHTNESS,
  ENC_MODE_PAGE,
  ENC_MODE_CUSTOM0,
  ENC_MODE_CUSTOM1,
  ENC_MODE_CUSTOM2,
  _NUM_ENCODER_MODES,
  ENC_MODE_CLOCK_SET // This shouldn't be included in the default modes, so we put it after NUM_ENCODER_MODES
};

enum custom_encoder_behavior {
    ENC_CUSTOM_CW = 0,
    ENC_CUSTOM_CCW,
    ENC_CUSTOM_PRESS
};

enum oled_modes {
  OLED_DEFAULT,
  OLED_TIME,
  OLED_LOGO,
  OLED_OFF,
  _NUM_OLED_MODES
};


// Keyboard Information
extern volatile uint8_t led_numlock;
extern volatile uint8_t led_capslock;
extern volatile uint8_t led_scrolllock;
extern uint8_t layer;

// OLED Behavior
extern uint16_t last_flush;
extern bool queue_for_send;
extern uint8_t oled_mode;
extern bool oled_sleeping;

// Encoder Behavior
extern uint8_t encoder_value;
extern uint8_t encoder_mode;
extern uint8_t enabled_encoder_modes;

// RTC
extern RTCDateTime last_timespec;
extern uint16_t last_minute;

// RTC Configuration
extern bool clock_set_mode;
extern uint8_t time_config_idx;
extern int8_t hour_config;
extern int16_t minute_config;
extern int8_t year_config;
extern int8_t month_config;
extern int8_t day_config;
extern uint8_t previous_encoder_mode;

void pre_encoder_mode_change(void);
void post_encoder_mode_change(void);
void change_encoder_mode(bool negative);
uint16_t handle_encoder_clockwise(void);
uint16_t handle_encoder_ccw(void);
uint16_t handle_encoder_press(void);
uint16_t retrieve_custom_encoder_config(uint8_t encoder_idx, uint8_t behavior);
void set_custom_encoder_config(uint8_t encoder_idx, uint8_t behavior, uint16_t new_code);

void update_time_config(int8_t increment);

__attribute__ ((weak))
void draw_ui(void);
void draw_default(void);
void draw_clock(void);

void custom_config_load(void);

#define LAYOUT( \
                        KA01, KA02, KA03, KA04, KA05, KA06, KA07, KA08, KA09, KA10, KA11, KA12, KA13, KA14, KA15, KA16, \
	KB14 ,KD13,     KB01, KB02, KB03, KB04, KB05, KB06, KB07, KB08, KB09, KB10, KB11, KB12, KB13,       KB15, KB16, \
	KC13 ,KC14,     KC01, KC02, KC03, KC04, KC05, KC06, KC07, KC08, KC09, KC10, KC11, KC12,             KC15, KC16, \
	KE09 ,KE10,     KD01, KD02, KD03, KD04, KD05, KD06, KD07, KD08, KD09, KD10, KD11, KD12,       KD14, KD15, KD16, \
	KE04 ,KE05,     KE01, KE02, KE03,             KE06, KE07, KE08,             KE11, KE12, KE13, KE14, KE15, KE16  \
) { \
	{  KA01 , KA02 , KA03 , KA04 , KA05 , KA06 , KA07 , KA08 , KA09 , KA10 , KA11 , KA12 , KA13 , KA14 , KA15 , KA16 }, \
	{  KB01 , KB02 , KB03 , KB04 , KB05 , KB06 , KB07 , KB08 , KB09 , KB10 , KB11 , KB12 , KB13 , KB14 , KB15 , KB16 }, \
	{  KC01 , KC02 , KC03 , KC04 , KC05 , KC06 , KC07 , KC08 , KC09 , KC10 , KC11 , KC12 , KC13 , KC14 , KC15 , KC16 }, \
	{  KD01 , KD02 , KD03 , KD04 , KD05 , KD06 , KD07 , KD08 , KD09 , KD10 , KD11 , KD12 , KD13 , KD14 , KD15 , KD16 }, \
	{  KE01 , KE02 , KE03 , KE04 , KE05 , KE06 , KE07 , KE08 , KE09 , KE10 , KE11 , KE12 , KE13 , KE14 , KE15 , KE16 } \
	}
