/*

    Author: Francisco Ochando
    Module: Pump.cpp
    Description: Class Pump. Manages pump rotation and liquid volume

 */

#include "Pump.h"


void Pump::Setup() {
  
  pinMode (PIN_STEPPER_STEP, OUTPUT);
  pinMode (PIN_STEPPER_DIR, OUTPUT);
  
}


// TODO

bool Pump::dirCW() {
  return cw;
}

void Pump::setMotor() {

  digitalWrite(PIN_STEPPER_DIR, cw);
  if (PIN_STEPPER_STEP == LOW) {
    digitalWrite(PIN_STEPPER_STEP, HIGH);  
  } else {
    digitalWrite(PIN_STEPPER_STEP, LOW);
  }
  
}

void Pump::doStep() {
  digitalWrite(PIN_STEPPER_STEP, HIGH);
  delay(0.1); 
  digitalWrite(PIN_STEPPER_STEP, LOW);  
}

void Pump::Enable() {
  enabled_ = true;  
}

void Pump::Disable() {
  enabled_ = false;
}

bool Pump::isEnabled() {
  return enabled_;
}

int CalcMs (int rpms) {
  int calcms = 0;
  calcms = rpms * 200 / 60;
  return calcms;
}

float Pump::getVol ( int rpm ) {
  return rpm * Radio * Diametro * pi * pi / 2;
}

void Pump::setDir ( bool ccw ) {
  if ( ccw ) {
    cw = true; 
    digitalWrite(PIN_STEPPER_DIR, HIGH);
    Serial.println ("Rotacion dcha CW");    
  } else {
    cw = false;
    digitalWrite(PIN_STEPPER_DIR, LOW);
    Serial.println ("Rotacion izda CCW");    
  }
}

void Pump::setRPM( int rpm ) {
  RPM = rpm;
}

void Pump::setACEL( int acel ) {
  ACEL = acel;
}

float Pump::getRPS( int rpm ) {
  return rpm/60;
}