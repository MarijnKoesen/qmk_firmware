#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Fillers to make layering more clear

#define ____ KC_TRNS
#define _____ KC_TRNS
#define ______ KC_TRNS
#define XXXX KC_NO

#define SFT_ESC  SFT_T(KC_ESC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define LOW_SPC LT(LOWER, KC_SPACE)
#define CTL_BSPC LCTL_T(KC_BSPC)
#define DEL_GUI RGUI_T(KC_DEL)
#define ENT_RAISE LT(RAISE, KC_ENTER)
#define SHF_GRV LSFT(KC_GRV)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* bAse (qwerty)
 * +------------------------------------------+                              +-----------------------------------------+
 * |  TAB  |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  |   :  |  \   |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  ESC  |   A  |   R  |   S  |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |  '   |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | L⇧ /` |   Z  |   X  |   C  |   V  |   B  |                              |   K  |   M  |   ,  |   .  |   /  |  R⇧  |
 * +-------+------+------+------+-------------+                              +-------------+------+------+------+------+
 *                |  [   |   ]  |                                                          |   -  |   =  |
 *                '------+------'-------------+                              +-------------'------+------'
 *                              | SPACE | BKSP |                             | DEL | ENTER |
 *                              |   +   |   +  |                             |  +  |   +   |
 *                              | LOWER | CTRL |                             |  ⌘  | RAISE |
 *                              '-------+------+                             +-----+-------+
 *                                             +------+------+ +------+------+
 *                                             |  ALT | HOME | | END  | ALT  |
 *                                             |------+------| |------+------|
 *                                             | PGUP |      | |      | PGDN |
 *                                             +------+------+ +------+------+

// qwerty...
//    KC_ESC,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_MINS,   \
//    KC_TAB,  KC_A,  KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,   \
//    SHF_GRV, KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_BSLASH, \
 */


[_BASE] = LAYOUT( \

    KC_TAB,  KC_Q,  KC_W,   KC_F,   KC_P,   KC_G,               KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_BSLS,   \
    KC_ESC,  KC_A,  KC_R,   KC_S,   KC_T,   KC_D,               KC_H,   KC_N,   KC_E,   KC_I,   KC_O,   KC_QUOTE,  \
    SHF_GRV, KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_K,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSHIFT, \
                    KC_LBRC,KC_RBRC,                                            KC_MINS,KC_EQL,                    \
                            LOW_SPC,CTL_BSPC,                           DEL_GUI,ENT_RAISE,                         \
                                    KC_LALT,KC_HOME,           KC_END, KC_RALT,                                    \
                                    KC_BSPC,KC_GRV,            KC_LGUI,KC_LALT                                     \
),

[_LOWER] = LAYOUT(
    _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 ,_______,            _______, KC_P7, KC_P8,  KC_P9,  _______,RESET,     \
    _______, KC_F5 , KC_F6 , KC_F7 , KC_F8 ,_______,            _______, KC_P4, KC_P5,  KC_P6,  _______,KC_PSCR,   \
    _______, KC_F9 , KC_F10, KC_F11, KC_F11,_______,            _______, KC_P1, KC_P2,  KC_P3,  _______,_______,   \
                    _______,_______,                                            KC_P0,  KC_DOT,                    \
                                    _______,_______,                    _______,_______,                           \
                                            _______,_______,    _______,_______,                                   \
                                            _______,_______,    _______,_______                                    \
),

[_RAISE] = LAYOUT(
    _______,KC_EQL ,KC_AT,  KC_PLUS,KC_RPRN,KC_PIPE,            _______, _______, KC_UP,   KC_PGUP, KC_VOLU, KC_MPRV, \
    _______,KC_LBRC,KC_RBRC,KC_LCBR,KC_RCBR,KC_GRV,             _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE, KC_MNXT,  \
    _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,            _______, _______, KC_DOWN, KC_PGDN, KC_VOLD, KC_MSTP, \
                    _______,_______,                                              ______,  _______,                   \
                                    _______,_______,                     _______,_______,                             \
                                            _______,_______,    _______,_______,                                      \
                                            _______,_______,    _______,_______                                       \
)
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

