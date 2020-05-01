# ECMO

*Extra Corporeal Membrane Oxygenation*

> *Nota:* Este documento se actualiza continuamente a medida que evoluciona el proyecto, por favor, revísalo frecuentemente y si crees que falta algo solicita que lo actualicemos.

## ¿Qué es una ECMO? ##
Una **ECMO** o **Membrana de Oxigenación Extra Corpórea** es una asistencia mecánica circulatoria y respiratoria, capaz de proporcionar soporte cardíaco y pulmonar, durante un periodo de días o semanas, para la insuficiencia cardiaca o respiratoria refractarias a tratamiento convencional. Es en resumen un soporte vital extracorpóreo con oxigenador incorporado. 

> A diferencia de los sistemas de perfusión o bypass cardio-pulmonar que están diseñados para sustituir de forma completa y breve la función del corazón y pulmón en el quirófano y así facilitar la cirugía, la **ECMO** mantiene la asistencia necesaria para garantizar las funciones vitales durante un periodo de tiempo mayor.

Este artículo de la _Revista Española de Perfusión_ nos parece muy interesante e ilustrativo para todos aquellos que quieran entender el problema y sería casi de lectura obligatoria si realmente quieres ayudar: [Soporte vital extracorpóreo. Oxigenación por
membrana extracorpórea. ECMO](https://www.aep.es/articulo/71/Monogra%CC%81fico%20ECMO.pdf "Soporte vital extracorpóreo. Oxigenación por
membrana extracorpórea. ECMO")

## ¿Por qué un ECMO?

** El problema **
Además de la falta de respiradores hay otra crisis que inicialmente se pasó por alto: 
https://www.infobae.com/america/the-new-york-times/2020/04/19/coronavirus-ademas-de-la-falta-de-respiradores-hay-otra-crisis-que-se-paso-por-alto/

** ¿Qué se puede hacer? **
Ramsés Marrero convova en el foro A.I.R.E. https://foro.coronavirusmakers.org/index.php?p=/discussion/comment/2749 este proyecto de clase 3.

## El proyecto ##
Intentamos construir una ECMO maker que cumpla con parámetros hemodinámicos suficientes para mantener con vida a pacientes muy graves afecados por COVID-19. 

> Recuerda que se trata de emular el comportamiento de un dispositivo comercial pero queremos construir algo low-cost pero con garantías médicas.

> *Nota importante:* Todos los que se acaben de añadir al proyecto les recomedamos la visualización del siguiente **[vídeo](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/files/zoom_Ramses.mp4?inline=true "Ramsés explica en que consiste un ECMO")** de una videoconferencia en la que el médico Ramsés Marrero explica de que se trata.
También rogamos encarecidamente que lean toda la información disponible antes de preguntar por los grupos de Telegram cuestiones que ya están resueltas.

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

![Idea](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/images/idea.png "Ramsés explica en que consiste un ECMO")

*Presiones intrasistema:*
* P1: presión negativa de succión venosa (valores normales hasta -70 mmHg)
* P2: presión entre la bomba y el oxigenador (valor máximo de la normalidad entre   250 - 300 mmHg).
* P3: presión entre el oxigenador y la cánula arterial (valor máximo de la normalidad entre 250 – 300 mmHg).
* Diferencial de presión (calculado) ∆P (P2 – P3)

## Componentes del sistema ##

### Consola ###
* Es la encargada del control hemodinámico del sistema.
* Permite regular la velocidad de rotación de la bomba peristáltica (RPM) y el flujo en litros por minuto (LPM)
* Muestra la información aportada por los sensores hemodinámicos, bioquímicos o de seguridad implantados en el circuito.

### Bomba peristáltica ###
* Se necesita lograr un caudal de hasta 6 Litros por minuto (Lpm).
* Se descarta el uso de una bomba centrífuga porque tendría que ser de grado médico aunque es la que se usa en sistemas comerciales modernos.

### Tubos ###
* El tubo interior que aplasta debe tener un diámetro de 7mm externo y 6mm de diámetro interno para aprovechar los que hay de forma abundante en los hospitales.
* Para conseguir suficiente caudal (de hasta 6Lpm) se ha determinado que serán necesarios al menos dos tubos de ese diámetro.
* Los tubos no tienen porque ser de grado médico, podrían valer tubos de acuario suficientemente blando para poder aplastarse en la bomba peristáltica (* para los prototipos)

### Sensores ###

Algunas ideas:
* Interesa conocer la presión antes y después del filtro y también al final del recorrido
* De nuevo la presión hay que medirla de forma indirecta (sin “tocar” la sangre) o utilizar sensores desechables.

* Presión:
    * Dendrómetro
    * Webcam + machine learnnig para ver el flujo
    * Ultrasonidos / Doppler
    * Sensores barométricos / de presión
    
* Para detectar obstruccion:
    * Utilización de un oxímetro
    * Medida de la corriente del motor o uso de sensores hall para determinar si la velocidad de giro es la prefijada.

### Oxigenador ###
Es el elemento esencial del EMCO, la membrana que permite la oxigenación de la sangre del paciente. 
* Opción de usar un modelo comercial.
* Se están estudiando tamnbién distintas opciones de fabricación 

### Perfusor ###
Es un elemento adicional (independiente) que permite la infusión de heparina para evitar la coagulación de la sangre.

## Colaboración ##

Si crees que puedes ayudar entra en los grupos de Telegram y dirígete al subgrupo en el que creas que puedes aportar más: 
https://t.me/joinchat/AEZqrlHdWOAwDOvL7WSOKA



