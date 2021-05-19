#include QMK_KEYBOARD_H
#include <stdio.h>

#ifdef RGBLIGHT_ENABLE
char rbf_info_str[24];
const char *read_rgb_info(void) {

  snprintf(rbf_info_str, sizeof(rbf_info_str), "%s %2d h%3d s%3d v%3d",
    rgblight_is_enabled() ? "on" : "- ", rgblight_get_mode(),
    rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val());
  return rbf_info_str;
}
#endif

#ifdef RGB_MATRIX_ENABLE
char rbf_matrix_info_str[24];
const char *read_rgb_matrix_info(void) {

  snprintf(rbf_matrix_info_str, sizeof(rbf_matrix_info_str), "%s %2d h%3d s%3d v%3d",
    rgb_matrix_is_enabled() ? "on" : "- ", rgb_matrix_get_mode(),
    rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val());
  return rbf_matrix_info_str;
}
#endif
