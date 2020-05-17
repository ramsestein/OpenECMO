# Estados de la máquina

## Documento que describe los estados de la Máquina
En el presente documento se describen los estados de la máquina del LCD en función del estado de los botones, el encoder y los sensores.
El LCD utilizado es un 20x4. La configuración para un LCD 16x2 es posible.
Simulación de LCD en: http://avtanski.net/projects/lcd/
## Estados del LCD en función de los estados de la Máquina
1.	Estado de arranque
Al arrancar la máquina muestra la presentación de bienvenida y las RPM por defecto (configuración de inicio a determinar).
![Pantalla inicial del LCD de la bomba peristáltica](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/Bomba%20peristaltica/img/image001.png "Pantalla inicial del LCD de la bomba peristáltica")
2.	Estado de configuración inicio
	Al pulsar el SWITCH_REV se invierte el sentido de la bomba. Esto sólo es posi-ble antes de la marcha del motor o una vez detenido. 
![Invirtiendo el sentido de giro](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/Bomba%20peristaltica/img/image002.png "Invirtiendo el sentido de giro")
3.	Estado de selección de RPM
	La selección de RPM es posible en el modo de configuración inicial o durante el modo de funcionamiento actuando sobre el ENCODER ROTATIVO (varian las RPM y el caudal - VOL).
![Selección de RPM](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/Bomba%20peristaltica/img/image001.png "Selección de RPM")
4.	Estado de funcionamiento
	Al pulsar SWITCH_ENC se arranca la bomba con la velocidad configurada (ON). Así mismo, al pulsar el mismo, se para la bomba.
5.	Estado de Alarma (funcionamiento)
	Durante el funcionamiento la pantalla LCD muestra el estado <ALARM> si re-produce un desajuste de las RPM por causa de un bloqueo del Sistema.
	![Estado de Alarma](https://gitlab.com/coronavirusmakers/ecmo/-/raw/master/Bomba%20peristaltica/img/image001.png "Estado de Alarma")
6.	Estado de OFF
