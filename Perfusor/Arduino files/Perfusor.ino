/**
 * @file Perfusor.ino
 * @author Limako
 * @author Sergio Gasquez Arcos (sergio.gasquez@gmail.com)
 * @brief Main sketch in order to test the syringe driver
 * @version 0.1
 * @date 2020-05-03
 * 
 * @copyright GPLv3
 * 
 */

#include "src/SyringeDriver.h"

#ifdef BYJ
SyringeDriver syringeDriver(LCD_I2C_ADDRESS, LCD_COLS, LCD_ROWS, AccelStepper::FULL4WIRE, STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
#endif   // BYJ

#ifdef NEMA17
SyringeDriver syringeDriver(LCD_I2C_ADDRESS, LCD_COLS, LCD_ROWS, AccelStepper::DRIVER, STEPPER_STEP_PIN, STEPPER_DIR_PIN);
#endif   // NEMA17


void setup()
{
  attachInterrupt(digitalPinToInterrupt(3), encoder, CHANGE);
  syringeDriver.initialize();
  syringeDriver.homing();
}

void loop()
{
  uint8_t state = syringeDriver.getActualState();
  if (state == static_cast<uint8_t>(State::INSERT_SYRINGE))
  {
    syringeDriver.updateDiameter();
  }
  else if (state == static_cast<uint8_t>(State::UPDATE_LOAD))
  {
    syringeDriver.updateLoad();
  }
  else if (state == static_cast<uint8_t>(State::UPDATE_FLOW))
  {
    syringeDriver.updateFlow();
    syringeDriver.updateParameters();
  }
  else if (state == static_cast<uint8_t>(State::ADJUSTING))
  {
    syringeDriver.Aprox();
  }
  else if (state == static_cast<uint8_t>(State::FINE_ADJUSTING))
  {
    
    syringeDriver.FineAdj();
  }
  else if (state == static_cast<int>(State::DRAIN_SYRINGE) && digitalRead(ACCEPT_BUTTON_PIN))
  {
    syringeDriver.Drain();
  }
  else
  {
  }
}

void encoder()
{
  syringeDriver.encoder();
}
