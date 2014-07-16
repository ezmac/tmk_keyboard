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
#define MAIN_LAYER 0
#define MOUSE_LAYER 3
#define NORMAN_LAYER 4
#define DVORAK_LAYER 5
#define SHIFT_KEY_REFERENCE_LAYER 11
#define TMUX_MODAL_REFERENCE_LAYER 12
#define AWESOME_MODAL_REFERENCE_LAYER 13
#define BLUESHIFT_LAYER 10
#define SHORTCUT_LAYER 10
#define ONESHOTMOD_REFERENCE_LAYER 14
#define ONESHOT_TIMEOUT 0
static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //my frequent workflow is vim on right, chrome left.  ctrl+win+j or k to switch.  
  //  keys used often: ctrl, win, shift, esc, space, enter, hjkl, d, u, c, x, i [] '"-_ ()
  //  shift should be on the thumbs or be one shottable.
  //  programmer frequent symbols should be easy


  //thumb rework is an attempt to reduce my reliance on thumb based chording.
    /*
     * Keymap: Default Layer in QWERTY
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  GRV   |   1  |   2  |   3  |   4  |   5  |  F5  |           |  F6  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TAB   |   Q  |   W  |   E  |   R  |   T  |  `   |           | ESC  |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  ESC   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |    "   |
     * |--------+------+------+------+------+------|SHIFT |           |SHIFT |------+------+------+------+------+--------|
     * | shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | shift  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~L3  | ~L9  | LALT | LGUI | LCTL |                                       | RCTL | RGUI | RALT | FN4  | F12  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | MOUSE|GUIWIN|       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |TMXWIN|       |      |      |      |
     *                                 | BkSp |  ~L1 |------|       |------|  ~L1 | Space|
     *                                 |      | ESC  |GUISCN|       |      | TAB  |      |
     *                                 `--------------------'       `--------------------'
     *
     ****************************************************************************************************
     *
     * FN4 is ~9 and with the key left of 1, its the teensy key combo
     * todo: replace lmeta and rmeta with layers.  Since I always use it for gui commands, it would make sense to do tap key hold action with a layer toggle making the cluster different.
     *       this also makes sense with bksp and space..actually, using space/bksp as shift makes a lot of sense..
     */

/*
 * I'd like to have no combo keys required.  that means all modifiers should be toggle-able
 * the question is "Should it act like sticky keys or just be oneshot?"
 *
 * That was the original thought.  Turns out, sticky modifiers are annoying
 *
 * 
 */

#define KC_COMBO(keys) keys

    KEYMAP(  // Layer0: default
        // left hand
         // GRV,FN14,FN14,FN14,FN14,FN14,   F5, //use shifted numbers
          GRV,   1,   2,   3,   4,   5, GRV,
          TAB,   Q,   W,   E,   R,   T,BRKT,
          ESC,   A,   S,   D,   F,   G,
        LSFT,   Z,   X,   C,   V,   B, FN14,
         FN3, FN4, LALT,LGUI,LCTL,
                                      FN15,LALT,
                                           LGUI,
                              BSPC, FN16, LSFT,
        // right hand
         //F6,FN14,FN14,FN14,FN14,FN14,  MINS, use shifted numbers
         F6,   6,   7,   8,   9,   0,  MINS,
        FN13,   Y,   U,   I,   O,   P,   BSLS,
               H,   J,   K,   L,   SCLN,QUOT,
         TAB,  N,   M,   COMM,DOT, SLSH,RSFT,
                 RCTL,RGUI,RALT,  NO, F12,
        RALT,FN15,
        RGUI,
        RSFT, FN17, SPACE
    ),


    /*
       outer keys are evil or something.  need more []{}(), number pad, and plus.  consider layer docs above to be moot.
$test
       This is the new base layout
       ,--------------------------------------------------            ,--------------------------------------------------,
       |        |      |      |      |      |      |  ~   |           |      |      |      |      |      |      |        |
       |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
       |        |      |      |      |      |      |  [   |           |  ]   |      |      |      |      |      |        |
       |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
       |--------+------+------+------+------+------|  +   |           |  =   |------+------+------+------+------+--------|
       |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
       `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         |      |      |      |      |  '   |                                       |  "   |      |      |      |      |
         `----------------------------------'                                       `----------------------------------'
                                              ,-------------,       ,-------------.
                                              |      |      |       |      |      |
                                       ,------|------|------|       |------+------+------,
                                       |      |      |      |       |      |      |      |
                                       | BKSP | ~L1  |------|       |------|      |      |
                                       |      | ESC  | SHFT |       | SFHT |      |      |
                                       `--------------------'       `--------------------'


       This is the new shifted layer.  
       ,--------------------------------------------------            ,--------------------------------------------------,
       |        |      |      |      |      |      |  ~   |           |      |      |      |      |      |      |        |
       |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
       |        |      |      |      |      |      |  [   |           |  ]   |      |      |      |      |      |        |
       |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
       |--------+------+------+------+------+------|  +   |           |  =   |------+------+------+------+------+--------|
       |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
       `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
         |      |      |      |      |  '   |                                       |  "   |      |      |      |      |
         `----------------------------------'                                       `----------------------------------'
                                              ,-------------,       ,-------------.
                                              |      |      |       |      |      |
                                       ,------|------|------|       |------+------+------,
                                       |      |      |      |       |      |      |      |
                                       |      |      |------|       |------|      |      |
                                       |      |      |      |       |      |      |      |
                                       `--------------------'       `--------------------'

      
      * this is left for ease, but blueshift layer is now layer 10 and blueshift's FN14 layer is 11.  This is because higher
      * levels have priority and having blueshift at 10 allows the colmak layer (4) to still use the same blueshift.
     * This layout is based off "Blueshift".  There should be a link, but a google for ergodox and blueshift should get it.
     * I may have missed a few keys or changed them and not updated the docs
     *
     ****************************************************************************************************
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------. *
     * |  App   |   f1 |  f2  |  f3  |  f4  |   f5 |  f6  |           |  f7  |  f8  |  f9  |  f10 |  f11 | f12  | PgUp   | *
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TAB   |      |   {  |   }  |   $  |   %  |  =>  |           |      |      |      |      |      |      | PgDn   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  End   |   _  |   (  |   )  |   +  |   "  |------|           |------| left | down |  up  |right |   $  |   =    |
     * |--------+------+------+------+------+------|  ->  |           |      |------+------+------+------+------+--------j
     * | shift  |  -   |   [  |   ]  |      |      |      |           |      |  !   | INS  | HOME | PGUP |      |  shift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Vol+ | Vol- |Next  |      |      |                                       | DEL  |  END | PGDN |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | TRNS |       | TRNS | ???  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 | ESC  | TAB  |------|       |------|  TAB | Enter|
     *                                 |      |      | RCTL |       | RCTL |      |      |
     *                                 `--------------------'       `--------------------'
     *
     */

    KEYMAP(  // Layer1: blueshift
        // left hand
        APP,  F1,  F2,  F3,  F4,  F5,  F6, 
        TAB,TRNS,FN14,FN14,FN14,FN14,FN11,
         ESC,FN14,FN14,FN14,FN14,FN14,
        TRNS,MINS,FN14,MINS,BSLS, EQL,FN12,
        VOLU,VOLD,MNXT,TRNS,TRNS,
                                        TRNS,TRNS,
                                           TRNS,
                              ESC, FN1,  LCTL,
        // right hand
          F7,  F8,  F9, F10, F11, F12,PGUP,
          NO,TRNS,FN14,MINS,TRNS,TRNS,PGDN,
        LEFT,DOWN,  UP,RIGHT,FN14, EQL,
          NO,FN14,INS,HOME,PGUP,TRNS,TRNS,
                  DEL, END,PGDN,TRNS,TRNS,
        TRNS,FN14,
        TRNS,
        TRNS, FN1, ENTER
    ),

    /*
     *
     *
     * this is a dupe of layer 1's blueshift layout.  Layer 2 is used for fn14's shifted keys.
     * if layer 1's key is FN14, it will shift the key from this layer (layer 2).
     * This firmware can have 32 keyboard layers, and 32 functions, but functions are more useful to me.
     * using a layer for reference allows me to use only one function and access any shifted key.  
     * That's worth the tradeoff to me.
     * ,--------------------------------------------------.           ,--------------------------------------------------. *
     * |  App   |   f1 |  f2  |  f3  |  f4  |   f5 |  f6  |           |  f7  |  f8  |  f9  |  f10 |  f11 | f12  | PgUp   | *
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TAB   |      |   {  |   }  |   $  |   %  |  =>  |           |      |      |      |      |      |      | PgDn   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  End   |   _  |   (  |   )  |   +  |   "  |------|           |------| left | down |  up  |right |   $  |   =    |
     * |--------+------+------+------+------+------|  ->  |           |      |------+------+------+------+------+--------j
     * | shift  |  -   |   [  |   ]  |      |      |      |           |      |  !   | INS  | HOME | PGUP |      |  shift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Vol+ | Vol- |Next  |      |      |                                       | DEL  |  END | PGDN |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | TRNS |       | TRNS | ???  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 | ESC  | TAB  |------|       |------|  TAB | Enter|
     *                                 |      |      | RCTL |       | RCTL |      |      |
     *                                 `--------------------'       `--------------------'
     *
     ****************************************************************************************************/
    KEYMAP(  
        // left hand
        // layer 2 is for blueshift FN14
        TRNS,  NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,TRNS,LBRC,RBRC,   4,   5,TRNS,
        TRNS,  NO,   9,   0, EQL,QUOT,
        LSFT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,

        // right hand
             TRNS,  NO,  NO,  NO,  NO,  NO,  NO,
             TRNS,   6,   7,   8,   9,   0,PGUP,
                    NO,  NO,  NO,  NO,BSLS,  NO,
               NO,   1,SCLN,COMM, DOT,MINS,  NO,
                         NO,  NO,  NO,  NO,  NO,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer3: experimental mouse key layer
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
             BTN3,NO,  NO,  NO,  NO,  NO,  NO,
             BTN1,WH_L,WH_D,WH_U,WH_R,WH_R,PGUP,
             MS_L,MS_D,MS_U,MS_R,PGDN,TRNS,
             BTN2,BTN2,HOME,END, DEL, INS, NO,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
    /*
     *
     *
     * this is the COLEMAN layout
     *
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  GRV   |   1  |   2  |   3  |   4  |   5  |  F5  |           |  F6  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TAB   |   Q  |   W  |   F  |   P  |   G  |  `   |           | ESC  |   J  |   L  |   U  |   Y  |   ;  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  ESC   |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |    "   |
     * |--------+------+------+------+------+------|MOUSE |           | TAB  |------+------+------+------+------+--------|
     * | shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | shift  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~L1  | ~L9  | +L3  | LAlt | LGui |                                       | RCTL | RALT | FN13 | FN4  | F12  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |SFTCTL| LALT |       | RALT |SFTCTL|
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LMETA|       | RMETA|      |      |
     *                                 | BkSp |  ~L1 |------|       |------|  ~L1 | Space|
     *                                 | Shift| ESC  | LCTL |       | RCTL | TAB  | Shift|
     *                                 `--------------------'       `--------------------'
     *
     ****************************************************************************************************/
    KEYMAP(  // Layer4: norman
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,   F,   P,   G,TRNS,
        TRNS,TRNS,   R,   S,   T,   D,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
         FN5,TRNS, FN3,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,FN16,TRNS,


        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,   J,   L,   U,   Y,SCLN,TRNS,
                     H,   N,   E,   I,   O,TRNS,
             TRNS,   K,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,FN17,TRNS
    ),
        // right hand



    KEYMAP(  // Layer5: dvorak layer
        // left hand
        GRV,FN14,FN14,FN14,FN14,FN14,  F5,
        TRNS,SCLN,COMM,DOT ,   P,   Y,TRNS,
        TRNS,   A,   O,   E,   U,   I,
        TRNS,QUOT,   Q,   J,   K,   X,TRNS,
        FN5,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
               F6,FN14,FN14,FN14,FN14,FN14,TRNS,
             TRNS,   F,   G,   R,   L,SLSH,TRNS,
                     D,   H,   T,   N,   S,MINS,
             TRNS,   B,   M,   W,   V,   Z,TRNS,
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
    KEYMAP(  // Layer9: numpad, leftled:blue
        // left hand
         FN0,NO,  NO,  NO,  NO,  PAUS,PSCR,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  TRNS,NO,
        TRNS,NO,  NO,  NO,  TRNS,NO,  TRNS,
        TRNS,TRNS,FN2,TRNS,TRNS,
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

     /*
     * This layout is based off "Blueshift".  There should be a link, but a google for ergodox and blueshift should get it.
     * I may have missed a few keys or changed them and not updated the docs
     *
     ****************************************************************************************************
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------. *
     * |  App   |   f1 |  f2  |  f3  |  f4  |   f5 |  f6  |           |  f7  |  f8  |  f9  |  f10 |  f11 | f12  | PgUp   | *
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TAB   |      |   {  |   }  |   $  |   %  |  =>  |           |      |      |  _   |  -   |      |      | PgDn   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  End   |   _  |   (  |   )  |   +  |   "  |------|           |------| left | down |  up  |right |   $  |   =    |
     * |--------+------+------+------+------+------|  ->  |           |      |------+------+------+------+------+--------j
     * | shift  |  -   |   [  |   ]  |      |      |      |           |      |  !   | INS  | HOME | PGUP |      |  shift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Vol+ | Vol- |Next  |      |      |                                       | DEL  |  END | PGDN |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | TRNS |       | TRNS | ???  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 | ESC  | TAB  |------|       |------|  TAB | Enter|
     *                                 |      |      | RCTL |       | RCTL |      |      |
     *                                 `--------------------'       `--------------------'
     *
     */

    KEYMAP(  // Layer10: blueshift
        // left hand
        APP,  F1,  F2,  F3,  F4,  F5,  F6, 
        TAB,TRNS,FN14,FN14,FN14,FN14,FN11,
         ESC,FN14,FN14,FN14,FN14,FN14,
        TRNS,MINS,LBRC,RBRC,TRNS,TRNS,FN12,
        VOLU,VOLD,MNXT,TRNS,TRNS,
                                        TRNS,TRNS,
                                           TRNS,
                              ESC, FN1,  LCTL,
        // right hand
          F7,  F8,  F9, F10, F11, F12,PGUP,
          NO,TRNS,FN14,MINS,TRNS,TRNS,PGDN,
        LEFT,DOWN,  UP,RIGHT,FN14, EQL,
          NO,FN14,INS,HOME,PGUP,TRNS,TRNS,
                  DEL, END,PGDN,TRNS,TRNS,
        TRNS,FN14,
        TRNS,
        TRNS, FN1, ENTER
    ),

    /*
     *
     *
     * this is a dupe of layer 10's blueshift layout.  Layer 11 is used for fn14's shifted keys.
     * if layer 10's key is FN14, it will shift the key from this layer (layer 11).
     * This firmware can have 32 keyboard layers, and 32 functions, but functions are more useful to me.
     * using a layer for reference allows me to use only one function and access any shifted key.  
     * That's worth the tradeoff to me.
     * ,--------------------------------------------------.           ,--------------------------------------------------. *
     * |  App   |   f1 |  f2  |  f3  |  f4  |   f5 |  f6  |           |  f7  |  f8  |  f9  |  f10 |  f11 | f12  | PgUp   | *
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TAB   |      |   {  |   }  |   $  |   %  |  =>  |           |      |      |  _   |  -   |      |      | PgDn   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  End   |   _  |   (  |   )  |   +  |   "  |------|           |------| left | down |  up  |right |   $  |   =    |
     * |--------+------+------+------+------+------|  ->  |           |      |------+------+------+------+------+--------j
     * | shift  |  -   |   [  |   ]  |      |      |      |           |      |  !   | INS  | HOME | PGUP |      |  shift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Vol+ | Vol- |Next  |      |      |                                       | DEL  |  END | PGDN |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | TRNS |       | TRNS | ???  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 | ESC  | TAB  |------|       |------|  TAB | Enter|
     *                                 |      |      | RCTL |       | RCTL |      |      |
     *                                 `--------------------'       `--------------------'
     *
     ****************************************************************************************************/
    KEYMAP(  
        // left hand
        // layer 11 is for blueshift FN14
        TRNS,  1,  2,  3,  4,  5,  NO,
        TRNS,TRNS,LBRC,RBRC,   4,   5,TRNS,
        TRNS,MINS,   9,   0, EQL,QUOT,
        LSFT,TRNS,LBRC,RBRC,TRNS,TRNS,EQLS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,

        // right hand
             TRNS,  6,  7,  8,  9,  0,  NO,
             TRNS,TRNS,MINS,TRNS,TRNS,TRNS,PGUP,
                    NO,  NO,  NO,  NO,BSLS,  NO,
               NO,   1,SCLN,COMM, DOT,MINS,  NO,
                         NO,  NO,  NO,  NO,  NO,
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
    ONE_SHOT_MOD,
    ESCAPE_WRAPPER,
    SHIFT_KEY
};

enum macro_id {
    LSHIFT_LBRACE,
    LSHIFT_RBRACE,
    LSHIFT_LT,
    LSHIFT_GT,
    HELLO,
    VOLUP,
    FAT_ARROW,
    THIN_ARROW
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key

    ACTION_LAYER_MOMENTARY(BLUESHIFT_LAYER),                      // FN1 - Momentary toggle layer one for blueshift
    ACTION_LAYER_MOMENTARY(SHORTCUT_LAYER),                      // FN2 - Momentary toggle layer 3 for mouse
    ACTION_LAYER_TOGGLE(4),                         // FN3 - toggle layer 4 for norman layout
    ACTION_LAYER_MOMENTARY(9),                      // FN4 - toggle layer 9 for teensy boot key



    ACTION_LAYER_TOGGLE(5),                         // FN5 - toggle layer 5 for norman layout
    ACTION_MACRO_TAP(LSHIFT_GT),                    // FN6 - >
    ACTION_MACRO_TAP(LSHIFT_LBRACE),                // FN7 - {
    ACTION_MACRO_TAP(LSHIFT_RBRACE),                // FN8 - }

    ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SPC),          // FN9 = space/shift key
    ACTION_MODS_TAP_KEY(MOD_RSFT, KC_BSPC),         // FN10 = bspace/shift key

    ACTION_MACRO(FAT_ARROW),                        // FN11 = Fat arrow =>
    ACTION_MACRO(THIN_ARROW),                       // FN12 = Thin arrow ->
    ACTION_FUNCTION(ESCAPE_WRAPPER),                // FN13 = clear oneshot and send esc.
    ACTION_FUNCTION(SHIFT_KEY),                     // FN14 = SHIFT_KEY action
    ACTION_FUNCTION(TMUX_MODAL),                     // FN15 = modal action for tmux..
    ACTION_LAYER_TAP_KEY(10, KC_ESC),               // FN16 - blueshift on hold, escape on tap.
    ACTION_LAYER_TAP_KEY(10, KC_TAB),               // FN17 - blueshift on hold, tab on tap.

    ACTION_FUNCTION(AWESOME_MODAL),                     // FN18 = shifted numbers
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
