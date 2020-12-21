#include QMK_KEYBOARD_H


// #ifdef RGBLIGHT_ENABLE
// //Following line allows macro to read current RGB settings
// extern rgblight_config_t rgblight_config;
// #endif

// extern uint8_t is_master;

// // Each layer gets a name for readability, which is then used in the keymap matrix below.
// // The underscores don't mean anything - you can have a layer called STUFF or any other name.
// // Layer names don't all need to be of the same length, obviously, and you can also skip them
// // entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   ADJUST,
//   BACKLIT,
//   RGBRST
// };

// enum macro_keycodes {
//   KC_SAMPLEMACRO,
// };

//#define LY_LWR MO(_LOWER)
//#define LY_RSE MO(_RAISE)

// ESC when tapped and Left Control when held  (see TAPPING_TERM in config.h)
#define ESC_LCTL LCTL_T(KC_ESC)

// SUPER when tapped and Left ALT when held
//#define KY_SUPER_LALT ALT_T(KC_LGUI)

// Mod-Tap key MT(mod, kc) acts like a modifier when held, and a regular keycode kc when tapped

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |Tab     |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/ESC|   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+                              +------+------+------+------+------+--------|
 * | Gui    |   Z  |   X  |   C  |   V  |   B  |                              |   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+                +------+------+------+------+----------------------'
 *                               | Cmd  |Shift | Space|                | Enter|Shift |AltGr |
 *                               | Alt  |      | Lower|                | Raise|      |      |
 *                               ----------------------                ----------------------
 */
  [0] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOTE,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     ESC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            MT(MOD_LALT, KC_LGUI), KC_LSFT,LT(_LOWER,KC_SPC),\
                                                                      LT(_RAISE, KC_ENT), KC_RSFT,  KC_ALGR \
                                      //`--------------------------'  `--------------------------'

  ),


// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   [_QWERTY] = LAYOUT(
//         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
//         KY_ESC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
//         KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
//                                                 MT(MOD_LALT, KC_LGUI),  LOWER,LT(_LOWER, KC_SPC),KC_ENT,   RAISE,   KC_ALGR
//     ),

  /* Lower layer: http://www.keyboard-layout-editor.com/#/gists/c3fba5eaa2cd70fdfbdbc0f9e34d3bc0 */
  [1] = LAYOUT(
        _______,   KC_EXLM,    KC_AT,     KC_HASH,  KC_DLR,    KC_PERC,                    KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
        _______,  KC_KP_1,    KC_KP_2,   KC_KP_3,  KC_KP_4,   KC_KP_5,                    KC_PIPE,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  _______,
        KC_KP_0,  KC_KP_6,    KC_KP_7,   KC_KP_8,  KC_KP_9,   KC_KP_DOT,                  KC_BSLS,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_CAPS,
                                                   _______,    KC_LSFT,  _______, MO(3),  KC_RSFT,  _______
    ),

  /* Raise layer: http://www.keyboard-layout-editor.com/#/gists/08b44355d4ca85d294bad9e2821f91d7 */
  [2] = LAYOUT(
        _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_INS,
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F11,   _______,
        _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                       KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_F12,   _______,
                                              KC_LGUI,  KC_LSFT,      MO(3),  _______,  KC_RSFT,  _______

  ),

  /* Adjust layer: http://www.keyboard-layout-editor.com/#/gists/77e7572e077b36a23eb2086017e16fee */
  // [3] = LAYOUT(
  //       _______,  _______,  KC_MPLY,  KC_VOLU,  KC_MSTP,  _______,                      EEP_RST,  RESET,    _______,  _______,  _______,  RGB_TOG,
  //       _______,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,                      RGB_RMOD, RGB_VAD,  RGB_VAI,  RGB_MOD,  RGB_SPI,  _______,
  //       _______,  _______,  _______,  KC_MUTE,  _______,  _______,                      RGB_HUI,  RGB_SAD,  RGB_SAI,  RGB_HUD,  RGB_SPD,  _______,     
  //                                               _______,  _______,  _______,  _______,  _______,  _______
  // )

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
   return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_render_slave(void) {
  oled_write_P(PSTR("SCIPIO"), false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
        //oled_render_slave();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE


// int RGB_current_mode;

// void persistent_default_layer_set(uint16_t default_layer) {
//   eeconfig_update_default_layer(default_layer);
//   default_layer_set(default_layer);
// }

// // Setting ADJUST layer RGB back to default
// void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
//   if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
//     layer_on(layer3);
//   } else {
//     layer_off(layer3);
//   }
// }

// void matrix_init_user(void) {
//     #ifdef RGBLIGHT_ENABLE
//       RGB_current_mode = rgblight_config.mode;
//     #endif
//     //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
//     #ifdef SSD1306OLED
//         iota_gfx_init(!has_usb());   // turns on the display
//     #endif
// }

// //SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
// #ifdef SSD1306OLED

// // When add source files to SRC in rules.mk, you can use functions.
// const char *read_layer_state(void);
// const char *read_logo(void);
// void set_keylog(uint16_t keycode, keyrecord_t *record);
// const char *read_keylog(void);
// const char *read_keylogs(void);

// // const char *read_mode_icon(bool swap);
// // const char *read_host_led_state(void);
// // void set_timelog(void);
// // const char *read_timelog(void);

// void matrix_scan_user(void) {
//    iota_gfx_task();
// }

// void matrix_render_user(struct CharacterMatrix *matrix) {
//   if (is_master) {
//     // If you want to change the display of OLED, you need to change here
//     matrix_write_ln(matrix, read_layer_state());
//     matrix_write_ln(matrix, read_keylog());
//     //matrix_write_ln(matrix, read_keylogs());
//     //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
//     //matrix_write_ln(matrix, read_host_led_state());
//     //matrix_write_ln(matrix, read_timelog());
//   } else {
//     matrix_write(matrix, read_logo());
//   }
// }

// void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
//   if (memcmp(dest->display, source->display, sizeof(dest->display))) {
//     memcpy(dest->display, source->display, sizeof(dest->display));
//     dest->dirty = true;
//   }
// }

// void iota_gfx_task_user(void) {
//   struct CharacterMatrix matrix;
//   matrix_clear(&matrix);
//   matrix_render_user(&matrix);
//   matrix_update(&display, &matrix);
// }
// #endif//SSD1306OLED

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
// #ifdef SSD1306OLED
//     set_keylog(keycode, record);
// #endif
//     // set_timelog();
//   }

//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//         persistent_default_layer_set(1UL<<_QWERTY);
//       }
//       return false;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//         update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_RAISE);
//         update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//     case ADJUST:
//         if (record->event.pressed) {
//           layer_on(_ADJUST);
//         } else {
//           layer_off(_ADJUST);
//         }
//         return false;
//     case RGB_MOD:
//       #ifdef RGBLIGHT_ENABLE
//         if (record->event.pressed) {
//           rgblight_mode(RGB_current_mode);
//           rgblight_step();
//           RGB_current_mode = rgblight_config.mode;
//         }
//       #endif
//       return false;
//     case RGBRST:
//       #ifdef RGBLIGHT_ENABLE
//         if (record->event.pressed) {
//           eeconfig_update_rgblight_default();
//           rgblight_enable();
//           RGB_current_mode = rgblight_config.mode;
//         }
//       #endif
//       break;
//   }
//   return true;
// }
