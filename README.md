# sdvx-keypad
## About
PIC18F14k50用.  
[MLAのサンプル](http://www.microchip.com/ja/mplab/microchip-libraries-for-applications)をベースにしています.  
USBで接続するとHIDキーボードとして認識されます.  
Makefile内のXC(コンパイラへのパス)は必要に応じて変更してください.
入力と出力の対応は以下の通りです.  

|入力ピン|出力されるキー|
|---:|---:|
|RC0|a|
|RC1|b|
|RC2|c|
|RC3|d|
|RC4|e|
|RC5|f|
|RC6|Enter|
|RB7|g|
|RB6|h|
|RB5|i|
|RB4|j|
RC7には状態表示用LEDを接続できます. USB接続が確立されると引き込みでONになります.  
RC6をSTARTボタンに割り当てれば幸せになれるかもしれません.
