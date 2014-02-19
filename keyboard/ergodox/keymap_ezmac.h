#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "debug.h"
#include "keymap.h"

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap: Default Layer in QWERTY
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ~    |   1  |   2  |   3  |   4  |   5  |  F5  |           |  F6  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   ]    |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~L1  | +L2  | Caps | LAlt | LGui |                                       |  Lft |  Up  |  Dn  | Rght | ~L6  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | ???  | LALT |       | RALT | ???  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LMETA|       | RMETA|      |      |
     *                                 | BkSp |  ~L1 |------|       |------|  ~L1 | Space|
     *                                 |      |      | LCTRL|       | RCTRL|      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     *
     ****************************************************************************************************
     *
     * This layout is based off "Blueshift".  There should be a link, but a google for ergodox and blueshift should get it.
     * I may have missed a few keys or changed them and not updated the docs
     *
     ****************************************************************************************************
     *
     *
     *
     * Keymap: Default Layer in Workman
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  ~     |   f1 |  f2  |  f3  |  f4  |   f5 |  f6  |           |  f7  |  f8  |  f9  |  f10 |  f11 | f12  |   ??   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   D  |   R  |   W  |   B  |  NO  |           | ~L7  |   J  |   F  |   U  |   P  |   $  |   :    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Tab/Shf|   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   -    |
     * |--------+------+------+------+------+------| Home |           | End  |------+------+------+------+------+--------|
     * | LCtrl  |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |   /  |   |    |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~L5  | ~L2  | Caps | LAlt | LGui |                                       |  Lft |  Up  |  Dn  | Rght | ~L6  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | TRNS |       | TRNS | ???  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 | ESC  |  ~L1 |------|       |------|  ~L1 | Enter|
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 `--------------------'       `--------------------'
     *
     * Keymap: Default Layer in Workman / with Shift
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  `     |   1  |   2  |   3  |   4  |   5  |   "  |           |   \  |   6  |   7  |   8  |   9  |   0  |   +    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   D  |   R  |   W  |   B  |  NO  |           | ~L7  |   J  |   F  |   U  |   P  |   @  |   %    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Tab/Shf|   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   _    |
     * |--------+------+------+------+------+------| Home |           | End  |------+------+------+------+------+--------|
     * | LCtrl  |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |   /  |   &    |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~L5  | ~L2  | Caps | LAlt | LGui |                                       |  Lft |  Up  |  Dn  | Rght | ~L6  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |  L0  |  +L2 |       | PgUp | Del  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |  NO  |       | PgDn |      |      |
     *                                 | BkSp |  ESC |------|       |------| Enter| Space|
     *                                 |      |      |  Spc |       | Ins  |      |      |
     *                                 `--------------------'       `--------------------'
     *
     */

/*
 * I'd like to have no combo keys required.  that means all modifiers should be toggle-able
 * the question is "Should it act like sticky keys or just be oneshot?"
 *
 * 
 */

#define KC_COMBO(keys) keys

    KEYMAP(  // Layer0: default
        // left hand
        GRV, 1,   2,   3,   4,   5,   F5,
        TAB, Q,   W,   E,   R,   T,   NO,
        ESC, A,   S,   D,   FN9,   G,
        LSFT,Z,   X,   C,   V,   B,   NO,
        FN1,FN4,FN2,LEFT,FN10,
                                      LGUI,LALT,
                                           LGUI,
                                 BSPACE, FN1, LCTRL,
        // right hand
             F6, 6,   7,   8,   9,   0,   MINS,
             NO ,Y,   U,   I,   O,   P,   BSLS,
                  H,   J,   K,   L,   SCLN,QUOT,
             NO, N,   M,   COMM,DOT, SLSH,RSFT,
                       LEFT,DOWN,UP,  RGHT,F12,
        RALT,RGUI,
        RGUI,
        RCTRL, FN1, SPACE
    ),

    KEYMAP(  // Layer1: blueshift
        // left hand
        NO, F1, F2, F3, F4, F5, F6, 
        TRNS, NO, NO, NO, NO, NO, TRNS,
        TRNS, FN5, FN6, NO, NO, NO,
        TRNS,NO, NO, NO, NO, NO, TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           NO,
                                 ESC,TRNS,TRNS,
        // right hand
             F7, F8, F9, F10, F11, F12, MINUS,
             TRNS, TRNS,LBRC, RBRC, FN7 , FN8, EQUAL,
                LEFT,   DOWN,   UP,   RIGHT, NO  ,   TRNS,
             TRNS,APP, INS,   HOME,PGUP,TRNS,TRNS,
                       DEL,END,PGDN,SLASH,TRNS,
        TRNS,TRNS,
        NO,
        TRNS,TRNS,ENTER
    ),

    KEYMAP(  // Layer2: numpad, leftled:blue
        // left hand
        TRNS,NO,  NO,  NO,  NO,  PAUS,PSCR,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  TRNS,NO,
        TRNS,NO,  NO,  NO,  TRNS,NO,  TRNS,
        TRNS,TRNS,FN3,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             SLCK,NLCK,PSLS,PAST,PAST,PMNS,BSPC,
             TRNS,NO,  P7,  P8,  P9,  PMNS,PGUP,
                  TRNS,P4,  P5,  P6,  PPLS,PGDN,
             TRNS,NO,  P1,  P2,  P3,  PPLS,PENT,
                       P0,  PDOT,SLSH,PENT,PENT,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer3: F-keys + PgUp/PgDn on right hand, leftled:green
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  TRNS,NO,  NO,  NO,
        TRNS,NO,  TRNS,NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  F1,  F2,  F3,  F4,  PGUP,
                  NO,  F5,  F6,  F7,  F8,  PGDN,
             TRNS,NO,  F9,  F10, F11, F12, APP,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),

    KEYMAP(  // Layer4: unconvenient keys on right hand, leftled:red
        // left hand
        FN0,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,NO,  NO,  NO,  NO,
        TRNS,TRNS,NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,

        // in Workman right hand will be:
        //              +
        //    ^ { } ( ) =
        //    ' ! $ " ; \
        //    # [ < > ] \
        //

        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  PPLS,
             TRNS,MINS,4,   5,   9,   0,   EQL,
                  BSLS,2,   P,   FN1, 1,   FN2,
             TRNS,3,   6,   FN3, FN4, 7,   FN2,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer5: F-keys instead of numbers, leftled:red
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F6,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F7,  F8,  F9,  F10, F11, F12, TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer6: F-keys, cursor, Workman-layer switch, Teensy, leftled:red+onboard
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F6,
        FN0, NO,  PGUP,UP,  PGDN,PGUP,TRNS,
        TRNS,NO,  LEFT,DOWN,RGHT,PGDN,
        TRNS,INS, DEL, END, HOME,NO,  TRNS,
        FN18,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F7,  F8,  F9,  F10, F11, F12, MINS,
             TRNS,PGUP,PGUP,UP,  PGDN,NO,  FN0,
                  PGDN,LEFT,DOWN,RGHT,NO,  TRNS,
             TRNS,NO,  HOME,END, DEL, INS, TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    //
    // rarely used
    //

    KEYMAP(  // Layer7: F-keys only, leftled:red
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,F13, F14, F15, F16, NO,  TRNS,
        TRNS,F17, F18, F19, F20, NO,
        TRNS,F21, F22, F23, F24, NO,  TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  F1,  F2,  F3,  F4,  TRNS,
                  NO,  F5,  F6,  F7,  F8,  TRNS,
             TRNS,NO,  F9,  F10, F11, F12, TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer8: mouse and navigation, leftled:blue and green
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  TRNS,NO,  NO,
        TRNS,NO,  NO,  TRNS,NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,

        // right hand
             TRNS,NO,  NO,  NO,  NO,  NO,  NO,
             TRNS,BTN2,WH_L,WH_U,WH_D,WH_R,PGUP,
                  BTN1,MS_L,MS_U,MS_D,MS_R,PGDN,
             TRNS,BTN3,HOME,END, DEL, INS, NO,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

/*
    // templates to copy from

    KEYMAP(  // LayerN: transparent on edges + hard-defined thumb keys, all others are empty
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
    KEYMAP(  // LayerN: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
*/

};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
    ONE_SHOT_SHIFT,
    ONE_SHOT_ALT,
    ONE_SHOT_CTRL,
    ONE_SHOT_META,
    ONE_SHOT_BLUESHIFT,
};

enum macro_id {
    LSHIFT_LBRACE,
    LSHIFT_RBRACE,
    LSHIFT_LT,
    LSHIFT_GT,
    HELLO,
    VOLUP,
};


/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key

    ACTION_LAYER_MOMENTARY(1),                      // FN1 - Toggle layer one
    ACTION_LAYER_ON(2, ON_PRESS),                   // FN2 - Push layer 2
    ACTION_LAYER_OFF(2, ON_PRESS),                            // FN3 - Pop layer 2
    ACTION_LAYER_MOMENTARY(4),                      // FN4 - Toggle layer four 


    ACTION_MACRO_TAP(LSHIFT_LT),                    // FN5
    ACTION_MACRO_TAP(LSHIFT_GT),                    // FN6
    ACTION_MACRO_TAP(LSHIFT_LBRACE),                // FN7
    ACTION_MACRO_TAP(LSHIFT_RBRACE),                // FN8

    ACTION_LAYER_TAP_KEY(1, KC_F),                  // FN9 = layer push for blueshift on F.
    ACTION_FUNCTION_TAP(ONE_SHOT_SHIFT),            // FN10 = One shot shift.

    ACTION_MODS_TAP_KEY(MOD_LSFT, KC_FN12),         // FN11 = LShift with tap Tab
    ACTION_MODS_ONESHOT(MOD_LSFT),
    ACTION_MODS_TAP_KEY(MOD_LALT, KC_SPC),          // FN13 = LAlt   with tap Space
    ACTION_MODS_TAP_KEY(MOD_LGUI, KC_ESC),          // FN14 = LGui   with tap Escape
    ACTION_MODS_TAP_KEY(MOD_RSFT, KC_QUOT),         // FN15 = RShift with tap quotes
    ACTION_MODS_TAP_KEY(MOD_RCTL, KC_RBRC),         // FN16 = RCtrl  with tap ]

    ACTION_LAYER_SET(0, ON_BOTH),                   // FN17 - set Layer0
    ACTION_LAYER_SET(1, ON_BOTH),                   // FN18 - set Layer1, to use Workman layout at firmware level
    ACTION_LAYER_SET(2, ON_BOTH),                   // FN19 - set Layer2, to use with Numpad keys

    ACTION_LAYER_MOMENTARY(2),                      // FN20 - momentary Layer2, to use with Numpad keys
    ACTION_LAYER_TAP_KEY(5, KC_ENT),                // FN21 - momentary Layer5 on Enter, to use with F* keys on top row
    ACTION_LAYER_TAP_KEY(6, KC_ENT),                // FN22 - momentary Layer6 on Enter, to use with F* keys on top row, cursor, Teensy, Workman-layer switch
    ACTION_LAYER_MOMENTARY(7),                      // FN23 - momentary Layer7, to use with F* keys (F1-F24)

    ACTION_LAYER_TAP_KEY(4, KC_Z),                  // FN24 = momentary Layer4 on Z key, to use with unconvenient keys
    ACTION_LAYER_TAP_KEY(3, KC_X),                  // FN25 = momentary Layer3 on X key, to use with F* keys
    ACTION_LAYER_TAP_KEY(8, KC_C),                  // FN26 = momentary Layer8 on C key, to use with mouse and navigation keys
    ACTION_LAYER_TAP_KEY(2, KC_V),                  // FN27 = momentary Layer2 on V key, to use with Numpad keys

    // i'd like to remove this - will try to get used to live without this and convert them to usual keys
    ACTION_LAYER_TAP_KEY(4, KC_A),                  // FN28 = momentary Layer4 on A key, to use with unconvenient keys
    ACTION_LAYER_TAP_KEY(3, KC_S),                  // FN29 = momentary Layer3 on S key, to use with F* keys
    ACTION_LAYER_TAP_KEY(8, KC_D),                  // FN30 = momentary Layer8 on D key, to use with mouse and navigation keys
    ACTION_LAYER_TAP_KEY(2, KC_F),                  // FN31 = momentary Layer2 on F key, to use with Numpad keys
};





/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt);



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt);
