/**
 ******************************************************************************
 * \file Melody.h
 *
 * \par<b>Detailed Description:</b>
 * Definition of a melody with its name, bpm, frequencies and durations.
 ******************************************************************************
 */
#ifndef MELODY_H
#define MELODY_H

#include <Arduino.h>

/******************************************************************************
 ** Constants, Makros and type definitions                                   **
 ******************************************************************************/

typedef struct {
    const uint16_t    bpm;
    const uint16_t    voice1Len;
    const uint16_t * const voice1;
} melody_t;

/// Shifts the given frequency (of octave 4) to the given octave
//lint -emacro( 506, MEL_TONE_SHIFT_TO_OCTAVE )
//lint -emacro( 778, MEL_TONE_SHIFT_TO_OCTAVE )
#define MEL_TONE_SHIFT_TO_OCTAVE(freq, x)   ((x >= 4) ? (freq << (x-4)) : (freq >> (4-x)))

/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_C(x)                       MEL_TONE_SHIFT_TO_OCTAVE(262, x)
/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_CIS(x)                     MEL_TONE_SHIFT_TO_OCTAVE(277, x)
/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_D(x)                       MEL_TONE_SHIFT_TO_OCTAVE(294, x)
/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_DIS(x)                     MEL_TONE_SHIFT_TO_OCTAVE(311, x)
/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_E(x)                       MEL_TONE_SHIFT_TO_OCTAVE(330, x)
/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_F(x)                       MEL_TONE_SHIFT_TO_OCTAVE(349, x)
/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_FIS(x)                     MEL_TONE_SHIFT_TO_OCTAVE(370, x)
/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_G(x)                       MEL_TONE_SHIFT_TO_OCTAVE(392, x)
/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_GIS(x)                     MEL_TONE_SHIFT_TO_OCTAVE(415, x)
/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_A(x)                       MEL_TONE_SHIFT_TO_OCTAVE(440, x)
/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_AIS(x)                     MEL_TONE_SHIFT_TO_OCTAVE(466, x)
/// Tone definition C  . Use octave number as parameter MEL_TONE_A(4) -> 440 Hz
#define MEL_TONE_H(x)                       MEL_TONE_SHIFT_TO_OCTAVE(494, x)

/// Define a puase as freqency 0 Hz
#define MEL_PAUSE                           0

/// Default BPM is set to 256 BPM
#define MEL_BPM_DEFAULT     256

#define MEL_NOTE_4TH        (60000LL / MEL_BPM_DEFAULT)                         ///< 1/4 Note length
#define MEL_NOTE_8TH        (MEL_NOTE_4TH / 2)                                  ///< 1/8 Note length
#define MEL_NOTE_16TH       (MEL_NOTE_4TH / 4)                                  ///< 1/16 Note length
#define MEL_NOTE_32TH       (MEL_NOTE_4TH / 8)                                  ///< 1/32 Note length
#define MEL_NOTE_2TH        (MEL_NOTE_4TH * 2)                                  ///< 1/2 Note length
#define MEL_NOTE_1TH        (MEL_NOTE_4TH * 4)                                  ///< Full Note length
#define MEL_NOTE_HALF       (MEL_NOTE_4TH * 2)                                  ///< 1/2 Note length
#define MEL_NOTE_FULL       (MEL_NOTE_4TH * 4)                                  ///< 1/1 Note length

#define MEL_NOTE_4TH_DOT    (MEL_NOTE_4TH  + MEL_NOTE_8TH)                      ///< dotted 1/4 Note length
#define MEL_NOTE_8TH_DOT    (MEL_NOTE_8TH  + MEL_NOTE_16TH)                     ///< dotted 1/8 Note length
#define MEL_NOTE_16TH_DOT   (MEL_NOTE_16TH + MEL_NOTE_32TH)                     ///< dotted 1/16 Note length
#define MEL_NOTE_32TH_DOT   (MEL_NOTE_32TH + MEL_NOTE_32TH/2)                   ///< dotted 1/32 Note length
#define MEL_NOTE_2TH_DOT    (MEL_NOTE_2TH  + MEL_NOTE_4TH)                      ///< dotted 1/2 Note length
#define MEL_NOTE_1TH_DOT    (MEL_NOTE_1TH  + MEL_NOTE_2TH)                      ///< dotted 1/1 Note length
#define MEL_NOTE_HALF_DOT   (MEL_NOTE_HALF + MEL_NOTE_4TH)                      ///< dotted 1/2 Note length
#define MEL_NOTE_FULL_DOT   (MEL_NOTE_FULL + MEL_NOTE_2TH)                      ///< dotted 1/1 Note length

#endif // MELODY_H
