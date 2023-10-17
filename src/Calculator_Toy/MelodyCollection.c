#include "MelodyCollection.h"

/******************************************************************************
 ** Constants, Makros and type definitions                                   **
 ******************************************************************************/

#define MEL_LENGTH(x)           (sizeof(x)/sizeof(uint16_t))

/******************************************************************************
 ** Variables                                                                **
 ******************************************************************************/

//------------------------------------------------------------------------------
/// Melody "Good"
const uint16_t melodyGood_voice[] = {
  MEL_TONE_F(6),   200,
  MEL_PAUSE,        50,
  MEL_TONE_AIS(6), 150};
const melody_t melodyGood = { 2*MEL_BPM_DEFAULT, MEL_LENGTH(melodyGood_voice), melodyGood_voice};

//------------------------------------------------------------------------------
/// Melody "Bad"
const uint16_t melodyBad_voice[] = {
  MEL_TONE_F(6),   200,
  MEL_PAUSE,        50,
  MEL_TONE_AIS(5), 500};
const melody_t melodyBad = { 2*MEL_BPM_DEFAULT, MEL_LENGTH(melodyBad_voice), melodyBad_voice};

//------------------------------------------------------------------------------
/// Melody "Score up"
const uint16_t melodyScoreUp_voice[] = { MEL_TONE_A(6), 100};
const melody_t melodyScoreUp = { MEL_BPM_DEFAULT, MEL_LENGTH(melodyScoreUp_voice), melodyScoreUp_voice};

//------------------------------------------------------------------------------
/// Melody "Victory"
const uint16_t melodyVictory_voice[] = {
  MEL_TONE_C(4),  MEL_NOTE_8TH,
  MEL_TONE_E(4),  MEL_NOTE_8TH,
  MEL_TONE_F(4),  MEL_NOTE_8TH,
  MEL_TONE_G(4),  MEL_NOTE_4TH,
  MEL_TONE_E(4),  MEL_NOTE_8TH,
  MEL_TONE_G(4),  MEL_NOTE_2TH};
const melody_t melodyVictory = { 240, MEL_LENGTH(melodyVictory_voice), melodyVictory_voice};
                                
//------------------------------------------------------------------------------
/// Melody "Finish drum"
const uint16_t melodyFinishDrum_voice[] = {
  MEL_TONE_C(4),  MEL_NOTE_4TH,
  MEL_TONE_G(3),  MEL_NOTE_8TH,
  MEL_TONE_G(3),  MEL_NOTE_8TH,
  MEL_TONE_A(3),  MEL_NOTE_4TH,
  MEL_TONE_G(3),  MEL_NOTE_4TH,
  MEL_PAUSE,      MEL_NOTE_8TH,
  MEL_TONE_H(3),  MEL_NOTE_4TH,
  MEL_TONE_C(4),  MEL_NOTE_4TH};
const melody_t melodyFinishDrum = { 240, MEL_LENGTH(melodyFinishDrum_voice), melodyFinishDrum_voice};
