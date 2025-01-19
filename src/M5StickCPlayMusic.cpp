#include "M5StickCPlayMusic.h"
#include <M5StickC.h>

M5StickCPlayMusic::M5StickCPlayMusic(int pin)
{
    _pin = pin;
}

// M5StickCをセットアップする用の関数
// 簡易用
void M5StickCPlayMusic::begin()
{
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.setCursor(0, 30, 4);
    M5.Lcd.println("speaker");

    pinMode(_pin, OUTPUT); // 出力モードに設定
}

void M5StickCPlayMusic::playMusic(const uint8_t *music_data, uint16_t sample_rate)
{
    uint32_t length = strlen((char *)music_data);                // 音源データの長さ
    uint16_t delay_interval = ((uint32_t)1000000 / sample_rate); // サンプル間隔（マイクロ秒）

    for (int i = 0; i < length; i++)
    {
        // dacWrite(_pin, music_data[i]);
        if (music_data[i] > 128)
        {
            digitalWrite(_pin, HIGH); // 波形がプラスの時HIGH
        }
        else
        {
            digitalWrite(_pin, LOW); // 波形がマイナスの時LOW
        }

        delayMicroseconds(delay_interval); // サンプル間隔で待機
    }
}
