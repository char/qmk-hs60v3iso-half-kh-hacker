#include QMK_KEYBOARD_H
#include "../../../wilba_tech/wt_rgb_backlight.h"
#include "../../../wilba_tech/wt_rgb_backlight_api.h"

#define BASE_LAYER 0
#define NAV_LAYER 1
#define EXT_NAV_LAYER 2
#define F_KEYS_LAYER 3
#define INTERNAL_LAYER 4

#define _BS KC_NONUS_BSLASH
#define CAPS_F_TOGG LT(F_KEYS_LAYER, KC_CAPS)
#define CAPS_ENAV TG(EXT_NAV_LAYER)
#define INTERN TG(INTERNAL_LAYER)

#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT_60_iso( \
    KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPACE, \
    KC_TAB,     KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, \
    CAPS_F_TOGG, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, \
    KC_LSFT, _BS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,    KC_RSHIFT, \
    KC_LCTRL, KC_LGUI, KC_LALT,         KC_SPACE,        KC_RALT, KC_RGUI, MO(NAV_LAYER), KC_RCTL \
  ),

  [NAV_LAYER] = LAYOUT_60_iso( \
    KC_GRAVE, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, KC_DELETE, \
    KC_PSCR, ____, KC_UP, ____, ____, ____, ____, ____, ____, ____, ____, ____, RESET, \
    CAPS_ENAV, KC_LEFT, KC_DOWN, KC_RIGHT, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,    ____, \
    ____, ____, ____, ____, ____, INTERN, ____, ____ \
  ),

  [EXT_NAV_LAYER] = LAYOUT_60_iso( \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
    ____, ____, KC_PGUP, ____, ____, ____, ____, ____, KC_INS, ____, ____, ____, ____, \
    ____, KC_HOME, KC_PGDOWN, KC_END, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,    ____, \
    ____, ____, ____, ____, ____, ____, ____, ____ \
  ),

  [F_KEYS_LAYER] = LAYOUT_60_iso(
    ____, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,    ____, \
    ____, ____, ____, ____, ____, ____, ____, ____ \
  ),

  [INTERNAL_LAYER] = LAYOUT_60_iso( \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, RGB_HUD, RGB_HUI, ____, \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, RGB_RMOD, RGB_MOD, \
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
    ____, ____, ____, ____, ____, ____, ____, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, ____,    ____, \
    ____, ____, ____, ____, ____, ____, ____, ____ \
  )
};

void matrix_init_user(void) {
  uint8_t backlight_config[2] = { id_effect, 0 };
  backlight_config_set_value(backlight_config);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (IS_LAYER_OFF(NAV_LAYER)) {
    if (IS_LAYER_ON(EXT_NAV_LAYER)) {
      layer_off(EXT_NAV_LAYER);
    }

    if (IS_LAYER_ON(INTERNAL_LAYER)) {
      layer_off(INTERNAL_LAYER);
    }
  }

  return true;
}
