OLED_DRIVER_ENABLE  = yes

RGBLIGHT_ENABLE = yes
AUTO_SHIFT_ENABLE = yes

# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
EXTRAFLAGS += -flto


# If you want to change the display of OLED, you need to change here
        # SRC +=  ./lib/glcdfont.c \
        #         ./lib/rgb_state_reader.c \
        #         ./lib/layer_state_reader.c \
        #         ./lib/logo_reader.c \
        #         ./lib/keylogger.c \
        #         # ./lib/mode_icon_reader.c \
        #         # ./lib/host_led_state_reader.c \
#         # ./lib/timelogger.c \
