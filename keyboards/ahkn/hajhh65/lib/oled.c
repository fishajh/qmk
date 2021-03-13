#include "rev1.h"
#include "micro_oled.h"
#include <stdio.h>

__attribute__ ((weak))
void draw_ui() {
#ifdef QWIIC_MICRO_OLED_ENABLE
  clear_buffer();
  last_flush = timer_read();
  send_command(DISPLAYON);
  if(clock_set_mode){
    draw_clock();
    return;
  }
  switch (oled_mode){
    default:
    case OLED_DEFAULT:
      draw_default();
      break;
    case OLED_TIME:
      draw_clock();
      break;
    case OLED_LOGO:
      draw_default();
      break;
    case OLED_OFF:
      send_command(DISPLAYOFF);
      break;
  }
#endif
}

// draw encoder mode
void draw_encoder(int8_t startX, int8_t startY, bool show_legend){
  if(show_legend){
    draw_string(startX + 1, startY + 2, "ENC", PIXEL_ON, NORM, 0);
  } else {
    startX -= 22;
  }
  draw_rect_filled_soft(startX + 22, startY + 1, 3 + (3 * 6), 9, PIXEL_ON, NORM);
  char* mode_string = "";
  switch(encoder_mode){
    default:
    case ENC_MODE_VOLUME:
      mode_string = "VOL";
      break;
    case ENC_MODE_MEDIA:
      mode_string = "MED";
      break;
    case ENC_MODE_SCROLL:
      mode_string = "SCR";
      break;
    case ENC_MODE_BRIGHTNESS:
      mode_string = "BRT";
      break;
    case ENC_MODE_PAGE:
      mode_string = "PAG";
      break;
    case ENC_MODE_CLOCK_SET:
      mode_string = "CLK";
      break;
    case ENC_MODE_CUSTOM0:
      mode_string = "CS0";
      break;
    case ENC_MODE_CUSTOM1:
      mode_string = "CS1";
      break;
    case ENC_MODE_CUSTOM2:
      mode_string = "CS2";
      break;
  }
  draw_string(startX + 24, startY + 2, mode_string, PIXEL_ON, XOR, 0);
}
//end of funtion draw encoder mode


// draw keyboard layer 
void draw_layer_section(int8_t startX, int8_t startY, bool show_legend){
  if(show_legend){
    draw_string(startX + 1, startY + 2, "LAYER", PIXEL_ON, NORM, 0);
  } else {
    startX -= 32;
  }
  draw_rect_filled_soft(startX + 32, startY + 1, 9, 9, PIXEL_ON, NORM);
  draw_char(startX + 34, startY + 2, layer + 0x30, PIXEL_ON, XOR, 0);
}
//end 

// draw matrix location funtion 
void draw_matrix_location(int8_t  startX, int8_t startY, bool show_legend) {
  if(show_legend){
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
       for (uint8_t y = 0; y < MATRIX_COLS; y++) {
          draw_pixel(startX + y + 2, startY + x + 2,(matrix_get_row(x) & (1 << y)) > 0, NORM);
        }
      }
       draw_rect_soft(startX, startY, 19, 9, PIXEL_ON, NORM);
       /* hadron oled location on thumbnail */
       draw_rect_filled_soft(startX + 14, startY + 2, 3, 1, PIXEL_ON, NORM);
    
  } else {
  //nothing in here
  }
}
//end off draw mstrix location funtion

//draw mods funtion
void draw_mods_funtion(int8_t  startX, int8_t startY, bool show_legend) {
 uint8_t mods = get_mods();
  if(show_legend){
    if (mods & MOD_LSFT) {
    draw_rect_filled_soft(startX + 0, startY, 5 + (1 * 6), 11, PIXEL_ON, NORM);
    draw_string(startX + 3, startY + 2, "S", PIXEL_OFF, NORM, 0);
    } else {
    draw_string(startX + 3, startY + 2, "S", PIXEL_ON, NORM, 0);
     }
    if (mods & MOD_LCTL) {
    draw_rect_filled_soft(startX + 10, startY, 5 + (1 * 6), 11, PIXEL_ON, NORM);
    draw_string(startX + 13, startY + 2, "C", PIXEL_OFF, NORM, 0);
    } else {
    draw_string(startX + 13, startY + 2, "C", PIXEL_ON, NORM, 0);
     }
    if (mods & MOD_LALT) {
    draw_rect_filled_soft(startX + 20, startY, 5 + (1 * 6), 11, PIXEL_ON, NORM);
    draw_string(startX + 23, startY + 2, "A", PIXEL_OFF, NORM, 0);
    } else {
    draw_string(startX + 23, startY + 2, "A", PIXEL_ON, NORM, 0);
    }
    if (mods & MOD_LGUI) {
    draw_rect_filled_soft(startX + 30, startY, 5 + (1 * 6), 11, PIXEL_ON, NORM);
    draw_string(startX + 33, startY + 2, "G", PIXEL_OFF, NORM, 0);
    } else {
    draw_string(startX + 33, startY + 2, "G", PIXEL_ON, NORM, 0);
    }
  } else {
  //nothing in here
  }
}
//end of draw mods


void draw_default(){
  uint8_t hour = last_minute / 60;
  uint16_t minute = last_minute % 60;

  if(encoder_mode == ENC_MODE_CLOCK_SET){
    hour = hour_config;
    minute = minute_config;
  }

  char hour_str[3] = "";
  char min_str[3] = "";

  sprintf(hour_str, "%02d", hour);
  sprintf(min_str, "%02d", minute);

  

/* Layer indicator is 41 x 10 pixels */
  draw_layer_section(0,0,true);

#define ENCODER_INDICATOR_X 45
#define ENCODER_INDICATOR_Y 0
  draw_encoder(ENCODER_INDICATOR_X, ENCODER_INDICATOR_Y, true);

/* Matrix display is 19 x 9 pixels */
#define MATRIX_DISPLAY_X 0
#define MATRIX_DISPLAY_Y 18
  draw_matrix_location(MATRIX_DISPLAY_X, MATRIX_DISPLAY_Y, false);

/* Mod display is 41 x 16 pixels */
#define MOD_DISPLAY_X 30
#define MOD_DISPLAY_Y 18
draw_mods_funtion(MOD_DISPLAY_X, MOD_DISPLAY_Y, false);

/* Lock display is 23 x 21 */
#define LOCK_DISPLAY_X 100
#define LOCK_DISPLAY_Y 0

  if (led_capslock == true) {
    draw_rect_filled_soft(LOCK_DISPLAY_X + 0, LOCK_DISPLAY_Y, 5 + (3 * 6), 9, PIXEL_ON, NORM);
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y +1, "CAP", PIXEL_OFF, NORM, 0);
  } else if (led_capslock == false) {
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y +1, "CAP", PIXEL_ON, NORM, 0);
  }

  if (led_scrolllock == true) {
    draw_rect_filled_soft(LOCK_DISPLAY_X + 0, LOCK_DISPLAY_Y + 11, 5 + (3 * 6), 9, PIXEL_ON, NORM);
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y + 11 +1, "SCR", PIXEL_OFF, NORM, 0);
  } else if (led_scrolllock == false) {
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y + 11 +1, "SCR", PIXEL_ON, NORM, 0);
  }

  if (led_numlock == true) {
    draw_rect_filled_soft(LOCK_DISPLAY_X + 0, LOCK_DISPLAY_Y + 21, 5 + (3 * 6), 9, PIXEL_ON, NORM);
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y + 21 +1, "NUM", PIXEL_OFF, NORM, 0);
  } else if (led_numlock == false) {
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y + 21 +1, "NUM", PIXEL_ON, NORM, 0);
  }

#define CLOCK_DISPLAY_X 14
#define CLOCK_DISPLAY_Y 14
  draw_string(CLOCK_DISPLAY_X+2, CLOCK_DISPLAY_Y, hour_str, PIXEL_ON, NORM, 1);
  draw_string(CLOCK_DISPLAY_X + 20, CLOCK_DISPLAY_Y - 1, ":", PIXEL_ON, NORM, 1);
  draw_string(CLOCK_DISPLAY_X + 28, CLOCK_DISPLAY_Y, min_str, PIXEL_ON, NORM, 1);

  send_buffer();
}

void draw_clock(){
  int8_t hour = last_minute / 60;
  int16_t minute = last_minute % 60;
  int16_t year = last_timespec.year + 1980;
  int8_t month = last_timespec.month;
  int8_t day = last_timespec.day;

  if(encoder_mode == ENC_MODE_CLOCK_SET){
    hour = hour_config;
    minute = minute_config;
    year = year_config + 1980;
    month = month_config;
    day = day_config;
  }

  char hour_str[3] = "";
  char min_str[3] = "";
  char year_str[5] = "";
  char month_str[3] = "";
  char day_str[3] = "";

  sprintf(hour_str, "%02d", hour);
  sprintf(min_str, "%02d", minute);
  sprintf(year_str, "%d", year);
  sprintf(month_str, "%02d", month);
  sprintf(day_str, "%02d", day);


#define DATE_DISPLAY_X 6
#define DATE_DISPLAY_Y 0
  draw_string(DATE_DISPLAY_X, DATE_DISPLAY_Y, year_str, PIXEL_ON, NORM, 0);
  draw_string(DATE_DISPLAY_X + 25, DATE_DISPLAY_Y, "-", PIXEL_ON, NORM, 0);
  draw_string(DATE_DISPLAY_X + 31, DATE_DISPLAY_Y, month_str, PIXEL_ON, NORM, 0);
  draw_string(DATE_DISPLAY_X + 44, DATE_DISPLAY_Y, "-", PIXEL_ON, NORM, 0);
  draw_string(DATE_DISPLAY_X + 50, DATE_DISPLAY_Y, day_str, PIXEL_ON, NORM, 0);

#define CLOCK_DISPLAY_X 14
#define CLOCK_DISPLAY_Y 14
  draw_string(CLOCK_DISPLAY_X, CLOCK_DISPLAY_Y, hour_str, PIXEL_ON, NORM, 1);
  draw_string(CLOCK_DISPLAY_X + 17, CLOCK_DISPLAY_Y, ":", PIXEL_ON, NORM, 1);
  draw_string(CLOCK_DISPLAY_X + 25, CLOCK_DISPLAY_Y, min_str, PIXEL_ON, NORM, 1);
  if(clock_set_mode){
    switch(time_config_idx){
      case 0: // hour
      default:
        draw_line(CLOCK_DISPLAY_X, CLOCK_DISPLAY_Y + 16, CLOCK_DISPLAY_X + 16, CLOCK_DISPLAY_Y + 16, PIXEL_ON, NORM);
        draw_line(CLOCK_DISPLAY_X, CLOCK_DISPLAY_Y + 17, CLOCK_DISPLAY_X + 16, CLOCK_DISPLAY_Y + 17, PIXEL_ON, NORM);
        break;
      case 1: // minute
        draw_line(CLOCK_DISPLAY_X + 25, CLOCK_DISPLAY_Y + 16, CLOCK_DISPLAY_X + 41, CLOCK_DISPLAY_Y + 16, PIXEL_ON, NORM);
        draw_line(CLOCK_DISPLAY_X + 25, CLOCK_DISPLAY_Y + 17, CLOCK_DISPLAY_X + 41, CLOCK_DISPLAY_Y + 17, PIXEL_ON, NORM);
        break;
      case 2: // year
        draw_line(DATE_DISPLAY_X, DATE_DISPLAY_Y + 9, DATE_DISPLAY_X + 23, DATE_DISPLAY_Y + 9, PIXEL_ON, NORM);
        break;
      case 3: // month
        draw_line(DATE_DISPLAY_X + 31, DATE_DISPLAY_Y + 9, DATE_DISPLAY_X + 43, DATE_DISPLAY_Y + 9, PIXEL_ON, NORM);
        break;
      case 4: //day
        draw_line(DATE_DISPLAY_X + 50, DATE_DISPLAY_Y + 9, DATE_DISPLAY_X + 61, DATE_DISPLAY_Y + 9,PIXEL_ON, NORM);
        break;
    }
  }

  draw_encoder(80, 0, true);
  draw_layer_section(80, 11, true);

#define CAPS_DISPLAY_X 86
#define CAPS_DISPLAY_Y 22

  if (led_capslock == true) {
    draw_rect_filled_soft(CAPS_DISPLAY_X, CAPS_DISPLAY_Y, 5 + (4 * 6), 9, PIXEL_ON, NORM);
    draw_string(CAPS_DISPLAY_X + 3, CAPS_DISPLAY_Y +1, "CAPS", PIXEL_OFF, NORM, 0);
  } else if (led_capslock == false) {
    draw_string(CAPS_DISPLAY_X + 3, CAPS_DISPLAY_Y +1, "CAPS", PIXEL_ON, NORM, 0);
  }
  send_buffer();

}

