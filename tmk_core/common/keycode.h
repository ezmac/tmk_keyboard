/*
Copyright 2011,2012 Jun Wako <wakojun@gmail.com>

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

/*
 * Keycodes based on HID Usage Keyboard/Keypad Page(0x07) plus special codes
 * http://www.usb.org/developers/devclass_docs/Hut1_12.pdf
 */
#ifndef KEYCODE_H
#define KEYCODE_H


#define IS_ERROR(code)           (KC_ROLL_OVER <= (code) && (code) <= KC_UNDEFINED)
#define IS_ANY(code)             (KC_A         <= (code) && (code) <= 0xFF)

#ifndef ACTIONMAP_ENABLE
#define IS_KEY(code)             (KC_A         <= (code) && (code) <= KC_EXSEL)
#else
#define IS_KEY(code)             ((KC_A         <= (code) && (code) <= KC_EXSEL) || \
                                  (KC_KP_00     <= (code) && (code) <= KC_KP_HEXADECIMAL))
#endif

#define IS_MOD(code)             (KC_LCTRL     <= (code) && (code) <= KC_RGUI)


#define IS_SPECIAL(code)         ((0xA5 <= (code) && (code) <= 0xDF) || (0xE8 <= (code) && (code) <= 0xFF))
#define IS_SYSTEM(code)          (KC_PWR       <= (code) && (code) <= KC_WAKE)
#define IS_CONSUMER(code)        (KC_MUTE      <= (code) && (code) <= KC_WFAV)
#define IS_FN(code)              (KC_FN0       <= (code) && (code) <= KC_FN31)
#define IS_MOUSEKEY(code)        (KC_MS_UP     <= (code) && (code) <= KC_MS_ACCEL2)
#define IS_MOUSEKEY_MOVE(code)   (KC_MS_UP     <= (code) && (code) <= KC_MS_RIGHT)
#define IS_MOUSEKEY_BUTTON(code) (KC_MS_BTN1   <= (code) && (code) <= KC_MS_BTN5)
#define IS_MOUSEKEY_WHEEL(code)  (KC_MS_WH_UP  <= (code) && (code) <= KC_MS_WH_RIGHT)
#define IS_MOUSEKEY_ACCEL(code)  (KC_MS_ACCEL0 <= (code) && (code) <= KC_MS_ACCEL2)

#define MOD_BIT(code)   (1<<MOD_INDEX(code))
#define MOD_INDEX(code) ((code) & 0x07)
#define FN_BIT(code)    (1<<FN_INDEX(code))
#define FN_INDEX(code)  ((code) - KC_FN0)
#define FN_MIN          KC_FN0
#define FN_MAX          KC_FN31

/* 
 * imported shortnames for ergodox configuration
 */
/* ----------------------------------------------------------------------------
 * USB Keyboard Key Codes : short names
 *
 * These are for convenience (and to help with formatting, keeping stuff from
 * getting too long).  See "keyboard-usage-page.h" for definitions and
 * everything.
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


// error
#define KEY_ErrorRollOver _ErrRollover
#define KEY_POSTFail _PostFail
#define KEY_ErrorUndefined _ErrUndef


// ----------------------------------------------------------------------------
// main keyboard
// ----------------------------------------------------------------------------

// letters
#define KEY_a_A KC_A
#define KEY_b_B KC_B
#define KEY_c_C KC_C
#define KEY_d_D KC_D
#define KEY_e_E KC_E
#define KEY_f_F KC_F
#define KEY_g_G KC_G
#define KEY_h_H KC_H
#define KEY_i_I KC_I
#define KEY_j_J KC_J
#define KEY_k_K KC_K
#define KEY_l_L KC_L
#define KEY_m_M KC_M
#define KEY_n_N KC_N
#define KEY_o_O KC_O
#define KEY_p_P KC_P
#define KEY_q_Q KC_Q
#define KEY_r_R KC_R
#define KEY_s_S KC_S
#define KEY_t_T KC_T
#define KEY_u_U KC_U
#define KEY_v_V KC_V
#define KEY_w_W KC_W
#define KEY_x_X KC_X
#define KEY_y_Y KC_Y
#define KEY_z_Z KC_Z

// numbers
#define KEY_0_RightParenthesis KC_0
#define KEY_1_Exclamation KC_1
#define KEY_2_At KC_2
#define KEY_3_Pound KC_3
#define KEY_4_Dollar KC_4
#define KEY_5_Percent KC_5
#define KEY_6_Caret KC_6
#define KEY_7_Ampersand KC_7
#define KEY_8_Asterisk KC_8
#define KEY_9_LeftParenthesis KC_9

// function
#define KEY_F1 KC_F1
#define KEY_F2 KC_F2
#define KEY_F3 KC_F3
#define KEY_F4 KC_F4
#define KEY_F5 KC_F5
#define KEY_F6 KC_F6
#define KEY_F7 KC_F7
#define KEY_F8 KC_F8
#define KEY_F9 KC_F9
#define KEY_F10 KC_F10
#define KEY_F11 KC_F11
#define KEY_F12 KC_F12
#define KEY_F13 KC_F13
#define KEY_F14 KC_F14
#define KEY_F15 KC_F15
#define KEY_F16 KC_F16
#define KEY_F17 KC_F17
#define KEY_F18 KC_F18
#define KEY_F19 KC_F19
#define KEY_F20 KC_F20
#define KEY_F21 KC_F21
#define KEY_F22 KC_F22
#define KEY_F23 KC_F23
#define KEY_F24 KC_F24

// whitespace and symbols
#define KEY_ReturnEnter KC_ENTER
#define KEY_Spacebar KC_SPACE
#define KEY_Tab KC_TAB
// ---
#define KEY_Backslash_Pipe KC_BSLASH
#define KEY_LeftBracket_LeftBrace KC_LBRACKET
#define KEY_RightBracket_RightBrace KC_RBRACKET
#define KEY_Comma_LessThan KC_COMMA
#define KEY_Dash_Underscore KC_MINUS
#define KEY_Equal_Plus KC_EQUAL
#define KEY_GraveAccent_Tilde KC_GRAVE
#define KEY_Period_GreaterThan KC_DOT
#define KEY_SingleQuote_DoubleQuote KC_QUOTE
#define KEY_Semicolon_Colon KC_SCOLON
#define KEY_Slash_Question KC_SLASH
// ---
/*
#define KEY_DecimalSeparator KC_sep_dec
#define KEY_ThousandsSeparator KC_sep_thousands
#define KEY_CurrencyUnit KC_currencyUnit
#define KEY_CurrencySubunit KC_currencySubunit
*/
// international and language
#define KEY_International1 KC_INT1
#define KEY_International2 KC_INT2
#define KEY_International3 KC_INT3
#define KEY_International4 KC_INT4
#define KEY_International5 KC_INT5
#define KEY_International6 KC_INT6
#define KEY_International7 KC_INT7
#define KEY_International8 KC_INT8
#define KEY_International9 KC_INT9
// ---
#define KEY_LANG1 KC_LANG1
#define KEY_LANG2 KC_LANG2
#define KEY_LANG3 KC_LANG3
#define KEY_LANG4 KC_LANG4
#define KEY_LANG5 KC_LANG5
#define KEY_LANG6 KC_LANG6
#define KEY_LANG7 KC_LANG7
#define KEY_LANG8 KC_LANG8
#define KEY_LANG9 KC_LANG9
// ---
#define KEY_NonUS_Backslash_Pipe KC_backslash_nonUS
#define KEY_NonUS_Pound_Tilde KC_pound_nonUS

// text control
#define KEY_DeleteBackspace KC_BSPACE
#define KEY_DeleteForward KC_DEL
#define KEY_Home KC_HOME
#define KEY_End KC_END
#define KEY_PageUp KC_PGIP
#define KEY_PageDown KC_PGDOWN
#define KEY_UpArrow KC_UP
#define KEY_DownArrow KC_DOWN
#define KEY_LeftArrow KC_LEFT
#define KEY_RightArrow KC_RIGHT
#define KEY_Escape KC_ESC
#define KEY_Insert KC_INSERT

// modifier
#define KEY_LeftAlt KC_LALT
#define KEY_RightAlt KC_RALT
#define KEY_LeftControl KC_LCTRL
#define KEY_RightControl KC_RCTRL
#define KEY_LeftGUI KC_LGUI
#define KEY_RightGUI KC_RGUI
#define KEY_LeftShift KC_LSHIFT
#define KEY_RightShift KC_RSHIFT

// lock
#define KEY_CapsLock KC_CAPSLOCK
#define KEY_ScrollLock KC_SCROLLLOCK
// (numlock is under keypad)
// --- not generally used
#define KEY_LockingCapsLock KC_LOCKING_CAPS
#define KEY_LockingNumLock KC_LOCKING_NUM
#define KEY_LockingScrollLock KC_LOCKING_SCROLL

// special function
#define KEY_Pause KC_PAUSE
#define KEY_PrintScreen KC_PRINT
// ---
#define KEY_Application KC_APP
#define KEY_Execute KC_EXECUTE
#define KEY_Power KC_POWER
// ---
#define KEY_Help KC_HELP
#define KEY_Menu KC_MENU
// ---
#define KEY_Cut KC_CUT
#define KEY_Copy KC_COPY
#define KEY_Paste KC_PASTE
#define KEY_Find KC_FIND
#define KEY_Select KC_SELECT
#define KEY_Stop KC_STOP
#define KEY_Undo KC_UNDO
// ---
#define KEY_Mute KC_AUDIO_MUTE
#define KEY_VolumeUp KC_AUDIO_VOL_UP
#define KEY_VolumeDown KC_AUDIO_VOL_DOWN

/*
 * Short names for ease of definition of keymap
 */
#define KC_LCTL KC_LCTRL
#define KC_RCTL KC_RCTRL
#define KC_LSFT KC_LSHIFT
#define KC_RSFT KC_RSHIFT
#define KC_ESC  KC_ESCAPE
#define KC_BSPC KC_BSPACE
#define KC_ENT  KC_ENTER
#define KC_DEL  KC_DELETE
#define KC_INS  KC_INSERT
#define KC_CAPS KC_CAPSLOCK
#define KC_CLCK KC_CAPSLOCK
#define KC_RGHT KC_RIGHT
#define KC_PGDN KC_PGDOWN
#define KC_PSCR KC_PSCREEN
#define KC_SLCK KC_SCROLLLOCK
#define KC_PAUS KC_PAUSE
#define KC_BRK  KC_PAUSE
#define KC_NLCK KC_NUMLOCK
#define KC_SPC  KC_SPACE
#define KC_MINS KC_MINUS
#define KC_EQL  KC_EQUAL
#define KC_GRV  KC_GRAVE
#define KC_RBRC KC_RBRACKET
#define KC_LBRC KC_LBRACKET
#define KC_COMM KC_COMMA
#define KC_BSLS KC_BSLASH
#define KC_SLSH KC_SLASH
#define KC_SCLN KC_SCOLON
#define KC_QUOT KC_QUOTE
#define KC_APP  KC_APPLICATION
#define KC_NUHS KC_NONUS_HASH
#define KC_NUBS KC_NONUS_BSLASH
#define KC_LCAP KC_LOCKING_CAPS
#define KC_LNUM KC_LOCKING_NUM
#define KC_LSCR KC_LOCKING_SCROLL
#define KC_ERAS KC_ALT_ERASE
#define KC_CLR  KC_CLEAR
/* Japanese specific */
#define KC_ZKHK KC_GRAVE
#define KC_RO   KC_INT1
#define KC_KANA KC_INT2
#define KC_JYEN KC_INT3
#define KC_JPY  KC_INT3
#define KC_HENK KC_INT4
#define KC_MHEN KC_INT5
/* Korean specific */
#define KC_HAEN KC_LANG1
#define KC_HANJ KC_LANG2
/* Keypad */
#define KC_P1   KC_KP_1
#define KC_P2   KC_KP_2
#define KC_P3   KC_KP_3
#define KC_P4   KC_KP_4
#define KC_P5   KC_KP_5
#define KC_P6   KC_KP_6
#define KC_P7   KC_KP_7
#define KC_P8   KC_KP_8
#define KC_P9   KC_KP_9
#define KC_P0   KC_KP_0
#define KC_PDOT KC_KP_DOT
#define KC_PCMM KC_KP_COMMA
#define KC_PSLS KC_KP_SLASH
#define KC_PAST KC_KP_ASTERISK
#define KC_PMNS KC_KP_MINUS
#define KC_PPLS KC_KP_PLUS
#define KC_PEQL KC_KP_EQUAL
#define KC_PENT KC_KP_ENTER
/* Unix function key */
#define KC_EXEC KC_EXECUTE
#define KC_SLCT KC_SELECT
#define KC_AGIN KC_AGAIN
#define KC_PSTE KC_PASTE
/* Mousekey */
#define KC_MS_U KC_MS_UP
#define KC_MS_D KC_MS_DOWN
#define KC_MS_L KC_MS_LEFT
#define KC_MS_R KC_MS_RIGHT
#define KC_BTN1 KC_MS_BTN1
#define KC_BTN2 KC_MS_BTN2
#define KC_BTN3 KC_MS_BTN3
#define KC_BTN4 KC_MS_BTN4
#define KC_BTN5 KC_MS_BTN5
#define KC_WH_U KC_MS_WH_UP
#define KC_WH_D KC_MS_WH_DOWN
#define KC_WH_L KC_MS_WH_LEFT
#define KC_WH_R KC_MS_WH_RIGHT
#define KC_ACL0 KC_MS_ACCEL0
#define KC_ACL1 KC_MS_ACCEL1
#define KC_ACL2 KC_MS_ACCEL2
/* Sytem Control */
#define KC_PWR  KC_SYSTEM_POWER
#define KC_SLEP KC_SYSTEM_SLEEP
#define KC_WAKE KC_SYSTEM_WAKE
/* Consumer Page */
#define KC_MUTE KC_AUDIO_MUTE
#define KC_VOLU KC_AUDIO_VOL_UP
#define KC_VOLD KC_AUDIO_VOL_DOWN
#define KC_MNXT KC_MEDIA_NEXT_TRACK
#define KC_MPRV KC_MEDIA_PREV_TRACK
#define KC_MFFD KC_MEDIA_FAST_FORWARD
#define KC_MRWD KC_MEDIA_REWIND
#define KC_MSTP KC_MEDIA_STOP
#define KC_MPLY KC_MEDIA_PLAY_PAUSE
#define KC_EJCT KC_MEDIA_EJECT
#define KC_MSEL KC_MEDIA_SELECT
#define KC_MAIL KC_MAIL
#define KC_CALC KC_CALCULATOR
#define KC_MYCM KC_MY_COMPUTER
#define KC_WSCH KC_WWW_SEARCH
#define KC_WHOM KC_WWW_HOME
#define KC_WBAK KC_WWW_BACK
#define KC_WFWD KC_WWW_FORWARD
#define KC_WSTP KC_WWW_STOP
#define KC_WREF KC_WWW_REFRESH
#define KC_WFAV KC_WWW_FAVORITES
/* Jump to bootloader */
#define KC_BTLD KC_BOOTLOADER
/* Transparent */
#define KC_TRANSPARENT  1
#define KC_TRNS KC_TRANSPARENT



/* USB HID Keyboard/Keypad Usage(0x07) */
enum hid_keyboard_keypad_usage {
    KC_NO               = 0x00,
    KC_ROLL_OVER,
    KC_POST_FAIL,
    KC_UNDEFINED,
    KC_A,               /* 0x04 */
    KC_B,
    KC_C,
    KC_D,
    KC_E,
    KC_F,
    KC_G,
    KC_H,
    KC_I,
    KC_J,
    KC_K,
    KC_L,
    KC_M,               /* 0x10 */
    KC_N,
    KC_O,
    KC_P,
    KC_Q,
    KC_R,
    KC_S,
    KC_T,
    KC_U,
    KC_V,
    KC_W,
    KC_X,
    KC_Y,
    KC_Z,
    KC_1,
    KC_2,
    KC_3,               /* 0x20 */
    KC_4,
    KC_5,
    KC_6,
    KC_7,
    KC_8,
    KC_9,
    KC_0,
    KC_ENTER,
    KC_ESCAPE,
    KC_BSPACE,
    KC_TAB,
    KC_SPACE,
    KC_MINUS,
    KC_EQUAL,
    KC_LBRACKET,
    KC_RBRACKET,        /* 0x30 */
    KC_BSLASH,          /* \ (and |) */
    KC_NONUS_HASH,      /* Non-US # and ~ (Typically near the Enter key) */
    KC_SCOLON,          /* ; (and :) */
    KC_QUOTE,           /* ' and " */
    KC_GRAVE,           /* Grave accent and tilde */
    KC_COMMA,           /* , and < */
    KC_DOT,             /* . and > */
    KC_SLASH,           /* / and ? */
    KC_CAPSLOCK,
    KC_F1,
    KC_F2,
    KC_F3,
    KC_F4,
    KC_F5,
    KC_F6,
    KC_F7,              /* 0x40 */
    KC_F8,
    KC_F9,
    KC_F10,
    KC_F11,
    KC_F12,
    KC_PSCREEN,
    KC_SCROLLLOCK,
    KC_PAUSE,
    KC_INSERT,
    KC_HOME,
    KC_PGUP,
    KC_DELETE,
    KC_END,
    KC_PGDOWN,
    KC_RIGHT,
    KC_LEFT,            /* 0x50 */
    KC_DOWN,
    KC_UP,
    KC_NUMLOCK,
    KC_KP_SLASH,
    KC_KP_ASTERISK,
    KC_KP_MINUS,
    KC_KP_PLUS,
    KC_KP_ENTER,
    KC_KP_1,
    KC_KP_2,
    KC_KP_3,
    KC_KP_4,
    KC_KP_5,
    KC_KP_6,
    KC_KP_7,
    KC_KP_8,            /* 0x60 */
    KC_KP_9,
    KC_KP_0,
    KC_KP_DOT,
    KC_NONUS_BSLASH,    /* Non-US \ and | (Typically near the Left-Shift key) */
    KC_APPLICATION,
    KC_POWER,
    KC_KP_EQUAL,
    KC_F13,
    KC_F14,
    KC_F15,
    KC_F16,
    KC_F17,
    KC_F18,
    KC_F19,
    KC_F20,
    KC_F21,             /* 0x70 */
    KC_F22,
    KC_F23,
    KC_F24,
    KC_EXECUTE,
    KC_HELP,
    KC_MENU,
    KC_SELECT,
    KC_STOP,
    KC_AGAIN,
    KC_UNDO,
    KC_CUT,
    KC_COPY,
    KC_PASTE,
    KC_FIND,
    KC__MUTE,
    KC__VOLUP,          /* 0x80 */
    KC__VOLDOWN,
    KC_LOCKING_CAPS,    /* locking Caps Lock */
    KC_LOCKING_NUM,     /* locking Num Lock */
    KC_LOCKING_SCROLL,  /* locking Scroll Lock */
    KC_KP_COMMA,
    KC_KP_EQUAL_AS400,  /* equal sign on AS/400 */
    KC_INT1,
    KC_INT2,
    KC_INT3,
    KC_INT4,
    KC_INT5,
    KC_INT6,
    KC_INT7,
    KC_INT8,
    KC_INT9,
    KC_LANG1,           /* 0x90 */
    KC_LANG2,
    KC_LANG3,
    KC_LANG4,
    KC_LANG5,
    KC_LANG6,
    KC_LANG7,
    KC_LANG8,
    KC_LANG9,
    KC_ALT_ERASE,
    KC_SYSREQ,
    KC_CANCEL,
    KC_CLEAR,
    KC_PRIOR,
    KC_RETURN,
    KC_SEPARATOR,
    KC_OUT,             /* 0xA0 */
    KC_OPER,
    KC_CLEAR_AGAIN,
    KC_CRSEL,
    KC_EXSEL,           /* 0xA4 */

    /* NOTE: Following code range(0xB0-DD) are shared with special codes of 8-bit keymap */
    KC_KP_00            = 0xB0,
    KC_KP_000,
    KC_THOUSANDS_SEPARATOR,
    KC_DECIMAL_SEPARATOR,
    KC_CURRENCY_UNIT,
    KC_CURRENCY_SUB_UNIT,
    KC_KP_LPAREN,
    KC_KP_RPAREN,
    KC_KP_LCBRACKET,    /* { */
    KC_KP_RCBRACKET,    /* } */
    KC_KP_TAB,
    KC_KP_BSPACE,
    KC_KP_A,
    KC_KP_B,
    KC_KP_C,
    KC_KP_D,
    KC_KP_E,            /* 0xC0 */
    KC_KP_F,
    KC_KP_XOR,
    KC_KP_HAT,
    KC_KP_PERC,
    KC_KP_LT,
    KC_KP_GT,
    KC_KP_AND,
    KC_KP_LAZYAND,
    KC_KP_OR,
    KC_KP_LAZYOR,
    KC_KP_COLON,
    KC_KP_HASH,
    KC_KP_SPACE,
    KC_KP_ATMARK,
    KC_KP_EXCLAMATION,
    KC_KP_MEM_STORE,    /* 0xD0 */
    KC_KP_MEM_RECALL,
    KC_KP_MEM_CLEAR,
    KC_KP_MEM_ADD,
    KC_KP_MEM_SUB,
    KC_KP_MEM_MUL,
    KC_KP_MEM_DIV,
    KC_KP_PLUS_MINUS,
    KC_KP_CLEAR,
    KC_KP_CLEAR_ENTRY,
    KC_KP_BINARY,
    KC_KP_OCTAL,
    KC_KP_DECIMAL,
    KC_KP_HEXADECIMAL,  /* 0xDD */

    /* Modifiers */
    KC_LCTRL            = 0xE0,
    KC_LSHIFT,
    KC_LALT,
    KC_LGUI,
    KC_RCTRL,
    KC_RSHIFT,
    KC_RALT,
    KC_RGUI,            /* 0xE7 */
};

/* Special keycodes for 8-bit keymap
   NOTE: 0xA5-DF and 0xE8-FF are used for internal special purpose */
enum internal_special_keycodes {
    /* System Control */
    KC_SYSTEM_POWER     = 0xA5,
    KC_SYSTEM_SLEEP,
    KC_SYSTEM_WAKE,

    /* Media Control */
    KC_AUDIO_MUTE,
    KC_AUDIO_VOL_UP,
    KC_AUDIO_VOL_DOWN,
    KC_MEDIA_NEXT_TRACK,
    KC_MEDIA_PREV_TRACK,
    KC_MEDIA_FAST_FORWARD,
    KC_MEDIA_REWIND,
    KC_MEDIA_STOP,
    KC_MEDIA_PLAY_PAUSE,
    KC_MEDIA_EJECT,
    KC_MEDIA_SELECT,
    KC_MAIL,
    KC_CALCULATOR,
    KC_MY_COMPUTER,
    KC_WWW_SEARCH,
    KC_WWW_HOME,
    KC_WWW_BACK,
    KC_WWW_FORWARD,
    KC_WWW_STOP,
    KC_WWW_REFRESH,
    KC_WWW_FAVORITES,    /* 0xBC */

    /* Jump to bootloader */
    KC_BOOTLOADER       = 0xBF,

    /* Fn key */
    KC_FN0              = 0xC0,
    KC_FN1,
    KC_FN2,
    KC_FN3,
    KC_FN4,
    KC_FN5,
    KC_FN6,
    KC_FN7,
    KC_FN8,
    KC_FN9,
    KC_FN10,
    KC_FN11,
    KC_FN12,
    KC_FN13,
    KC_FN14,
    KC_FN15,

    KC_FN16             = 0xD0,
    KC_FN17,
    KC_FN18,
    KC_FN19,
    KC_FN20,
    KC_FN21,
    KC_FN22,
    KC_FN23,
    KC_FN24,
    KC_FN25,
    KC_FN26,
    KC_FN27,
    KC_FN28,
    KC_FN29,
    KC_FN30,
    KC_FN31,            /* 0xDF */

    /**************************************/
    /* 0xE0-E7 for Modifiers. DO NOT USE. */
    /**************************************/

    /* Mousekey */
    KC_MS_UP            = 0xF0,
    KC_MS_DOWN,
    KC_MS_LEFT,
    KC_MS_RIGHT,
    KC_MS_BTN1,
    KC_MS_BTN2,
    KC_MS_BTN3,
    KC_MS_BTN4,
    KC_MS_BTN5,         /* 0xF8 */
    /* Mousekey wheel */
    KC_MS_WH_UP,
    KC_MS_WH_DOWN,
    KC_MS_WH_LEFT,
    KC_MS_WH_RIGHT,     /* 0xFC */
    /* Mousekey accel */
    KC_MS_ACCEL0,
    KC_MS_ACCEL1,
    KC_MS_ACCEL2        /* 0xFF */
};

#endif /* KEYCODE_H */
