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
#include "Arduino.h"


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
  while (!digitalRead(END_STOP_PIN))
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
  else if (m_actualState == static_cast<int>(State::ADJUST_LOAD))
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Seleccione Flow");
    Display::setCursor(0, 1);
    Display::print("en mLxH:");
  }
  else if (m_actualState == static_cast<int>(State::ADJUST_FLOW))
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
  else if (m_actualState == static_cast<int>(State::FINE_ADJUSTING))
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Carga:");
    Display::setCursor(0, 1);
    Display::print("Flujo:");
  }
  m_actualState++;
}
void SyringeDriver::updateSyringeDiameter()
{
  Display::setCursor(10, 1);
  float diameter = map(analogRead(POTENTIOMETER_PIN), 0, 1024, 0, 40);
  Display::print(diameter);
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
    incrementActualState();
  }
  m_diameter = diameter;
}

void SyringeDriver::updateLoad()
{
  Display::setCursor(10, 1);
  float load = map(analogRead(POTENTIOMETER_PIN), 0, 1024, 0, 60);
  Display::print(load);
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
    incrementActualState();
  }
  m_load = load;
}

void SyringeDriver::updateFlow()
{
  Display::setCursor(10, 1);
  float flow = map(analogRead(POTENTIOMETER_PIN), 0, 1024, 2, 15);
  Display::print(flow);
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
    incrementActualState();
  }
  m_flow = flow;
}

float SyringeDriver::getLoad()
{
  return m_load;
}


float SyringeDriver::getFlow()
{
  return m_flow;
}

uint8_t SyringeDriver::getProgress()
{
  int32_t currentPosition = Stepper::currentPosition();
  m_progress = map(currentPosition, 0, m_length, 0, 100);
  return m_progress;
}


void SyringeDriver::displayDrainningInfo()
{
  // Progress
  Display::setCursor(10, 0);
  Display::print((getProgress() * getLoad() / 100));
  Display::setCursor(14, 0);
  Display::print("ml");
  // Speed
  Display::setCursor(10, 1);
  Display::print(getFlow());
  Display::setCursor(12, 1);
  Display::print("ml/H");
}


void SyringeDriver::calculateLength()
{
  m_length = (m_load * 4000000) / (PI * m_diameter * m_diameter);

  m_targetPosition = m_length - SLIDER_LENGTH;
}

float SyringeDriver::getLength()
{
  return m_length;
}

float SyringeDriver::getTargetPosition()
{
  return m_targetPosition;
}