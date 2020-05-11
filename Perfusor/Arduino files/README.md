# Perfusor
## Overview
The goal is to develop **firmware based on arduino for an syringe driver (infusion pump)**, used to gradually administer small amounts of fluid to a patient, in this case, heparin.
## Hardware Requirements
* Microcontroller: Arduino (any version) or similar 
*  Motor diver supported by [AccelStepper](https://www.airspayce.com/mikem/arduino/AccelStepper/index.html)
* 3 Buttons 
* End stop 
* LCD Display 
* Potentiometer
* Syringe support

## How to use it
1. Clone the repository
1. Set up the code in the src/Configuration.h file:
   1. Configure your display
      1. Number of rows
      1. Number of cols
      1. I2C Address of the device
   1. Configure the syringe driver: 
      1. Slider length in mm
      1. Number of steps per turn   
      1. How much it moves per turn
   1. Choose your stepper dirver NEMA17 or BJY. If you want to use any other you have to take into account the interface that it requires and the pins needed.
  *Note: If you are using inverted pins for the driver changes need to be made in the constructor of SyringeDriver (SyringeDriver::SyringeDriver())*
   1. Change the pinout if needed.
1. **Compile and upload the code!**


 
## Libraries 
* [AccelStepper](https://www.airspayce.com/mikem/arduino/AccelStepper/index.html)
* [NewLiquidCrystal](https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home#!tests)
