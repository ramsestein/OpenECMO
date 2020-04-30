# Perfusor #

## Descripción ##
La bomba de perfusion es un dispositivo que dispensa fluido durante un período de tiempo determinado.
El diseño mecánico se basa en un diseño de actuador lineal juno a una jeringa, controlado por un sistema electronico.


El dispositivo debe ser independiente del resto del sistema ECMO.
La jeringa se coloca en el perfusor ya purgada.

El diseño usara una jeringa 50-60 ml tipo BD Plastic (diametro 26.7 mm)

[Jeringuilla](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/images/jeringuilla.jpeg "Jeringuilla de 50-60ml")
[Datos y tamaños de las jeringuillas](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/files/Syringe-Selection-Guide.pdf "Datos de las jeringuillas")

La interface de usuario debe permitir:
* Indicar y modificar la velocidad de perfusion
* Cargar nueva jeringa (volver al inicio de carrera)

## Requerimientos funcionales ##
* Resolución de 0.1 mL
* Velocidad ajustable
* Posibilidad de hacer una embolada puntual de x mL
* Indicación de estado
* indicador de alarma cuando este al 95% del final


## Hardware ##

El sitema mecanico consta de:
* Motor paso a paso
* 
* 


El sitema electronico consta de:
* Arduino o un microprocesador similar
* 2 sensores endstop (inicio+final)
* Alarma sonora y visual (LED rojo) antes de llegar el final de carrera
* Display (Pantalla LCD I2C 16x2 o OLED)
* Dos botones (?)
* Codificador rotatorio
* LEDs indicadores de estado (Verde: Operativo; Rojo: Alarma)

## Diseño actual (en desarollo) ##

https://cad.onshape.com/documents/83fc61005005f6cafa1e611e/w/66630729656df7a5a0b484c3/e/114f94c28aaf946ab67668a8

## Como testear el perfusor

## Enlaces de interes ##
1. http://biohackacademy.github.io/biofactory/class/8-pumps/
2. https://github.com/gniezen/openpump
3. https://docs.google.com/document/d/1zW16lL-d0ZAO8lZd7ANE9CllARVIuFvh3bQfag9HGlk/mobilebasic#
