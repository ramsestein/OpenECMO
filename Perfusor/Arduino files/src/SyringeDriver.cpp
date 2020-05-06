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
  while (!digitalRead(STEPPER_FORWARD_BUTTON_PIN))   // Duda??
    Stepper::run();
  Stepper::stop();
  Stepper::setCurrentPosition(0);

  m_actualState = static_cast<uint8_t>(State::INSERT_SYRINGE);
}

uint8_t SyringeDriver::getActualState()
{
  return m_actualState;
}

void SyringeDriver::incrementActualState()
{
  m_actualState++;
}

void SyringeDriver::updateSyringeDiameter()
{
  Display::clear();
  Display::setCursor(0, 0);
  Display::print("Coloca la nueva");
  Display::setCursor(0, 1);
  Display::print("Jeringa D:");
  Display::setCursor(10, 1);
  float diameter = analogRead(POTENTIOMETER_PIN);
  Display::print(diameter);
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
  }
  m_diameter = diameter;
}

void SyringeDriver::updateMaxSpeed()
{
  Display::clear();
  Display::setCursor(0, 0);
  Display::print("Seleccione ");
  Display::setCursor(0, 1);
  Display::print("MaxSpeed: ");
  Display::setCursor(10, 1);
  float maxSpeed = analogRead(POTENTIOMETER_PIN);
  Display::print(maxSpeed);
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
  }
  m_maxSpeed = maxSpeed;
}

void SyringeDriver::updateAcceleration()
{
  Display::clear();
  Display::setCursor(0, 0);
  Display::print("Seleccione");
  Display::setCursor(0, 1);
  Display::print("Accelerat:");
  Display::setCursor(10, 1);
  float acceleration = analogRead(POTENTIOMETER_PIN);
  Display::print(acceleration);
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
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