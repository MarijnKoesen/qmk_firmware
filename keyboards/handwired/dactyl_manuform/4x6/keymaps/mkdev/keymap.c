#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _QWERTY 3

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

#define CTL_BSPC LCTL_T(KC_BSPC)
#define DEL_GUI RGUI_T(KC_DEL)
#define SHF_GRV LSFT_T(KC_GRV)

// To work around too fast keypresses for LT() we need to use
// interrupts, see https://github.com/qmk/qmk_firmware/issues/303
#define LOW_SPC 0x9001 // LT(LOWER, KC_SPACE)
#define RAISE_ENT 0x9004 //  LT(RAISE, KC_ENTER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* base (colemak/qwerty)
 * +------------------------------------------+                              +-----------------------------------------+
 * |  TAB  |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  |   :  |  \   |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  ESC  |   A  |   R  |   S  |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |  '   |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | L⇧ +` |   Z  |   X  |   C  |   V  |   B  |                              |   K  |   M  |   ,  |   .  |   /  |  R⇧  |
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
 *                                             | PGDN |  ⌘   | |      | PGUP |
 *                                             +------+------+ +------+------+
 */

[_BASE] = LAYOUT( 

    KC_TAB,  KC_Q,  KC_W,   KC_F,   KC_P,   KC_G,               KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_BSLS,   \
    KC_ESC,  KC_A,  KC_R,   KC_S,   KC_T,   KC_D,               KC_H,   KC_N,   KC_E,   KC_I,   KC_O,   KC_QUOTE,  \
    SHF_GRV, KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_K,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSHIFT, \
                    KC_LBRC,KC_RBRC,                                            KC_MINS,KC_EQL,                    \
                            LOW_SPC,CTL_BSPC,                           DEL_GUI,RAISE_ENT,                         \
                                    KC_PGDN, KC_LALT,           KC_RALT,KC_PGUP,                                    \
                                    KC_LGUI, KC_HOME,           KC_END ,_______                                     \
),
[_QWERTY] = LAYOUT( 

    KC_TAB,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_MINS,   \
    KC_ESC,  KC_A,  KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,   \
    SHF_GRV, KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_BSLASH, \
                    KC_LBRC,KC_RBRC,                                            KC_MINS,KC_EQL,                    \
                            LOW_SPC,CTL_BSPC,                           DEL_GUI,RAISE_ENT,                         \
                                    KC_PGDN, KC_LALT,           KC_RALT,KC_PGUP,                                    \
                                    KC_LGUI, KC_HOME,           KC_END ,_______                                     \
),

/*
 * +------------------------------------------+                              +-----------------------------------------+
 * |       |  F1  |  F2  |  F3  |  F4  |      |                              |      | 7  & | 8  * | 9  ( |      |      |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |       |  F5  |  F6  |  F7  |  F8  |      |                              |      | 4  $ | 5  % | 6  ^ |      |      |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |   ~   |  F9  | F10  | F11  | F12  |      |                              |      | 1  ! | 2  @ | 3  # |      |      |	
 * +-------+------+------+------+-------------+                              +-------------+------+------+------+------+
 *                |      |      |                                                          | 0  ) |   .  |
 *                '------+------'-------------+                              +-------------'------+------'
 *                              |       |      |                             |     |       |
 *                              |       |      |                             |     |       |
 *                              |       |      |                             |     |       |
 *                              '-------+------+                             +-----+-------+
 *                                             +------+------+ +------+------+
 *                                             |      |      | |      |      |
 *                                             |------+------| |------+------|
 *                                             |      |      | |      |      |
 *                                             +------+------+ +------+------+
 */
[_LOWER] = LAYOUT(
    _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 ,_______,            _______, KC_7, KC_8,  KC_9,  _______,RESET,     \
    _______, KC_F5 , KC_F6 , KC_F7 , KC_F8 ,_______,            _______, KC_4, KC_5,  KC_6,  _______,KC_PSCR,   \
    _______, KC_F9 , KC_F10, KC_F11, KC_F12,_______,            _______, KC_1, KC_2,  KC_3,  _______,_______,   \
                    _______,_______,                                            KC_0, KC_DOT,                   \
                                    _______,KC_LGUI,                    _______,_______,                        \
                                            _______,_______,    _______,_______,                                \
                                            _______,_______,    _______,_______                                 \
),

/*
 * +------------------------------------------+                              +-----------------------------------------+
 * |       |   =  |   @  |  +   |  (   |  |   |                              |      |      |  ↑   | PGUP | VOL↑ | PREV |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |   $   |  [   |   ]  |  {   |  }   |  `   |                              |      |  ←   |  ↓   |  →   | MUTE | STOP |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |   ~   |  %   |   ^  |  [   |  ]   |  ~   |                              |      |      |  ↓   | PGDN | VOL↓ | NEXT |
 * +-------+------+------+------+-------------+                              +-------------+------+------+------+------+
 *                |      |      |                                                          |      |      |
 *                '------+------'-------------+                              +-------------'------+------'
 *                              |       |      |                             |     |       |
 *                              |       |      |                             |     |       |
 *                              |       |      |                             |     |       |
 *                              '-------+------+                             +-----+-------+
 *                                             +------+------+ +------+------+
 *                                             |      |      | |      |      |
 *                                             |------+------| |------+------|
 *                                             |      |      | |      |      |
 *                                             +------+------+ +------+------+
 */
[_RAISE] = LAYOUT(
    _______,KC_EQL ,KC_AT,  KC_PLUS,KC_RPRN,KC_PIPE,            _______, _______, KC_UP,   KC_PGUP, KC_VOLU, KC_MPRV, \
    KC_DLR ,KC_LBRC,KC_RBRC,KC_LCBR,KC_RCBR,KC_GRV,             _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE, KC_MSTP, \
    KC_GRV ,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,            _______, _______, KC_DOWN, KC_PGDN, KC_VOLD, KC_MNXT, \
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

/*
 * +------------------------------------------+                              +-----------------------------------------+
 * |       |      |      |      |      |      |                              |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |       |      |      |      |      |      |                              |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |       |      |      |      |      |      |                              |      |      |      |      |      |      |
 * +-------+------+------+------+-------------+                              +-------------+------+------+------+------+
 *                |      |      |                                                          |      |      |
 *                '------+------'-------------+                              +-------------'------+------'
 *                              |       |      |                             |     |       |
 *                              |       |      |                             |     |       |
 *                              |       |      |                             |     |       |
 *                              '-------+------+                             +-----+-------+
 *                                             +------+------+ +------+------+
 *                                             |      |      | |      |      |
 *                                             |------+------| |------+------|
 *                                             |      |      | |      |      |
 *                                             +------+------+ +------+------+
 */

// To work around too fast keypresses for LT() we need to use
// interrupts, see https://github.com/qmk/qmk_firmware/issues/303
bool layer_interrupted = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
      case LOW_SPC:
          if (record->event.pressed) {
            layer_interrupted = false;
            layer_on(_LOWER);
          } else {
            if (!layer_interrupted) {
              register_code(KC_SPACE);
              unregister_code(KC_SPACE);
            }
            layer_off(_LOWER);
          }
          return false;
      break;

      case RAISE_ENT:
          if (record->event.pressed) {
            layer_interrupted = false;
            layer_on(_RAISE);
          } else {
            if (!layer_interrupted) {
              register_code(KC_ENTER);
              unregister_code(KC_ENTER);
            }
            layer_off(_RAISE);
          }
          return false;
      break;

      default:
          layer_interrupted = true;
      break;
    }
    return true;
}
