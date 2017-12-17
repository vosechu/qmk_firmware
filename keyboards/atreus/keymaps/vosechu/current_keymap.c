// Commands:
// make atreus:vosechu
// avrdude -patmega32u4 -cavr109 -b57600 -Uflash:w:atreus_vosechu.hex -P/dev/tty.usbmodem1411

// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
enum {
  DV = 0,
  QW,
  GAM1,
  RSE,
  SRSE,
  LWR,
  SLWR,
  ALT,
  NAV
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

// Extended alpha key layers for Dvorak
#define NAV_A    LT(NAV,  KC_A)
#define ALTER_O  LT(ALT,  KC_O)
#define SRSE_E   LT(SRSE, KC_E)
#define RSE_U    LT(RSE,  KC_U)
#define LWR_H    LT(LWR,  KC_H)
#define SLWR_T   LT(SLWR, KC_T)

// Make Overloaded Keys switch faster
#define TAPPING_TERM 200

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DV] =  { /* ================================================== DVORAK ======================================== */
  { KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y    , _______ , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    },
  { NAV_A   , ALTER_O , SRSE_E  , RSE_U   , KC_I    , _______ , KC_D    , LWR_H   , SLWR_T  , KC_N    , KC_S    },
  { KC_SCLN , KC_Q    , KC_J    , KC_K    , KC_X    , KC_BSPC , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    },
  { CTLGRV  , ALTTAB  , KC_LGUI , KC_BSPC , SFTSPC  , KC_ENT  , KC_SPC  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT }
},
[QW] =  { /* ================================================== QWERTY ======================================== */
  { KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , _______ , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    },
  { KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , _______ , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN },
  { KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , _______ , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH },
  { _______ , _______ , KC_LALT , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ }
},
[LWR] = { /* ================================================== LOWER ========================================= */
  { KC_LABK , KC_RABK , KC_LCBR , KC_RCBR , KC_EQL  , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
  { KC_LPRN , KC_RPRN , KC_LBRC , KC_RBRC , KC_MINS , _______ , XXXXXXX , _LAYER_ , XXXXXXX , XXXXXXX , XXXXXXX },
  { KC_ESC  , KC_TAB  , KC_GRV  , KC_BSLS , KC_SLSH , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
  { _______ , _______ , _______ , _______ , XXXXXXX , _______ , _______ , _______ , _______ , _______ , _______ }
},
[SLWR] = { /* ================================================= SHIFTED LOWER ================================= */
  { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PLUS , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
  { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_UNDS , _______ , XXXXXXX , XXXXXXX , _LAYER_ , XXXXXXX , XXXXXXX },
  { XXXXXXX , XXXXXXX , KC_TILD , KC_PIPE , KC_QUES , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
  { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ }
},
[RSE] = { /* ================================================== RAISE ========================================= */
  { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX },
  { XXXXXXX , XXXXXXX , XXXXXXX , _LAYER_ , XXXXXXX , _______ , XXXXXXX , KC_4    , KC_5    , KC_6    , XXXXXXX },
  { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , KC_1    , KC_2    , KC_3    , XXXXXXX },
  { _______ , _______ , _______ , _______ , XXXXXXX , _______ , _______ , KC_0    , KC_0    , KC_DOT  , XXXXXXX }
},
[SRSE] = { /* ================================================= SHIFTED RAISE ================================= */
  { XXXXXXX , XXXXXXX , XXXXXXX , KC_PGUP , XXXXXXX , _______ , XXXXXXX , KC_AMPR , KC_ASTR , XXXXXXX , XXXXXXX },
  { XXXXXXX , XXXXXXX , _LAYER_ , KC_PGDN , XXXXXXX , _______ , XXXXXXX , KC_DLR  , KC_PERC , KC_CIRC , XXXXXXX },
  { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , KC_EXLM , KC_AT   , KC_HASH , XXXXXXX },
  { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ }
},
[ALT] = { /* ================================================== ALTERNATE RAISE =============================== */
  { RESET   , XXXXXXX , XXXXXXX , SLACKUP , KC_VOLU , _______ , KC_VOLU , KC_F7   , KC_F8   , KC_F9   , TO(DV)  },
  { XXXXXXX , _LAYER_ , XXXXXXX , SLACKDN , KC_VOLD , _______ , KC_VOLD , KC_F4   , KC_F5   , KC_F6   , TO(QW)  },
  { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_MUTE , _______ , KC_MUTE , KC_F1   , KC_F2   , KC_F3   , XXXXXXX },
  { _______ , _______ , _______ , _______ , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX }
},
[NAV] = { /* ================================================== ALTERNATE RAISE =============================== */
  { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
  { _LAYER_ , TABLEFT , TABRIGT , HISTBAK , HISTFWD , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
  { XXXXXXX , SCRLEFT , SCRFULL , SCRRIGT , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
  { _______ , _______ , _______ , _______ , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX }
}
// [EMPTY] = { /* ================================================== EMPTY ========================================= */
//   { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
//   { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
//   { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
//   { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ }
// }
};

const uint16_t PROGMEM fn_actions[] = {

};

void matrix_init_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // if (record->event.pressed) {
  //   switch(keycode) {
  //     case SMILEY:
  //       SEND_STRING(":)"); // this is our macro!
  //       return false;
  //     case TONGUE:
  //       SEND_STRING(":P"); // this is our macro!
  //       return false;
  //     case MEHFACE:
  //       SEND_STRING(":/"); // this is our macro!
  //       return false;
  //   }
  // }
  return true;
};

/* Layout TODO

* History navigation needs to be left handed only
* Need to analyze which keys get pressed when my right hand is on the mouse

*/
