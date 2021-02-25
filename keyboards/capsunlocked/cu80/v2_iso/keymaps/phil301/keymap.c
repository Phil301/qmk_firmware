/*
Copyright 2021 CapsUnlocked

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Max delay between tap dance taps (ms)
// #define TAPPING_TERM 125

#include QMK_KEYBOARD_H

// Phil's QMK TODOs
// [x] RGB controls (super layer)
// [x] Volume controls (pscr-paus layer)
// [x] Move RESET to ctrl layer
// [x] Numpad on nav cluster (fn layer)
// [x] Enable Right control
// [x] Ctrl+alt+delete single key
// [ ] FN+Enter for Ctrl+Enter ?(send email)
// [ ] MS Teams mute? (Ctrl+Shift+M)

enum layers {
  L_DEFAULT,
  L_CTRL,
  L_FN,
  L_SUPER,
};

enum tap_dancing {
  // TD_MUTE_CAD,
  TD_MICMUTE_CAD,
  TD_F12_MUTE,
};

// Tap dance setup
qk_tap_dance_action_t tap_dance_actions[] = {
  // [TD_MUTE_CAD] = ACTION_TAP_DANCE_DOUBLE(KC_MUTE, LCTL(LALT(KC_DEL))),
  [TD_MICMUTE_CAD] = ACTION_TAP_DANCE_DOUBLE(LCTL(LSFT(KC_M)), LCTL(LALT(KC_DEL))),
  [TD_F12_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_MUTE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DEFAULT] = LAYOUT_tkl_iso(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  TD(TD_F12_MUTE),         KC_VOLD, KC_VOLU, TD(TD_MICMUTE_CAD),

    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,        KC_MINS,  KC_EQL,    KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,        KC_LBRC,  KC_RBRC,            KC_DEL,  KC_END,  KC_PGDN,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,     KC_QUOT,  KC_NUHS,   KC_ENT,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,      KC_SLSH,             KC_RSFT,          KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(L_SUPER), MO(L_FN), MO(L_CTRL),         KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [L_CTRL] = LAYOUT_tkl_iso(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       LCTL(KC_HOME), LCTL(KC_PGUP),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          LCTL(KC_DEL),  LCTL(KC_END),  LCTL(KC_PGDN),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______,                LCTL(KC_UP),
    _______, _______, _______,                   _______,                            _______, _______, _______, _______,          LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RGHT)
  ),
  [L_FN] = LAYOUT_tkl_iso(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,               KC_KP_7, KC_KP_8, KC_KP_9,

    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      KC_KP_4, KC_KP_5, KC_KP_6,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,               KC_KP_1, KC_KP_2, KC_KP_3,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LCTL(KC_ENT),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,               KC_KP_0,
    _______, _______, _______,                   _______,                            _______, _______, _______, _______,               _______, KC_NLCK, KC_SLCK
  ),
  [L_SUPER] = LAYOUT_tkl_iso(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RGB_M_P, RGB_M_B, RGB_M_R,

    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RGB_HUD, RGB_SAD, RGB_VAD,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
    _______, _______, _______,                   _______,                            _______, _______, _______, _______,          RGB_RMOD,RGB_TOG, RGB_MOD
  ),
};
