#include QMK_KEYBOARD_H
#include <stdio.h>

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define KC_EURO ALGR(KC_5)
// Mod-Tap key MT(mod, kc) acts like a modifier when held, and a regular keycode kc when tapped

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x6_3( 
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐

    KC_GRV   ,   KC_Q   ,   KC_W   ,    KC_E  ,    KC_R  ,    KC_T  ,                                        KC_Y  ,    KC_U  ,    KC_I  ,    KC_O  ,   KC_P   ,  KC_QUOTE,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 

  MT(MOD_LCTL,
  KC_ESC),       KC_A   ,    KC_S  ,    KC_D  ,    KC_F  ,    KC_G  ,                                        KC_H  ,    KC_J  ,    KC_K  ,    KC_L  , KC_SCLN, MT(MOD_RCTL, 
                                                                                                                                                                  KC_MINS),
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 

    MT(MOD_LGUI, 
       KC_TAB),  KC_Z   ,    KC_X  ,    KC_C  ,    KC_V  ,    KC_B  ,                                        KC_N  ,    KC_M  ,  KC_COMM ,  KC_DOT  , KC_SLSH  , KC_EQL,
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘       

                                               MT(MOD_LALT, 
                                                  KC_LGUI), KC_LSFT, 
                                                                      LT(_LOWER,
                                                                           KC_SPC),
                                                                                              LT(_RAISE, 
                                                                                                  KC_ENT), MT(MOD_RSFT, 
                                                                                                              KC_BSPC),  MT(MOD_RALT, 
                                                                                                                             KC_INS) \
                                            // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
 
  ),


  /* red Lower layer: http://www.keyboard-layout-editor.com/#/gists/c3fba5eaa2cd70fdfbdbc0f9e34d3bc0 */
  [_LOWER] = LAYOUT_split_3x6_3(
        KC_CAPS,   KC_EXLM,    KC_AT,     KC_HASH,  KC_DLR,    KC_PERC,                    KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
        KC_LCTL,  KC_KP_1,    KC_KP_2,   KC_KP_3,  KC_KP_4,   KC_KP_5,                    _______,  KC_PIPE,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_RCTL,
        KC_KP_0,  KC_KP_6,    KC_KP_7,   KC_KP_8,  KC_KP_9,   KC_KP_DOT,                  _______,  KC_BSLS,  KC_EQL,   KC_LBRC,  KC_RBRC,  _______,
                                                   _______,    KC_LSFT,  _______, MO(3),  KC_RSFT,  _______
    ),

  /* blu Raise layer: http://www.keyboard-layout-editor.com/#/gists/08b44355d4ca85d294bad9e2821f91d7 */
  [_RAISE] = LAYOUT_split_3x6_3(
        _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_INS,
        KC_LCTL,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F11,   KC_RCTL,
        _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                       KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_F12,   _______,
                                            _______ ,    KC_LSFT,      MO(3),  _______,  KC_RSFT,  _______

  ),

  /* Adjust layer: http://www.keyboard-layout-editor.com/#/gists/77e7572e077b36a23eb2086017e16fee */
  // [3] = LAYOUT(
  //       _______,  _______,  KC_MPLY,  KC_VOLU,  KC_MSTP,  _______,                      EEP_RST,  RESET,    _______,  _______,  _______,  RGB_TOG,
  //       _______,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,                      RGB_RMOD, RGB_VAD,  RGB_VAI,  RGB_MOD,  RGB_SPI,  _______,
  //       _______,  _______,  _______,  KC_MUTE,  _______,  _______,                      RGB_HUI,  RGB_SAD,  RGB_SAI,  RGB_HUD,  RGB_SPD,  _______,     
  //                                               _______,  _______,  _______,  _______,  _______,  _______
  // )

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EURO,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};



#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return rotation;
    }
}

void render_crkbd_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

#    define KEYLOG_LEN 5
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Lyout"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR(" QRTY"), false);
            break;
    }
}

void render_layer_state(void) {
    oled_write_P(PSTR("LAYER"), false);
    oled_write_P(PSTR("Lower"), layer_state_is(_LOWER));
    oled_write_P(PSTR("Raise"), layer_state_is(_RAISE));
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("Lock:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("C"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_ln_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("Mods:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_bootmagic_status(void) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    oled_write_P(PSTR("BTMGK"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(logo[0][0], !keymap_config.swap_lctl_lgui);
    oled_write_P(logo[1][0], keymap_config.swap_lctl_lgui);
    oled_write_P(PSTR(" "), false);
    oled_write_P(logo[0][1], !keymap_config.swap_lctl_lgui);
    oled_write_P(logo[1][1], keymap_config.swap_lctl_lgui);
    oled_write_P(PSTR(" NKRO"), keymap_config.nkro);
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_default_layer_state();
    render_keylock_status(host_keyboard_leds());
    render_mod_status(get_mods());
    render_bootmagic_status();

    render_keylogger_status();
}

void oled_task_user(void) {
    update_log();
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_crkbd_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode);
    }
    return true;
}
#endif
