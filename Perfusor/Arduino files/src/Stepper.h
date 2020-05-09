/**
 * @file Stepper.h
 * @author Limako
 * @author Sergio Gasquez Arcos (sergio.gasquez@gmail.com)
 * @brief Stepper motor which will control the syringe
 * @version 0.1
 * @date 2020-05-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef STEPPER_H
#define STEPPER_H


#include <AccelStepper.h>

class Stepper : public AccelStepper
{
public:
  /**
 * @brief Construct a new Stepper object
 * 
 * @param t_interface Interface Number of pins to interface to
 * @param t_pin1 Arduino digital pin number for motor pin 1
 * @param t_pin2 Arduino digital pin number for motor pin 2
 * @param t_pin3 Arduino digital pin number for motor pin 3
 * @param t_pin4 Arduino digital pin number for motor pin 4
 */
  Stepper(uint8_t t_interface = AccelStepper::FULL4WIRE, uint8_t t_pin1 = 2, uint8_t t_pin2 = 3, uint8_t t_pin3 = 4, uint8_t t_pin4 = 5);

  /**
   * @brief Sets up the initial values for maximum speed and acceleration
   * 
   * @param t_maxSpeed Maximum speed 
   * @param t_acceleration Maximum acceleration
   */
  void initialize(float t_maxSpeed = 50, float t_acceleration = 20);

private:
};

#endif   // STEPPER_H