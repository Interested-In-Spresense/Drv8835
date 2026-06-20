# DRV8835 DCモータードライバーモジュールライブラリ

DRV8835モータードライバーモジュールをArduino/Spresenseから制御するためのライブラリです。

対象モジュール（参考）:
https://akizukidenshi.com/catalog/g/g109848/

## 概要

- 2chのDCモーター制御
- 速度指定（0-100%）
- 正転・逆転・停止
- MODEピンあり/なしの2種類の初期化関数

## ピン割り当て

引数 `e0, p0, e1, p1` は以下の入力端子に対応します。

- e0: IN0
- p0: IN1
- e1: IN2
- p1: IN3

MODEピンを使う場合は `mp` にMODE端子のGPIO番号を指定します。

## API

### 初期化

```cpp
void begin(bool m, uint8_t e0, uint8_t p0, uint8_t e1, uint8_t p1, uint8_t mp);
void begin(bool m, uint8_t e0, uint8_t p0, uint8_t e1, uint8_t p1);
```

- `m` : モード設定値（MODEピンへ出力する値）
- `e0, p0, e1, p1` : モータードライバ入力端子のGPIO番号
- `mp` : MODEピンのGPIO番号

### 動作制御

```cpp
void speed(uint8_t ch, uint8_t value);
void front(uint8_t ch);
void back(uint8_t ch);
void front(uint8_t ch, uint8_t speed);
void back(uint8_t ch, uint8_t speed);
void stop(uint8_t ch);
```

- `ch` : チャンネル番号（0 または 1）
- `value`, `speed` : 0-100（%）

## 使い方

### MODEピンを使う例

```cpp
#include "Drv8835.h"

const uint8_t modePin = 2;

void setup() {
	Drv8835.begin(true, 19, 18, 21, 20, modePin);
}

void loop() {
	Drv8835.speed(0, 60);
	Drv8835.front(0);
	delay(1000);

	Drv8835.stop(0);
	delay(500);
}
```

### MODEピンを使わない例

```cpp
#include "Drv8835.h"

void setup() {
	Drv8835.begin(false, 19, 18, 21, 20);
}

void loop() {
	Drv8835.front(0, 50);
	delay(1000);

	Drv8835.back(0, 50);
	delay(1000);
}
```

## サンプル

examples配下に以下のサンプルがあります。

- simple
- simple_enph
- simple_inin

## ビルド確認

Spresense向けに以下サンプルのコンパイル確認済みです。

- simple
- simple_enph
- simple_inin

`arduino-cli` では、ライブラリの `architecture=all` に関する警告が出ることがありますが、コンパイル自体は通ります。

## ライセンス

このライブラリはLGPL v2.1以降で提供されます。
