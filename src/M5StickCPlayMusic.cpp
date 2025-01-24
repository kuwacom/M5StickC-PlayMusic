#include "M5StickCPlayMusic.h"
#include <M5StickC.h>

M5StickCPlayMusic::M5StickCPlayMusic(int pin)
{
    _pin = pin;
    _volume = 1;
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

void M5StickCPlayMusic::setVolume(double volume)
{
    _volume = volume;
}

void M5StickCPlayMusic::playMusic(const uint8_t *musicData, uint16_t sampleRate, PlayMusicCallbackFunction callback)
{
    uint32_t length = strlen((char *)musicData);
    uint16_t delayInterval = ((uint32_t)1000000 / sampleRate);

    for (int i = 0; i < length; i++)
    {
        dacWrite(_pin, musicData[i] * _volume);
        if (callback != nullptr)
        {
            // インデックスと音の値を渡す
            callback(i, musicData[i]);
        }
        delayMicroseconds(delayInterval);
    }
}

void M5StickCPlayMusic::playMusicNoCallback(const uint8_t *musicData, uint16_t sampleRate)
{
    uint32_t length = strlen((char *)musicData);
    uint16_t delayInterval = ((uint32_t)1000000 / sampleRate);

    for (int i = 0; i < length; i++)
    {
        dacWrite(_pin, musicData[i] * _volume);
        delayMicroseconds(delayInterval);
    }
}
