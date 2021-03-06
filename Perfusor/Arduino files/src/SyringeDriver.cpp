/**
 * @file SyringeDriver.cpp
 * @author Limako
 * @author Sergio Gasquez Arcos (sergio.gasquez@gmail.com)
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
  m_stepsPerMl = STEPS_PER_TURN / MOVE_PER_TURN;

#ifdef NEMA17
  Stepper::setPinsInverted(false, false, true);
  Stepper::setEnablePin(ENABLE_PIN);
#endif   // NEMA17
}

void SyringeDriver::initialize(float t_maxSpeed, float t_acceleration)
{
  Stepper::initialize();
  Display::initialize();
}

void SyringeDriver::homing()
{
  Stepper::setMaxSpeed(3 * m_stepsPerMl);   // Speed: 3 mm/s
  Stepper::setAcceleration(3 * m_stepsPerMl);
  Display::clear();
  Display::setCursor(0, 0);
  Display::print("Homing!");
  Stepper::move(500000);
  while (!digitalRead(END_STOP_PIN))
  {
    Stepper::run();
  }
  Stepper::stop();
  Stepper::setCurrentPosition(SLIDER_LENGTH * m_stepsPerMl);
  setState(State::INSERT_SYRINGE);
}

uint8_t SyringeDriver::getActualState()
{
  return m_actualState;
}

void SyringeDriver::setState(State t_state)
{
  if (t_state == State::INSERT_SYRINGE)
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Escoja Diametro");
    Display::setCursor(0, 1);
    Display::print("En mm:");
  }
  else if (t_state == State::UPDATE_LOAD)
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Escoja Carga");
    Display::setCursor(0, 1);
    Display::print("En ml: ");
  }
  else if (t_state == State::UPDATE_FLOW)
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Escoja Flujo");
    Display::setCursor(0, 1);
    Display::print("En ml/h:");
  }
  else if (t_state == State::ADJUSTING)
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Aproximando!");
  }
  else if (t_state == State::FINE_ADJUSTING)
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Ajuste fino");
  }
  else if (t_state == State::DRAIN_SYRINGE)
  {
    Display::clear();
    Display::setCursor(0, 0);
    Display::print("Carga:");
    Display::setCursor(0, 1);
    Display::print("Flujo:");
    Display::setCursor(14, 0);
    Display::print("ml");
    Display::setCursor(8, 1);
    Display::print(getFlow());
    Display::setCursor(12, 1);
    Display::print("ml/h");
  }
  else
  {
  }
  m_actualState = static_cast<uint8_t>(t_state);
}

void SyringeDriver::updateDiameter()
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
    setState(State::UPDATE_LOAD);
  }
  m_diameter = diameter;
}

void SyringeDriver::updateLoad()
{
  Display::setCursor(10, 1);
  float load = map(analogRead(POTENTIOMETER_PIN), 0, 1024, 0, 600) / 10.0;
  Display::print(load);
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
    setState(State::UPDATE_FLOW);
  }
  m_load = load;
}

void SyringeDriver::updateFlow()
{
  Display::setCursor(10, 1);
  float flow = map(analogRead(POTENTIOMETER_PIN), 0, 1024, 20, 150) / 10.0;
  Display::print(flow);
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
    setState(State::ADJUSTING);
  }
  m_flow = flow;
}

void SyringeDriver::adjust()
{
  Stepper::moveTo(m_length);
  Stepper::setSpeed(3 * m_stepsPerMl);   // Speed: 3 mm/s
  while ((Stepper::currentPosition() >= m_length + 20 || Stepper::currentPosition() < m_length - 20) && !digitalRead(ACCEPT_BUTTON_PIN))
  {
    Stepper::runSpeedToPosition();
  }
  Stepper::stop();
  while (digitalRead(ACCEPT_BUTTON_PIN))
  {
    delay(1);
  }
  setState(State::FINE_ADJUSTING);
}

void SyringeDriver::fineAdjusting()
{
  if (digitalRead(STEPPER_FORWARD_BUTTON_PIN))
  {
    Stepper::move(10);
    Stepper::setSpeed(3 * m_stepsPerMl);
    Stepper::runSpeedToPosition();
  }
  else if (digitalRead(STEPPER_BACKWARD_BUTTON_PIN))
  {
    Stepper::move(-10);
    Stepper::setSpeed(3 * m_stepsPerMl);
    Stepper::runSpeedToPosition();
  }
  else
  {
    Stepper::stop();
  }
  if (digitalRead(ACCEPT_BUTTON_PIN))
  {
    while (digitalRead(ACCEPT_BUTTON_PIN))
    {
      delay(1);
    }
    Stepper::setCurrentPosition(m_length);
    m_lastPosition = m_length;
    setState(State::DRAIN_SYRINGE);
  }
}

void SyringeDriver::drain()
{
  while (digitalRead(ACCEPT_BUTTON_PIN))
  {
    delay(1);
  }
  getProgress();
  displayDrainingInfo();
  while (Stepper::currentPosition() != 0 && !digitalRead(ACCEPT_BUTTON_PIN))
  {
    if (digitalRead(STEPPER_BACKWARD_BUTTON_PIN))
    {
      Stepper::move(-10);
      Stepper::setSpeed(3 * m_stepsPerMl);
    }
    else
    {
      Stepper::moveTo(0);
      Stepper::setSpeed(m_maxSpeed);
    }
    Stepper::runSpeedToPosition();
    if (m_lastPosition - Stepper::currentPosition() > 180)
    {
      displayAlarmStep();
    }
    if (getProgress() < m_lastProgress)
    {
      displayDrainingInfo();
    }
    m_lastProgress = m_progress;
  }
  Stepper::stop();
  while (digitalRead(ACCEPT_BUTTON_PIN))
  {
    delay(1);
  }
  setState(State::INSERT_SYRINGE);
}

float SyringeDriver::getLoad()
{
  return m_load;
}

float SyringeDriver::getFlow()
{
  return m_flow;
}

float SyringeDriver::getProgress()
{
  m_progress = map(Stepper::currentPosition(), 0, m_length, 0, 1000) / 10.0;
  return m_progress;
}

void SyringeDriver::displayDrainingInfo()
{
  // Remaining load
  Display::setCursor(9, 0);
  Display::print(m_progress * m_load / 100);
}

void SyringeDriver::displayAlarmStep()
{
  Display::setCursor(0, 0);
  Display::print("Alarm Lose Steps");
}


void SyringeDriver::updateParameters()
{
  m_length = (m_load * 4000 * m_stepsPerMl) / (PI * m_diameter * m_diameter);
  m_startingPosition = m_length;
  m_maxSpeed = (m_length * (m_flow / m_load)) / 3600;
}

void SyringeDriver::encoder()
{
  m_lastPosition = Stepper::currentPosition();
  //displayDrainingInfo();
}

float SyringeDriver::getLength()
{
  return m_length;
}

float SyringeDriver::getStartingPosition()
{
  return m_startingPosition;
}

float SyringeDriver::getMaxSpeed()
{
  return m_maxSpeed;
}

float SyringeDriver::getStepsPerMl()
{
  return m_stepsPerMl;
}

float SyringeDriver::getLastPosition()
{
  return m_lastPosition;
}