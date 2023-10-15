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

#define MEL_MAX_NUM_OF_MELODIES 8                                               ///< Maximal number of melodies in the jukebox

#define MEL_NO_VOICE        ((uint16_t*) 0)                                     ///< Null pointer defining no voice
/******************************************************************************
 ** Variables                                                                **
 ******************************************************************************/
extern const melody_t melodyGood;
extern const melody_t melodyBad;
extern const melody_t melodyScoreUp;
extern const melody_t melodyVictory;
extern const melody_t melodyFinishDrum;


/******************************************************************************
 ** Functions                                                                **
 ******************************************************************************/

#endif // MELODYCOLLECTION_H
