/* Copyright 2020 keni242 
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

#include QMK_KEYBOARD_H
#include "version.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};


enum custom_keycodes {
  VRSN,
};


#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  | RAISE|           |LOWER |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Grv  |  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  |   *  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_QWERTY] = LAYOUT_all(
KC_EQL , KC_1 , KC_2 , KC_3 , KC_4 , KC_5 , KC_LEFT ,            KC_RGHT , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_MINS,
KC_DEL , KC_Q , KC_W , KC_E , KC_R , KC_T , RAISE  ,             LOWER   , KC_Y , KC_U , KC_I , KC_O , KC_P , KC_BSLS,
KC_BSPC, KC_A , KC_S , KC_D , KC_F , KC_G ,                                KC_H , KC_J , KC_K , KC_L ,KC_SCLN,GUI_T(KC_QUOT),
KC_LSFT,CTL_T(KC_Z),KC_X,KC_C,KC_V , KC_B , ALL_T(KC_NO),        KC_MEH  , KC_N , KC_M ,KC_COMM,KC_DOT,CTL_T(KC_SLSH), KC_RSFT,
KC_GRV,KC_QUOT,LALT(KC_LSFT), KC_LEFT, KC_RGHT ,                                  KC_UP,KC_DOWN, KC_LBRC, KC_RBRC, KC_PAST,
                                    ALT_T(KC_APP), KC_LGUI,  KC_LALT, CTL_T(KC_ESC),
                                   KC_SPC, KC_BSPC,KC_HOME,  KC_PGUP, KC_TAB, KC_ENT,
                                   KC_SPC, KC_BSPC, KC_END,  KC_PGDN, KC_TAB, KC_ENT
),
/* Keymap 1:  LOWER Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |    F1   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  | RAISE|           |LOWER |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat| LYR  |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWER] = LAYOUT_all(
  KC_F1 ,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX,     XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,
  XXXXXXX, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, XXXXXXX,
  XXXXXXX, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                      KC_DOWN,   KC_4,    KC_5,    KC_6,    KC_PLUS, XXXXXXX,
  XXXXXXX, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, XXXXXXX,
  EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, KC_DOT,  KC_0,    KC_EQL,  XXXXXXX,
                                               RGB_MOD, XXXXXXX,     RGB_TOG, RGB_TOG,
                                      RGB_VAD, RGB_VAI, XXXXXXX,     XXXXXXX, RGB_HUD, RGB_HUI,
                                      RGB_VAD, RGB_VAI, XXXXXXX,     XXXXXXX, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media; mouse keys and RGB
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      | MsUp |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |MsLeft|MsDown|MsRght| RAISE|           |LOWER |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |Lclk  |      | Rclk |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * |   Prev | Next | Play |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |VolUp |VolDn | Mute |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = LAYOUT_all(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,     KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, XXXXXXX, KC_BTN2,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,     KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_VOLU, KC_VOLD, KC_MUTE, XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                                               XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
)
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180 ;  // flips the display 180 degrees if offhand
    }
    return rotation;
}
// When you add source files to SRC in rules.mk, you can use functions.
     const char *read_layer_state(void);
     const char *read_logo(void);
     void set_keylog(uint16_t keycode, keyrecord_t *record);
     const char *read_keylogs(void);
     const char *read_host_led_state(void);
     const char *read_keylog(void);
     const char *read_mode_icon(bool swap);
     void set_timelog(void);
     const char *read_timelog(void);
#ifdef RGBLIGHT_ENABLE
     const char *read_rgb_info(void);
#endif
#ifdef RGB_MATRIX_ENABLE
     const char *read_rgb_matrix_info(void);
#endif
#ifdef WPM_ENABLE
     const char *wpm_state(void);
     void render_anim(void);
#endif

void oled_task_user(void) {
  if (!is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_host_led_state(), false);
  #ifdef RGBLIGHT_ENABLE
    oled_write_ln(read_rgb_info(), false);
  #endif
  #ifdef RGB_MATRIX_ENABLE
    oled_write_ln(read_rgb_matrix_info(),false);
  #endif
    oled_write_ln(read_keylogs(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    oled_write_ln(read_timelog(), false);
  } else {
	#ifdef WPM_ENABLE
           if ( get_current_wpm() != 0 ) {
	       oled_write(wpm_state(), false);
             }
	   render_anim();
	#else
             oled_write(read_logo(), false);
             oled_scroll_left();  // Turns on scrolling
    #endif
  }
}
#endif
// OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
      switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
    }
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    set_timelog();
  }
  return true;
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
       if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
  }
#endif
