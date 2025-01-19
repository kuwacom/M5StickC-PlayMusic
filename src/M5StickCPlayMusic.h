#ifndef M5STICKCPLAYMUSIC_H
#define M5STICKCPLAYMUSIC_H

#include <Arduino.h>

class M5StickCPlayMusic
{
public:
    M5StickCPlayMusic(int pin);
    void begin();
    void playMusic(const uint8_t *music_data, uint16_t sample_rate);

private:
    int _pin;
};

#endif
