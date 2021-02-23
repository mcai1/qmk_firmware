/* Copyright 2020 Boardsource
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_all(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, RGB_TOG,
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, RGB_MOD,
		KC_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  MO(_FN),
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,          KC_UP,
		KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,           KC_SPC,           KC_SPC,           KC_LALT, KC_LCTL, KC_GRV,  KC_LEFT, KC_DOWN, KC_RGHT
	),
[_FN] = LAYOUT_all(
  KC_GRV,      KC_F1,     KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     _______,    _______,    KC_HOME,
  KC_NO,                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_MPLY,    KC_NO,      KC_NO,      KC_NO,      KC_END,
  RESET,                  KC_NO,      KC_NO,      KC_NO,      KC_NO,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,
  KC_NO,      KC_NO,      KC_F5,      KC_MPLY,      KC_NO,      KC_NO,    _______,    _______,    KC_MUTE,    _______,    _______,    _______,    _______,                KC_VOLU,
  _______,    _______,    _______,                _______,                _______,                _______,                _______,    _______,    _______,    KC_MPRV,    KC_VOLD,    KC_MNXT
)


};

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
    {0, 6, HSV_PURPLE},       // Light 4 LEDs, starting with LED 6
    {12, 4, HSV_PURPLE}       // Light 4 LEDs, starting with LED 12
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
    rgblight_sethsv_azure();
}