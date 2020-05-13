/**
 * @file SyringeDriver.h
 * @author Limako
 * @author Sergio Gasquez Arcos (sergio.gasquez@gmail.com)
 * @brief Class which will control the system
 * @version 0.1
 * @date 2020-05-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef SYRINGE_DRIVER_H
#define SYRINGE_DRIVER_H


#include "Stepper.h"
#include "Display.h"
#include "Configuration.h"

enum class State : uint8_t {
  INITIAL = 0,
  INSERT_SYRINGE = 1,
  UPDATE_LOAD = 2,
  UPDATE_FLOW = 3,
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
  void initialize(float t_maxSpeed = 50, float t_acceleration = 20);

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
   * @brief Increments the actual state
   * 
   */
  void setState(State t_state);

  /**
   * @brief Updates the diameter of the syringe being used
   * 
   */
  void updateDiameter();

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
  float getProgress();

  /**
   * @brief Displays the draining info (progress and speed)
   * 
   */
  void displayDrainningInfo();

  /**
   * @brief Calcultes the length in steps of the syringe
   * 
   */
  void updateParameters();

  /**
   * @brief Get the Length object
   * 
   * @return float Length
   */
   
   
  void encoder();
   
  float getLength();

  /**
   * @brief Get the StartingPosition object
   * 
   * @return float StartingPosition
   */
  float getStartingPosition();


  /**
   * @brief Get the Max Speed object
   * 
   * @return float m_maxSpeed
   */
  float getMaxSpeed();

  /**
   * @brief Get the Steps Per Ml object
   * 
   * @return float m_stepsPerMl
   */
  float getStepsPerMl();
  float getLastPosition();
  void SyringeDriver::displayAlarmStep();
  void SyringeDriver::Aprox();
  void SyringeDriver::FineAdj();
  void SyringeDriver::Drain();

private:
  uint8_t m_actualState = 0;      // Actual state of the state machine
  float m_startingPosition = 0;   // Starting position of the syringe in steps
  float m_load = 0;               // Load of the syringe in ml
  float m_flow = 0;               // Flow rate in ml/h
  float m_diameter = 0;           // Diameter of the syringe
  float m_length = 0;             // Length of the syringe in steps
  float m_progress = 0;           // Percetage of the syringe drained
  float m_stepsPerMl = 0;         // Steps per milimeter
  float m_maxSpeed = 0;           // Maximum speed in steps per second
  float m_lastPosition = 0;	      // Stepper position on last interrupt
  float m_lastProgress = 0;
};

#endif   // SYRINGE_DRIVER_H
