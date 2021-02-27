#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI | Alt  | App  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
                   KC_Q     , KC_1 , KC_2 , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 ,KC_MINS,KC_EQL,KC_BSPC,KC_BSPC,KC_DEL, \
 KC_Q , KC_W ,     KC_TAB   , KC_Q , KC_W , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I , KC_O , KC_P ,KC_LBRC,KC_RBRC,       KC_BSLS,KC_HOME, \
 KC_Q , KC_W ,     KC_CAPS  , KC_A , KC_S , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K , KC_L , KC_SCLN,KC_QUOT,    KC_ENTER,KC_PGUP, \
 KC_Q , KC_W ,     KC_LSFT  ,KC_NUBS,KC_Z , KC_X , KC_C , KC_V , KC_B , KC_N , KC_M ,KC_COMM,KC_DOT,KC_SLSH , KC_RSFT,   KC_UP   ,KC_PGDN, \
 KC_Q , KC_W ,     KC_LCTL  ,KC_LGUI,KC_LALT,   KC_SPC,         KC_SPC,        KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT,KC_DOWN  ,KC_RGHT
  ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
                       KC_Q     , KC_1 , KC_2 , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 ,KC_MINS,KC_EQL,KC_BSPC,KC_BSPC,KC_DEL, \
 KC_Q , KC_W ,     KC_TAB   , KC_Q , KC_W , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I , KC_O , KC_P ,KC_LBRC,KC_RBRC,       KC_BSLS,KC_HOME, \
 KC_Q , KC_W ,     KC_CAPS  , KC_A , KC_S , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K , KC_L , KC_SCLN,KC_QUOT,    KC_ENTER,KC_PGUP, \
 KC_Q , KC_W ,     KC_LSFT  ,KC_NUBS,KC_Z , KC_X , KC_C , KC_V , KC_B , KC_N , KC_M ,KC_COMM,KC_DOT,KC_SLSH , KC_RSFT,   KC_UP   ,KC_PGDN, \
 KC_Q , KC_W ,     KC_LCTL  ,KC_LGUI,KC_LALT,   KC_SPC,         KC_SPC,        KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT,KC_DOWN  ,KC_RGHT
  ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
                   KC_Q     , KC_1 , KC_2 , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 ,KC_MINS,KC_EQL,KC_BSPC,KC_BSPC,KC_DEL, \
 KC_Q , KC_W ,     KC_TAB   , KC_Q , KC_W , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I , KC_O , KC_P ,KC_LBRC,KC_RBRC,       KC_BSLS,KC_HOME, \
 KC_Q , KC_W ,     KC_CAPS  , KC_A , KC_S , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K , KC_L , KC_SCLN,KC_QUOT,    KC_ENTER,KC_PGUP, \
 KC_Q , KC_W ,     KC_LSFT  ,KC_NUBS,KC_Z , KC_X , KC_C , KC_V , KC_B , KC_N , KC_M ,KC_COMM,KC_DOT,KC_SLSH , KC_RSFT,   KC_UP   ,KC_PGDN, \
 KC_Q , KC_W ,     KC_LCTL  ,KC_LGUI,KC_LALT,   KC_SPC,         KC_SPC,        KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT,KC_DOWN  ,KC_RGHT
  ),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |R Tog |R Mode|R Rev |R Grad| Reset|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |R  HUI|R  SAI|R  VAI|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |R  HUD|R  SAD|R  VAD|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT(
                    KC_Q     , KC_1 , KC_2 , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 ,KC_MINS,KC_EQL,KC_BSPC,KC_BSPC,KC_DEL, \
 KC_Q , KC_W ,     KC_TAB   , KC_Q , KC_W , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I , KC_O , KC_P ,KC_LBRC,KC_RBRC,       KC_BSLS,KC_HOME, \
 KC_Q , KC_W ,     KC_CAPS  , KC_A , KC_S , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K , KC_L , KC_SCLN,KC_QUOT,    KC_ENTER,KC_PGUP, \
 KC_Q , KC_W ,     KC_LSFT  ,KC_NUBS,KC_Z , KC_X , KC_C , KC_V , KC_B , KC_N , KC_M ,KC_COMM,KC_DOT,KC_SLSH , KC_RSFT,   KC_UP   ,KC_PGDN, \
 KC_Q , KC_W ,     KC_LCTL  ,KC_LGUI,KC_LALT,   KC_SPC,         KC_SPC,        KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT,KC_DOWN  ,KC_RGHT
  )

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
