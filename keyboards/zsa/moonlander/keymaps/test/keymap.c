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

#define MOUSE_L KC_MS_LEFT
#define MOUSE_R KC_MS_RIGHT
#define MOUSE_U KC_MS_UP
#define MOUSE_D KC_MS_DOWN
#define MOUSE_B1 KC_MS_BTN1
#define MOUSE_B2 KC_MS_BTN2

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
    _______ , _______ , _______ , KC_QUES , VOL_MUTE, VOL_DOWN, VOL_UP  ,                            _______ , _______ , _______ , KC_EXLM , KC_EQUAL, _______ ,KC_DELETE,
    _______ , KC_TAB  , KC_L    , KC_Y    , KC_P    , KC_B    , KC_GRAVE,                            _______ , KC_Z    , KC_F    , KC_O    , KC_U    , _______ , _______ ,
    KC_ESC  , KC_C    , KC_R    , KC_S    , KC_T    , KC_G    , CW_TOGG ,                            KC_MINUS, KC_M    , KC_N    , KC_E    , KC_I    , KC_A    , KC_SCLN ,
    KC_Q    , KC_W    , KC_J    , KC_V    , KC_D    , KC_K    ,                                                KC_X    , KC_H    , KC_QUOTE, KC_COMMA, KC_DOT  , _______ ,
    _______ , _______ , _______ , _______ , KC_UNDS ,                     _______ ,         _______ ,                    KC_ASTR , KC_LABK , KC_RABK , _______ , _______ ,
    KC_SPACE,OSL(NUMB),KC_BSLS  ,                                                                    KC_SLASH,OSL(SYMB), KC_BSPC
  ),

  [NUMB] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                            _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ ,OSL(ARRO), _______ , _______ , _______ ,                            _______ , _______ , KC_7    , KC_8    , KC_9    , _______ , _______ ,
    TO(BASE),OSM(LWN),OSM(LAT),OSM(LST),OSM(LCL), _______ , _______ ,                            _______ , _______ , KC_4    , KC_5    , KC_6    , KC_PLUS , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                                _______ , KC_1    , KC_2    , KC_3    , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                     _______ ,         _______ ,                    KC_0    , _______ , _______ , _______ , _______ ,
    _______ , KC_NO   , _______ ,                                                                    _______ , _______ , KC_ENTER
  ),

  [SYMB] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                            _______ , _______ , _______ , KC_SLASH, _______ , _______ , _______ ,
    _______ , KC_EXLM , KC_AT   , KC_LCBR , KC_RCBR , KC_PIPE , KC_HASH ,                            KC_NO   , KC_NO   , _______ , _______ , _______ , KC_ASTR , _______ ,
    TO(0)   , KC_PERC , KC_AMPR , KC_LPRN , KC_RPRN , KC_GRAVE, _______ ,                            _______ , _______ ,OSM(RCL),OSM(RST),OSM(RAT),OSM(RWN),KC_KP_MINUS,
    _______ , KC_DLR  , KC_CIRC , KC_LBRC , KC_RBRC , KC_TILD ,                                                MOUSE_L , MOUSE_D , MOUSE_U , MOUSE_R , _______ , _______ ,
    _______ , _______ , _______ , _______ , KC_F    ,                     _______ ,         _______ ,                    MOUSE_B1, MOUSE_B2, KC_NO   , _______ , _______ ,
    _______ , _______ , _______ ,                                                                    _______ , _______ , RCTL(KC_BSPC)
  ),

  [MOVE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,LALT(KC_KP_8),  _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    TO(0),          _______, _______, _______, _______, _______, _______,                                                                 _______, _______, LGUI(KC_4),     LGUI(KC_5),     LGUI(KC_6),     _______, _______,
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
