/*

    Author: Francisco Ochando
    Module: Pump.h
    Description: Pump header. Manages pump rotation

 */

#include  <Arduino.h>

// Stepper driver (FlexyStepper)
#define PIN_STEPPER_STEP  7
#define PIN_STEPPER_DIR   8
#define PIN_STEPPER_EN    9
#define PIN_SW_REVERSE   12


class Pump
{

  public:

    bool dirCW ();
    bool isEnabled( void );
    float getVol ( int rpm );
    float getRPS( int rpm );
    void Setup( void );
    void setMotor ();
    void setRPM ( int rpm );
    void setACEL( int acel );
    void doStep ();
    void setDir ( bool forward );
    void Enable( void );
    void Disable( void );
    
  private:

    int RPM = 0;
    int ACEL = 0;
    bool cw = true;
    bool enabled_ = false;
    float caudal;
    const byte Radio = 6;
    const float Diametro = 0.6;
    const float pi = 3.1415;

    int CalcMs (int rpms);
  
};