# Perfusor #

## Descripción ##
La bomba de perfusion (o infusión) es un dispositivo que dispensa fluido durante un período de tiempo determinado. 

Info de la wikipedia: https://es.wikipedia.org/wiki/Bomba_de_infusi%C3%B3n

## Proyecto ##
* El diseño mecánico se basa en un diseño de actuador lineal junto a una jeringa, controlado por un sistema electrónico.
* El dispositivo debe ser independiente del resto del sistema [ECMO](https://gitlab.com/coronavirusmakers/ecmo "ECMO").
* La jeringa se coloca en el perfusor ya purgada.


El diseño usara una jeringa 50-60 ml tipo BD Plastic o similar (diametro 26.7 mm) 

[Jeringuilla](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/images/jeringuilla.jpeg "Jeringuilla de 50-60ml")

[Datos y tamaños de las jeringuillas](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/files/Syringe-Selection-Guide.pdf "Datos de las jeringuillas")


## Requerimientos funcionales ##
* Tenemos que lograr un control entre 0.1ml/h - 1200ml/h para una jeringuilla de 50ml (valores calculados)
* Resolución de 0.1 mL
* Dosis tipica es de 2-15ml/h
* Velocidad ajustable
* Posibilidad de hacer una embolada puntual de x mL
* Indicación de estado
* indicador de alarma cuando este al 95% del final
*  La interface de usuario debe permitir:
    * Indicar y modificar la velocidad de perfusion
    * Cargar nueva jeringa (volver al inicio de carrera)

## Hardware ##

El sitema mecanico consta de:
* Motor paso a paso 
* Un sistema de husillo / cremallera.. (por concretar)
    * Aquí tenemos un enlace con cálculos al respecto de los husillos: https://docs.google.com/spreadsheets/d/1-_jbQUJL_gpxpd1H1qJIKm36sRTwBJtxHg9JuVWixjs/edit#gid=0    

El sitema electronico consta de:
* Arduino o un microprocesador similar mejor un Mega
* 2 sensores endstop (inicio+final) mejor ópticos o hall para evitar problemas mecánicos
* Alarma sonora (zumbador) y visual (LED rojo) antes de llegar el final de carrera
* Display (Pantalla LCD I2C 16x2, 20x4 u OLED)
* Dos botones (?)
* Codificador rotatorio (encoder para selección de opciones)
* LEDs indicadores de estado (Verde: Operativo; Rojo: Alarma)

## Diseño actual (en desarollo) ##

https://cad.onshape.com/documents/83fc61005005f6cafa1e611e/w/66630729656df7a5a0b484c3/e/114f94c28aaf946ab67668a8

## Como testear el perfusor

## Enlaces de interes ##
1. http://biohackacademy.github.io/biofactory/class/8-pumps/
2. https://github.com/gniezen/openpump
3. https://docs.google.com/document/d/1zW16lL-d0ZAO8lZd7ANE9CllARVIuFvh3bQfag9HGlk/mobilebasic#