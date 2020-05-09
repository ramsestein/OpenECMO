/**
 * @file Stepper.cpp
 * @author Limako
 * @author Sergio Gasquez Arcos (sergio.gasquez@gmail.com)
 * @brief Stepper motor which will control the syringe
 * @version 0.1
 * @date 2020-05-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Stepper.h"

Stepper::Stepper(uint8_t t_interface, uint8_t t_pin1, uint8_t t_pin2, uint8_t t_pin3, uint8_t t_pin4) : AccelStepper(t_interface, t_pin1, t_pin2, t_pin3, t_pin4)
{
}

void Stepper::initialize(float t_maxSpeed, float t_acceleration)
{
  AccelStepper::setMaxSpeed(t_maxSpeed);
  AccelStepper::setAcceleration(t_acceleration);
}