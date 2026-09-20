
#include QMK_KEYBOARD_H




void keyboard_post_init_user(void) {
   
    oled_scroll_set_area(0, 7);
    oled_scroll_left();        
}

bool oled_task_user(void) {

    oled_write_P(PSTR("    IK DEXK KEYBOARD - WELCOME!    "), false);
    
    return false;
}
enum custom_keycodes {
    Q_VSCODE = SAFE_RANGE,
    Q_BRAVE,
    Q_ACMD,
    Q_CAD,
    Q_EVERYTHING,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case Q_VSCODE:
            if (record->event.pressed) {
                
                SEND_STRING(SS_DOWN(X_LGUI) "s" SS_UP(X_LGUI));
                wait_ms(200);
                SEND_STRING("Visual Studio Code\n");
            }
            
            return false;

            case Q_BRAVE:
            if (record->event.pressed) {
               
                SEND_STRING(SS_DOWN(X_LGUI) "s" SS_UP(X_LGUI)); 
                wait_ms(200);
                SEND_STRING("Brave\n");
            }
            
            return false;
            case Q_ACMD:
            if (record->event.pressed) {
                
                SEND_STRING(SS_DOWN(X_LGUI) "s" SS_UP(X_LGUI));
                wait_ms(200);
                SEND_STRING(SS_DOWN(X_LSFT) "Command Prompt\n" SS_UP(X_LSFT));
            }
            
            return false;
            case Q_CAD:
            if (record->event.pressed) {
                
                SEND_STRING(SS_DOWN(X_LGUI) "s" SS_UP(X_LGUI)); 
                wait_ms(200);
                SEND_STRING("Autodesk Fusion\n");
            }
            
            return false;

            case Q_EVERYTHING:
            if (record->event.pressed) {
               
                SEND_STRING(SS_DOWN(X_LGUI) "s" SS_UP(X_LGUI)); 
                wait_ms(200);
                SEND_STRING("Everything\n");
            }
            
            return false;
            default:
            return true;
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] =LAYOUT_4x4(
        KC_CPNL,   KC_MAIL,   KC_DEL,   Q_EVERYTHING,
        KC_VOLU,   KC_VOLD,   KC_CALC,   KC_MYCM,
        KC_MPRV,   KC_MNXT,   Q_BRAVE,   Q_VSCODE,
        KC_MUTE,   KC_MPLY,   Q_CAD, Q_ACMD
    )
};
