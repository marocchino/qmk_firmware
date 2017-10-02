#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#define WINS 0 // wins
#define BASE 1 // default layer
#define MDIA 2 // media keys
#define SYMB 3 // symbol keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};
// macros
#define CPM M(0)
#define CPW M(1)
#define PRN M(2)
#define BRC M(3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Windows
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  6   |           |   7  |   8  |   9  |   0  |   -  |   =  | BkSp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  ()  |           |  {}  |   Y  |   U  |   I  |   O  |   P  | \|     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/FN | Enter  |
 * |--------+------+------+------+------+------|   -  |           |   =  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | //FN | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Hyper| LAlt |SftGui|   [  |   ]  |                                       | Left | Down |  Up  | Right|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ESC  | RAlt |       | '"   | L1   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 | LCtrl|Space |------|       |------|Space | RCtrl|
 *                                 |      |      | LAlt |       | RAlt |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[WINS] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,  KC_1,    KC_2,          KC_3,    KC_4,    KC_5,    KC_6,
        KC_TAB,  KC_Q,    KC_W,          KC_E,    KC_R,    KC_T,    PRN,
        KC_LCTL, KC_A,    KC_S,          KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,          KC_C,    KC_V,    KC_B,    KC_MINS,
        KC_HYPR, KC_LALT, LSFT(KC_LGUI), KC_LBRC, KC_RBRC,
                                                           KC_ESC,  KC_RALT,
                                                                    KC_LGUI,
                                                  KC_LCTL, KC_SPC,  KC_LALT,
        // right hand
        KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,            KC_BSPC,
        BRC,     KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,              KC_BSLS,
                 KC_H,     KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), KC_ENT,
        KC_EQL,  KC_N,     KC_M,    KC_COMM, KC_DOT,  LT(MDIA, KC_SLSH), KC_LSFT,
                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,           CPW,
        KC_QUOT, TG(BASE),
        KC_RGUI,
        KC_RALT, KC_SPC,   KC_RCTL
    ),
/* Keymap 1: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  6   |           |   7  |   8  |   9  |   0  |   -  |   =  | BkSp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  ()  |           |  {}  |   Y  |   U  |   I  |   O  |   P  | \|     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  | A/FN |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/FN | Enter  |
 * |--------+------+------+------+------+------|   -  |           |   =  |------+------+------+------+------+--------|
 * | LShift | Z/FN |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | //FN | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Hyper| LAlt |SftGui|   [  |   ]  |                                       | Left | Down |  Up  | Right| C&P  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ESC  |  Ja  |       | Dict | L1   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  Ko  |       | Dash |      |      |
 *                                 | LGui |Space |------|       |------|Space | RGui |
 *                                 |      |      |  En  |       | Spot |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,  KC_1,          KC_2,          KC_3,    KC_4,    KC_5,   KC_6,
        KC_TAB,  KC_Q,          KC_W,          KC_E,    KC_R,    KC_T,   PRN,
        KC_LCTL, LT(SYMB, KC_A),KC_S,          KC_D,    KC_F,    KC_G,
        KC_LSFT, LT(SYMB, KC_Z),KC_X,          KC_C,    KC_V,    KC_B,   KC_MINS,
        KC_HYPR, KC_LALT,       LSFT(KC_LGUI), KC_LBRC, KC_RBRC,
                                                                 KC_ESC, HYPR(KC_0),
                                                                         HYPR(KC_9),
                                                        KC_LGUI, KC_SPC, HYPR(KC_8),
        // right hand
        KC_7,         KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,            KC_BSPC,
        BRC,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,              KC_BSLS,
                      KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), KC_ENT,
        KC_EQL,       KC_N,    KC_M,    KC_COMM, KC_DOT,  LT(MDIA, KC_SLSH), KC_LSFT,
                               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,           CPM,
        HYPR(KC_D),   KC_TRNS,
        RCTL(KC_SPC),
        RGUI(KC_SPC), KC_SPC,  KC_RGUI
    ),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------| Left | Down |  Up  | Right|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       | Prev |VolDn |VolUp | Next | Mute |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |TEENSY|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(  // layer 2 : media
       KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_MPLY,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE,
       KC_TRNS, RESET,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: Symbol
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |   `    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |  [   |  ]   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |  ;:  |  '"  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[SYMB] = KEYMAP(  // layer 3 : symbol
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_SCLN, KC_QUOT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(MDIA),                // FN1 - Momentary Layer 1 (Media)
    [2] = ACTION_LAYER_TAP_TOGGLE(WINS),                // FN2 - Momentary Layer 2 (Windows)
    [3] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN3 - Momentary Layer 3 (Symbol)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    static uint16_t key_timer;
    // MACRODOWN only works in this function
    switch(id) {
      case 0:
        if (record->event.pressed) {
          key_timer = timer_read(); // if the key is being pressed, we start the timer.
        } else { // this means the key was just released, so we can figure out how long it was pressed for (tap or "held down").
          if (timer_elapsed(key_timer) > 150) { // 150 being 150ms, the threshhold we pick for counting something as a tap.
            return MACRO( D(LGUI), T(C), U(LGUI), END  );
          } else {
            return MACRO( D(LGUI), T(V), U(LGUI), END  );
          }
        }
        break;
      case 1:
        if (record->event.pressed) {
          key_timer = timer_read(); // if the key is being pressed, we start the timer.
        } else { // this means the key was just released, so we can figure out how long it was pressed for (tap or "held down").
          if (timer_elapsed(key_timer) > 150) { // 150 being 150ms, the threshhold we pick for counting something as a tap.
            return MACRO( D(LCTL), T(C), U(LCTL), END  );
          } else {
            return MACRO( D(LCTL), T(V), U(LCTL), END  );
          }
        }
        break;
      case 2:
        if (record->event.pressed) {
          key_timer = timer_read();
          register_code(KC_LSFT);
        } else if (timer_elapsed(key_timer) < 150) {
          register_code(KC_9);
          unregister_code(KC_9);
          register_code(KC_0);
          unregister_code(KC_0);
          unregister_code(KC_LSFT);
          register_code(KC_LEFT);
          unregister_code(KC_LEFT);
        } else {
          unregister_code(KC_LSFT);
        }
        break;
      case 3:
        if (record->event.pressed) {
          key_timer = timer_read();
          register_code(KC_LSFT);
        } else if (timer_elapsed(key_timer) < 150) {
          register_code(KC_LBRC);
          unregister_code(KC_LBRC);
          register_code(KC_RBRC);
          unregister_code(KC_RBRC);
          unregister_code(KC_LSFT);
          register_code(KC_LEFT);
          unregister_code(KC_LEFT);
        } else {
          unregister_code(KC_LSFT);
        }
        break;
    }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 0:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
