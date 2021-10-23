## 2-2
### 問：スマホなど、バッテリーで動くデバイスのデジタル論理回路は何Vで動作するか？

### 答
- 3.7V
- リチウムイオン電池の電圧が3.7Vなことから、バッテリーを利用するものは5V電圧ではないらしい
https://ja.wikipedia.org/wiki/%E3%83%AA%E3%83%81%E3%82%A6%E3%83%A0%E3%82%A4%E3%82%AA%E3%83%B3%E4%BA%8C%E6%AC%A1%E9%9B%BB%E6%B1%A0

- ただし,充電器はUSB2.0だと5Vで充電しているらしい. 理由はリチウム電池の特性や規格がもともと5Vだったなどいろいろあるらしいが参考までに.

https://electronics.stackexchange.com/questions/220444/why-some-phones-need-a-5v-charger-although-the-battery-needs-3-7v-only

## 2-7
### 問：チップメーカーが7nmのテクノロジーを使っていると誇るのはどういう意味か
### 答
- 何が7nmなのか：プロセスルールのこと
https://ja.wikipedia.org/wiki/%E9%9B%86%E7%A9%8D%E5%9B%9E%E8%B7%AF#%E3%83%97%E3%83%AD%E3%82%BB%E3%82%B9%E3%83%BB%E3%83%AB%E3%83%BC%E3%83%AB
- プロセスルールとは?
https://chimolog.co/bto-cpu-process/#:~:text=%E3%83%97%E3%83%AD%E3%82%BB%E3%82%B9%E3%81%AF%E3%80%8C%E8%A3%BD%E9%80%A0%E3%80%8D%E3%81%A8%E3%81%84%E3%81%86%E6%84%8F%E5%91%B3,%E3%81%8C%E3%83%97%E3%83%AD%E3%82%BB%E3%82%B9%E3%83%AB%E3%83%BC%E3%83%AB%E3%81%A8%E3%81%84%E3%81%86%E3%81%93%E3%81%A8%E3%80%82

- ただし、この7nmは会社によって評価の仕方が違うっぽく一概にIntelの値がでかいからダメというわけでもないらしい.
    - 後方互換性とかをサポートしながら, ベンチャーと戦い続けるIntel辛そう...

## 2-12
### 問：クロックレスロジックはどこで使われているか
### 答
- ARMのプロセッサ
https://www.cqpub.co.jp/DWM/contents/0105/dwm010501100.pdf

- Asynchronous circuitやSequential logicを参照したけどいまいちそれ以上の具体例は見られなかった.
https://en.wikipedia.org/wiki/Asynchronous_circuit#:~:text=In%20digital%20electronics%2C%20an%20asynchronous,by%20simple%20data%20transfer%20protocols.

https://en.wikipedia.org/wiki/Sequential_logic

- ちなみに、非同期分散処理を解析するためのネットワークモデルみたいなのがペトリネットという数理モデルらしい.wiki豊富でびっくりしたし、面白そうではあるので興味あったら是非
https://en.wikipedia.org/wiki/Petri_net