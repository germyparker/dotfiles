#include "keymap_common.h"


// Default
#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[KEYMAPS_COUNT][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* Keymap 0: Default Layer
     * ,-------------------------------------------------.
     * |Esc | Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P| Bs  |
     * |-------------------------------------------------|
     * |Tab  |  A|  S|  D|  F|  G|  H|  J|  K|  L|   Ent |
     * |-------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,| SFT|FN0|
     * |-------------------------------------------------|
     * |Ctrl|Win |Alt |       Space            |Fn1 | Fn2|
     * `-------------------------------------------------'
     */
    KEYMAP(
        ESC, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P, BSPC,\
        TAB,A,   S,   D,   F,   G,   H,   J,   K,   L,       ENT,\
        LSFT,     Z,   X,   C,   V,   B,   N,   M, COMM,RSFT,  FN0,\
        LCTL,LGUI,LALT,          SPC,                  FN1,FN2),

    /* Keymap 1: Raised layer, FN0
     * ,-------------------------------------------------.
     * | ` |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|Del  |
     * |-------------------------------------------------|
     * |    |PgUp|Home| = | ; | [ | ] | ' | \ | - |      |
     * |-------------------------------------------------|
     * |     |PgDn|End|   |   |    |   |    | . |    |   |
     * |-------------------------------------------------|
     * |    |    |    |                        |    |    |
     * `-------------------------------------------------'
     */
    KEYMAP( /*RAISE*/
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   DEL,\
        TRNS,PGUP,HOME,EQL,SCLN,LBRC,RBRC,QUOT,BSLS,  MINS,     TRNS,\
        TRNS,     PGDN,  END, FN3, FN4, VOLU,VOLD,MUTE,DOT,TRNS,TRNS,\
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS),
    

    /* Keymap 2: Left layer, FN1
     * ,-------------------------------------------------.
     * |F12| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10| F11 |
     * |-------------------------------------------------|
     * |    |    |    |   |   |   |   |   |   |   |      |
     * |-------------------------------------------------|
     * |     |    |   |FN3|FN4|VolU|VolD|Mute| / |   |   |
     * |-------------------------------------------------|
     * |    |    |    |                        |    |    |
     * `-------------------------------------------------'
     */

    KEYMAP( /*LEFT IT*/
        F12,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,\
        TRNS, PGDN,  END, FN3, FN4, VOLU,VOLD,MUTE,SLSH,TRNS,TRNS,\
        TRNS,TRNS,TRNS,          TRNS,           TRNS,TRNS),

    /* Keymap 3: Right layer, FN2
     * ,-------------------------------------------------.
     * |   |   | Up|   |   |   |   |   |   |   |Psrc|    |
     * |-------------------------------------------------|
     * |    |Left|Down|Rgt|   |   |   |   |   |   |      |
     * |-------------------------------------------------|
     * |     |    |   |   |   |    |    |   |Ins|    |   |
     * |-------------------------------------------------|
     * |    |    |    |                        |    |    |
     * `-------------------------------------------------'
     */

    KEYMAP( /*RIGHT IT*/
        TRNS, TRNS, UP, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, PSCR, TRNS,\
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,     TRNS,\
        TRNS,     TRNS,  TRNS, TRNS, TRNS, TRNS,TRNS,TRNS,INS,TRNS,TRNS,\
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS)

};

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[FN_ACTIONS_COUNT] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const uint16_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_MOMENTARY(2),
    [2] = ACTION_LAYER_MOMENTARY(3),
    [3] = ACTION_BACKLIGHT_DECREASE(),
    [4] = ACTION_BACKLIGHT_INCREASE()
};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif

/*
 * Action macro definition
 */
enum macro_id {
    KEYPAD_00 = 0,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case KEYPAD_00:
            return (record->event.pressed ?
                    MACRO( T(P0), T(P0), END ) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
}
