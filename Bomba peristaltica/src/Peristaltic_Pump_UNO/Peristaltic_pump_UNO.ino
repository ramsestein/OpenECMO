/*
 
  Author: Francisco Ochando

  Description: Peristalthic Pump, LCD and buttons. Current sensor.
  
  This Code is free software: you can redistribute it and/or modify 
  it under the terms of the GNU General Public License as published 
  by the Free Software Foundation, either version 3 of the License, 
  or (at your option) any later version.
  
  This is distributed in the hope that it will be useful, but WITHOUT 
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public 
  License for more details.
  
  See <http://www.gnu.org/licenses/>.

*/

/*
Peristaltic Pump:
Commands:
move <speed> Set continuous pump rotation speed (rpm)
*/

#include <AccelStepper.h>
#include <FlexyStepper.h>
#include "Peristaltic_pump.h"
#include "Sensor.h"
#include "Pump.h"
#include <TimerOne.h>

Peristaltic BOMBA;
//AccelStepper Motor(1, PIN_STEP, PIN_DIR);
FlexyStepper stepper;
Pump MOTOR;
Sensor sensor;

byte ledstate = LOW; // Blinking indicator LED

String buffer;
byte readout;

long last_time = 0;
long steps = 0;
uint16_t stepper_timer = 0;
uint16_t step_time = 0;
uint16_t update_timer = 0;
uint16_t speed_motor = 0;
uint16_t Rpm = 0;
uint16_t Rpm_old = 0;
uint16_t stepcount = 0;
uint16_t counter = 0;
unsigned long time;
bool ena = false;             // Bomba activada
bool fwd = true;              // Direccion (true = dcha)
bool alarm = false;



void InitStepper() 
{ 

  stepper.connectToPins(PIN_STEP, PIN_DIR);
  stepper.setStepsPerRevolution( 400 );
  stepper.setTargetPositionInSteps( 8000 );
  stepper.setSpeedInRevolutionsPerSecond( Rpm/60 );
  stepper.setAccelerationInRevolutionsPerSecondPerSecond( Rpm/60 );
  stepper.setTargetPositionInRevolutions( Rpm*60 ); // Target en RPM = 1 hora de giro

}


void setup() {

  // Open serial connection and print a message
  Serial.begin(BPS96);
  Serial.println(F("ECMO Peristaltic Pump"));

  // Config pins
  pinMode(PIN_STEP, OUTPUT);
  pinMode(PIN_ENABLE,OUTPUT);
  pinMode(PIN_DIR,OUTPUT);
  pinMode(SW_ENC,INPUT_PULLUP); 
  pinMode(SW_REV,INPUT);
  pinMode(PIN_LED,OUTPUT); 
  
  // Activa LED carga software
  digitalWrite(PIN_LED, HIGH); 
  
  // Initialize LCD
  BOMBA.LCD.Setup();
  // Time after wellcome banner
  delay(800);
  BOMBA.LCD.Init();
  BOMBA.LCD.setDir( fwd );
  
  // Initialize PUMP
  MOTOR.setDir( fwd ); 

  Serial.println("Desactivada");

  BOMBA.LCD.setRPM(analogRead(A0), Rpm_old);
  Rpm = BOMBA.LCD.getRPM();
  BOMBA.LCD.PrintRPM( Rpm );
  Serial.println(Rpm);
  Rpm_old = Rpm;

  digitalWrite(PIN_LED, LOW); 
  // Desactiva LED carga inicial software
  
  // Initial Setup Motor
  InitStepper();

}

void Potenciometro() {
  BOMBA.LCD.setRPM(analogRead(A0), Rpm_old);
  Rpm = BOMBA.LCD.getRPM();
  if (Rpm != Rpm_old) {
    // Serial.println(Rpm); // Debug
    BOMBA.LCD.PrintRPM(Rpm);
    BOMBA.LCD.PrintVol(MOTOR.getVol( Rpm ));  
  }
  Rpm_old = Rpm;
}


// ---------------------- MAIN --------------------------

void loop() {
  
  static uint16_t state=0, counter=60;

  // Comprueba los pulsadores de Dirección y Enable
  BOMBA.LCD.ReadButton();
  if(BOMBA.LCD.ButPressed()) {
    time = millis();
    if((time - last_time) > 300) {
    if(BOMBA.LCD.getButton() == SW_REV_PULSADO) { 
      if (MOTOR.dirCW()) {
        BOMBA.LCD.setDir( false );
        MOTOR.setDir( false ); 
      } else {
        BOMBA.LCD.setDir( true );
        MOTOR.setDir( true );     
      }           
    } else if(BOMBA.LCD.getButton() == SW_ENC_PULSADO) {
      MOTOR.Enable();
    }
    }
    BOMBA.LCD.Reset();
    last_time = time;
  }

  
  // Debug. Test de funcionamiento
  if (MOTOR.isEnabled()) {
    Serial.println("Bomba Activada"); // Debug
    digitalWrite(PIN_LED, HIGH); // Activa LED Actividad
    BOMBA.LCD.setON( true );
    while(!stepper.motionComplete() && MOTOR.isEnabled()) {
      //noInterrupts();
      stepper.processMovement(); // Not blocking process
      Serial.println(stepcount); // Debug sent steps
      stepcount++; 
      //interrupts();
      // Watchdog alarm
      if(alarm) {
        BOMBA.LCD.setAlarm();
        digitalWrite(PIN_ALR, HIGH); // Activa LED de alarma
      }
      // End Watchdog alarm
      BOMBA.LCD.ReadButton();
      if(BOMBA.LCD.ButPressed() && BOMBA.LCD.getButton() == SW_ENC_PULSADO) {
        time = millis();
        if((time - last_time) > 300) {
          MOTOR.Disable();
          Serial.println("Bomba desactivada"); // Debug
        } 
        last_time = time;   
      }
      /*
      if (stepper.getCurrentPositionInSteps() == 1000) {
        Serial.println("Ha llegado a 1000 pasos ");    
      }
      if (stepper.getCurrentPositionInSteps() == 8000) {
        Serial.println("Final ");    
      }
      */
      if (stepper.getCurrentPositionInRevolutions() == Rpm ) {
        Serial.println("Pasos enviados para 1 minuto de giro ");  
      }
    }
    MOTOR.Disable();
    digitalWrite(PIN_LED, LOW); // Desactiva LED Actividad
    BOMBA.LCD.setON( false );            
  }
  // Fin debug, test de funcionamiento

  #if ENCODER
  
  // Lee Encoder
  state = (state<<1) | digitalRead(CLK_PIN) | 0xe000;
  Rpm = BOMBA.LCD.getEncoder( state , counter );
  // Fin lee Encoder
  
  #else
  
  // Lee Potenciometro
  //BOMBA.LCD.setRPM(BOMBA.LCD.ReadPot(int(analogRead(A0)), Rpm_old));
  BOMBA.LCD.setRPM(analogRead(A0), Rpm_old);
  Rpm = BOMBA.LCD.getRPM();
  if (Rpm != Rpm_old) {
    // Serial.println(Rpm); // Opcion Debug
    BOMBA.LCD.PrintRPM( Rpm );
    BOMBA.LCD.PrintVol(MOTOR.getVol( Rpm ));  
  }
  Rpm_old = Rpm;
  // Fin Lee Potenciometro
  
  #endif 

}