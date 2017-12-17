#include QMK_KEYBOARD_H
#include "laptreus.h"

enum layer_names {
  _QWERTY = 0,
  _DVORAK,
  _LOWER,
  _RAISE,
  _LIFT
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define _LAYER_ KC_TRNS
#define XXXXXXX KC_NO

// Adding macros to make the keymaps below much easier to read.
#define CTLESC CTL_T(KC_ESC)
#define CTLGRV CTL_T(KC_GRV)
#define ALTTAB ALT_T(KC_TAB)
#define SFTSPC SFT_T(KC_SPC)

// Extended alpha key layers
#define RSE_J  LT(_RAISE, KC_J)
#define LWR_F  LT(_LOWER, KC_F)
#define RSE_H  LT(_RAISE, KC_H)
#define LWR_U  LT(_LOWER, KC_U)
#define LFT_BK  LT(_LIFT, KC_BSPC)
#define LFT_ENT LT(_LIFT, KC_ENT)

// Macro keys for some apps
#define SLACKUP LALT(LSFT(KC_UP))
#define SLACKDN LALT(LSFT(KC_DOWN))
#define TABLEFT LGUI(LSFT(KC_LBRC))
#define TABRIGT LGUI(LSFT(KC_RBRC))
#define HISTBAK LGUI(KC_LBRC)
#define HISTFWD LGUI(KC_RBRC)
#define SCRLEFT HYPR(KC_LEFT)
#define SCRRIGT HYPR(KC_RGHT)
#define SCRFULL HYPR(KC_F)

// Layer toggles
#define TO_QW TO(_QWERTY)
#define TO_DV TO(_DVORAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
    KC_ESC  , KC_A    , KC_S    , KC_D    , LWR_F   , KC_G    , KC_H    , RSE_J   , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
    KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
    KC_HYPR , CTLGRV  , ALTTAB  , KC_LGUI , LFT_BK  , SFTSPC  , KC_SPC  , LFT_ENT , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
  ),
  [_DVORAK] = LAYOUT(
    KC_TAB  , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y    , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , KC_BSPC ,
    KC_ESC  , KC_A    , KC_O    , KC_E    , LWR_U   , KC_I    , KC_D    , RSE_H   , KC_T    , KC_N    , KC_S    , KC_SLSH ,
    KC_LSFT , KC_SCLN , KC_Q    , KC_J    , KC_K    , KC_X    , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , KC_ENT  ,
    KC_HYPR , CTLGRV  , ALTTAB  , KC_LGUI , LFT_BK  , SFTSPC  , KC_SPC  , LFT_ENT , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
  ),
  [_LOWER] = LAYOUT(
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , _LAYER_ , XXXXXXX , XXXXXXX , KC_4    , KC_5    , KC_6    , XXXXXXX , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_1    , KC_2    , KC_3    , XXXXXXX , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_0    , KC_0    , KC_DOT  , _______ , _______
  ),
  [_RAISE] = LAYOUT(
    _______ , KC_LABK , KC_RABK , KC_LCBR , KC_RCBR , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
    _______ , KC_LPRN , KC_RPRN , KC_LBRC , KC_RBRC , XXXXXXX , XXXXXXX , _LAYER_ , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
  [_LIFT] = LAYOUT(
    _______ , HISTBAK , TABLEFT , KC_UP   , TABRIGT , HISTFWD , KC_MUTE , XXXXXXX , SCRLEFT , SCRFULL , SCRRIGT , _______ ,
    _______ , XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGUP , KC_VOLU , SLACKUP , XXXXXXX , XXXXXXX , TO_QW   , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PGDN , KC_VOLD , SLACKDN , XXXXXXX , XXXXXXX , TO_DV   , _______ ,
    _______ , RESET   , _______ , _______ , _LAYER_ , KC_BSPC , _______ , KC_LSFT , KC_LGUI , KC_LALT , KC_LCTL , _______
  )
};
