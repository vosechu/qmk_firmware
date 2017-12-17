// Commands:
// make atreus62:vosechu
// avrdude -patmega32u4 -cavr109 -b57600 -Uflash:w:atreus62_vosechu.hex -P/dev/tty.usbmodem1411

// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
#include "atreus62.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
enum {
  QW = 0,
  RSE,
  LWR
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
#define SFTZED SFT_T(KC_Z)
#define SPCLWR LT(LWR, KC_SPC)
#define SPCRSE LT(RSE, KC_SPC)

// Make Overloaded Keys switch faster
#define TAPPING_TERM 200

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QW] =  { /* ================================================== QWERTY ============================================================ */
  { KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , _______ , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC },
  { KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , _______ , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_MINS },
  { KC_ESC  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , _______ , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_ENT  },
  { KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_BSPC , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_QUOT },
  { KC_HYPR , CTLGRV  , ALTTAB  , KC_LGUI , KC_LSFT , SFTSPC  , SPCRSE  , KC_SPC  , KC_ENT  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT }
},
[LWR] = { /* ================================================== LOWER ============================================================= */
  { _______ , _______ , _______ , _______ , _______ , KC_PGUP , _______ , KC_VOLU , _______ , _______ , KC_MINS , KC_EQL  , KC_DEL  },
  { _______ , _______ , _______ , _______ , _______ , KC_PGDN , _______ , KC_VOLD , _______ , _______ , KC_LBRC , KC_RBRC , KC_BSLS },
  { _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MUTE , _______ , _______ , _______ , _______ , _______ },
  { _______ , _______ , _______ , _______ , _______ , _______ , _LAYER_ , _______ , _______ , _______ , _______ , _______ , _______ },
  { _______ , _______ , _______ , _______ , _______ , _______ , XXXXXXX , _______ , _______ , _______ , _______ , _______ , _______ }
},
[RSE] = { /* ================================================== RAISE ============================================================= */
  { _______ , _______ , _______ , _______ , _______ , KC_PGUP , _______ , KC_VOLU , _______ , _______ , KC_MINS , KC_EQL  , KC_DEL  },
  { _______ , _______ , _______ , _______ , _______ , KC_PGDN , _______ , KC_VOLD , _______ , _______ , KC_LBRC , KC_RBRC , KC_BSLS },
  { _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MUTE , _______ , _______ , _______ , _______ , _______ },
  { _______ , _______ , _______ , _______ , _______ , _______ , XXXXXXX , _______ , _______ , _______ , _______ , _______ , _______ },
  { _______ , _______ , _______ , _______ , _______ , _______ , _LAYER_ , _______ , _______ , _______ , _______ , _______ , _______ }
}
};
