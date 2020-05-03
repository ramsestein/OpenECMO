# Bomba Peristáltica  #

## Descripción ##
Una bomba peristáltica es un tipo de bomba hidráulica de desplazamiento positivo usada para bombear una variedad de fluidos.


## Requerimientos funcionales ##
* Bombeo continuo
* Resolución de 1 ml
* Dirección hacia adelante / hacia atrás
* Velocidad ajustable


## Hardware ##

El sitema mecánico consta de:
* Motor paso a paso
* Una caja impresa en 3D con rodamientos para hacer la bomba peristáltica 
* Tubos para diálisis de 6mm de diámetro interior y 7mm de diámetro exterior


El sitema electrónico consta de:
* Arduino Nano 
* Driver para el motor
* Motor paso a paso Nema 23 con eje de 6.35 u 8 mm
* Display (Pantalla LCD I2C 16x2 u OLED)
* Codificador rotatorio (encoder)
* Un botón pera realizar emboladas rápidas. 
* (Quizá un segundo botón)
* LEDs indicadores de estado (Verde: Operativo; Rojo: Alarma)
* Zumbador de alarma


## Diseño actual (en desarollo) ##
Se han subido los archivos de un diseño 3D para motores nema 23 con ejes de 6,23 y 8mm en la carpeta STL que utiliza para probar rodamientos 608zz. 
Deben utilizarse tubos de 7mm de diámetros exterior y 6mm de diámetro exterior habituales en los hospitales y que se utilizan para diálisis.

## Como testear el bomba persitaltica
* Medición de consumo de corriente
* Encoder
* Sensor hall 


## Enlaces de interes ##
1. http://biohackacademy.github.io/biofactory/class/8-pumps/
2. http://2017.igem.org/Team:Aachen/Hardware

