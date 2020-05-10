# Perfusor
## Overview
The goal is to develop firmware based on arduino for an infusion pump, used to gradually administer small amounts of fluid to a patient, in this case, heparin.
## Hardware Requirements
1. Microcontroller: Arduino (any version) or similar (1)
1. Motor diver supported by [AccelStepper](https://www.airspayce.com/mikem/arduino/AccelStepper/index.html)
1. Buttons (3)
1. End stop (1)
1. LCD Display (Code is made with 16x2)
1. Potentiometer
1. Syringe support

## How to use it
1. Clone the repository
1. Set up the code:
  1. Configure your display
    1. Number of rows
    1. Number of cols
    1. I2C Address of the device
  1. Configure the syringe driver: 
    1. Slider length in mm
    1. Number of steps per turn
    1. How much it moves per turn
  1. Choose your stepper dirver NEMA17 or BJY. Note if you want to use any other you have to take into account the interface that it requires and the pins needed.
  *Note: Check if you are using inverted pins for the driver. This can be changed in the constructor of SyringeDriver (SyringeDriver::SyringeDriver())*
  1. Change the pinout if needed.
1. Compile and upload the code!


## Libraries 
* [AccelStepper](https://www.airspayce.com/mikem/arduino/AccelStepper/index.html)
* []()
