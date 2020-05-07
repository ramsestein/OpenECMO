/**
 * @file SyringeDriver.h
 * @author Limako
 * @author Sergio Gasquez Arcos (sergio.gasquez@gmail.es)
 * @brief Class which will control the system
 * @version 0.1
 * @date 2020-05-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef SYRINGE_DRIVER_H
#define SYRINGE_DRIVER_H

#define SLIDER_LENGTH 72000

#include "Stepper.h"
#include "Display.h"
#include "Pinout.h"

/// @todo: Refactor states, add some if needed
enum class State : uint8_t {
  INITIAL = 0,
  INSERT_SYRINGE = 1,
  ADJUST_LOAD = 2,
  ADJUST_FLOW = 3,
  ADJUSTING = 4,
  FINE_ADJUSTING = 5,
  DRAIN_SYRINGE = 6
};


class SyringeDriver : public Stepper
  , public Display
{
public:
  /**
  * @brief Construct a new Syringe Driver object 
  * 
  * @param t_LcdAddr I2C Address of the Display
  * @param t_LcdCols Number of colummns
  * @param t_LcdRows Number of rows
  * @param t_interface Interface Number of pins to interface to
  * @param t_pin1 Arduino digital pin number for motor pin 1
  * @param t_pin2 Arduino digital pin number for motor pin 2
  * @param t_pin3 Arduino digital pin number for motor pin 3
  * @param t_pin4 Arduino digital pin number for motor pin 4
  */
  SyringeDriver(uint8_t t_lcdAddr, uint8_t t_lcdCols, uint8_t t_lcdRows, uint8_t t_interface = AccelStepper::FULL4WIRE, uint8_t t_pin1 = 2, uint8_t t_pin2 = 3, uint8_t t_pin3 = 4, uint8_t t_pin4 = 5);

  /**
  * @brief Invoces Display and Stepper initialize methods
  * 
  * @param t_maxSpeed Maximum speed 
  * @param t_acceleration Maximum acceleration
  */
  void initialize();

  /**
   * @brief Proceeds to the device homing
   * 
   */
  void homing();

  /**
   * @brief Get the Actual State object
   * 
   * @return uint8_t Actual state
   */
  uint8_t getActualState();

  /**
   * @brief Increments the actual state
   * 
   */
  void incrementActualState();

  /**
   * @brief Updates the diameter of the syringe being used
   * 
   */
  void updateSyringeDiameter();

  /**
   * @brief Updates the maximum speed of the syringe
   * 
   */
  void updateLoad();

  /**
   * @brief Updates the maximum speed of the syringe
   * 
   */
  void updateFlow();

  /**
   * @brief Get the Max Speed object
   * 
   * @return float Max Speed
   */
  float getLoad();

  /**
   * @brief Get the Acceleration object
   * 
   * @return float Acceleration
   */
  float getFlow();

  /**
   * @brief Computes the progress of the syringe drainning
   * 
   * @return uint8_t Percentage to be fully drained
   */
  uint8_t getProgress();

  /**
   * @brief Displays the draining info (progress and speed)
   * 
   */
  void displayDrainningInfo();

  /**
   * @brief Calcultes the length in steps of the syringe
   * 
   */
  void calculateLength();

  /**
   * @brief Get the Length object
   * 
   * @return float Length
   */
  float getLength();

  /**
   * @brief Get the targetPosition object
   * 
   * @return float targetPosition
   */
  float getTargetPosition();

private:
  float m_load = 0;             // Load of the syringe in ml
  float m_flow = 0;             // Flow rate in ml/h
  uint8_t m_actualState = 0;    // Actual state of the state machine
  float m_diameter = 0;         // Diameter of the syringe
  float m_length = 0;           // Length in steps
  float m_targetPosition = 0;   //
  float m_progress = 0;         // Percetage of the syringe drained
};

#endif   // SYRINGE_DRIVER_H
