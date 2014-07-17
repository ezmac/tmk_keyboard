/*
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "keycode.h"
#include "action.h"
#include "action_layer.h"
#include "action_code.h"
#include "action_macro.h"
#include "action_util.h"
#include "action.h"
#include "bootloader.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "ergodox.h"


/* ErgoDox keymap definition macro */
#define KEYMAP(                                                 \
                                                                \
    /* left hand, spatial positions */                          \
    k00,k01,k02,k03,k04,k05,k06,                                \
    k10,k11,k12,k13,k14,k15,k16,                                \
    k20,k21,k22,k23,k24,k25,                                    \
    k30,k31,k32,k33,k34,k35,k36,                                \
    k40,k41,k42,k43,k44,                                        \
                            k55,k56,                            \
                                k54,                            \
                        k53,k52,k51,                            \
                                                                \
    /* right hand, spatial positions */                         \
        k07,k08,k09,k0A,k0B,k0C,k0D,                            \
        k17,k18,k19,k1A,k1B,k1C,k1D,                            \
            k28,k29,k2A,k2B,k2C,k2D,                            \
        k37,k38,k39,k3A,k3B,k3C,k3D,                            \
                k49,k4A,k4B,k4C,k4D,                            \
    k57,k58,                                                    \
    k59,                                                        \
    k5C,k5B,k5A )                                               \
                                                                \
   /* matrix positions */                                       \
   {                                                            \
    { KC_##k00,KC_##k10,KC_##k20,KC_##k30,KC_##k40,KC_NO   },   \
    { KC_##k01,KC_##k11,KC_##k21,KC_##k31,KC_##k41,KC_##k51},   \
    { KC_##k02,KC_##k12,KC_##k22,KC_##k32,KC_##k42,KC_##k52},   \
    { KC_##k03,KC_##k13,KC_##k23,KC_##k33,KC_##k43,KC_##k53},   \
    { KC_##k04,KC_##k14,KC_##k24,KC_##k34,KC_##k44,KC_##k54},   \
    { KC_##k05,KC_##k15,KC_##k25,KC_##k35,KC_NO,   KC_##k55},   \
    { KC_##k06,KC_##k16,KC_NO,   KC_##k36,KC_NO,   KC_##k56},   \
                                                                \
    { KC_##k07,KC_##k17,KC_NO,   KC_##k37,KC_NO,   KC_##k57},   \
    { KC_##k08,KC_##k18,KC_##k28,KC_##k38,KC_NO,   KC_##k58},   \
    { KC_##k09,KC_##k19,KC_##k29,KC_##k39,KC_##k49,KC_##k59},   \
    { KC_##k0A,KC_##k1A,KC_##k2A,KC_##k3A,KC_##k4A,KC_##k5A},   \
    { KC_##k0B,KC_##k1B,KC_##k2B,KC_##k3B,KC_##k4B,KC_##k5B},   \
    { KC_##k0C,KC_##k1C,KC_##k2C,KC_##k3C,KC_##k4C,KC_##k5C},   \
    { KC_##k0D,KC_##k1D,KC_##k2D,KC_##k3D,KC_##k4D,KC_NO   }    \
   }

#if defined(KEYMAP_DVORAK)
#include "keymap_dvorak.h"
#elif defined(KEYMAP_COLEMAK)
#include "keymap_colemak.h"
#elif defined(KEYMAP_WORKMAN)
#include "keymap_workman.h"
#elif defined(KEYMAP_MICRO)
#include "keymap_micro.h"
#elif defined(KEYMAP_CUB)
#include "keymap_cub.h"
#elif defined(KEYMAP_EZMAC)
#include "keymap_ezmac.h"
#else

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // layer 0 : default
        // left hand
        EQL, 1,   2,   3,   4,   5,   ESC,
        BSLS,Q,   W,   E,   R,   T,   FN2,
        TAB, A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   FN1,
        LGUI,GRV, BSLS,LEFT,RGHT,
                                      LCTL,LALT,
                                           HOME,
                                 BSPC,DEL, END,
        // right hand
             FN3, 6,   7,   8,   9,   0,   MINS,
             LBRC,Y,   U,   I,   O,   P,   RBRC,
                  H,   J,   K,   L,   SCLN,QUOT,
             FN1, N,   M,   COMM,DOT, SLSH,RSFT,
                       LEFT,DOWN,UP,  RGHT,RGUI,
        RALT,RCTL,
        PGUP,
        PGDN,ENT, SPC
    ),

    KEYMAP(  // layer 1 : function and symbol keys
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F11,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN4,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12, F6,  F7,  F8,  F9,  F10, TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 2 : keyboard functions
        // left hand
        FN0, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 3: numpad
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
             SLCK,NLCK,PSLS,PAST,PAST,PMNS,BSPC,
             TRNS,NO,  P7,  P8,  P9,  PMNS,BSPC,
                  NO,  P4,  P5,  P6,  PPLS,PENT,
             TRNS,NO,  P1,  P2,  P3,  PPLS,PENT,
                       P0,  PDOT,SLSH,PENT,PENT,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY),                    // FN0 - Teensy key
    ACTION_LAYER_MOMENTARY(1),                      // FN1 - switch to Layer1
    ACTION_LAYER_SET(2, ON_PRESS),                  // FN2 - push Layer2
    ACTION_LAYER_SET(3, ON_PRESS),                  // FN3 - push Layer3
    ACTION_LAYER_SET(0, ON_PRESS),                  // FN4 - push Layer0
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}

#endif


#define KEYMAPS_SIZE    (sizeof(keymaps) / sizeof(keymaps[0]))
#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, key_t key)
{
    if (layer < KEYMAPS_SIZE) {
        return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
    } else {
        // fall back to layer 0
        return pgm_read_byte(&keymaps[0][(key.row)][(key.col)]);
    }
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    action_t action;
    if (FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    } else {
        action.code = ACTION_NO;
    }
    return action;
}
void var_dump_keyrecord(keyrecord_t *record)
{
  keyevent_t event = record->event;
  tap_t tap = record->tap;
  
  xprintf("keyRecord:\n\
    keyEvent:\n\
        \tpressed: %d\n\
        \ttime: %u\n\
        \tkey:\n\
        \t\trow: %d\n\
        \t\tcol: %d\n\
    tap:\n\
        \tinterrupted: %d\n\
        \treserved2: %d\n\
        \treserved1: %d\n\
        \treserved0: %d\n\
        \ttap_count: %d\n\
        "
    ,event.pressed, event.time, event.key.row, event.key.col, tap.interrupted, tap.reserved2, tap.reserved1, tap.reserved0, tap.count);
}
//TODO: Make this take the modifier key.  Figure out if this should handle the event with a name like add.
void handle_one_shot_mod_action(keyrecord_t *record)
{  
  dprint("HOSMA");
  keyevent_t event = record->event;
  tap_t tap = record->tap;
  key_t key = event.key;
  uint8_t pressed_keycode = keymap_key_to_keycode(ONESHOTMOD_REFERENCE_LAYER, key);
  uint8_t mod_key = MOD_BIT(pressed_keycode);

  var_dump_keyrecord(record);
  xprintf("pressed_keycode is: %d. mod_key is %d\n",pressed_keycode, mod_key);


// for some reason, the released key sent to the os is the lower case version
  // also, if key is held, the OS does not receive it until another key is pressed.  This affects shift clicking.
  if IS_MOD(pressed_keycode){

    if (event.pressed) {
      register_code(pressed_keycode);
      if (tap.count == 0 || tap.interrupted) {
        xprintf("** adding mod, should be holding key\n");
      } else {
        add_oneshot_mods(mod_key);
        xprintf("** setting mod, should be tapping key. tap.count was %d\n",tap.count);
      }
    } else {
      unregister_code(pressed_keycode);
      if (tap.count == 0 || tap.interrupted) {
        xprintf("** deleting mod, should be releasing from heldkey\n");
      }
      else{
        //clear_oneshot_mods(mod_key);
        xprintf("** mod_key should be releasing. No action required\n tap.count was %d\n",tap.count);
      }
    }
  }
  else
  {
    xprintf("Was not a mod key");
  }
} 

void action_shift_key(keyrecord_t *record)
{
  keyevent_t event = record->event;
  tap_t tap = record->tap;
  key_t key = event.key;
  uint8_t pressed_keycode = keymap_key_to_keycode(SHIFT_KEY_REFERENCE_LAYER, key);
  uint8_t held_mods = (pressed_keycode);
  uint8_t mod_key = MOD_BIT(KC_LSFT);

  //var_dump_keyrecord(record);
  //xprintf("pressed_keycode is: %d. mod_key is %d\n, amk= %d\n, held_mods=%d",pressed_keycode, mod_key, ACTION_MODS_KEY(MOD_LSFT, mod_key), held_mods);
  //print("mod_bit ");phex(MOD_BIT(KC_LSFT)); print("\n"); 
  //print("pressed_keycode ");phex(pressed_keycode); print("\n"); 
  //print("key ");phex(key); print("\n"); 
  //print("mod_bit<<8 ");phex(MOD_BIT(KC_LSFT)<<8); print("\n"); 
  //print("mod_bit<<8|pressed_keycode ");phex(MOD_BIT(KC_LSFT)<<8|pressed_keycode); print("\n"); 
  //print("ACTION_MODS_KEY ");phex( ACTION_MODS_KEY(MOD_BIT(KC_LSFT), pressed_keycode)); print("\n"); 
  print("\n");
  //print("test");phex(MOD_BIT(key));print("\n");
  //print("held_mods ");phex(held_mods&0x07); print("\n"); 


  action_t action = layer_switch_get_action(event.key);
  uint8_t mods = action.key.mods<<4; 
  xprintf("pressed_keycode is: %d. mod_key is %d\n",pressed_keycode, mod_key);

  print("MOD_LSFT | MOD_RSFT");phex(MOD_LSFT);print(" | ");phex(MOD_RSFT);
  print("new test ");phex(mods); print("\n"); 
  if(IS_MOD(held_mods)) {
    print("Was a mod!");
  }
  /*
  print("0xMOD_BIT(held_mods) ");phex(MOD_BIT(held_mods)); print("\n"); 
  print("0xMOD_BIT(KC_LSFT) ");phex(MOD_BIT(KC_LSFT)); print("\n"); 
       print("\n"); 
  print("0xMOD_BIT(MOD_LSFT) ");phex(MOD_BIT(MOD_LSFT)); print("\n"); 
  // for some reason, the released key sent to the os is the lower case version
  // also, if key is held, the OS does not receive it until another key is pressed.  This affects shift clicking.
  */
   // if the heldmods x 
  if (!(held_mods ^ (MOD_LSFT | MOD_RSFT)) !=0){
    print("shift was held\n"); 
    mod_key = 0;
  }
  if (event.pressed) {
    //print("event.pressed\n");
    add_oneshot_mods(mod_key);
    register_code(pressed_keycode);
  } else {
    //print("event.pressed broke\n");
    unregister_code(pressed_keycode);
  }
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;
    tap_t tap = record->tap;

    print("action_function called\n");
    print("id  = "); phex(id); print("\n");
    print("opt = "); phex(opt); print("\n");
    switch (id) {
        case TEENSY_KEY:
            clear_keyboard();
            print("\n\nJump to bootloader... ");
            _delay_ms(250);
            bootloader_jump(); // should not return
            print("not supported.\n");
            break;

        //case TAPSHOT_HOLD_TOGGLE_LAYER:  
            // TODO:
            // - Write some code to do tap one shot hold momentary toggle on layers.
            // - convert ONE_SHOT_MOD to use ACTION_MODS_ONESHOT if possible.  Might save space
            // - remove unused debug statements.
            break;
        case ESCAPE_WRAPPER:
            {
                if (event.pressed) {
                    uint8_t osm = has_any_oneshot_mods();
                    xprintf("escape_wrapper called\n Oneshot mods are: %d\n", get_oneshot_mods());
                    if (osm !=0)
                    {
                      xprintf("clearing oneshot mods\n");
                      clear_oneshot_mods();
                      xprintf("oneshot mods are now %d\n", get_oneshot_mods());
                    }
                    else
                    {
                      xprintf("exec escape\n");
                      add_key(KC_ESC);
                      send_keyboard_report();
                    }
                } else {
                      del_key(KC_ESC);
                      send_keyboard_report();

                  // key was released
                }

            }
            break;
        case ONE_SHOT_MOD:
            // NOTE: cant use register_code to avoid conflicting with magic key bind
            //this is basically how ACTION_MODS_TAP_KEY works.
            handle_one_shot_mod_action(record);
            break;
        case SHIFT_KEY:
            action_shift_key(record);
            break;
    }
}
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;
    tap_t tap = record->tap;

    switch (id) {
        case FAT_ARROW:
            return (event.pressed ?
                    MACRO( T(SPACE), T(EQUAL), D(LSHIFT), T(DOT), U(LSHIFT), T(SPACE), END ) : MACRO_NONE);
            break;
        case THIN_ARROW:
                return (event.pressed ?
                        MACRO( T(SPACE), T(MINS), D(LSHIFT), T(DOT), U(LSHIFT),T(SPACE), END ) : MACRO_NONE);
            break;
        case LSHIFT_LBRACE:
            if (tap.count > 0 && !tap.interrupted) {
                return (event.pressed ?
                        MACRO( D(LSHIFT), T(LBRC), U(LSHIFT), END ) : MACRO_NONE);
            } else {
                return (event.pressed ?
                        MACRO( D(LSHIFT), END ) : MACRO( U(LSHIFT), END ) );
            }
            break;
        case LSHIFT_RBRACE:
            if (tap.count > 0 && !tap.interrupted) {
                return (event.pressed ?
                        MACRO( D(RSHIFT), T(RBRC), U(RSHIFT), END ) : MACRO_NONE);
            } else {
                return (event.pressed ?
                        MACRO( D(RSHIFT), END ) : MACRO( U(RSHIFT), END ) );
            }
            break;
        case LSHIFT_LT:
            if (tap.count > 0 && !tap.interrupted) {
                return (event.pressed ?
                        MACRO( D(LSHIFT), T(COMMA), U(LSHIFT), END ) : MACRO_NONE);
            } else {
                return (event.pressed ?
                        MACRO( D(LSHIFT), END ) : MACRO( U(LSHIFT), END ) );
            }
            break;
        case LSHIFT_GT:
            if (tap.count > 0 && !tap.interrupted) {
                return (event.pressed ?
                        MACRO( D(RSHIFT), D(DOT), U(DOT), U(RSHIFT), END ) : MACRO_NONE);
            } else {
                return (event.pressed ?
                        MACRO( D(RSHIFT), END ) : MACRO( U(RSHIFT), END ) );
            }
            break;
        case HELLO:
            return (event.pressed ?
                    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) :
                    MACRO_NONE );
            break;
        case VOLUP:
            return (event.pressed ?
                    MACRO( D(VOLU), U(VOLU), END ) :
                    MACRO_NONE );
            break;
    }
    return MACRO_NONE;
}


