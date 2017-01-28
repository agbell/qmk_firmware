#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define FLOCK 1 // symbols
#define JLOCK 2 // media keys

#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
        [BASE] = KEYMAP(
                // left hand
                GUI_T(KC_ESC), KC_1, KC_2,   KC_3, KC_4, KC_5, KC_MINS,
                KC_LBRC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TAB,
                KC_LCBR, SFT_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), FUNC(1), GUI_T(KC_G),
                KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC,
                KC_BSLS, KC_GRAVE,  _______,  _______ ,_______,
                _______,  _______,
                _______,
                KC_SPC, KC_ENT, _______ ,

                // right hand
                KC_EQL,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             _______,
                KC_TAB,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_RBRC,
                GUI_T(KC_H),   FUNC(2),   CTL_T(KC_K),   ALT_T(KC_L),   SFT_T(KC_SCLN),           KC_RCBR,
                KC_DELETE,  KC_N,   KC_M,   KC_COMM,KC_DOT, KC_QUOT,           KC_LSHIFT,
                _______,  _______,_______,_______,          KC_SLSH,
                _______,        _______,
                _______,
                _______,KC_ENT, KC_SPC
        ),
        [FLOCK] = KEYMAP(
                // left hand
                _______,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
                _______,KC_LBRC,KC_NUHS,  KC_TILD,_______,_______,_______,
                _______,KC_LCBR,_______, _______,_______,_______,
                _______,KC_BSLS,KC_PIPE,_______,_______,_______,_______,
                _______,_______,_______,_______,_______,
                _______,_______,
                _______,
                _______,_______,_______,
                // right hand
                KC_F12, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  _______,
                _______, _______, KC_HOME,   KC_PGUP,    _______,    KC_RBRC, _______,
                KC_LEFT, KC_DOWN,   KC_UP,    KC_RIGHT,    KC_RCBR, _______,
                _______, _______, KC_END,   KC_PGDOWN,    KC_QUES,    KC_SLSH, _______,
                _______,_______,  _______,    _______,  _______,
                _______, _______,
                _______,
                _______, _______, _______
        ),
        [FLOCK] = KEYMAP(
                // left hand
                _______,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
                _______,KC_LBRC,KC_NUHS,  KC_TILD,_______,_______,_______,
                _______,KC_LCBR,_______, _______,_______,_______,
                _______,KC_BSLS,KC_PIPE,_______,_______,_______,_______,
                _______,_______,_______,_______,_______,
                _______,_______,
                _______,
                _______,_______,_______,
                // right hand
                KC_F12, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  _______,
                _______, _______, KC_HOME,   KC_PGUP,    _______,    KC_RBRC, _______,
                KC_LEFT, KC_DOWN,   KC_UP,    KC_RIGHT,    KC_RCBR, _______,
                _______, _______, KC_END,   KC_PGDOWN,    KC_QUES,    KC_SLSH, _______,
                _______,_______,  _______,    _______,  _______,
                _______, _______,
                _______,
                _______, _______, _______
        )
};

const uint16_t PROGMEM fn_actions[] = {
        [1] = ACTION_LAYER_TAP_KEY(FLOCK,KC_F),
        [2] = ACTION_LAYER_TAP_KEY(JLOCK,KC_J)            // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
        // MACRODOWN only works in this function
        switch(id) {
        case 0:
                if (record->event.pressed) {
                        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                }
                break;
        }
        return MACRO_NONE;
};

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
        case 1:
                ergodox_right_led_1_on();
                break;
        case 2:
                ergodox_right_led_2_on();
                break;
        default:
                // none
                break;
        }

};
