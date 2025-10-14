# DRV8835 Motor Driver Library

秋月電子の「DRV8835 使用ステッピング & DC モータードライバーモジュール」用の制御ライブラリです。  
このライブラリを使うことで、Arduino 環境で DRV8835 を簡単に制御できます。

---

## 機能概要

- DRV8835 チップで DC モータを 2 チャンネル制御  
- モード選択（EN/PH モード or IN/IN モード）対応  
- 各チャンネルに対して速度指定付き前進／後退制御  
- チャンネル毎の停止制御  
- 0～100％ の速度スケールで扱いやすい

---

## クラスとメソッド

ライブラリの中心は `Drv8835Class` で、以下のメソッドを提供します：

| メソッド | 説明 |
|---|---|
| `begin(bool m, uint8_t e0, uint8_t p0, uint8_t e1, uint8_t p1)` | モードピンなしで初期化 |
| `begin(bool m, uint8_t e0, uint8_t p0, uint8_t e1, uint8_t p1, uint8_t mp)` | モードピンありで初期化 |
| `speed(uint8_t ch, uint8_t value)` | 指定チャンネル(ch=0 or 1)の速度を 0～100 に設定 |
| `front(uint8_t ch)` | 指定チャンネルを前進（現在設定速度） |
| `back(uint8_t ch)` | 指定チャンネルを後退（現在設定速度） |
| `front(uint8_t ch, uint8_t speed)` | 指定チャンネルを指定速度で前進 |
| `back(uint8_t ch, uint8_t speed)` | 指定チャンネルを指定速度で後退 |
| `stop(uint8_t ch)` | 指定チャンネルを停止 |

なお、チャンネルは `0` および `1` を使用します。

---

## インストール方法

1. このリポジトリをクローンまたは ZIP でダウンロード  
   ```bash
   git clone https://github.com/Interested-In-Spresense/Drv8835.git
   ```
2. Arduino の `libraries` フォルダに配置  
3. Arduino IDE でスケッチにて `#include "Drv8835.h"` を追加して使用

---

## 使用例

```cpp
#include <Drv8835.h>

void setup() {
  // m = true → EN/PH モード, e0, p0, e1, p1, mp（モードピン）
  Drv8835.begin(true, 3, 4, 5, 6, 7);
  // またはモードピンなし
  // Drv8835.begin(true, 3, 4, 5, 6);
}

void loop() {
  // チャンネル 0 を前進、チャンネル 1 を後退
  Drv8835.front(0, 80);
  Drv8835.back(1, 80);
  delay(1000);

  Drv8835.stop(0);
  Drv8835.stop(1);
  delay(500);
}
```

---

## 注意事項 / Tips

- `m = true` を選ぶと EN/PH モード、`false` を選ぶと IN/IN モードになる仕様です。  
- `speed()` メソッドで速度を設定した後、`front()` / `back()` を使うとその速度が使われます。  
- モードピンを用いる場合は `begin()` の第6引数として `mp`（モードピン）を渡します。

---

## ライセンス

このライブラリは **GNU Lesser General Public License (LGPL) v2.1 以降** の条件で公開されています。  
（元のライセンス文を参照してください）
