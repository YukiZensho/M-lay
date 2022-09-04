#include QMK_KEYBOARD_H


enum unicode_names {
    THUP, THLW,
    DHUP, DHLW,
    SCUP, SCLW,
    ASUP, ASLW,
    SHUP, SHLW,
    NGUP, NGLW,

    ACUT, GRAV,
    MACR, TILD,

    TU, PI,

    SG, FG,
    WT, RB,
    ZW, FH,
    WM, TR,

    DOTS, DILW,
    OUUP, OULW,
    REUP, RELW,
    LNGS, DBLS,
    HEUP, HELW,

};

const uint32_t PROGMEM unicode_map[] = {
    [THUP] = 0xDE,   // Þ
    [THLW] = 0xFE,   // þ
    [DHUP] = 0xD0,   // Ð
    [DHLW] = 0xF0,   // ð
    [SCUP] = 0x18F,  // Ə
    [SCLW] = 0x259,  // ə
    [ASUP] = 0xC6,   // Æ
    [ASLW] = 0xE6,   // æ
    [SHUP] = 0x3A3,  // Σ
    [SHLW] = 0x283,  // ʃ
    [NGUP] = 0x14A,  // Ŋ
    [NGLW] = 0x14B,  // ŋ

    [ACUT] = 0x301,  // ◌́ ́
    [GRAV] = 0x300,  // ◌̀
    [MACR] = 0x304,  // ◌̄
    [TILD] = 0x303,  // ◌̃

    [TU] = 0x3C4,    // τ
    [PI] = 0x3C0,    // π

    [SG] = 0x1F937,  // 🤷
    [FG] = 0x1F3F3,  // 🏳
    [WT] = 0x1F3FB,  // 🏻
    [RB] = 0x1F308,  // 🌈
    [ZW] = 0x200D,   // ZWJ
    [FH] = 0xFE0F,   // FLTH
    [WM] = 0x2640,   // ♀
    [TR] = 0x26A7,   // ⚧
     
    [DOTS] = 0x307,  //  ̇
    [DILW] = 0x131,  // ı
    [OUUP] = 0x222,  // Ȣ
    [OULW] = 0x223,  // ȣ
    [REUP] = 0x280,  // ʀ
    [RELW] = 0x27B,  // ɻ
    [LNGS] = 0x17F,  // ſ
    [DBLS] = 0xDF,   // ß
    [HEUP] = 0x29C,  // ʜ
    [HELW] = 0xA769, // ꝩ 
};


enum layer_number {
  _OBAHI = 0,
  _THORN,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* OBAHI
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   0  |   2  |   4  |   6  |   8  |                    |   1  |   3  |   5  |   7  |   9  |  ◌̄◌̃  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Æ  |   Ə  |   N  |   L  |   F  |                    |   R  |   S  |   T  |   W  |   Þ  |  ◌́◌̀  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   O  |   B  |   A  |   H  |   I  |-------.    ,-------|   Y  |   E  |   U  |   M  |   J  |  Ŋ   |
 * |------+------+------+------+------+------|NUMPAD |    |  QWE  |------+------+------+------+------+------|
 * |LCTRL |   Q  |   Z  |   D  |   G  |   P  |-------|    |-------|   K  |   C  |   V  |   X  |   Ð  |  Σ   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_OBAHI] = LAYOUT(
  KC_ESC,          KC_1,         KC_2,         KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,     KC_0,          XP(MACR,TILD),
  KC_TAB,          XP(ASLW,ASUP),XP(SCLW,SCUP),KC_N,    KC_L,    KC_F,                         KC_R,    KC_S,    KC_T,    KC_W,     XP(THLW,THUP), XP(ACUT,GRAV),
  KC_LSFT,         KC_O,         KC_B,         KC_A,    KC_H,    KC_I,                         KC_Y,    KC_E,    KC_U,    KC_M,     KC_J,          XP(NGLW,NGUP),
  KC_LCTRL,        KC_Q,         KC_Z,         KC_D,    KC_G,    KC_P, KC_LOCK,  TG(_THORN),   KC_K,    KC_C,    KC_V,    KC_X,     XP(DHLW,DHUP), XP(SHLW,SHUP),
                                 KC_LALT,      KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE),   KC_BSPC, KC_DEL
),
/* THORN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ◌̄◌̃  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ◌́◌̀  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ð  |  Ŋ   |
 * |------+------+------+------+------+------|NUMPAD |    |  QWE  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   Þ  |   Ə  |   Æ  |  Σ   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_THORN] = LAYOUT(
  KC_ESC,          KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,         KC_9,         KC_0,          XP(MACR,TILD),
  KC_TAB,          KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,         KC_O,         KC_P,          XP(ACUT,GRAV),
  KC_LSFT,         KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,         KC_L,         XP(DHLW,DHUP), XP(NGLW,NGUP),
  KC_LCTRL,        KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LOCK,     _______,   KC_N,    KC_M,    XP(THLW,THUP),XP(SCLW,SCUP),XP(ASLW,ASUP), XP(SHLW,SHUP),
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE),   KC_BSPC, KC_DEL
),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F13 | F14  | F15  | F16  | F17  | F18  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |                    |  F19 |  F20 |  F21 | F22  | F23  | F24  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   <  |   >  |   τ  |   +  |   -  |-------.    ,-------|   +  |   <  |   >  |   (  |   )  |   -  |
 * |------+------+------+------+------+------| LOCK  |    | MOD   |------+------+------+------+------+------|
 * |      |   [  |   ]  |   {  |   =  |   _  |-------|    |-------|   =  |   [  |   ]  |   {  |   }  |   _  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,                     KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,                    KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
  _______, KC_LABK, KC_RABK, XP(TU,PI),KC_PLUS, KC_MINS,                   KC_PLUS, KC_LABK, KC_RABK, KC_LPRN, KC_RPRN, KC_MINS,
  _______, KC_LBRC, KC_RBRC, KC_LCBR,  KC_EQL,  KC_UNDS, KC_LOCK,  UC_MOD, KC_EQL,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_UNDS,
                             _______,  _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |   ~  | SHRG | WHIT | ZWTH | WHMN |   `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   ȣ  |      |   ɻ  |   5  |                    |   \  | Home | PgDw | PgUp | END  |   '  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   İ  |   ſ  |      |   ꝩ  |  F6  |-------.    ,-------|   |  | Left | Down |  Up  |Right |   "  |
 * |------+------+------+------+------+------| LOCK  |    |    ]  |------+------+------+------+------+------|
 * |      |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   /  |   ;  |   ,  |   .  |   :  |   ?  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______,      _______,      _______, _______, _______,                      KC_TILD, XP(SG,FG),XP(WT,RB),XP(ZW,FH),XP(WM,TR),KC_GRV ,
  KC_GRV,  KC_1,         XP(OULW,OUUP),_______, XP(RELW,REUP),KC_5,                         KC_BSLS, KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_QUOT,
  _______, XP(DILW,DOTS),XP(LNGS,DBLS),_______, XP(HELW,HEUP),KC_F6,                       KC_PIPE, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_DQUO,
  _______,  KC_F8,       KC_F9,        KC_F10,  KC_F11,       KC_F12,   KC_LOCK, _______,  KC_SLSH, KC_SCLN,  KC_COMM,  KC_DOT ,  KC_COLN,  KC_QUES,
                             _______,  _______, _______,     _______,  _______, _______, _______,  _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_A, KC_B),                 ENCODER_CCW_CW(KC_C, KC_D)  },
    [_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
