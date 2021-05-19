# Build Options
#   change yes to no to disable
#
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes
ENCODER_ENABLE = yes        # Enable Encoder
OLED_DRIVER_ENABLE = yes     # Enable OLEDS display
WPM_ENABLE = yes             # Enable WPM Calculator
# After "OLED_DRIVE_ENABLE = yes",if you want to change the display of OLED, you need to change here
# Enable ".lib/wpm_bonggo.c" only when enable "WPM_ENABLE".
SRC +=  ./lib/layer_state_reader.c \
        ./lib/host_led_state_reader.c \
        ./lib/keylogger.c \
        ./lib/rgb_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/wpm_bonggo.c \
        ./lib/timelogger.c \
        ./lib/mode_icon_reader.c \
