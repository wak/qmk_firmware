/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "timer.h"

#define JIS    0
#define MAC    1
#define HHKB   2

enum my_keycodes {
	MY_CONTROL = SAFE_RANGE,
	MY_SHIFT,
	MY_EQL_PLUS,
	MY_MIN_USCRE,
	MY_TILD_BQUOT,
	MY_QUOT_DQUOT,
	MY_KEEP_SCREEEN,
	MY_TOGGLE_OS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE Level: Default Layer
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | LAlt | LGUI | ******* Space ******* | RGUI | RAlt |
            |------+------+-----------------------+------+------|
    */

    [JIS] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, MY_MIN_USCRE, MY_EQL_PLUS, KC_JYEN, MY_TILD_BQUOT,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, JP_LBRC, JP_RBRC, KC_BSPC,
        MY_CONTROL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, MY_QUOT_DQUOT, KC_ENT,
        MY_SHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MY_SHIFT, MO(HHKB),
        KC_ZKHK, KC_LALT, /*        */ KC_SPC, KC_RALT, KC_LGUI),

    [MAC] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, MY_MIN_USCRE, MY_EQL_PLUS, KC_JYEN, MY_TILD_BQUOT,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, JP_LBRC, JP_RBRC, KC_BSPC,
        MY_CONTROL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, MY_QUOT_DQUOT, KC_ENT,
        MY_SHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MY_SHIFT, MO(HHKB),
        KC_ZKHK, KC_LGUI, /*        */ KC_SPC, KC_RGUI, KC_RALT),


    /* Layer HHKB: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr  | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps | Bac | End | Del |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | Hom | Lef | Up  | Dow| Rig| *  | /  | Hom | PgU | Lef | Rig | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    | +  | -  | End | PgD | Dow |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

	/* Fnキーを押している状態のレイアウト */
    [HHKB] = LAYOUT(
        MY_KEEP_SCREEEN, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, KC_TRNS, KC_BSPC, KC_END , KC_DEL , KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_TRNS, KC_BSPC,
        KC_TRNS, KC_HOME, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, KC_TRNS, KC_TRNS,
        MY_TOGGLE_OS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};

static bool mod_control;
static bool mod_shift;
static bool mod_alt;
static bool mod_gui;

static bool my_control;
static bool my_shift;

static void fetch_mods_status(void)
{
	mod_control = get_mods() & MOD_MASK_CTRL;
	mod_shift   = get_mods() & MOD_MASK_SHIFT;
	mod_alt     = get_mods() & MOD_MASK_ALT;
	mod_gui     = get_mods() & MOD_MASK_GUI;
}

static bool register_control_mods(void)
{
	if (!(get_mods() & MOD_MASK_CTRL)) {
		register_mods(MOD_BIT(KC_LCTL));
		return true;
	}
	return false;
}

static uint16_t unregister_control_mods(void)
{
	uint16_t ret = 0;

	if (get_mods() & MOD_BIT(KC_LCTL)) {
		unregister_mods(MOD_BIT(KC_LCTL));
		ret |= MOD_BIT(KC_LCTL);
	}
	
	return ret;
}

static void reset_my_control_mods(void)
{
	if (my_control)
		register_control_mods();
	else
		unregister_control_mods();
}

static bool register_shift_mods(void)
{
	if (!(get_mods() & MOD_MASK_SHIFT)) {
		register_mods(MOD_BIT(KC_LSFT));
		return true;
	}
	return false;
}

static uint16_t unregister_shift_mods(void)
{
	uint16_t ret = 0;

	if (get_mods() & MOD_MASK_SHIFT) {
		unregister_mods(MOD_BIT(KC_LSFT));
		ret |= MOD_BIT(KC_LSFT);
	}

	return ret;
}

static void reset_my_shift_mods(void)
{
	if (my_shift)
		register_shift_mods();
	else
		unregister_shift_mods();
}

static uint16_t unregister_alt_mods(void)
{
	uint16_t ret = 0;

	if (get_mods() & MOD_BIT(KC_LALT)) {
		unregister_mods(MOD_BIT(KC_LALT));
		ret |= MOD_BIT(KC_LALT);
	}
	
	if (get_mods() & MOD_BIT(KC_RALT)) {
		unregister_mods(MOD_BIT(KC_RALT));
		ret |= MOD_BIT(KC_RALT);
	}

	return ret;
}

typedef enum {
	KS_TRANS = -1,
	KS_OFF  = 0,
	KS_ON   = 1,
} KEY_STATUS;

struct translation {
	KEY_STATUS from_control;
	KEY_STATUS from_alt;
	KEY_STATUS from_shift;
	uint16_t from_keycode;
	KEY_STATUS to_control;
	KEY_STATUS to_alt;
	KEY_STATUS to_shift;
	uint16_t to_keycode;
	bool *flg_enabled;
	void (*callback)(struct translation *);
};

static bool flg_control_custom_key_enabled = false;

static void cb_toggle_custom_key_mode(struct translation *trans)
{
	flg_control_custom_key_enabled = !flg_control_custom_key_enabled;
}

static void cb_show_custom_key_mode(struct translation *trans)
{
	uint16_t tmp = unregister_control_mods();
	send_string(flg_control_custom_key_enabled ? "C" : "D");
	if (tmp)
		register_mods(tmp);
}

static void cb_win_vdesktop(struct translation *trans)
{
	uint16_t tmp = unregister_alt_mods();

	register_mods(MOD_BIT(KC_LGUI));
	tap_code(trans->from_keycode == KC_L ? KC_RIGHT : KC_LEFT);
	unregister_mods(MOD_BIT(KC_LGUI));

	if (tmp)
		register_mods(tmp);
}

void cb_toggle_os(struct translation *trans)
{
	static bool jis = true;

	if (jis)
		layer_move(MAC);
	else
		layer_move(JIS);

	jis = !jis;
}

static enum {
	KEEP_SCREEN_DISABLED,
	KEEP_SCREEN_MESSAGE,
	KEEP_SCREEN_CONTROL
} keep_screen_mode = KEEP_SCREEN_DISABLED;
static const char keep_screen_message[] = "This message is keeping screen.";
static int keep_screen_pos = 0;

void cb_toggle_keep_screen_message(struct translation *trans)
{
	if (keep_screen_mode == KEEP_SCREEN_MESSAGE) {
		keep_screen_mode = KEEP_SCREEN_DISABLED;
		return;
	}
	keep_screen_mode = KEEP_SCREEN_MESSAGE;
	keep_screen_pos = 0;
	send_string("]KM\\");
}

void cb_toggle_keep_screen_ctrl(struct translation *trans)
{
	if (keep_screen_mode == KEEP_SCREEN_CONTROL) {
		keep_screen_mode = KEEP_SCREEN_DISABLED;
		return;
	}
	keep_screen_mode = KEEP_SCREEN_CONTROL;
	keep_screen_pos = 0;
	unregister_control_mods();
	wait_ms(80);
	send_string("]KC\\");
	reset_my_control_mods();
}

void matrix_scan_user(void)
{
	static uint16_t keep_screen_timer = 0;

	if (!keep_screen_mode)
		return;

	uint16_t e = timer_elapsed(keep_screen_timer);

	if (e > 5 * 1000) {
		/* Every 20 second */
		keep_screen_timer += e/1000*1000;

		if (keep_screen_mode == KEEP_SCREEN_MESSAGE) {
			char c = keep_screen_message[keep_screen_pos];
			if (c == 'y' || c == 'Y' || c == 'n' || c == 'N') {
				send_char('"');				 /* * */
			} else if (c == ' ') {
				register_shift_mods();
				tap_code(JP_BSLS);			 /* _ */
				unregister_shift_mods();
			} else {
				send_char(c);
			}

			if (keep_screen_message[keep_screen_pos + 1] == '\0')
				keep_screen_pos = 0;
			else
				keep_screen_pos += 1;
		} else {
			register_control_mods();
			wait_ms(500);
			unregister_control_mods();
		}
	}
}

#define KS____ KS_TRANS
static struct translation TRANSLATION_MAP[] = {
	/* US -> JIS translation map */
	/* CTL    ALT     SHIFT   KEYCODE                 CTL     ALT     SHIFT   KEYCODE */
	{ KS____, KS____, KS_OFF, MY_EQL_PLUS  , /* -> */ KS____, KS____, KS_ON , JP_MINS }, /* = */
	{ KS____, KS____, KS_ON , MY_EQL_PLUS  , /* -> */ KS____, KS____, KS_ON , JP_SCLN }, /* + */
	{ KS____, KS____, KS_OFF, MY_MIN_USCRE , /* -> */ KS____, KS____, KS_OFF, JP_MINS }, /* - */
	{ KS____, KS____, KS_ON , MY_MIN_USCRE , /* -> */ KS____, KS____, KS_ON , JP_BSLS }, /* _ */
	{ KS____, KS____, KS_OFF, MY_TILD_BQUOT, /* -> */ KS____, KS____, KS_ON , JP_AT   }, /* ` */
	{ KS____, KS____, KS_ON , MY_TILD_BQUOT, /* -> */ KS____, KS____, KS_ON , JP_CIRC }, /* ~ */
	{ KS____, KS____, KS_OFF, MY_QUOT_DQUOT, /* -> */ KS____, KS____, KS_ON , KC_7    }, /* ' */
	{ KS____, KS____, KS_ON , MY_QUOT_DQUOT, /* -> */ KS____, KS____, KS_ON , KC_2    }, /* " */
	{ KS____, KS____, KS_ON , KC_2         , /* -> */ KS____, KS____, KS_OFF, JP_AT   }, /* @ */
	{ KS____, KS____, KS_ON , KC_6         , /* -> */ KS____, KS____, KS_OFF, JP_CIRC }, /* ^ */
	{ KS____, KS____, KS_ON , KC_7         , /* -> */ KS____, KS____, KS_ON , KC_6    }, /* & */
	{ KS____, KS____, KS_ON , KC_8         , /* -> */ KS____, KS____, KS_ON , JP_COLN }, /* * */
	{ KS____, KS____, KS_ON , KC_9         , /* -> */ KS____, KS____, KS_ON , KC_8    }, /* ( */
	{ KS____, KS____, KS_ON , KC_0         , /* -> */ KS____, KS____, KS_ON , KC_9    }, /* ) */
	{ KS____, KS____, KS_ON , KC_SCLN      , /* -> */ KS____, KS____, KS_OFF, JP_COLN }, /* : */

	/* Custom key */
	/* CTL    ALT     SHIFT   KEYCODE          CTL     ALT     SHIFT   KEYCODE   FLAG  CALLBACK */
	{ KS_ON , KS____, KS_OFF, KC_ESC,          KS____, KS____, KS____, KC_NO   , NULL, cb_toggle_custom_key_mode }, /* C-ESC              */
	{ KS_ON , KS____, KS_ON , KC_ESC,          KS____, KS____, KS____, KC_NO   , NULL, cb_show_custom_key_mode   }, /* C-S-ESC            */
	{ KS_ON , KS____, KS_ON , KC_A  , /* -> */ KS_ON , KS____, KS_OFF, KC_A    , &flg_control_custom_key_enabled }, /* C-S-a => C-a       */
	{ KS_ON , KS____, KS____, KC_A  , /* -> */ KS_OFF, KS____, KS____, KC_HOME , &flg_control_custom_key_enabled }, /* C-a   -> HOME      */
	{ KS_ON , KS____, KS____, KC_E  , /* -> */ KS_OFF, KS____, KS____, KC_END  , &flg_control_custom_key_enabled }, /* C-e   -> END       */
	{ KS_ON , KS____, KS____, KC_D  , /* -> */ KS_OFF, KS____, KS____, KC_DEL  , &flg_control_custom_key_enabled }, /* C-d   -> Delete    */
	{ KS_ON , KS____, KS____, KC_U  , /* -> */ KS_OFF, KS____, KS____, KC_BSPC , &flg_control_custom_key_enabled }, /* C-u   -> Backspace */
	{ KS_ON , KS____, KS____, KC_O  , /* -> */ KS_OFF, KS____, KS____, KC_DEL  , &flg_control_custom_key_enabled }, /* C-o   -> Delete    */
	{ KS_ON , KS____, KS____, KC_J  , /* -> */ KS_OFF, KS____, KS____, KC_DOWN , &flg_control_custom_key_enabled }, /* C-j   -> Down      */
	{ KS_ON , KS____, KS____, KC_K  , /* -> */ KS_OFF, KS____, KS____, KC_UP   , &flg_control_custom_key_enabled }, /* C-k   -> Up        */
	{ KS_ON , KS____, KS____, KC_H  , /* -> */ KS_OFF, KS____, KS____, KC_LEFT , &flg_control_custom_key_enabled }, /* C-h   -> Left      */
	{ KS_ON , KS____, KS____, KC_L  , /* -> */ KS_OFF, KS____, KS____, KC_RIGHT, &flg_control_custom_key_enabled }, /* C-l   -> Right     */
	{ KS_ON , KS____, KS____, KC_M  , /* -> */ KS_OFF, KS____, KS____, KC_ENT  , &flg_control_custom_key_enabled }, /* C-m   -> Enter     */

	/* Shortcut key */
	/* CTL    ALT     SHIFT   KEY            CTL     ALT     SHIFT   KEY    FLAG  CALLBACK */
	{ KS_ON , KS_ON , KS_OFF, KC_L, /* -> */ KS____, KS____, KS____, KC_NO, NULL, cb_win_vdesktop }, /* C-A-l */
	{ KS_ON , KS_ON , KS_OFF, KC_H, /* -> */ KS____, KS____, KS____, KC_NO, NULL, cb_win_vdesktop }, /* C-A-h */

	/* Keep screen key */
	/* CTL    ALT     SHIFT   KEYCODE                   CTL     ALT     SHIFT   KEY    FLAG  CALLBACK */
	{ KS_OFF, KS_OFF, KS_OFF, MY_KEEP_SCREEEN, /* -> */ KS____, KS____, KS____, KC_NO, NULL, cb_toggle_keep_screen_message },
	{ KS_ON , KS_OFF, KS_OFF, MY_KEEP_SCREEEN, /* -> */ KS____, KS____, KS____, KC_NO, NULL, cb_toggle_keep_screen_ctrl },

	/* Toggle OS */
	/* CTL    ALT     SHIFT   KEYCODE                CTL     ALT     SHIFT   KEY    FLAG  CALLBACK */
	{ KS____, KS____, KS____, MY_TOGGLE_OS, /* -> */ KS____, KS____, KS____, KC_NO, NULL, cb_toggle_os },
};
#undef KS____

static struct translation *translating = NULL;

static struct translation *find_translation_key(uint16_t keycode)
{
	struct translation *trans;

	if (!my_shift && !my_control && !mod_alt) {
		if (KC_A <= keycode && keycode <= KC_0)
			return NULL;
	}

	for (int i = 0; i < sizeof(TRANSLATION_MAP) / sizeof(*TRANSLATION_MAP); i++) {
		trans = &TRANSLATION_MAP[i];

		if (trans->from_keycode != keycode)
			continue;

		if (trans->flg_enabled != NULL && !*trans->flg_enabled)
			continue;

		if (trans->from_shift != KS_TRANS &&
			((trans->from_shift == KS_ON && !my_shift) ||
			 (trans->from_shift == KS_OFF && my_shift)))
			continue;

		if (trans->from_control != KS_TRANS &&
			((trans->from_control == KS_ON && !my_control) ||
			 (trans->from_control == KS_OFF && my_control)))
			continue;

		if (trans->from_alt != KS_TRANS &&
			((trans->from_alt == KS_ON && !mod_alt) ||
			 (trans->from_alt == KS_OFF && mod_alt)))
			continue;

		return trans;
	}

	return NULL;
}

static void disable_translation_key(struct translation *trans)
{
	unregister_code(trans->to_keycode);
	reset_my_control_mods();
	reset_my_shift_mods();
}

static void enable_translation_key(struct translation *trans)
{
	bool should_wait = false;

	if (trans->to_shift != KS_TRANS) {
		if (trans->to_shift)
			should_wait |= register_shift_mods();
		else
			should_wait |= unregister_shift_mods();
	}

	if (trans->to_control != KS_TRANS) {
		if (trans->to_control)
			should_wait |= register_control_mods();
		else
			should_wait |= unregister_control_mods();
	}

	if (should_wait)
		wait_ms(80);

	register_code(trans->to_keycode);
}

static void reset_translation_key(void)
{
	if (translating)
		disable_translation_key(translating);
	translating = NULL;
}

static void do_translation_key(struct translation *trans)
{
	reset_translation_key();

	if (trans->callback) {
		trans->callback(trans);
	} else {
		enable_translation_key(trans);
		translating = trans;
	}
}


static bool process_translation_key(uint16_t keycode, keyrecord_t *record)
{
	struct translation *trans = find_translation_key(keycode);

	if (trans) {
		if (record->event.pressed) {
			do_translation_key(trans);
			return false;
		} else {
			disable_translation_key(trans);
		}
	} else {
		if (record->event.pressed) {
			reset_translation_key();
			return true;
		} else {
			reset_translation_key();
		}
	}
	return true;
}

static bool process_my_control(uint16_t keycode, keyrecord_t *record)
{
	if (keycode != MY_CONTROL)
		return true;

	my_control = record->event.pressed;
	reset_translation_key();
	reset_my_control_mods();

	return false;
}

static bool process_my_shift(uint16_t keycode, keyrecord_t *record)
{
	if (keycode != MY_SHIFT)
		return true;

	my_shift = record->event.pressed;
	reset_translation_key();
	reset_my_shift_mods();

	return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	fetch_mods_status();

	if (!process_my_shift(keycode, record))
		return false;

	if (!process_my_control(keycode, record))
		return false;
	
	if (!process_translation_key(keycode, record))
		return false;
	
	return true;
}
