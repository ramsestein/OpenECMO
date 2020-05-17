
#include "Sensor.h"

float SENSIBILITY = 0.185;  // Modelo 5A
float threshold = 2.5;      // Rango 

float Sensor::getCurrent( byte samples ) {
  float voltage;
  float current = 0;
  for (int i = 0; i < samples; i++)
  {
    voltage = analogRead(A0) * 5.0 / 1023.0;
    current += (voltage - 2.5) / SENSIBILITY;
  }
  return(current / samples);  
}
