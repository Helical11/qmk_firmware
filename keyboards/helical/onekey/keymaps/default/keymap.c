// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// 必要なヘッダーファイルをインクルード
#include QMK_KEYBOARD_H

// タップダンスの識別子を定義
enum {
    TD_DOUBLE = 0, // ダブルタップ用のタップダンス
};

// タップダンスの動作を定義
void double_tap_dance(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // シングルタップ時にKC_Aを送信
        register_code16(KC_A);
        unregister_code16(KC_A);
    } else if (state->count == 2) {
        // ダブルタップ時にKC_Bを送信
        register_code16(KC_B);
        unregister_code16(KC_B);
    }
}

// タップダンスアクションを登録
tap_dance_action_t tap_dance_actions[] = {
    [TD_DOUBLE] = ACTION_TAP_DANCE_FN(double_tap_dance) // TD_DOUBLEにdouble_tap_danceを割り当て
};

// キーマップを定義
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TD(TD_DOUBLE) // タップダンスキーをレイアウトに配置
    )
};
