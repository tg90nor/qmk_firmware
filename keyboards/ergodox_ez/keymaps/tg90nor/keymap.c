#include QMK_KEYBOARD_H
#include "ergodox_ez/ergodox_ez.h"
#include "ergodox_ez/config.h"
#include "version.h"
#include "process_key_override.h"
#include "os_detection.h"

enum layers {
    _DVOR,
    _QWER,
    _RNUM,
    _LNUM,
    _RMOU,
    _LMOU,
    _PROG,
    _FUNC,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    TROW,
    _D_LEFT,
    _D_RGHT,
};

const key_override_t **key_overrides = (const key_override_t *[]){
    &ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, KC_MUTE),
    &ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN),
    &ko_make_basic(MOD_MASK_SHIFT, KC_HOME, KC_RPRN),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_DLR, KC_TILD, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS, (1 << _PROG)),
    // KC_AMPR        ,KC_PERC        ,KC_QUES        ,KC_PIPE        ,KC_CIRC
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_AMPR, KC_1, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_PERC, KC_2, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_QUES, KC_3, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_PIPE, KC_4, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_CIRC, KC_5, (1 << _PROG)),
    // KC_EQL         ,KC_ASTR        ,KC_TILD        ,KC_PLUS        ,KC_EXLM
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_EQL, KC_6, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_ASTR, KC_7, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_TILD, KC_8, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_PLUS, KC_9, (1 << _PROG)),
    &ko_make_with_layers(MOD_MASK_SHIFT, KC_EXLM, KC_0, (1 << _PROG)),
    NULL // Null terminate the array of overrides!
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DVOR] = LAYOUT_ergodox(
//left
    KC_GRV          ,KC_1           ,KC_2           ,KC_3           ,KC_4           ,KC_5           ,_D_LEFT        ,
    KC_TAB          ,KC_SCLN        ,KC_COMM        ,KC_DOT         ,KC_P           ,KC_Y           ,KC_LBRC        ,
    KC_LCTL         ,KC_A           ,KC_O           ,KC_E           ,KC_U           ,KC_I           ,
    KC_LSFT         ,KC_QUOT        ,KC_Q           ,KC_J           ,KC_K           ,KC_X           ,KC_SLSH        ,
    DF(_QWER)       ,KC_LGUI        ,KC_LALT        ,KC_LEFT        ,KC_UP          ,
                     KC_VOLD        ,KC_VOLU        ,
                                     KC_MEH         ,
    KC_SPC          ,KC_BSPC        ,KC_PGUP        ,
//right
    _D_RGHT         ,KC_6           ,KC_7           ,KC_8           ,KC_9           ,KC_0           ,KC_EQL         ,
    KC_RBRC         ,KC_F           ,KC_G           ,KC_C           ,KC_R           ,KC_L           ,KC_AT          ,
                     KC_D           ,KC_H           ,KC_T           ,KC_N           ,KC_S           ,KC_MINS        ,
    KC_BSLS         ,KC_B           ,KC_M           ,KC_W           ,KC_V           ,KC_Z           ,KC_ESC         ,
                                     KC_DOWN        ,KC_RIGHT       ,KC_HOME        ,KC_END         ,TROW           ,
    KC_RCTL         ,KC_INS         ,
    KC_RALT         ,
    KC_PGDN         ,KC_DEL         ,KC_ENT
),
[_QWER] = LAYOUT_ergodox(
//left
    KC_GRV          ,KC_1           ,KC_2           ,KC_3           ,KC_4           ,KC_5           ,_D_LEFT        ,
    KC_TAB          ,KC_Q           ,KC_W           ,KC_E           ,KC_R           ,KC_T           ,KC_LBRC        ,
    KC_LCTL         ,KC_A           ,KC_S           ,KC_D           ,KC_F           ,KC_G           ,
    KC_LSFT         ,KC_Z           ,KC_X           ,KC_C           ,KC_V           ,KC_B           ,KC_QUOT        ,
    DF(_DVOR)       ,KC_LGUI        ,KC_LALT        ,KC_LEFT        ,KC_UP          ,
                     KC_VOLD        ,KC_VOLU        ,
                                     KC_MEH         ,
    KC_SPC          ,KC_BSPC        ,KC_PGUP        ,
//right
    _D_RGHT         ,KC_6           ,KC_7           ,KC_8           ,KC_9           ,KC_0           ,KC_MINS        ,
    KC_RBRC         ,KC_Y           ,KC_U           ,KC_I           ,KC_O           ,KC_P           ,KC_EQL         ,
                     KC_H           ,KC_J           ,KC_K           ,KC_L           ,KC_SCLN        ,KC_AT          ,
    KC_BSLS         ,KC_N           ,KC_M           ,KC_COMM        ,KC_DOT         ,KC_SLSH        ,KC_ESC         ,
                                     KC_DOWN        ,KC_RIGHT       ,KC_HOME        ,KC_END         ,TROW           ,
    KC_RCTL         ,KC_INS         ,
    KC_RALT         ,
    KC_PGDN         ,KC_DEL         ,KC_ENT
),
[_PROG] = LAYOUT_ergodox(
//left
    KC_DLR          ,KC_AMPR        ,KC_PERC        ,KC_QUES        ,KC_PIPE        ,KC_CIRC        ,_______        ,
    _______         ,_______        ,_______        ,_______        ,_______        ,_______        ,KC_LCBR        ,
    _______         ,_______        ,_______        ,_______        ,_______        ,_______        ,
    _______         ,_______        ,_______        ,_______        ,_______        ,_______        ,KC_LPRN        ,
    _______         ,_______        ,_______        ,_______        ,_______        ,
                     _______        ,_______        ,
                                     _______        ,
    _______         ,_______        ,_______        ,
//right
    _______         ,KC_EQL         ,KC_ASTR        ,KC_TILD        ,KC_PLUS        ,KC_EXLM        ,KC_HASH        ,
    KC_LBRC         ,_______        ,_______        ,_______        ,_______        ,_______        ,KC_AT          ,
                     _______        ,_______        ,_______        ,_______        ,_______        ,KC_MINS        ,
    KC_SLSH         ,_______        ,_______        ,_______        ,_______        ,_______        ,_______        ,
                                     _______        ,_______        ,_______        ,_______        ,_______        ,
    _______         ,_______        ,
    _______         ,
    _______         ,_______        ,_______
),
[_FUNC] = LAYOUT_ergodox(
//left
    KC_ESC          ,KC_F1          ,KC_F2          ,KC_F3          ,KC_F4          ,KC_F5          ,KC_F6          ,
    _______         ,_______        ,_______        ,_______        ,_______        ,_______        ,_______        ,
    _______         ,_______        ,_______        ,_______        ,_______        ,_______        ,
    _______         ,_______        ,_______        ,_______        ,_______        ,_______        ,_______        ,
    _______         ,_______        ,_______        ,_______        ,_______        ,
                     _______        ,_______        ,
                                     _______        ,
    _______         ,_______        ,_______        ,
//right
    KC_F7           ,KC_F8          ,KC_F9          ,KC_F10         ,KC_F11         ,KC_F12         ,VRSN           ,
    _______         ,_______        ,_______        ,_______        ,_______        ,_______        ,_______        ,
                     _______        ,_______        ,_______        ,_______        ,_______        ,QK_BOOT        ,
    _______         ,_______        ,_______        ,_______        ,_______        ,_______        ,KC_GRV         ,
                                     _______        ,_______        ,_______        ,_______        ,_______        ,
    _______         ,_______        ,
    _______         ,
    _______         ,_______        ,_______
),
};
// clang-format on

void process_hostos_keycode(uint16_t keycode, keyrecord_t *record) {
  uint8_t host_os = detected_host_os();
  uint16_t keycode_to_press = KC_NO;
  if (host_os == OS_MACOS || host_os == OS_IOS) {
    switch (keycode) {
      case _D_LEFT:
        keycode_to_press = C(KC_LEFT);
        break;
      case _D_RGHT:
        keycode_to_press = C(KC_RGHT);
        break;
    }
  } else {
    switch (keycode) {
      case _D_LEFT:
        keycode_to_press = LSG(KC_LEFT);
        break;
      case _D_RGHT:
        keycode_to_press = LSG(KC_RGHT);
        break;
    }
  }
  if (record->event.pressed) {
    register_code16(keycode_to_press);
  } else {
    unregister_code16(keycode_to_press);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            }
        case TROW:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    layer_invert(_FUNC);
                    return false;
                } else {
                    layer_invert(_PROG);
                    return false;
                }
            }
        case _D_LEFT:
            process_hostos_keycode(keycode, record);
            return false;
        case _D_RGHT:
            process_hostos_keycode(keycode, record);
            return false;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_right_led_1_set(100);
    ergodox_right_led_2_set(80);
    ergodox_right_led_3_set(80);

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
            break;
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            default_layer_state_set_user(default_layer_state);
            break;
    }

    return state;
};

layer_state_t default_layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    switch (layer) {
    case 0:
        ergodox_right_led_1_off();
        ergodox_right_led_2_off();
        ergodox_right_led_3_off();
        break;
    case 1:
        ergodox_right_led_1_on();
        ergodox_right_led_2_off();
        ergodox_right_led_3_off();
        break;
    default:
        break;
    }
    return state;
};
