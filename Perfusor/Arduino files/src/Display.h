/**
 * @file Display.h
 * @author Limako
 * @author Sergio Gasquez Arcos (sergio.gasquez@gmail.com)
 * @brief Display where information will be displayed
 * @version 0.1
 * @date 2020-05-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef DISPLAY_H
#define DISPLAY_H


#include <LiquidCrystal_I2C.h>

class Display : public LiquidCrystal_I2C
{
public:
  /**
   * @brief Construct a new Display object
   * 
   * @param t_LcdAddr I2C Address of the Display
   * @param t_LcdCols Number of colummns
   * @param t_LcdRows Number of rows
   */
  Display(uint8_t t_lcdAddr, uint8_t t_lcdCols, uint8_t t_lcdRows);

  /**
   * @brief Sets up and displays an initial message
   * 
   */
  void initialize();

private:
};
#endif   // DISPLAY_H