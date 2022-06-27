#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "keylogger.h"
#ifdef ENCODER_ENABLE
#    include "encoder.h"
#endif
#ifdef OLED_ENABLE
#    include "oled.h"
#endif
#ifdef RAW_ENABLE
#    include "raw_hid.h"
#    define RAW_EPSIZE 32
#endif

enum custom_keycodes {
    KC_QMKBEST = SAFE_RANGE,
    ENC_MODE_L,
    ENC_MODE_R,
    KC_EVIL1,
    KC_EVIL2,
    KC_EVIL3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, MT(MOD_RSFT, KC_QUOT), MT(MOD_LCTL, KC_ESC), KC_Z, KC_X, KC_C, KC_V, KC_B, MO(2), KC_QMKBEST, KC_NO, KC_LEAD, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, ENC_MODE_L, KC_LGUI, MO(1), KC_SPC, KC_LALT, MO(1), KC_ENT, MO(2), KC_RALT, ENC_MODE_R),
        [1] = LAYOUT(KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_LSFT, KC_NO, KC_NO, KC_DEL, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RALT, KC_RSFT, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(5), KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_ESC, ENC_MODE_L, KC_LGUI, KC_NO, KC_TRNS, MO(5), MO(4), KC_BSPC, MO(3), KC_RALT, ENC_MODE_R),
        [2] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS, KC_PIPE, KC_BSLS, KC_UNDS, KC_MINS, KC_QUOT, KC_DQUO, KC_LCBR, KC_NO, KC_NO, KC_RCBR, KC_NO, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_QUES, ENC_MODE_L, KC_LALT, MO(4), KC_BSPC, MO(5), KC_NO, KC_NO, KC_NO, KC_NO, ENC_MODE_R),
        [3] = LAYOUT(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_NO, KC_NO, KC_NO, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_ESC, KC_NO, KC_NO, KC_NO, KC_SPC, KC_NO, KC_NO, KC_ENT, KC_TRNS, KC_RALT, KC_NO),
        [4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_MPRV, KC_MNXT, KC_MFFD, KC_NO, KC_BSPC, KC_NO, KC_NO, KC_NO, BL_INC, BL_DEC, KC_NO, KC_MPLY, KC_VOLD, KC_VOLU, KC_NO, KC_BRIU, KC_NO, KC_NO, KC_NO, BL_BRTG, BL_STEP, BL_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MSTP, KC_MUTE, KC_NO, KC_NO, KC_BRID, KC_ESC, KC_NO, KC_NO, KC_NO, KC_SPC, KC_NO, KC_TRNS, KC_ENT, KC_NO, KC_RALT, KC_NO),
        [5] = LAYOUT(KC_NO, KC_EVIL1, KC_EVIL2, KC_EVIL3, KC_NO, KC_NO, KC_WHOM, KC_WSCH, KC_WREF, KC_WFAV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WBAK, KC_NO, KC_NO, KC_WFWD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO)
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        /*
        SEQ_ONE_KEY(KC_F) {
            SEND_STRING("QMK is awesome.");
        }
        SEQ_TWO_KEYS(KC_D, KC_D) {
            SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
        }
        SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
            SEND_STRING("https://start.duckduckgo.com\n");
        }
        SEQ_TWO_KEYS(KC_A, KC_S) {
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
        }
        */
    }
}
/*
char keylog_str[24] = {};
// int  keylogs_str_idx = 0;

static const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d %2d %c", record->event.key.row, record->event.key.col, keycode, name);
    / *
    if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
        keylogs_str_idx = 0;
        for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
            keylogs_str[i] = ' ';
        }
    }
    keylogs_str[keylogs_str_idx] = name;
    keylogs_str_idx++;
    * /
}

const char *get_keylog(void) {
  return keylog_str;
}
*/

uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
#endif
    mod_state = get_mods();
    switch (keycode) {
        /*
        case KC_BSPC: {
            static bool delkey_reg istered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    delkey_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            return true;
        }
        */
        /*
        case KC_QMKBEST: {
            if (record->event.pressed) {
                // SEND_STRING("QMK is the best thing ever!");
                // SEND_STRING(LCTL(LSFT(KC_U)));
                // send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
                // SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
                // send_string(KC_ENT);
            } else {
                // when keycode QMKBEST is released
            }
            break;
        }
        */
        /*
        case KC_EVIL1:
            oled_write_ln_P(PSTR("EVIL"), true);
            break;
        */
#ifdef ENCODER_ENABLE
        case ENC_MODE_L: {
            if (record->event.pressed) encoder_cycle_mode(true, (mod_state & MOD_MASK_SHIFT));
            break;
        }
        case ENC_MODE_R: {
            if (record->event.pressed) encoder_cycle_mode(false, (mod_state & MOD_MASK_SHIFT));
            break;
        }
#endif
    }

    /*
    uint8_t buf[32];
    memset(buf,0x00,sizeof(buf));
    buf[0] = 0x07;
    buf[1] = (wpm >> 8) & 0xff;
    buf[2] = wpm & 0xff;
    //raw_hid_send(buf,sizeof(buf));
    */
    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        encoder_action(encoder_get_mode(true), clockwise);
    } else if (index == 1) {
        encoder_action(encoder_get_mode(false), clockwise);
    }
#    ifdef OLED_ENABLE
    oled_on();
#    endif
    return true;
}
#endif

