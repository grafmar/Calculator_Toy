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
  m_isEnterNumber(false),
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
    myDisplay.showConfig(myCalculation.getOperations(), String(myCalculation.getMaxSmallNum()), m_isEnterNumber);
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
  bool updateScreen = false;
  if (m_isEnterNumber) {
    if ((key == '>') && (m_resultPos > 0)) {
      myCalculation.setMaxSmallNum(atoi(m_result));
      updateScreen = true;
      m_isEnterNumber = false;
    } else {
      handleEnterNumber(key,4);
      showConfigNumber();
    }
  } else {
    switch(key) {
      case '1':
        toggleOperation(Calculation::EN_PLUS);
        updateScreen = true;
        break;

      case '2':
        toggleOperation(Calculation::EN_MINUS);
        updateScreen = true;
        break;

      case '3':
        toggleOperation(Calculation::EN_MULT);
        updateScreen = true;
        break;

      case '4':
        toggleOperation(Calculation::EN_DIV);
        updateScreen = true;
        break;

      case '5':
        m_isEnterNumber=true;
        m_resultPos=0;
        m_result[0]='\0';
        showConfigNumber();
        break;

      case '>':
        enterGame();
        break;

      case KeypadReader::ESC_KEY:
      case KeypadReader::NO_KEY:
      default:
        break;
    }
  }
  if (updateScreen) {
    myDisplay.showConfig(myCalculation.getOperations(), String(myCalculation.getMaxSmallNum()), m_isEnterNumber);
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
  myDisplay.showConfig(myCalculation.getOperations(), String(myCalculation.getMaxSmallNum()), m_isEnterNumber);
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

void Game::toggleOperation(uint8_t op) {
  uint8_t setOp = myCalculation.getOperations();
  if (setOp != op) { // only toggle if other operations are set
    setOp = setOp ^ op;
    myCalculation.setOperations(setOp);
  }
}

void Game::showConfigNumber() {
  myDisplay.showConfig(myCalculation.getOperations(), String(m_result), m_isEnterNumber);  
}

void Game::handleEnterNumber(char key, uint8_t maxDigits) {
  if ((key >= '0') && (key <= '9') && (m_resultPos < maxDigits)) {
    m_result[m_resultPos++] = key;
    m_result[m_resultPos] = '\0';
  }
  if ((key == '<') && (m_resultPos > 0)) {
    m_resultPos--;
    m_result[m_resultPos] = '\0';
  }

}
