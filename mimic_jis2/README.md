# Mimic JIS 2
英語配列のキーボードを日本語設定のOSで使用するための実装です。

## 対応機器
- USB-USB Converter
  https://geekhack.org/index.php?topic=109514.0
  > make converter/usb_usb:mimic_jis2

- HHKB Alt Controller with Mini-B connector
  https://geekhack.org/index.php?topic=71517.0
  > make hhkb/ansi:mimic_jis2

- Keyboard Quantizer Rev3
  https://github.com/sekigon-gonnoc/keyboard-quantizer-doc
  > make keyboard_quantizer/rev3:mimic_jis2

## カスタマイズ
以下のカスタマイズが可能です。
`#include "mimic_jis2.c"` の前に、以下のマクロを `#define` してください。

- MIMIC_JIS_KEEP_SCREEN_ENABLE
  - スクリーンロックしないように、定期的に文字入力する機能を有効にします。
  - 標準では、Ctrl+ESC で起動するようになっています。
  - 好みのキーに割り当てる場合は、MY_KEEP_SCREEEN キーをキーマップに設定してください。
- MIMIC_JIS_CONTROL_ZKHK_ENABLE
  - コントロールキーの空打ちで 全角/半角 キーをタップします。
- MIMIC_JIS_TILDE_TO_ZKHK_ENABLE
  - チルダキー を 全角/半角 キーに変更します。
  - 左上にチルダキーがあることが多いため、このキーを全角/半角にしたい場合に使用できます。
- MIMIC_JIS_MY_CUSTOM_FEATURE_ENABLE
  - 私の個人的なショートカットです。定義不要です。

## 特殊なキーの説明
内部で使用するための特別なキーコードを定義しています。
キーマップをお好みに変更する場合に活用ください。

### 製品共通
|キー定義|説明|
|-|-|
|MY_CONTROL        |Ctrlキーをハンドルするために使用しています。KC_LCTLなどを置き換えてください。|
|MY_SHIFT          |Shiftキーをハンドルするために使用しています。KC_LSFTなどを置き換えてください。|
|MY_EQL_PLUS       |英字キーの[=/+]キーをJIS配列向きの出力に変換するために使用します。|
|MY_MIN_USCRE      |英字キーの[-/_]キーをJIS配列向きの出力に変換するために使用します。|
|MY_TILD_BQUOT     |英字キーの[`/~]キーをJIS配列向きの出力に変換するために使用します。|
|MY_QUOT_DQUOT     |英字キーの['/"]キーをJIS配列向きの出力に変換するために使用します。|
|MY_KEEP_SCREEEN   |スクリーン維持機能の切り替え用のキーです。|
|MY_ZENKAKU_HANKAKU|[全角/半角]キーを出力します。|
|MY_MOD_1          |個人的なショートカットです。|
|MY_MOD_2          |個人的なショートカットです。|
|MY_MOD_3          |個人的なショートカットです。|

### HHKB Alt Controller専用
HHKB Alt Controllerは、取り外しが簡単にはできないため、
Win/Mac切替やUS/JIS切替ができるようにしています。

|キー定義|説明|
|-|-|
|MY_TOGGLE_OS      |WindowsとMac向けの入力を切り替えます。HHKB以外は意味ありません。|
|MY_TOGGLE_LANG    |US=>JIS変換するかしないかを切り替えます。HHKB以外は意味ありません。|
