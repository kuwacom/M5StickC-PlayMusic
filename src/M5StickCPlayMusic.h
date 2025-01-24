#ifndef M5STICKCPLAYMUSIC_H
#define M5STICKCPLAYMUSIC_H

#include <Arduino.h>

typedef void (*PlayMusicCallbackFunction)(int index, uint8_t sample);

class M5StickCPlayMusic
{
public:
    M5StickCPlayMusic(int pin);
    void begin();
    void setVolume(double volume);
    void playMusic(const uint8_t *musicData, uint16_t sampleRate, PlayMusicCallbackFunction callback);
    void playMusicNoCallback(const uint8_t *musicData, uint16_t sampleRate);

private:
    int _pin;
    double _volume;
};

#endif
