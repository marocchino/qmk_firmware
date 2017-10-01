/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

// macros
#define CPM M(0)
#define CPW M(1)
#define PRN M(2)
#define BRC M(3)

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _SYMBOL,
  _ADJUST
};

enum planck_keycodes {
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | \    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl | S A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ; L  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| S Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | / L  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Hyper| Alt  |   [  |   ]  | GUI  |    Space    | Left | Down |  Up  |Right |RAISE |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,              KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                KC_BSLS},
  {KC_LCTL, LT(_SYMBOL, KC_A), KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,             KC_ENT },
  {PRN,     LT(_SYMBOL, KC_Z), KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  LT(_LOWER, KC_SLSH), BRC},
  {KC_HYPR, KC_LALT,           KC_LBRC, KC_RBRC, KC_LGUI, KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,             RAISE}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BkSp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  ESC |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | BKSP |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   -  |   =  |  `   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   '  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_GRV },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  up  |      | RESET|      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | left | down | right|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | lclk | rclk |      |             | Back | Vol- | Vol+ | Play |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, _______, KC_MS_U, _______, RESET,   _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, KC_WBAK, KC_VOLD, KC_VOLU, KC_MPLY, _______}
}
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}

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
