#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#define BASE 0 // default layer
#define WINS 1 // wins
#define WINQ 2 // wins
#define WCTL 3 // wins control
#define MDIA 4 // media keys
#define SYMB 5 // symbol keys

//define modifiers
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

#define SYMB_Z LT(SYMB, KC_Z)
#define SYMB_A LT(SYMB, KC_A)
#define MDIA_SC LT(MDIA, KC_SCLN)
#define MDIA_SL LT(MDIA, KC_SLSH)
#define SFT_GUI LSFT(KC_LGUI)
#define _______ KC_TRNS

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  CPM,
  CPW,
  PRN,
  BRC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `      |   1  |   2  |   3  |   4  |   5  |  6   |           |   7  |   8  |   9  |   0  |   -  |   =  | BkSp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   D  |   F  |   K  |  ()  |           |  {}  |   J  |   U  |   R  |   L  |   ;  | \|     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  | A/FN |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  |   H  | Enter  |
 * |--------+------+------+------+------+------|   -  |           |   =  |------+------+------+------+------+--------|
 * | LShift | Z/FN |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |   ,  |   .  | //FN | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Hyper| LAlt |SftGui|   [  |   ]  |                                       | Left | Down |  Up  | Right| C&P  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ESC  |  Ja  |       | Dict | Wins |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  Ko  |       | Dash |      |      |
 *                                 | LGui |Space |------|       |------| BkSp | RGui |
 *                                 |      |      |  En  |       | Spot |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,
        KC_TAB,  KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,   PRN,
        KC_LCTL, SYMB_A,  KC_S,    KC_E,    KC_T,    KC_G,
        KC_LSFT, SYMB_Z,  KC_X,    KC_C,    KC_V,    KC_B,   KC_MINS,
        KC_HYPR, KC_LALT, SFT_GUI, KC_LBRC, KC_RBRC,
                                                     KC_ESC, HYPR(KC_0),
                                                             HYPR(KC_9),
                                            KC_LGUI, KC_SPC, HYPR(KC_8),
        // right hand
        KC_7,         KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        BRC,          KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN, KC_BSLS,
                      KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,    KC_ENT,
        KC_EQL,       KC_P,    KC_M,    KC_COMM, KC_DOT,  MDIA_SL, KC_LSFT,
                               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CPM,
        HYPR(KC_D),   DF(WINS),
        RCTL(KC_SPC),
        RGUI(KC_SPC), KC_BSPC, KC_RGUI
    ),
/* [BASE_QUERY] = LAYOUT_ergodox( */
/*         // left hand */
/*         KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6, */
/*         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   PRN, */
/*         KC_LCTL, SYMB_A,  KC_S,    KC_D,    KC_F,    KC_G, */
/*         KC_LSFT, SYMB_Z,  KC_X,    KC_C,    KC_V,    KC_B,   KC_MINS, */
/*         KC_HYPR, KC_LALT, SFT_GUI, KC_LBRC, KC_RBRC, */
/*                                                      KC_ESC, HYPR(KC_0), */
/*                                                              HYPR(KC_9), */
/*                                             KC_LGUI, KC_SPC, HYPR(KC_8), */
/*         // right hand */
/*         KC_7,         KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, */
/*         BRC,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, */
/*                       KC_H,    KC_J,    KC_K,    KC_L,    MDIA_SC, KC_ENT, */
/*         KC_EQL,       KC_N,    KC_M,    KC_COMM, KC_DOT,  MDIA_SL, KC_LSFT, */
/*                                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CPM, */
/*         HYPR(KC_D),   DF(WINS), */
/*         RCTL(KC_SPC), */
/*         RGUI(KC_SPC), KC_BSPC, KC_RGUI */
/*     ), */
/* Keymap 1: Windows
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `      |   1  |   2  |   3  |   4  |   5  |  6   |           |   7  |   8  |   9  |   0  |   -  |   =  | BkSp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   D  |   F  |   K  |  ()  |           |  {}  |   J  |   U  |   R  |   L  |   ;  | \|     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  | H/FN | Enter  |
 * |--------+------+------+------+------+------|   -  |           |   =  |------+------+------+------+------+--------|
 * | LShift | Z/FN |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |   ,  |   .  | //FN | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Hyper| LAlt |SftGui|   [  |   ]  |                                       | Left | Down |  Up  | Right|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ESC  | RAlt |       |Qwerty| Base |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 | LAlt |Space |------|       |------| BkSp | WCtl |
 *                                 |      |      | Lang |       | RAlt |      |      |
 *                                 `--------------------'       `--------------------'
 */
[WINS] = LAYOUT_ergodox(
        // left hand
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        KC_TAB,  KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    PRN,
        KC_LCTL, KC_A,    KC_S,    KC_E,    KC_T,    KC_G,
        KC_LSFT, SYMB_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,
        KC_HYPR, KC_LALT, SFT_GUI, KC_LBRC, KC_RBRC,
                                                     KC_ESC,  KC_RALT,
                                                              KC_LGUI,
                                            KC_LALT, KC_SPC,  LALT(KC_LSFT),
        // right hand
        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        BRC,     KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN, KC_BSLS,
                 KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,    KC_ENT,
        KC_EQL,  KC_P,    KC_M,    KC_COMM, KC_DOT,  MDIA_SL, KC_LSFT,
                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CPW,
        DF(WINQ), DF(BASE),
        KC_RGUI,
        KC_RALT,  KC_BSPC, MO(WCTL)
    ),
/* Keymap 2: Basic Qwerty layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `      |   1  |   2  |   3  |   4  |   5  |  6   |           |   7  |   8  |   9  |   0  |   -  |   =  | BkSp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  ()  |           |  {}  |   Y  |   U  |   I  |   O  |   P  | \|     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|   -  |           |   =  |------+------+------+------+------+--------|
 * | LShift | Z/FN |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | //FN | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Hyper| LAlt |SftGui|   [  |   ]  |                                       | Left | Down |  Up  | Right| C&P  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ESC  | RAlt |       | '"   | Base |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 | LAlt |Space |------|       |------| BkSp | WCtl |
 *                                 |      |      | Lang |       | RAlt |      |      |
 *                                 `--------------------'       `--------------------'
 */
[WINQ] = LAYOUT_ergodox(
        // left hand
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    PRN,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, SYMB_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,
        KC_HYPR, KC_LALT, SFT_GUI, KC_LBRC, KC_RBRC,
                                                     KC_ESC,  KC_RALT,
                                                              KC_LGUI,
                                            KC_LALT, KC_SPC,  LALT(KC_LSFT),
        // right hand
        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        BRC,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  MDIA_SL, KC_LSFT,
                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CPW,
        DF(WINS), DF(BASE),
        KC_RGUI,
        KC_RALT,  KC_BSPC, MO(WCTL)
    ),

/* Keymap 3: Windows Control
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Close|      |Reload| NTab |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | All  | Save | Find |      |      |------|           |------|      |      |      | Loc  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Undo | Cut  | Copy | Paste|      |      |           |      | NWin |      | Conf |      |      |        |
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
[WCTL] = LAYOUT_ergodox(
        // left hand
        _______,      LALT(KC_1),  LALT(KC_2),  LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6),
        LALT(KC_TAB), _______, LCTL(KC_F4), _______,    KC_F5,      LCTL(KC_T), _______,
        _______,      LCTL(KC_A),  LCTL(KC_S),  _______,    KC_F3,      _______,
        _______,      LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C), LCTL(KC_V), _______,    _______,
        _______,      _______,     _______,     _______,    _______,
                                                         _______, _______,
                                                                  _______,
                                                _______, _______, _______,
        // right hand
        _______, _______,    _______, _______, _______,    _______, _______,
        _______, _______,    _______, _______, _______,    _______, _______,
                 _______,    _______, _______, LCTL(KC_L), _______, _______,
        _______, LCTL(KC_N), _______, KC_F10,  _______,    _______, _______,
                             _______, _______, _______,    _______, _______,
        _______, _______,
        _______,
        _______, _______,  _______
    ),

/* Keymap 4: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
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
 *                                 |      |      |      |       |      |Brwser|      |
 *                                 |      |      |------|       |------|Back  |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       _______, _______, KC_MS_U, _______, _______, _______, _______,
       _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_BTN1, KC_BTN2,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
       _______, _______, _______, _______, _______, _______, _______,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_MPLY,
       _______, _______, _______, _______, _______, _______, _______,
                         KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE,
       _______, RESET,
       _______,
       _______, KC_WBAK, _______
),
/* Keymap 5: Symbol
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |  [{  |  ]}  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  H   |  J   |  K   |  L   |  '"  |        |
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
[SYMB] = LAYOUT_ergodox(
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,
        // right hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______,
                 KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______,  _______
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(MDIA),                // FN1 - Momentary Layer 1 (Media)
    [2] = ACTION_LAYER_TAP_TOGGLE(WINS),                // FN2 - Momentary Layer 2 (Windows)
    [3] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN3 - Momentary Layer 3 (Symbol)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t key_timer;
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
    case CPM:
      if (record->event.pressed) {
        key_timer = timer_read();
      } else if (timer_elapsed(key_timer) > 150) {
        SEND_STRING (SS_LGUI("c"));
      } else {
        SEND_STRING (SS_LGUI("v"));
      }
      return false;
      break;
    case CPW:
      if (record->event.pressed) {
        key_timer = timer_read();
      } else if (timer_elapsed(key_timer) > 150) {
        SEND_STRING (SS_LCTRL("c"));
      } else {
        SEND_STRING (SS_LCTRL("v"));
      }
      return false;
      break;
    case PRN:
      if (record->event.pressed) {
        key_timer = timer_read();
        SEND_STRING (SS_DOWN(X_LSHIFT));
      } else if (timer_elapsed(key_timer) < 150) {
        SEND_STRING (SS_UP(X_LSHIFT) "()" SS_TAP(X_LEFT));
      } else {
        SEND_STRING (SS_UP(X_LSHIFT));
      }
      return false;
      break;
    case BRC:
      if (record->event.pressed) {
        key_timer = timer_read();
        SEND_STRING (SS_DOWN(X_RSHIFT));
      } else if (timer_elapsed(key_timer) < 150) {
        SEND_STRING (SS_UP(X_RSHIFT)"{}"SS_TAP(X_LEFT));
      } else {
        SEND_STRING (SS_UP(X_RSHIFT));
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

    uint8_t modifiders = get_mods();
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case WCTL:
      case SYMB:
        ergodox_right_led_2_on();
        break;
      case MDIA:
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    if ( modifiders & MODS_GUI_MASK) {
      ergodox_right_led_1_on();
    }
    if ( modifiders & MODS_CTRL_MASK) {
      ergodox_right_led_2_on();
    }
    if ( modifiders & MODS_ALT_MASK) {
      ergodox_right_led_3_on();
    }
};
