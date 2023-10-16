#include "Game.h"
#include "KeypadReader.h"
#include "Calculation.h"
#include "MelodyPlayer.h"
#include "MelodyCollection.h"
#include "Display.h"
static const uint8_t BUZZER = 11;
MelodyPlayer melodyPlayer(BUZZER);

Display myDisplay;
Calculation myCalculation;

Game::Game() :
  m_state(GameState::CONFIG),
  m_score(0U),
  m_lifes(0U),
  m_points(0U),
  m_pointsTime(0U)
{
}

Game::~Game() {
}

void Game::begin() {
    myDisplay.begin();
    myDisplay.showConfig();
}

void Game::handle(char key) {
  switch(m_state) {
    case GameState::CONFIG:
      handleConfig(key);
      break;
    case GameState::GAME:
      handleGame(key);
      break;
    case GameState::SCORE:
      handleScore(key);
      break;
  }  
}

void Game::handleConfig(char key) {
  switch(key) {
    case '>':
      enterGame();
      break;

    case KeypadReader::ESC_KEY:
    case KeypadReader::NO_KEY:
    default:
      break;
  }
}

char myString[20];
uint8_t pos=0;

void Game::handleGame(char key) {
  if (key != KeypadReader::NO_KEY) {
    if (pos>18) pos=0;
    myString[pos++]=key;
    myString[pos]='\0';
    myCalculation.generateCalculation();
//    myDisplay.showGame(3, 1234, "7+18=", myString);
    myDisplay.showGame(3, 7, 14, myCalculation.getCalculationString().c_str(), myString);

    if (key == '0') myDisplay.showFinalScore(123);

/*
    if (key == '0') melodyPlayer.play(melodyGood);
    if (key == '1') melodyPlayer.play(melodyBad);
    if (key == '2') melodyPlayer.play(melodyScoreUp);
    if (key == '3') melodyPlayer.play(melodyVictory);
    if (key == '4') melodyPlayer.play(melodyFinishDrum);
    */
  }
}

void Game::handleScore(char key) {
}

void Game::enterConfig() {
  myDisplay.showConfig();
  m_state = GameState::CONFIG;
}

void Game::enterGame() {
  m_score = 0U;
  m_lifes = 3U;
  newGameStep();
  myDisplay.showGame(m_lifes, m_points, m_score, myCalculation.getCalculationString().c_str(), m_result);
  m_state = GameState::GAME;
}

void Game::enterScore() {
  myDisplay.showFinalScore(m_score);
  m_state = GameState::SCORE;
}

void Game::newGameStep() {
  m_points = 10;
  m_pointsTime = millis();
  m_resultPos = 0;
  m_result[0] = '\0';
  myCalculation.generateCalculation();
}
