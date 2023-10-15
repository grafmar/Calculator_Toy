#include "MelodyPlayer.h"

MelodyPlayer::MelodyPlayer(uint8_t buzzerIO) :
  m_buzzerIO(buzzerIO)
{
}

MelodyPlayer::~MelodyPlayer() {
}

void MelodyPlayer::play(melody_t melody) {
  for (uint16_t noteNum = 0U; noteNum < melody.voice1Len ; noteNum+=2) {
    uint16_t durAdapted = (uint16_t) ( (((uint32_t) melody.voice1[noteNum+1]) * MEL_BPM_DEFAULT) / melody.bpm);
    playNote(melody.voice1[noteNum], durAdapted);
  }
}

void MelodyPlayer::beep(uint16_t freq, uint16_t duration) {
    tone(m_buzzerIO, freq, duration);
    delay(duration*1.3);
    noTone(m_buzzerIO);
}

void MelodyPlayer::playNote(uint16_t freq, uint16_t duration) {
  if (freq == MEL_PAUSE) {
      pause(duration);
  } else {
    if (duration > 30) {
        tone(m_buzzerIO, freq, duration - 10);
    } else {
        tone(m_buzzerIO, freq, duration * 9 / 10);
    }
  }
  delay(duration);
  noTone(m_buzzerIO);
}

void MelodyPlayer::pause(uint16_t duration) {
  delay(duration);
}
