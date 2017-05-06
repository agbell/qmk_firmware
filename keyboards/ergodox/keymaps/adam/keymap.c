#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#define BASE 0 // default layer
#define FLOCK 1 // symbols arrows and F keys on F held down
#define JLOCK 2 // same as Flock but with fall thru J and mapped to J held down

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Sends macro when key is tapped, presses mod when key is held
#define tap_mod_macro(record, mod, macro) ( ((record)->event.pressed) ? \
     ( ((record)->tap.count <= 0 || (record)->tap.interrupted) ? MACRO(D(mod), END) : MACRO_NONE ) : \
     ( ((record)->tap.count > 0 && !((record)->tap.interrupted)) ? (macro) : MACRO(U(mod), END) ) )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layout
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;     |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |     |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
        [BASE] = KEYMAP(
                // left hand
                GUI_T(KC_ESC), KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS,
                _______, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TAB,
                _______, SFT_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), F(1), GUI_T(KC_G),
                _______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC,
                _______, _______,  _______,  _______ ,_______,
                _______,  _______,
                _______,
                KC_SPC, _______, _______ ,

                // right hand
                KC_EQL,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             _______,
                KC_TAB,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             _______,
                GUI_T(KC_H),   F(2),   CTL_T(KC_K),   ALT_T(KC_L),   SFT_T(KC_SCLN),           _______,
                KC_DELETE,  KC_N,   KC_M,   KC_COMM,KC_DOT, KC_QUOT,           _______,
                _______,  _______,_______,_______,          _______,
                _______,        _______,
                _______,
                _______,_______, KC_ENT
        ),
        [FLOCK] = KEYMAP(
                // left hand
                _______,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
                _______,KC_LBRC,KC_GRV,  KC_TILD,_______,_______,_______,
                _______,KC_LCBR,_______, _______,_______,_______,
                _______,KC_BSLS,KC_PIPE,_______,_______,_______,_______,
                _______,_______,_______,_______,_______,
                _______,_______,
                _______,
                KC_ESC,_______,_______,
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
        [JLOCK] = KEYMAP(
                // left hand
                _______,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
                _______,KC_LBRC,KC_GRV,  KC_TILD,_______,_______,_______,
                _______,KC_LCBR,_______, _______,_______,_______,
                _______,KC_BSLS,KC_PIPE,_______,_______,_______,_______,
                _______,_______,_______,_______,_______,
                _______,_______,
                _______,
                KC_ESC,_______,_______,
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
        [2] = ACTION_LAYER_TAP_KEY(JLOCK,KC_J),
        [3] = ACTION_MACRO_TAP(3),
        [4] = ACTION_MACRO_TAP(4)
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
        case 3:
            // the special Alt / { macro
            return tap_mod_macro(record, LALT, MACRO( D(LSFT), T(LBRC), U(LSFT), END));
            break;
       case 4:
            // the special Alt / } macro
            return tap_mod_macro(record, LALT, MACRO( D(LSFT), T(RBRC), U(LSFT), END));
            break;
        }

        return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};
