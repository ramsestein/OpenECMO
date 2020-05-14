/**
 * @file Configuration.h
 * @author Limako
 * @author Sergio Gasquez Arcos (sergio.gasquez@gmail.com)
 * @brief Connections and definitions for the system 
 * @version 0.1
 * @date 2020-05-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// Display Configuration
#define LCD_COLS 16
#define LCD_ROWS 2
#define LCD_I2C_ADDRESS 0x27

// Syringe Configuration
#define SLIDER_LENGTH 82      // Slider length in mm
#define STEPS_PER_TURN 3200   // Number of steps per turn
#define MOVE_PER_TURN 2       // Advance per turn in mm

// Choose Driver
#define NEMA17
// #define BYJ


#ifdef BJY
#define STEPPER_PIN_1 2
#define STEPPER_PIN_2 3
#define STEPPER_PIN_3 4
#define STEPPER_PIN_4 5
#define STEPPER_FORWARD_BUTTON_PIN 6
#define STEPPER_BACKWARD_BUTTON_PIN 7
#define ACCEPT_BUTTON_PIN 8
#define END_STOP_PIN 9
#define POTENTIOMETER_PIN A0
#endif   // BJY

#ifdef NEMA17
#define ENCODER_PIN 3
#define STEPPER_STEP_PIN 5
#define STEPPER_DIR_PIN 2
#define ENABLE_PIN 8
#define STEPPER_FORWARD_BUTTON_PIN 9
#define STEPPER_BACKWARD_BUTTON_PIN 10
#define ACCEPT_BUTTON_PIN 11
#define END_STOP_PIN 12
#define POTENTIOMETER_PIN A0
#endif   // NEMA17

#endif   // CONFIGURATION_H