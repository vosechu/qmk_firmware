// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "vosechu.h"

#define RED_BRIGHTNESS 2
#define GREEN_BRIGHTNESS 1
#define BLUE_BRIGHTNESS 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[DV] = LAYOUT( /* ================================================== DVORAK ============================================================ */
  PAWFIVE , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y         , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , KC_BSLS ,
  KC_ESC  , KC_A    , KC_O    , KC_E    , LWR_U   , KC_I         , KC_D    , RSE_H   , KC_T    , KC_N    , KC_S    , KC_SLSH ,
  MOUKEY  , KC_SCLN , KC_Q    , KC_J    , KC_K    , KC_X         , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , KC_ENT  ,
                                CTLGRV  , ALTTAB  , KC_LGUI      , KC_MINS , KC_EQL  , KC_SLSH ,
                      RESET   , KC_ESC  , LFT_BK  , SFTSPC       , KC_SPC  , LFT_ENT , KC_BSLS , XXXXXXX
),
[QW] = LAYOUT( /* ================================================== QWERTY ============================================================ */
  PAWFIVE , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T         , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSLS ,
  KC_ESC  , KC_A    , KC_S    , KC_D    , LWR_F   , KC_G         , KC_H    , RSE_J   , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
  MOUKEY  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B         , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
                                CTLGRV  , ALTTAB  , KC_LGUI      , KC_MINS , KC_EQL  , KC_SLSH ,
                      RESET   , KC_ESC  , LFT_BK  , SFTSPC       , KC_SPC  , LFT_ENT , KC_BSLS , XXXXXXX
),
[RSE] = LAYOUT( /* ================================================= LOWER ============================================================ */
  _______ , KC_LABK , KC_RABK , KC_LCBR , KC_RCBR , XXXXXXX      , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
  _______ , KC_LPRN , KC_RPRN , KC_LBRC , KC_RBRC , XXXXXXX      , XXXXXXX , _LAYER_ , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX      , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
                                _______ , _______ , _______      , _______ , _______ , _______ ,
                      _______ , _______ , _______ , _______      , _______ , _______ , _______ , _______
),
[LWR] = LAYOUT( /* ================================================= RAISE ============================================================ */
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX      , XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX , _______ ,
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , _LAYER_ , XXXXXXX      , XXXXXXX , KC_4    , KC_5    , KC_6    , XXXXXXX , _______ ,
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX      , XXXXXXX , KC_1    , KC_2    , KC_3    , XXXXXXX , _______ ,
                                _______ , _______ , _______      , _______ , KC_0    , KC_DOT  ,
                      _______ , _______ , _______ , _______      , _______ , _______ , _______ , _______
),
[LFT] = LAYOUT( /* ================================================= LIFT ============================================================ */
  _______ , HISTBAK , TABLEFT , KC_UP   , TABRIGT , HISTFWD      , KC_VOLU , SLACKUP , SCRLEFT , SCRFULL , SCRRIGT , _______ ,
  _______ , KC_ESC  , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGUP      , KC_VOLD , SLACKDN , XXXXXXX , XXXXXXX , TO(QW)  , _______ ,
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PGDN      , KC_MUTE , XXXXXXX , XXXXXXX , XXXXXXX , TO(DV)  , _______ ,
                                _______ , _______ , _______      , KC_LGUI , KC_LALT , KC_LCTL ,
                      RESET   , _LAYER_ , _______ , KC_BSPC      , SFTSPC  , _LAYER_ , _______ , _______
),
[MOUSE] = LAYOUT( /* =============================================== MOUSE ============================================================ */
  _______ , _______ , _______ , _______ , _______ , _______      , _______ , _______ , _______ , _______ , _______ , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______      , _______ , MS_BTN1 , MS_BTN2 , MS_BTN3 , _______ , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______      , _______ , _______ , _______ , _______ , _______ , _LAYER_ ,
                                _______ , _______ , _______      , _______ , _______ , _______ ,
                      _______ , _______ , _______ , _______      , _______ , _______ , _______ , _______
)
}; // end keymaps block

report_mouse_t currentReport = {};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
    case PAWFIVE:
      SEND_STRING(":pawfive:");
      return false;

		//MOUSE layer needs to be handled the same way as NUMKEY, but differently from shift
		case MOUKEY:
			if (record->event.pressed) {
				layer_on(MOUSE);
				blu_led_on();
			} else {
				layer_off(MOUSE);
				blu_led_off();
			}
			return false;
			break;

		//mouse buttons, for 1-3, to update the mouse report:
		case MS_BTN1:
			currentReport = pointing_device_get_report();
			if (record->event.pressed) {
				//update mouse report here
				currentReport.buttons |= MOUSE_BTN1; //MOUSE_BTN1 is a const defined in report.h
        red_led_on();
			} else {
				//update mouse report here
				currentReport.buttons &= ~MOUSE_BTN1;
        red_led_off();
			}
			pointing_device_set_report(currentReport);
			return false;
			break;
		case MS_BTN2:
			currentReport = pointing_device_get_report();
			if (record->event.pressed) {
				//update mouse report here
				currentReport.buttons |= MOUSE_BTN2; //MOUSE_BTN2 is a const defined in report.h
			} else {
				//update mouse report here
				currentReport.buttons &= ~MOUSE_BTN2;
			}
			pointing_device_set_report(currentReport);
			return false;
			break;
		case MS_BTN3:
			currentReport = pointing_device_get_report();
			if (record->event.pressed) {
				//update mouse report here
				currentReport.buttons |= MOUSE_BTN3; //MOUSE_BTN3 is a const defined in report.h
			} else {
				//update mouse report here
				currentReport.buttons &= ~MOUSE_BTN3;
			}
			pointing_device_set_report(currentReport);
			return false;
			break;
	}
	return true;
};
