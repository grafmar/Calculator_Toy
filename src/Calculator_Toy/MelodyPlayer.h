#ifndef MELODYPLAYER_H
#define MELODYPLAYER_H

#include <Arduino.h>
#include "Melody.h"

class MelodyPlayer {
public:

  explicit MelodyPlayer(uint8_t buzzerIO);
  ~MelodyPlayer();

  /**
  ******************************************************************************
  * \brief   Plays the given tone on the buzzer
  *
  * \param   buzTone     The tone to play
  * \return  -
  */
  void play(melody_t melody);

  /**
  ******************************************************************************
  * \brief   Beeps at the given frequency fot the given duration
  *
  * \param   freq        Frequency to beep
  * \param   duration    Duration of the beep in [ms]
  * \return  -
  */
  void beep(uint16_t freq, uint16_t duration);

  /**
  ******************************************************************************
  * \brief   Plays a the note at the given frequency fot the given duration
  *          with a slight pause at the end to recognize the note.
  *
  * \param   freq        Frequency to beep
  * \param   duration    Duration of the beep in [ms]
  * \return  -
  */
  void playNote(uint16_t freq, uint16_t duration);

  /**
  ******************************************************************************
  * \brief   Do a tone pause
  *
  * \param   duration    Duration of the beep in [ms]
  * \return  -
  */
  void pause(uint16_t duration);

private:

  uint8_t m_buzzerIO;

};

#endif // MELODYPLAYER_H
