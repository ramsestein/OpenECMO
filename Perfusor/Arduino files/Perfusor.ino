/**
 * @file Perfusor.ino
 * @author Limako
 * @author Sergio Gasquez Arcos (sergio.gasquez@gmail.es)
 * @brief Main sketch in order to test the syringe driver
 * @version 0.1
 * @date 2020-05-03
 * @copyrightLicencia GPLv3
**/

#define LCD_COLS 16
#define LCD_ROWS 2
#define LCD_I2C_ADDRESS 0x27

#include "src/SyringeDriver.h"


SyringeDriver syringeDriver(LCD_I2C_ADDRESS, LCD_COLS, LCD_ROWS);

void setup()
{
  syringeDriver.initialize();
}


void loop()
{
  uint8_t state = syringeDriver.getActualState();
  if (state == static_cast<int>(State::HOMING))
  {
    syringeDriver.homing();
    syringeDriver.incrementActualState();
  }
  else if (state == static_cast<int>(State::INSERT_SYRINGE))
  {
    syringeDriver.updateSyringeDiameter();
    syringeDriver.updateMaxSpeed();
    syringeDriver.updateAcceleration();
    syringeDriver.incrementActualState();
  }
  else if (state == static_cast<int>(State::FINE_ADJUSTING) && digitalRead(ACCEPT_BUTTON_PIN))
  {
    syringeDriver.clear();
    syringeDriver.setCursor(0, 0);
    syringeDriver.print("Aproximando!");
    syringeDriver.setMaxSpeed(500);
    syringeDriver.setAcceleration(200);
    syringeDriver.moveTo(-4000);
    while (syringeDriver.currentPosition() != -4000 && !digitalRead(STEPPER_BACKWARD_BUTTON_PIN))   // El pin 7 aqui seria un final de carrera
    {
      syringeDriver.run();
    }
    syringeDriver.stop();
    syringeDriver.clear();
    syringeDriver.setCursor(0, 0);
    syringeDriver.print("Ajuste fino");
    syringeDriver.setMaxSpeed(100);
    syringeDriver.setAcceleration(100);
    if (digitalRead(STEPPER_FORWARD_BUTTON_PIN))
    {
      syringeDriver.move(100);
      syringeDriver.run();
    }
    else if (digitalRead(STEPPER_BACKWARD_BUTTON_PIN))
    {
      syringeDriver.move(-100);
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
      syringeDriver.incrementActualState();
    }
  }
  else if (state == static_cast<int>(State::DRAIN_SYRINGE) && digitalRead(ACCEPT_BUTTON_PIN))
  {
    syringeDriver.setMaxSpeed(syringeDriver.getMaxSpeed());
    syringeDriver.setAcceleration(syringeDriver.getAcceleration());
    syringeDriver.moveTo(-50000);
    while (syringeDriver.currentPosition() != -50000 && !digitalRead(STEPPER_BACKWARD_BUTTON_PIN))   // Aqui seria un final de carrera
    {
      syringeDriver.run();
      syringeDriver.displayDrainningInfo();
    }
    syringeDriver.stop();
  }
  else
  {
  }
}
