/**
 * @file SyringeDriver.cpp
 * @author Limako
 * @author Sergio Gasquez Arcos (sergio.gasquez@gmail.es)
 * @brief Class which will control the system
 * @version 0.1
 * @date 2020-05-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "SyringeDriver.h"


SyringeDriver::SyringeDriver(uint8_t t_lcdAddr, uint8_t t_lcdCols, uint8_t t_lcdRows, uint8_t t_interface, uint8_t t_pin1, uint8_t t_pin2, uint8_t t_pin3, uint8_t t_pin4)
  : Stepper(t_interface, t_pin1, t_pin2, t_pin3, t_pin4), Display(t_lcdAddr, t_lcdCols, t_lcdRows)
{
}

void SyringeDriver::initialize()
{
  Stepper::initialize();
  Display::initialize();
}

void SyringeDriver::homing()
{
  Display::clear();
  Display::setCursor(0, 0);
  Display::print("Homing!");
  Stepper::move(500000);
  while (!digitalRead(STEPPER_FORWARD_BUTTON_PIN))
  {
    Stepper::run();
  }
  Stepper::stop();
  Stepper::setCurrentPosition(0);
  incrementActualState();
}

uint8_t SyringeDriver::getActualState()
{
  return m_actualState;
}

void SyringeDriver::incrementActualState()
{
  if (m_actualState == static_cast<int>(State::INITIAL))
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Nuevo Diametro");
    Display::setCursor(0, 1);
    Display::print("Jeringa D:");
  }
  else if (m_actualState == static_cast<int>(State::INSERT_SYRINGE))
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Seleccione carga ");
    Display::setCursor(0, 1);
    Display::print("en mL: ");
  }
  else if (m_actualState == static_cast<int>(State::ADJUST_MAX_SPEED))
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Seleccione Flow");
    Display::setCursor(0, 1);
    Display::print("en mLxH:");
  }
  else if (m_actualState == static_cast<int>(State::ADJUST_ACCELERATION))
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Aproximando!");
  }
  else if (m_actualState == static_cast<int>(State::ADJUSTING))
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Ajuste fino");
  }
  m_actualState++;
}
void SyringeDriver::updateSyringeDiameter()
{
  Display::setCursor(10, 1);
  float diameter = map(analogRead(POTENTIOMETER_PIN),0,1024,0,40);
  Display::print(diameter);
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    /*Display::setCursor(10, 1);
    diameter = analogRead(POTENTIOMETER_PIN);
    Display::print(diameter);*/
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
    incrementActualState();
  }
  m_diameter = diameter;
}

void SyringeDriver::updateMaxSpeed()
{

  Display::setCursor(10, 1);
  float maxSpeed = map(analogRead(POTENTIOMETER_PIN),0,1024,0,60);
  Display::print(maxSpeed);
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    /*Display::setCursor(10, 1);
    maxSpeed = analogRead(POTENTIOMETER_PIN);
    Display::print(maxSpeed);*/
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
    incrementActualState();
  }
  m_maxSpeed = maxSpeed;
}

void SyringeDriver::updateAcceleration()
{
  Display::setCursor(10, 1);
  float acceleration = map(analogRead(POTENTIOMETER_PIN),0,1024,2,15);
  Display::print(acceleration);
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    /*Display::setCursor(10, 1);
    acceleration = analogRead(POTENTIOMETER_PIN);
    Display::print(acceleration);*/
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
    incrementActualState();
  }
  m_acceleration = acceleration;
}

float SyringeDriver::getMaxSpeed()
{
  return m_maxSpeed;
}


float SyringeDriver::getAcceleration()
{
  return m_acceleration;
}

uint8_t SyringeDriver::getProgress()
{
  /// @todo : Review the method, what is the correct startingPosition/targetPosition? Should we save them into variable members ?
  int32_t startingPosition = 500000;
  int32_t targetPosition = -50000;
  int32_t currentPosition = Stepper::currentPosition();
  uint8_t progress = map(currentPosition, startingPosition, targetPosition, 0, 100);
  return progress;
}


void SyringeDriver::displayDrainningInfo()
{
  Display::clear();
  // Progress
  Display::setCursor(0, 0);
  Display::print("En Cliclo:");
  Display::setCursor(11, 0);
  Display::print(getProgress());
  Display::setCursor(15, 0);
  Display::print("%");
  // Speed
  Display::setCursor(0, 1);
  Display::print("Velocidad:");
  Display::setCursor(11, 0);
  Display::print(static_cast<int>(Stepper::speed()));
  Display::setCursor(13, 0);
  Display::print("ml/H");   // Review. The units will overfloat the display (16 rows)
}