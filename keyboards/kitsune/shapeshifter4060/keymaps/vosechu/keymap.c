#include QMK_KEYBOARD_H

#include "vosechu.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DV] = LAYOUT(
    KC_GRV  , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y                        , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , TT1     ,
    KC_ESC  , KC_A    , KC_O    , KC_E    , LWR_U   , KC_I                        , KC_D    , RSE_H   , KC_T    , KC_N    , KC_S    , TT2     ,
    KC_F13  , KC_SCLN , KC_Q    , KC_J    , KC_K    , KC_X                        , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , TT3     ,
              CTL_GRV , ALT_TAB , KC_LGUI , MO(LFT) , KC_LSFT , KC_BSPC , KC_ENT  , KC_SPC  , KC_MINS , KC_EQL  , KC_SLSH , KC_BSLS
  ),
  [QW] = LAYOUT(
    KC_GRV  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T                        , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , _______ ,
    KC_ESC  , KC_A    , KC_S    , KC_D    , LWR_F   , KC_G                        , KC_H    , RSE_J   , KC_K    , KC_L    , KC_SCLN , _______ ,
    KC_F13  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B                        , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , _______ ,
              CTL_GRV , ALT_TAB , KC_LALT , MO(LFT) , KC_LSFT , KC_BSPC , KC_ENT  , KC_SPC  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
  ),
  [LWR] = LAYOUT(
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX                     , XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , _LAYER_ , XXXXXXX                     , XXXXXXX , KC_4    , KC_5    , KC_6    , XXXXXXX , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX                     , XXXXXXX , KC_1    , KC_2    , KC_3    , XXXXXXX , _______ ,
              _______ , _______ , _______ , _______ , _______ , _______ , _______ , XXXXXXX , KC_0    , KC_DOT  , _______ , _______
  ),
  [RSE] = LAYOUT(
    _______ , KC_LABK , KC_RABK , KC_LCBR , KC_RCBR , XXXXXXX                     , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
    _______ , KC_LPRN , KC_RPRN , KC_LBRC , KC_RBRC , XXXXXXX                     , XXXXXXX , _LAYER_ , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX                     , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
              _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
  [LFT] = LAYOUT(
    _______ , BWSR_BK , TAB_LFT , KC_UP   , TAB_RGT , BWSR_FW                     , KC_MUTE , XXXXXXX , SCR_LFT , SCR_FUL , SCR_RGT , _______ ,
    _______ , XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGUP                     , KC_VOLU , SLACKUP , XXXXXXX , XXXXXXX , TO(QW)  , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PGDN                     , KC_VOLD , SLACKDN , XXXXXXX , XXXXXXX , TO(DV)  , _______ ,
              _______ , RESET   , _______ , _______ , _LAYER_ , KC_BSPC , _______ , KC_LSFT , KC_LGUI , KC_LALT , KC_LCTL , _______
  ),
  [TT1] = LAYOUT(
    _______ , _______ , _______ , KC_UP   , _______ , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
              _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
  [TT2] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
              _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
  [TT3] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
              _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  )
  // [EMPTY] = LAYOUT(
  //   _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
  //   _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
  //   _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______ , _______ ,
  //             _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  // ),
};
