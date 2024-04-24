/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------.   ,----------------------------------------------------------------------------------------------------|.
    KC_TAB, KC_Q              , KC_W             , KC_E             , KC_R             , KC_T      , KC_Y, KC_U             , KC_I             , KC_O             , KC_P                , KC_BSPC       ,
  //|------+------------------+------------------+------------------+------------------+------|    |-----+------------------+------------------+------------------+---------------------+---------------|
    KC_LSFT, MT(MOD_LGUI,KC_A), MT(MOD_LALT,KC_S), MT(MOD_LCTL,KC_D), MT(MOD_LSFT,KC_F), KC_G      , KC_H, MT(MOD_RSFT,KC_J), MT(MOD_RCTL,KC_K), MT(MOD_RALT,KC_L), MT(MOD_RGUI,KC_SCLN), LSFT(KC_MINUS),
  //|------+-----------------+-------------------+------------------+------------------+------|    |-----+------------------+------------------+------------------+---------------------+---------------|
    KC_LCTL, KC_Z             , KC_X             , KC_C             , KC_V             , KC_B      , KC_N, KC_M             , KC_COMM          ,  KC_DOT          , KC_SLSH             ,  KC_MINUS,
  //|------+-----------------+-------------------+------------------+------------------+------|    |-----+------------------+------------------+------------------+---------------------+---------------|
                                                  MT(MOD_LALT, KC_ESC),MO(1), MT(MOD_LSFT, KC_ENTER),    KC_SPC,MO(2), KC_RALT
                                               //`--------------------------------------------'   `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TRNS, KC_EXLM,KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR,KC_LPRN, KC_RPRN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_PIPE, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_QUOT, KC_EQL,  KC_GRV, KC_LCBR, KC_RCBR, KC_DQUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,                          KC_BSLS, KC_PLUS, KC_TILD,KC_LBRC, KC_RBRC,KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, _______, KC_TRNS,     KC_TRNS,   MO(3), KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_F11,  KC_F12,  KC_MUTE, KC_VOLD,KC_VOLU,                      KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,LALT(KC_F4),LGUI(KC_V),LGUI(KC_DOT),LSG(KC_L),LALT(KC_TAB),   LCTL(KC_TAB), KC_DELETE,KC_PGDN,KC_PGUP, KC_INSERT,KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,   MO(3), KC_TRNS,    KC_TRNS, _______, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,MEH(KC_DELETE), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, DT_UP, KC_BTN1,                       KC_BTN2, LALT(KC_LEFT),LSA(KC_DOWN),LSA(KC_UP),LALT(KC_RIGHT), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, DT_DOWN, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, _______, KC_TRNS,    KC_TRNS, _______, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LGUI,KC_A):
        case MT(MOD_RGUI,KC_SCLN):
            return TAPPING_TERM + 80;
        case MT(MOD_LSFT,KC_F):
        case MT(MOD_RSFT,KC_J):
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}
#endif
