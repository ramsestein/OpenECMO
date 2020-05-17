/*

    Author: Francisco Ochando
    Module: Pump.cpp
    Description: Class stepper. Manages pump rotation and liquid volume

 */

#include "Pump.h"


void Pump::Setup() {
  
  pinMode (PIN_STEPPER_STEP, OUTPUT);
  pinMode (PIN_STEPPER_DIR, OUTPUT);
  
}


// TODO

bool Pump::Forward() {
  forward = !forward;
  return forward;
}

void Pump::setMotor() {

  digitalWrite(PIN_STEPPER_DIR, forward);
  if (PIN_STEPPER_STEP == LOW) {
    digitalWrite(PIN_STEPPER_STEP, HIGH);  
  }
  else
  {
    digitalWrite(PIN_STEPPER_STEP, LOW);
  }
  
}

void Pump::doStep() {
  digitalWrite(PIN_STEPPER_STEP, HIGH);
  delay(0.1); 
  digitalWrite(PIN_STEPPER_STEP, LOW);  
}

bool Pump::enabled() {
  enable = !enable;
  return !enable;
}

int CalcMs (int rpms) {
  int calcms = 0;
  calcms = rpms * 200 / 60;
  return calcms;
}

float Pump::getVolume( int rpm ) {

  caudal = rpm * Radio * Diametro * pi * pi /2;
  return caudal;
  
}

void setDir ( bool forward ) {
  if (forward) {
    digitalWrite(PIN_STEPPER_DIR, HIGH);   
  } else {
    digitalWrite(PIN_STEPPER_DIR, LOW);   
  }
}
