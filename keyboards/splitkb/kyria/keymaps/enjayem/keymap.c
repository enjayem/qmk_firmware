/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _DVORAK = 0,
    _NAV,
    _CODE,
    _NUM,
    _SYM,
    _FUNCTION,
};

enum custom_keycodes {
    CCCV = SAFE_RANGE,
    COLEQ,
    DELLEFT,
    DELRGHT,
};


// Aliases for readability
#define DEFAULT   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define CODE     MO(_CODE)
#define NUM      MO(_NUM)
#define FKEYS    MO(_FUNCTION)

// Map Dvorak keys to their QWERTY counterparts
#define DV_A        KC_A
#define DV_B        KC_N
#define DV_C        KC_I
#define DV_D        KC_H
#define DV_E        KC_D
#define DV_F        KC_Y
#define DV_G        KC_U
#define DV_H        KC_J
#define DV_I        KC_G
#define DV_J        KC_C
#define DV_K        KC_V
#define DV_L        KC_P
#define DV_M        KC_M
#define DV_N        KC_L
#define DV_O        KC_S
#define DV_P        KC_R
#define DV_Q        KC_X
#define DV_R        KC_O
#define DV_S        KC_SCLN
#define DV_T        KC_K
#define DV_U        KC_F
#define DV_V        KC_DOT
#define DV_W        KC_COMM
#define DV_X        KC_B
#define DV_Y        KC_T
#define DV_Z        KC_SLSH
#define DV_DOT      KC_E
#define DV_COMM     KC_W
#define DV_SCLN     KC_Z
#define DV_SLSH     KC_LBRC
#define DV_LBRC     KC_MINS
#define DV_RBRC     KC_EQL
#define DV_EQL      KC_RBRC
#define DV_MINS     KC_QUOTE
#define DV_QUOT     KC_Q
#define DV_PLUS     KC_PLUS
#define DV_QUES     KC_QUES
#define DV_UNDS     KC_UNDS
#define DV_BSLS     KC_BSLS
#define DVX_C       X_I
#define DVX_V       X_DOT

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

/*
 * Base Layer: Dvorak
 *
 * ,-------------------------------------------.                               ,-------------------------------------------.u
 * |   !    | ' "  | , <  | . >  |   P  |   Y  |                               |   F  |   G  |   C  |   R  |   L  |  / ?   |
 * |--------+------+------+------+------+------|                               |------+------+------+------+------+--------|
 * |  Tab   |   A  |   O  |   E  |   U  |   I  |                               |   D  |   H  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------+--------------.  ,-------------+------+------+------+------+------+--------|
 * | Escape | ; :  |   Q  |   J  |   K  |   X  | MisCtl|CapsLk|  |F-keys| LPad |   B  |   M  |   W  |   V  |   Z  |  CCCV  |
 * `----------------------+------+------+------+-------+------|  |------+------+------+------+------+----------------------'
 *                        |rotary| CODE | del  |forward| NUM  |  | Sym  |  Ent | Space| NAV  |rotary|
 *                        |      |      |      |  del  |      |  |      |      |      |      |      |
 *                        `-----------------------------------'  `----------------------------------'
 */
    [_DVORAK] = LAYOUT(
     KC_EXLM     , DV_QUOT     , DV_COMM     , DV_DOT      , DV_P        , DV_Y   ,                                        DV_F   , DV_G        , DV_C        , DV_R        , DV_L        , DV_SLSH,
     KC_TAB      , LSFT_T(DV_A), LCTL_T(DV_O), LALT_T(DV_E), LGUI_T(DV_U), DV_I   ,                                        DV_D   , RGUI_T(DV_H), RALT_T(DV_T), RCTL_T(DV_N), RSFT_T(DV_S), DV_MINS,
     KC_ESC      , DV_SCLN     , DV_Q        , DV_J        , DV_K        , DV_X   , KC_MCTL , KC_CAPS ,  FKEYS  , KC_LPAD, DV_B   , DV_M        , DV_W        , DV_V        , DV_Z        , CCCV,
                                               _______     , CODE        , KC_BSPC, KC_DEL  , NUM     ,  SYM    , KC_ENT , KC_SPC , NAV         , _______
    ),

/*
 * Nav Layer: Navigation
 *
 * ,-------------------------------------------.                               ,-------------------------------------------.
 * |        |      |      |      |      |      |                               | PgUp | Home |   ↑  | End  | VolUp|        |
 * |--------+------+------+------+------+------|                               |------+------+------+------+------+--------|
 * |  Tab   | Shift| Ctrl | Alt  | Cmd  |      |                               | PgDn |  ←   |   ↓  |   →  | VolDn|        |
 * |--------+------+------+------+------+------+--------------.   ,------------+------+------+------+------+------+--------|
 * | Escape |      |      |      |      |      |       |      |  |      |      |      |      |      |      |VolMut|  CCCV  |
 * `----------------------+------+------+------+-------+------|  |------+------+------+------+------+----------------------'
 *                        |rotary|      | del  |forward|      |  |      | Ent  | Space| THIS |rotary|
 *                        |      |      |      |  del  |      |  |      |      |      |      |      |
 *                        `-----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, XXXXXXX,
      KC_TAB , KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, XXXXXXX,
      KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, CCCV   ,
                                 _______, XXXXXXX, KC_BSPC, KC_DEL , XXXXXXX, XXXXXXX, KC_ENT , KC_SPC , _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |rotary|      |      |      |      |  | THIS |      |      |      |rotary|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , DV_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, DV_PLUS,
     KC_PIPE , DV_BSLS, KC_COLN, DV_SCLN, DV_MINS, DV_LBRC, KC_LCBR, _______, _______, KC_RCBR, DV_RBRC, DV_UNDS, DV_COMM,  DV_DOT, DV_SLSH, DV_QUES,
                                 _______, _______, _______, _______, _______, KC_TRNS, _______, _______, _______, _______
    ),

/*
 * Num Layer: number pad (regular numbers, not "pad" numbers)
 *
 * ,-------------------------------------------.                               ,-------------------------------------------.
 * |        |      |      |      |      |      |                               |      |  7   |   8  |   9  |  *   |   /    |
 * |--------+------+------+------+------+------|                               |------+------+------+------+------+--------|
 * |   Tab  | Shift| Ctrl | Alt  |  Cmd |      |                               |      |  4   |   5  |   6  |  +   |   -    |
 * |--------+------+------+------+------+------+--------------.  ,-------------+------+------+------+------+------+--------|
 * | Escape |      |      |      |      |      |       |      |  |      |      |   .  |  1   |   2  |   3  |  0   |        |
 * `----------------------+------+------+------+-------+------|  |------+------+------+------+------+----------------------'
 *                        |rotary|      |  del |forward| THIS |  |      | Enter| Space|  @   |rotary|
 *                        |      |      |      |  del  |      |  |      |      |      |      |      |
 *                        `-----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_7   , KC_8   , KC_9,  KC_PAST , KC_PSLS,
      KC_TAB , KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,                                     XXXXXXX, KC_4   , KC_5   , KC_6,  KC_PPLS , KC_PMNS,
      KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PDOT, KC_1   , KC_2   , KC_3,  KC_0    , CCCV   ,
                                 _______, _______, KC_BSPC, KC_DEL , KC_TRNS, _______, KC_ENT , KC_SPC , KC_AT  , _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Cmd  | Alt  | Ctrl |Shift |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  | THIS |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Code Layer: code symbols pad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |   !  |   {  |   }  |   *  |   ?  |    +   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |   `  |   (  |   )  |   &  |   =  |    -   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |  :=  |   [  |   ]  |   |  |   \  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | THIS |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_CODE] = LAYOUT(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                    KC_EXLM, KC_LCBR, KC_RCBR, KC_ASTR, KC_QUES, DV_PLUS,
      KC_TAB , KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,                                    KC_GRV , KC_LPRN, KC_RPRN, KC_AMPR, DV_EQL , DV_MINS,
      KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, COLEQ  , DV_LBRC, DV_RBRC, KC_PIPE, DV_BSLS, CCCV   ,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


// #ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) { /* Left-side encoder */

            /* Adjust brightness during symbol layer */
            // if (IS_LAYER_ON(SYM)) {
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
            /* Adjust volume by default */
            // } else {
            //     if (clockwise) {
            //         tap_code(KC_VOLU);
            //     } else {
            //         tap_code(KC_VOLD);
            //     }
            // }
    /* You can copy the code and change the index for every encoder you have. Most
        keyboards will only have two, so this piece of code will suffice. */
    } else if (index == 1) { /* Right-side encoder */
        if (clockwise) {
            tap_code(KC_RGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }
    return false;
}
// #endif

bool is_cccv_active = false;
uint16_t cccv_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CCCV:
    // CCCV macro: copy when held, paste when tapped
        if (record->event.pressed) {
            cccv_timer = timer_read();
        } else {
            if (timer_elapsed(cccv_timer) > 300) {
                register_code(KC_LGUI);
                tap_code(DV_C);
                unregister_code(KC_LGUI);
            } else {
                register_code(KC_LGUI);
                tap_code(DV_V);
                unregister_code(KC_LGUI);
            }
        }
        break;
        case COLEQ:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            tap_code(DV_SCLN);
            unregister_code(KC_LSFT);
            tap_code(DV_EQL);
        }
        break;
    }
    return true;
};
