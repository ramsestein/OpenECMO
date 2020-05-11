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

### Mecánica ###

El sitema mecánico consta de:
* Piezas impresas en 3D
* Motor paso a paso 
* Un sistema de husillo / cremallera.. (por concretar)
    * Aquí tenemos un enlace con cálculos al respecto de los husillos: https://docs.google.com/spreadsheets/d/1-_jbQUJL_gpxpd1H1qJIKm36sRTwBJtxHg9JuVWixjs/edit#gid=0   
* 2 Rodamientos LM8UU
* 

### Electrónica ###
El sitema electrónico consta de:
* 1 Fuente de alimentación de 12V
* 1 Conversor DC-DC
* 1 microcontrolador tipo Arduino o un microprocesador similar
*  Motor diver supported by [AccelStepper](https://www.airspayce.com/mikem/arduino/AccelStepper/index.html)
* 1 sensor final de carrera o endstop (mejor óptico o hall para evitar problemas de pérdida de pasos pero también pueden ser mecánicos)
* Display (Pantalla LCD I2C 16x2, 20x4 u OLED)
* Tres botones
* Codificador rotatorio (encoder para selección de opciones) o un potenciómetro
* LEDs indicadores de estado (Verde: Operativo; Rojo: Alarma)
* Alarma sonora (zumbador) 

![Esquema del perfusor](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/Perfusor/img/perfusor_bb.png "Esquema del perfusor")
(Este esquema está incompleto pero sirve como referencia)
## Diseño actual (en desarollo) ##

https://cad.onshape.com/documents/83fc61005005f6cafa1e611e/w/66630729656df7a5a0b484c3/e/114f94c28aaf946ab67668a8

En la carpeta stl hay unos archivos en formato .stl para la  impresión en 3D de la estructura del dispositivo.

https://gitlab.com/coronavirusmakers/ecmo/-/tree/master/Perfusor/stl 

## Como testear el perfusor

## Enlaces de interes ##
### Diseños ###
1. http://biohackacademy.github.io/biofactory/class/8-pumps/
2. https://github.com/gniezen/openpump
3. https://docs.google.com/document/d/1zW16lL-d0ZAO8lZd7ANE9CllARVIuFvh3bQfag9HGlk/mobilebasic#

### Calculos ###