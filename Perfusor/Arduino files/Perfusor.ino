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
  else if (state == static_cast<uint8_t>(State::ADJUSTING) && digitalRead(ACCEPT_BUTTON_PIN))
  {
    syringeDriver.setMaxSpeed(3 * syringeDriver.getStepsPerMl());   // Speed: 3 mm/s
    syringeDriver.setAcceleration(3 * syringeDriver.getStepsPerMl());
    float startingPosition = syringeDriver.getStartingPosition();
    syringeDriver.moveTo(startingPosition);
    while (syringeDriver.currentPosition() != startingPosition && !digitalRead(STEPPER_BACKWARD_BUTTON_PIN))
    {
      syringeDriver.run();
    }
    syringeDriver.stop();
    syringeDriver.setState(State::FINE_ADJUSTING);
  }
  else if (state == static_cast<uint8_t>(State::FINE_ADJUSTING))
  {
    syringeDriver.setMaxSpeed(1.5 * syringeDriver.getStepsPerMl());   // Speed: 3 mm/s
    syringeDriver.setAcceleration(1.5 * syringeDriver.getStepsPerMl());
    if (digitalRead(STEPPER_FORWARD_BUTTON_PIN))
    {
      syringeDriver.move(10);
      syringeDriver.run();
    }
    else if (digitalRead(STEPPER_BACKWARD_BUTTON_PIN))
    {
      syringeDriver.move(-10);
      syringeDriver.run();
    }
    else
    {
      syringeDriver.stop();
    }
    if (digitalRead(ACCEPT_BUTTON_PIN))
    {
      while (digitalRead(ACCEPT_BUTTON_PIN))
      {
        delay(1);
      }
      syringeDriver.setState(State::DRAIN_SYRINGE);
    }
  }
  else if (state == static_cast<int>(State::DRAIN_SYRINGE) && digitalRead(ACCEPT_BUTTON_PIN))
  {
    /// @todo: When some button is pressed return to flow selection rate
    /// @todo: When some button is pressed go into a manual mode where pressing buttons you can drain the syringe at higher speed
    /// @todo: Check progress constantly to be able to alarm when a threshold is reached
    syringeDriver.setCurrentPosition(syringeDriver.getLength());
    syringeDriver.setMaxSpeed(syringeDriver.getMaxSpeed());   // Speed obtained with the flow rate
    syringeDriver.setAcceleration(syringeDriver.getMaxSpeed());
    syringeDriver.moveTo(0);
    while (syringeDriver.currentPosition() != 0 && !digitalRead(STEPPER_BACKWARD_BUTTON_PIN))   // Aqui seria un final de carrera
    {
      syringeDriver.run();
      syringeDriver.displayDrainingInfo();
    }
    syringeDriver.stop();
  }
  else
  {
  }
}
