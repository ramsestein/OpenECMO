/*
  Author: Waag Society's BioHack Academy Code.

  Modified: Francisco Ochando

  Modification description: Adding modifications. Current sensor.
  
  Waag Society's BioHack Academy Code is free software: you can 
  redistribute it and/or modify it under the terms of the GNU 
  General Public License as published by the Free Software 
  Foundation, either version 3 of the License, or (at your option) 
  any later version.
  
  Waag Society's BioHack Academy Code is distributed in the hope 
  that it will be useful, but WITHOUT ANY WARRANTY; without even 
  the implied warranty of MERCHANTABILITY or FITNESS FOR A 
  PARTICULAR PURPOSE.  See the GNU General Public License for more 
  details.
  
  You should have received a copy of the GNU General Public License
  along with Waag Society's BioHack Academy Code. If not, see 
  <http://www.gnu.org/licenses/>.
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

Peristaltic PERIS;
//AccelStepper Motor(1, PIN_STEP, PIN_DIR);
FlexyStepper stepper;
Pump pump;
Sensor sensor;

byte ledstate = LOW; // Blinking indicator LED

String buffer;
byte readout;

long last_time;
int stepper_timer = 0;
int step_time = 0;
long steps = 0;
uint16_t  update_timer = 0;
uint16_t speed_motor = 0;
uint16_t Rpm = 0;
uint8_t stepper_en = 0;
uint8_t pulsado = 0;
int16_t fwd_motor = 0;
unsigned long Current_val = 0;
bool ena = false;             // Bomba activada
bool fwd = true;              // Direccion (true = dcha)
const int timeThreshold = 150;
volatile int ISRCounter = 0;
long startTime = 0;
int counter = 0;
unsigned long time;


void setupStepper() 
{ 

  //stepper.setSpeedInStepsPerSecond(100);
  //stepper.setAccelerationInStepsPerSecondPerSecond(100);
  stepper.connectToPins(PIN_STEP, PIN_DIR);
  stepper.setTargetPositionInSteps(4000);
  stepper.setSpeedInRevolutionsPerSecond(1);
  stepper.setAccelerationInRevolutionsPerSecondPerSecond(1);

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
  pinMode(LED_PIN,OUTPUT); 
  
  // Config stepper enable
  stepper_en = 1;
  digitalWrite(PIN_ENABLE,1-stepper_en); // Activa LOW
  digitalWrite(LED_PIN, HIGH); // Activa HIGH
  
  // Initialize LCD
  PERIS.LCD.Setup();
  // Time after wellcome banner
  delay(800);
  PERIS.LCD.Init();
  setupStepper();
  Serial.println("Desactivada");

}

void Enable() {
  if (PERIS.LCD.getButton() == SW_ENC_PULSADO) {
    ena = !ena;
    //ena = pump.enabled();
    // Opcion debugger
    if (ena) {
      Serial.println("Activada ");
    } else {
      Serial.println("Desactivada ");      
    }
    // Fin opcion debugger
  }
}


void blink_enable() {
  if (ena){
    digitalWrite(LED_PIN, ledstate);
    ledstate = !ledstate;
  }
}


// ---------------------- MAIN --------------------------

void loop() {
  
  static uint16_t state=0, counter=60;

  // Comprueba los pulsadores para asignar Dirección y Enable
  if(PERIS.LCD.getButton() == SW_REV_PULSADO) {
    time = millis();
    if(time - last_time > 500) {
      Serial.print(SW_REV_PULSADO); 
      if (fwd) {
        fwd = !fwd;
        PERIS.LCD.PrintDir( fwd );
      } else {
        fwd = !fwd; 
        PERIS.LCD.PrintDir( fwd );     
      }  
      Serial.println (" Cambiada direccion");      
    } 
    last_time = time;   
  }

  if(PERIS.LCD.getButton() == SW_ENC_PULSADO) {
    time = millis();
    if(time - last_time > 500) {
      Serial.println(SW_ENC_PULSADO); 
      if (ena) {
        ena = !ena;
        Serial.println("Desactivada");
      } else {
        ena = !ena;
        Serial.println("Activada");      
      }        
    } 
    last_time = time;   
  }

  

  // Asigna direccion del motor
  if (fwd) {
     fwd_motor = 1000;  // el motor gira a la derecha    
  } else {
     fwd_motor = -1000;  // el motor gira a la izquierda    
  }

  
  // Debug. Test de funcionamiento
  if (ena) { 
    while(!stepper.motionComplete()) {
      stepper.processMovement(); // Not blocking

      if (stepper.getCurrentPositionInSteps() == 400) {
        Serial.println("Ha llegado a 400 pasos ");    
      }
      if (stepper.getCurrentPositionInSteps() == 4000) {
        Serial.println("Final ");    
      }
    }           
  }
  // Fin debug, test de funcionamiento
  

  // Lee el Encoder
  state = (state<<1) | digitalRead(CLK_PIN) | 0xe000;
  Rpm = PERIS.LCD.getEncoder( state , counter );
  // Fin lee el Encoder

}
