// Commands:
// make atreus:vosechu
// avrdude -patmega32u4 -cavr109 -b57600 -Uflash:w:atreus_vosechu.hex -P/dev/tty.usbmodem1411

// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
#include "atreus.h"
#include "vosechu.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DV] =  { /* ================================================== DVORAK ======================================== */
  { KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y    , _______ , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    },
  { KC_A    , KC_O    , KC_E    , RSE_U   , KC_I    , _______ , KC_D    , LWR_H   , KC_T    , KC_N    , KC_S    },
  { KC_SCLN , KC_Q    , KC_J    , KC_K    , KC_X    , MO(LFT) , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    },
  { CTLGRV  , ALTTAB  , KC_LGUI , KC_BSPC , SFTSPC  , KC_ENT  , KC_SPC  , KC_MINS , KC_EQL  , KC_SLSH , KC_BSLS }
},
[QW] =  { /* ================================================== QWERTY ======================================== */
  { KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , _______ , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    },
  { KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , _______ , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN },
  { KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , _______ , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH },
  { _______ , _______ , KC_LALT , _______ , _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT }
},
[GAM1] =  { /* ================================================ GAME ========================================== */
  { KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , _______ , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    },
  { KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , _______ , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN },
  { KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , _______ , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH },
  { _______ , _______ , KC_LALT , _______ , _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT }
},
[LWR] = { /* ================================================== LOWER ========================================= */
  { KC_LABK , KC_RABK , KC_LCBR , KC_RCBR , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
  { KC_LPRN , KC_RPRN , KC_LBRC , KC_RBRC , XXXXXXX , _______ , XXXXXXX , _LAYER_ , XXXXXXX , XXXXXXX , XXXXXXX },
  { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX },
  { _______ , _______ , _______ , _______ , XXXXXXX , _______ , _______ , _______ , _______ , _______ , _______ }
},
[RSE] = { /* ================================================== RAISE ========================================= */
  { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX },
  { XXXXXXX , XXXXXXX , XXXXXXX , _LAYER_ , XXXXXXX , _______ , XXXXXXX , KC_4    , KC_5    , KC_6    , XXXXXXX },
  { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , KC_1    , KC_2    , KC_3    , XXXXXXX },
  { _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_0    , KC_0    , KC_DOT  , XXXXXXX }
},
[LFT] = { /* ================================================== EMPTY ========================================= */
  { HISTBAK , TABLEFT , KC_UP   , TABRIGT , HISTFWD , _______ , KC_VOLU , SCRLEFT , SCRFULL , SCRRIGT , TO(GAM1)},
  { KC_ESC  , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGUP , _______ , KC_VOLD , XXXXXXX , XXXXXXX , XXXXXXX , TO(DV)  },
  { XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PGDN , _LAYER_ , KC_MUTE , XXXXXXX , XXXXXXX , XXXXXXX , TO(QW)  },
  { RESET   , _______ , _______ , _______ , _______ , _______ , _______ , KC_LSFT , KC_LGUI , KC_LALT , KC_LCTL }
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
