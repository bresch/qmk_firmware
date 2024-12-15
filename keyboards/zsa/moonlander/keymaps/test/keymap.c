/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"

#define VOL_MUTE KC_AUDIO_MUTE
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define VOL_UP KC_AUDIO_VOL_UP

#define LWN MOD_LGUI
#define RWN MOD_RGUI
#define LAT MOD_LALT
#define RAT MOD_RALT
#define LST MOD_LSFT
#define RST MOD_RSFT
#define LCL MOD_LCTL
#define RCL MOD_RCTL

#define KC_COL LCTL(KC_SCLN)

enum layers {
    BASE,
    NUMB,
    SYMB,
    MOVE,
    ARRO,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                            _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , KC_ESC  , KC_L    , KC_Y    , KC_P    , KC_B    , _______ ,                            _______ , KC_Z    , KC_F    , KC_O    , KC_U    , _______ , _______ ,
    _______ , KC_C    , KC_R    , KC_S    , KC_T    , KC_G    , _______ ,                            _______ , KC_M    , KC_N    , KC_E    , KC_I    , KC_A    , _______ ,
    _______ , KC_W    , KC_J    , KC_V    , KC_D    , KC_K    ,                                                KC_X    , KC_H    , KC_QUOTE, KC_COMMA, KC_DOT  , _______ ,
    _______ , _______ , _______ , _______ , KC_UNDS ,                     _______ ,         _______ ,                    KC_ASTR , _______ , _______ , _______ , _______ ,
                                                      KC_SPACE,OSL(NUMB), _______ ,         _______ ,OSL(SYMB), KC_BSPC
  ),

  [NUMB] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                            _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , TO(BASE), _______ ,OSL(ARRO), _______ , _______ , _______ ,                            _______ , _______ , KC_7    , KC_8    , KC_9    , _______ , _______ ,
    _______ , OSM(LWN), OSM(LAT), OSM(LST), OSM(LCL), _______ , _______ ,                            _______ , KC_MINUS, KC_4    , KC_5    , KC_6    , _______ , _______ ,
    _______ , _______ , VOL_MUTE, VOL_DOWN, VOL_UP  , _______ ,                                                KC_PLUS , KC_1    , KC_2    , KC_3    , KC_DOT  , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                     _______ ,         _______ ,                    KC_0    , _______ , _______ , _______ , _______ ,
                                                      _______ , KC_NO   , _______ ,         _______ , _______ ,KC_ENTER
  ),

  [SYMB] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                            _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , TO(BASE), KC_AT   , KC_LCBR , KC_RCBR , KC_BSLS , _______ ,                            KC_NO   , KC_NO   , KC_DLR  , KC_EXLM , KC_EQUAL, KC_ASTR , _______ ,
    _______ , KC_PERC , KC_AMPR , KC_LPRN , KC_RPRN , KC_GRAVE, _______ ,                            _______ , KC_HASH ,OSM(RCL),  OSM(RST), OSM(RAT), OSM(RWN), _______ ,
    _______ , KC_Q    , KC_CIRC , KC_LBRC , KC_RBRC , KC_TILD ,                                                _______ , KC_GRAVE, CW_TOGG , KC_SCLN ,S(KC_SCLN),_______ ,
    _______ , _______ , _______ , _______ , KC_SLASH,                     _______ ,         _______ ,                   KC_DELETE, _______ , _______ , _______ , _______ ,
                                                      KC_TAB  , _______ , _______ ,         _______ , _______ , _______
  ),

  [MOVE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, TO(BASE), _______,LALT(KC_KP_8),  _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,                                                                 _______, _______, LGUI(KC_4),     LGUI(KC_5),     LGUI(KC_6),     _______, _______,
    _______, _______, _______, _______, _______, _______,                                 _______, LGUI(KC_1),     LGUI(KC_2),     LGUI(KC_3),     _______, _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),

  [ARRO] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                                                 _______, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______, _______,
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, KC_NO,          _______,                 _______, _______, _______
  ),
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (record->event.pressed) {
//         switch (keycode) {
//         case VRSN:
//             SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
//             return false;
//         }
//     }
//     return true;
// }
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_QK_ONE_SHOT_MOD(keycode) && is_oneshot_layer_active() && record->event.pressed) {
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
    }
    return;
}
