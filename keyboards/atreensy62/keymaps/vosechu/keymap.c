// Commands:
// make atreus62:vosechu
// avrdude -patmega32u4 -cavr109 -b57600 -Uflash:w:atreus62_vosechu.hex -P/dev/tty.usbmodem1411

// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
#include "atreus62.h"
#include "vosechu.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DV] =  { /* ================================================== DVORAK ============================================================ */
  { PAWFIVE , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , _______ , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , RESET   },
  { XXXXXXX , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y    , _______ , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , XXXXXXX },
  { KC_ESC  , KC_A    , KC_O    , KC_E    , RSE_U   , KC_I    , _______ , KC_D    , LWR_H   , KC_T    , KC_N    , KC_S    , XXXXXXX },
  { XXXXXXX , KC_SCLN , KC_Q    , KC_J    , KC_K    , KC_X    , TT(LFT) , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , XXXXXXX },
  { XXXXXXX , CTLGRV  , ALTTAB  , KC_LGUI , KC_BSPC , SFTSPC  , KC_ENT  , KC_SPC  , KC_MINS , KC_EQL  , KC_SLSH , KC_BSLS , XXXXXXX }
},
[QW] =  { /* ================================================== QWERTY ============================================================ */
  { _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , _______ , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ },
  { _______ , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , _______ , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , _______ },
  { _______ , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , _______ , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT },
  { _______ , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , _______ , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , _______ },
  { KC_ESC  , _______ , _______ , KC_LALT , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ }
},
[LWR] = { /* ================================================== LOWER ============================================================= */
  { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ },
  { _______ , KC_LABK , KC_RABK , KC_LCBR , KC_RCBR , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ },
  { _______ , KC_LPRN , KC_RPRN , KC_LBRC , KC_RBRC , XXXXXXX , _______ , XXXXXXX , _LAYER_ , XXXXXXX , XXXXXXX , XXXXXXX , _______ },
  { _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ },
  { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ }
},
[RSE] = { /* ================================================== RAISE ============================================================= */
  { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ },
  { _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX , _______ },
  { _______ , XXXXXXX , XXXXXXX , XXXXXXX , _LAYER_ , XXXXXXX , _______ , XXXXXXX , KC_4    , KC_5    , KC_6    , XXXXXXX , _______ },
  { _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , KC_1    , KC_2    , KC_3    , XXXXXXX , _______ },
  { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_0    , KC_0    , KC_DOT  , XXXXXXX , _______ }
},
[LFT] = { /* ================================================== EMPTY ========================================= */
  { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ },
  { _______ , HISTBAK , TABLEFT , KC_UP   , TABRIGT , HISTFWD , _______ , KC_VOLU , SLACKUP , SCRLEFT , SCRFULL , SCRRIGT , _______ },
  { _______ , KC_ESC  , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGUP , _______ , KC_VOLD , SLACKDN , XXXXXXX , XXXXXXX , TO(DV)  , _______ },
  { _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PGDN , _LAYER_ , KC_MUTE , XXXXXXX , XXXXXXX , XXXXXXX , TO(QW)  , _______ },
  { _______ , RESET   , _______ , _______ , _______ , _______ , _______ , _______ , KC_LSFT , KC_LGUI , KC_LALT , KC_LCTL , _______ }
}
};

const uint16_t PROGMEM fn_actions[] = {

};

bool initialized = 0;

void matrix_init_user(void) {
  if (!initialized){
    rgblight_enable();
    initialized = 1;
  }
}

/* Layout TODO

* History navigation needs to be left handed only
* Need to analyze which keys get pressed when my right hand is on the mouse

*/
