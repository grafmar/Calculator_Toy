/**
 ******************************************************************************
 * \file MelodyCollection.h
 *
 * \par<b>Detailed Description:</b>
 * Collection of melodies to play
 ******************************************************************************
 */
#ifndef MELODYCOLLECTION_H
#define MELODYCOLLECTION_H

#include "Melody.h"

static const uint8_t melodyGood[] = {
  3, // number of notes
  MEL_TONE_F(6),   100,
  MEL_PAUSE,        25,
  MEL_TONE_AIS(6), 75};


static const uint8_t melodyBad[] = {
  3, // number of notes
  MEL_TONE_F(6),   100,
  MEL_PAUSE,        25,
  MEL_TONE_AIS(5), 250};

static const uint8_t melodyScoreUp[] = {
  1,
  MEL_TONE_A(6), 100};

static const uint8_t melodyVictory[] = {
  6, // number of notes
  MEL_TONE_C(4),  MEL_NOTE_8TH,
  MEL_TONE_E(4),  MEL_NOTE_8TH,
  MEL_TONE_F(4),  MEL_NOTE_8TH,
  MEL_TONE_G(4),  MEL_NOTE_4TH,
  MEL_TONE_E(4),  MEL_NOTE_8TH,
  MEL_TONE_G(4),  MEL_NOTE_2TH};
                                
static const uint8_t melodyFinishDrum[] = {
  8, // number of notes
  MEL_TONE_C(4),  MEL_NOTE_4TH,
  MEL_TONE_G(3),  MEL_NOTE_8TH,
  MEL_TONE_G(3),  MEL_NOTE_8TH,
  MEL_TONE_A(3),  MEL_NOTE_4TH,
  MEL_TONE_G(3),  MEL_NOTE_4TH,
  MEL_PAUSE,      MEL_NOTE_8TH,
  MEL_TONE_H(3),  MEL_NOTE_4TH,
  MEL_TONE_C(4),  MEL_NOTE_4TH};


#endif // MELODYCOLLECTION_H
