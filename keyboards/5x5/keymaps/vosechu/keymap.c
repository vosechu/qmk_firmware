#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
enum {
  PAD = 0
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define _LAYER_ KC_TRNS
#define XXXXXXX KC_NO

// Macro keys for some apps
#define SLACKUP LALT(LSFT(KC_UP))
#define SLACKDN LALT(LSFT(KC_DOWN))
#define TABLEFT LGUI(LSFT(KC_LBRC))
#define TABRIGT LGUI(LSFT(KC_RBRC))
#define HISTBAK LGUI(KC_LBRC)
#define HISTFWD LGUI(KC_RBRC)
#define RELOAD  LGUI(KC_R)
#define SCRLEFT HYPR(KC_LEFT)
#define SCRRIGT HYPR(KC_RGHT)
#define SCRFULL HYPR(KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [PAD] = {
    { KC_ESC  , SCRLEFT , SCRFULL , SCRRIGT , SLACKUP  , },
    { KC_VOLU , TABLEFT , KC_UP   , TABRIGT , SLACKDN  , },
    { KC_VOLD , KC_LEFT , KC_DOWN , KC_RGHT , KC_K     , },
    { KC_MUTE , HISTBAK , RELOAD  , HISTFWD , KC_J     , },
    { RESET   , _______ , _______ , _______ , _______}
  }
};
