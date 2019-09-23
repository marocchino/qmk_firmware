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

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _NORMAN,
  _QWERTY,
  _SYMBOL,
  _LOWER
};

enum preonic_keycodes {
  NORMAN = SAFE_RANGE,
  QWERTY,
  SYMBOL,
  LOWER,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Norman
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   D  |   F  |   K  |   J  |   U  |   R  |   L  |   ;  | \    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl | S A  |   S  |   E  |   T  |   G  |   Y  |   N  |   I  |   O  |   H  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| S Z  |   X  |   C  |   V  |   B  |   P  |   M  |   ,  |   .  | / L  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Meh  |  Alt |   [  |   ]  |  Cmd |    Space    | Left | Down |  Up  |Right | Alt  |
 * `-----------------------------------------------------------------------------------'
 */
[_NORMAN] = {
  {KC_GRV,  KC_1,              KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                KC_BSPC},
  {KC_TAB,  KC_Q,              KC_W,    KC_D,    KC_F,    KC_K,    KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN,             KC_BSLS},
  {KC_LCTL, LT(_SYMBOL, KC_A), KC_S,    KC_E,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,                KC_ENT },
  {KC_LSFT, LT(_SYMBOL, KC_Z), KC_X,    KC_C,    KC_V,    KC_B,    KC_P,    KC_M,    KC_COMM, KC_DOT,  LT(_LOWER, KC_SLSH), KC_RSFT},
  {KC_HYPR, KC_LALT,           KC_LBRC, KC_RBRC, KC_LGUI, KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,             KC_RALT}
},
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | \    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl | S A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| S Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | / L  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Meh  |  Alt |   [  |   ]  |  Cmd |    Space    | Left | Down |  Up  |Right | Alt  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_GRV,  KC_1,              KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                KC_BSPC},
  {KC_TAB,  KC_Q,              KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                KC_BSLS},
  {KC_LCTL, LT(_SYMBOL, KC_A), KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,             KC_ENT },
  {KC_LSFT, LT(_SYMBOL, KC_Z), KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  LT(_LOWER, KC_SLSH), KC_RSFT},
  {KC_HYPR, KC_LALT,           KC_LBRC, KC_RBRC, KC_LGUI, KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,             KC_RALT}
},

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   -  |   =  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   h  |   j  |   k  |   l  |   '  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______},
  {_______, _______, _______, _______, _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  up  |      |      |      |      |      | RESET|      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | left | down | right|      |      |Qwerty|Norman|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | lclk | rclk |      |             | Back | Vol- | Vol+ | Play |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,       KC_F8,   KC_F9,   KC_F10,  _______},
  {_______, _______, KC_MS_U, _______, _______, _______, _______,     _______,     RESET,   KC_F11,  KC_F12,  _______},
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, DF(_QWERTY), DF(_NORMAN), _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______,     _______,     _______, _______, _______, _______},
  {_______, _______, KC_BTN1, KC_BTN2, _______, _______, _______,     KC_WBAK,     KC_VOLD, KC_VOLU, KC_MPLY, _______}
}
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

