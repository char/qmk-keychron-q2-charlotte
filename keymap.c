#include QMK_KEYBOARD_H

enum layers{
    BASE,
    _NAV,
    _EXT,
    FKEY
};

#define CAPS_FK LT(FKEY, KC_CAPS)
#define CAPS_EX TG(_EXT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_iso_68(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          KC_MPLY,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,                    KC_HOME,
        CAPS_FK, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_NUHS,  KC_ENT,           KC_END,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_NAV), KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT),

    [_NAV] = LAYOUT_iso_68(
        KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   KC_DELETE,       _______,
        KC_PSCR, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,                    KC_F23,
        CAPS_EX, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,          KC_F24,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______,  _______, _______, _______),

    [_EXT] = LAYOUT_iso_68(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
        _______, KC_INS,  KC_PGUP, KC_SCRL, _______, _______, _______, _______, _______, _______, _______, _______,  _______,                    _______,
        _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,          QK_BOOTLOADER,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______,  _______, _______, _______),

    [FKEY] = LAYOUT_iso_68(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,   _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,                    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______,  _______, _______, _______),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV] = { ENCODER_CCW_CW(_______, _______) },
    [_EXT] = { ENCODER_CCW_CW(_______, _______) },
    [FKEY] = { ENCODER_CCW_CW(_______, _______) }
};
#endif

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_rgb_purple);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_OFF(_NAV)) {
        if (IS_LAYER_ON(_EXT)) {
            layer_off(_EXT);
        }
    }

    return true;


}

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_user(uint8_t index, bool active) {
    // TODO: do something useful with the DIP switch?
    return false;
}
#endif

