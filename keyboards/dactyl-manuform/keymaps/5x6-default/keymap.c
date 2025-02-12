#include "dactyl-manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN 1
#define _MOUSE 2
#define _VSCODE 3
#define HYPER(kc) (QK_LCTL | QK_LSFT | QK_LALT | QK_LGUI | (kc))

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP_5x6(
        // left hand
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_ESC,                  KC_MINS ,KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_TAB,                  KC_ENT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G, LT(_FN, KC_CAPS),    KC_BSPC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                                  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        LT(_VSCODE, KC_FN0), KC_GRV,  KC_BSLS, KC_SPC, KC_LSFT,                               KC_RSFT, KC_SPC,   KC_QUOT, KC_EQL,  KC_LBRC,
        MO(_MOUSE), KC_LGUI, KC_LALT,   KC_LCTRL,                                   KC_RIGHT, KC_LEFT, KC_UP,   KC_DOWN
         // bottom left // top left // bottom right // top right 
    ),
    
    [_FN] = KEYMAP_5x6(
            // left hand
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,         KC_F7,  KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,
            _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,      KC_DEL,  _______, KC_HOME, KC_UP,   KC_END,  KC_F12,
            _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_ENT,  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
            RESET,   _______, _______, _______, _______,                         KC_CALC, KC_MAIL, KC_MYCM, KC_WHOM, _______,
            _______, _______, _______, _______, _______,                         _______, _______, _______, _______, KC_RBRC,
            _______, _______, _______, _______,                                  _______, _______, _______, _______
        ),
    [_MOUSE] = KEYMAP_5x6(
        // left hand
        _______, _______, _______, _______, _______, KC_ACL0,                   _______, _______, _______, _______, _______, _______, 
        _______, _______, KC_WH_U, _______,  _______, KC_ACL2,                   _______, _______, _______, KC_MS_U, _______, _______, 
        _______, KC_BTN1, KC_BTN3, KC_BTN2,_______,  _______,                   _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, 
        _______, _______, KC_WH_D, _______,  _______,                                     _______, _______, _______, _______, _______, 
        _______, _______, _______, KC_BTN2, KC_BTN1,                                    KC_ACL2, KC_WH_D, _______, _______, _______, 
        _______, _______, _______, KC_ACL2,                                              _______, _______, KC_PGUP, KC_PGDOWN
    ),

    [_VSCODE] = KEYMAP_5x6(
        // left hand
        _______, _______, _______, _______, _______, _______,                   _______, HYPER(KC_6), HYPER(KC_7), HYPER(KC_8), HYPER(KC_9), HYPER(KC_0), 
        _______, _______, _______, _______,  _______, _______,                  KC_ENT,  HYPER(KC_Y), HYPER(KC_U), HYPER(KC_I),  HYPER(KC_O),HYPER(KC_P),
        _______, _______, _______, _______,_______,  _______,                   KC_BSPC, HYPER(KC_H), HYPER(KC_J), HYPER(KC_K), HYPER(KC_L), HYPER(KC_SCLN),
        _______, _______, _______, _______,  _______,                                    HYPER(KC_N),  HYPER(KC_M),HYPER(KC_COMM), HYPER(KC_1), HYPER(KC_BSLS),
        _______, _______, _______, _______,  _______,                                    KC_RSFT, KC_SPC,   HYPER(KC_QUOT), KC_EQL,  KC_LBRC,
        _______, _______, _______, _______,                                              _______, _______, KC_PGUP, KC_PGDOWN
    ),        

}; // Added missing semicolon here

void persistant_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
} 