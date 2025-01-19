#include <M5StickC.h>
#include "src/M5StickCPlayMusic.h"

#include <test/winXP_startup.h>
#include <test/winXP_shutdown.h>
#include <test/winXP_error.h>

// 音声を出力するピンの設定
const int speakerPin = 26;
// 再生サンプリングレート
const int sampleRate = 8000;

const uint8_t sine[] = {
    1,
    255,
    1,
    255,
    1,
    255,
    1,
    255,
    1,
    255,
    1,
    255,
};

M5StickCPlayMusic player(speakerPin);

void setup()
{
    // player.begin(); // 初期化を楽したい場合はこれ
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.setCursor(0, 30, 4);
    M5.Lcd.println("speaker");

    // ピンの初期化
    pinMode(speakerPin, OUTPUT); // 出力モードに設定
}

void loop()
{
    player.playMusic(winXP_startup, sampleRate); // 8000Hzのサンプリングレートで再生
    delay(10000);
    player.playMusic(winXP_shutdown, sampleRate);
    delay(10000);
}
