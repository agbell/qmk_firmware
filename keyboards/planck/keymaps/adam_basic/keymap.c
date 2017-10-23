#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_TERM    300
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define BASE 0 // default layer

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = {
  {KC_1,         KC_2,       KC_3,         KC_4,     KC_5,         KC_MINS, KC_EQL,    KC_6,        KC_7,        KC_8,         KC_9,           KC_0,     },
  {KC_Q,         KC_W,       KC_E,         KC_R,     KC_T,         KC_TAB,  KC_TAB,    KC_Y,        KC_U,        KC_I,         KC_O,           KC_P,    },
  {KC_A,         KC_S,       KC_D,         KC_F,     KC_G,         KC_BSPC, KC_DELETE, KC_H,        KC_J,        KC_K,         KC_L,           KC_SCLN, },
  {KC_Z,         KC_X,       KC_C,         KC_V,     KC_B,         KC_SPC,  KC_ENT,    KC_N,        KC_M,        KC_COMM,      KC_DOT,         KC_QUOTE}
},

};
