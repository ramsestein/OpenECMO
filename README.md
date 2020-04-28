# ECMO

*Extra Corporeal Membrane Oxygenation*

> *Nota:* Este documento se actualiza continuamente a medida que evoluciona el proyecto, por favor, revísalo frecuentemente y si crees que falta algo solicita que lo actualicemos.

## ¿Qué es una ECMO? ##
Es una asistencia mecánica circulatoria y respiratoria, capaz de proporcionar soporte cardiaco y pulmonar, durante un periodo de días o semanas, en la insuficiencia cardiaca o respiratoria refractarias a tratamiento convencional. Es un soporte vital extracorpóreo con oxigenador incorporado. 

> A diferencia de los sistemas de perfusión o bypass cardio-pulmonar que están diseñados para sustituir de forma completa y breve la función del corazón y pulmón en el quirófano y así facilitar la cirugía, la **ECMO** mantiene la asistencia necesaria para garantizar las funciones vitales durante un periodo de tiempo mayor [1].

Este artículo de la _Revista Española de Perfusión_ nos parece muy interesante e ilustrativo para todos aquellos que quieran entender el problema y sería casi de lectura obligatoria si realmente quieres ayudar: [Soporte vital extracorpóreo. Oxigenación por
membrana extracorpórea. ECMO](https://www.aep.es/articulo/71/Monogra%CC%81fico%20ECMO.pdf "Soporte vital extracorpóreo. Oxigenación por
membrana extracorpórea. ECMO")

## El proyecto ##
Intentamos construir una ECMO maker que cumpla con parámetros hemodinámicos suficientes para mantener con vida a pacientes muy graves afecados por COVID-19.

> Para todos los que se acaben de añadir al proyecto les recomedamos la visualización del siguiente **[vídeo](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/files/zoom_Ramses.mp4?inline=true "Ramsés explica en que consiste un ECMO")** de una videoconferencia en la que el médico Ramsés Marrero explica de que se trata.

Los objetivos hemodinámicos que debemos intentar conseguir tras la colocación del ECMO son:
* Flujo inicial del ECMO 50 – 80 ml/Kg./min. 
* Presión arterial media ≥ 65 mmHg. 
* Índice cardiaco ≥ 2.5 l/min./m2. 
* Presión de enclavamiento de arteria pulmonar (PEAP) 8-14 mmHg
* PVC 8-10 mmHg. 
* Saturación venosa mixta >65%. 
* Restauración de la diuresis (>0,5 ml/Kg. /h.) 
* Disminuir el ácido láctico en las primeras 4 horas.

## Esquema inicial ##

IMAGEN
Presiones intrasistema:
* P1: presión negativa de succión venosa (valores normales hasta -70 mmHg)
* P2: presión entre la bomba y el oxigenador (valor máximo de la normalidad entre   250 - 300 mmHg).
* P3: presión entre el oxigenador y la cánula arterial (valor máximo de la normalidad entre 250 – 300 mmHg).
* Diferencial de presión (calculado) ∆P (P2 – P3)

## Requisitos ##
### Tubos ###
* El tubo interior que aplasta debe tener un diámetro de 7mm externo y 6mm de diámetro interno.
* Usar tubos de sistemas de suerocon un mínimo de 1 lpm de caudal.
* Los tubos no tienen porque ser de grado médico, podrían valer tubos de acuario suficientemente blando para poder aplastarse en la bomba peristáltica (* para los prototipos)

### Sensores ###

Algunas ideas:
* Interesa conocer la presión antes y después del filtro y también al final del recorrido
* De nuevo la presión hay que medirla de forma indirecta (sin “tocar” la sangre).

* Presion:
    * Dendrómetro
    * Webcam + machine learnnig para ver el flujo
    * Ultrasonidos / Doppler
* Obstruccion:
    * Oxymetro







