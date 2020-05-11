/**
 * @file Display.cpp
 * @author Limako
 * @author Sergio Gasquez Arcos (sergio.gasquez@gmail.com)
 * @brief Display where information will be displayed
 * @version 0.1
 * @date 2020-05-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Display.h"
#include "Arduino.h"

Display::Display(uint8_t t_lcdAddr, uint8_t t_lcdCols, uint8_t t_lcdRows) : LiquidCrystal_I2C(t_lcdAddr, t_lcdCols, t_lcdRows)
{
}


void Display::initialize()
{
  LiquidCrystal_I2C::init();
  LiquidCrystal_I2C::backlight();
  LiquidCrystal_I2C::setCursor(3, 0);   // Centers the message
  LiquidCrystal_I2C::print("CV19Makers!");
  LiquidCrystal_I2C::setCursor(1, 1);   // Centers the message
  LiquidCrystal_I2C::print("Perfusor Team!");
  delay(1000);
  for (int positionCounter = 0; positionCounter < 13; positionCounter++)   // Slides the message
  {
    LiquidCrystal_I2C::scrollDisplayLeft();
    delay(150);
  }
}