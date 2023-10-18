#include "MelodyPlayer.h"

MelodyPlayer::MelodyPlayer(uint8_t buzzerIO) :
  m_buzzerIO(buzzerIO)
{
}

MelodyPlayer::~MelodyPlayer() {
}

void MelodyPlayer::play(uint8_t* melody) {
  const uint16_t melodyLength = melody[0];
  for (uint16_t noteNum = 0U; noteNum < melodyLength ; noteNum++) {
    // freqency was divided by 8 to fit uint8_t
    // length was divided by 2
    playNote(8*melody[2*noteNum+1], 2*melody[2*noteNum+2]); 
  }
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
