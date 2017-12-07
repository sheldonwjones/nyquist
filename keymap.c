#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

#define CTL_Z       CTL_T(KC_Z)
#define CTL_SLSH    CTL_T(KC_SLSH)
#define GUI_TAB     GUI_T(KC_TAB)
#define LT_NAVA     LT(_NAV, KC_A)
#define LT_NAVS     LT(_NAV, KC_SCLN)
#define LT_SYM      LT(_SYM, KC_S)
#define LT_NUM      LT(_NUM, KC_D)
#define LT_FUN      LT(_FUN, KC_F)
#define LT_GUI      LT(_GUI, KC_G)

extern keymap_config_t keymap_config;

enum nyquist_layers {
  _QWERTY,
  _NAV,
  _SYM,
  _NUM,
  _FUN,
  _GUI,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   [  |   {  | Alt< | GUI  | Tab  |Space |Enter | Bksp | GUI  | Alt> |   }  |  ]   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_EQL, \
  KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_MINS, \
  KC_ESC,  LT_NAVA, LT_SYM,  LT_NUM,  LT_FUN,  LT_GUI,  KC_H,    KC_J,    KC_K,    KC_L,    LT_NAVS,  KC_QUOT, \
  KC_LSPO, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLSH, KC_RSPC, \
  KC_LBRC, KC_LCBR, KC_LCTL, KC_LALT, GUI_TAB, KC_SPC,  KC_ENT,  KC_BSPC, KC_RGUI, KC_RALT, KC_RCBR,  KC_RBRC
),

/* Arrow
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | NAV  |      |      |      |      | | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |AGnorm|AGswap|      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_NAV] = KEYMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, \
  XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_SWAP, AG_NORM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Symbols
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |   (  |   )  |      | |   +  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      | SYM  |   {  |   }  |      | |   ~  |   $  |   %  |   ^  |   |  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |   [  |   ]  |      | |   =  |   !  |   @  |   #  |   /  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_SYM] = KEYMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, KC_PLUS, S(KC_7), S(KC_8), S(KC_9), S(KC_0), XXXXXXX, \
  _______, XXXXXXX, _______, KC_LCBR, KC_RCBR, XXXXXXX, KC_TILD, S(KC_4), S(KC_5), S(KC_6), KC_PIPE, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, KC_EQL,  S(KC_1), S(KC_2), S(KC_3), KC_BSLS, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Numbers
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |   +  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      | NUM  |      |      | |   *  |   4  |   5  |   6  |   .  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |   =  |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_NUM] = KEYMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_DOT,  _______, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  KC_1,    KC_2,    KC_3,    _______, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* FUN
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |RESET | |      |      |      |      |      |RESET |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      | FUN  |      | |      |  F4  |  F5  |  F6  |  F11 |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |  F1  |  F2  |  F3  |  F12 |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_FUN] = KEYMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* GUI
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      | I3 7 | I3 8 | I3 9 | I3 0 |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      | GUI  | |      | I3 4 | I3 5 | I3 6 |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      | I3 1 | I3 2 | I3 3 |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_GUI] = KEYMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(7),   TD(8),   TD(9),   TD(0),   XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, TD(4),   TD(5),   TD(6),   XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(1),   TD(2),   TD(3),   XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //i3... Tap once for desktop #, twice move select to desktop #
  [0]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_0), S(LALT(KC_0))),
  [1]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_1), S(LALT(KC_1))),
  [2]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_2), S(LALT(KC_2))),
  [3]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_3), S(LALT(KC_3))),
  [4]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_4), S(LALT(KC_4))),
  [5]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_5), S(LALT(KC_5))),
  [6]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_6), S(LALT(KC_6))),
  [7]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_7), S(LALT(KC_7))),
  [8]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_8), S(LALT(KC_8))),
  [9]  = ACTION_TAP_DANCE_DOUBLE(LALT(KC_9), S(LALT(KC_9))),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode switched to qwerty\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
