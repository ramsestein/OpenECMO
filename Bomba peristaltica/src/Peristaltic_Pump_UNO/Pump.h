/*

    Author: Francisco Ochando
    Module: Pump.h
    Description: Stepper header. Manages pump rotation

 */

#include  <Arduino.h>

// Stepper driver (FlexyStepper)
#define PIN_STEPPER_STEP  6
#define PIN_STEPPER_DIR   7
#define PIN_STEPPER_EN    8
#define PIN_SW_REVERSE   12


class Pump
{

  public:

    void Setup( void );
    bool Forward ();
    void setMotor ();
    bool enabled ();
    float getVolume ( int rpm );
    void setRPM ( int rpm );
    void doStep ();
    void setDir ( bool forward );
    
  private:

    bool forward = true;
    bool enable = false;
    float caudal;
    float Radio = 6;
    float Diametro = 0.6;
    const float pi = 3.1415;

    int CalcMs (int rpms);
  
};
