/*
    Author: Francisco Ochando
    
    Peristaltic_pump.h

    Fichero de cabecera

    Declara las clases y las variables globales

 */

#include  <Arduino.h>
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
#include  <TimerOne.h>
#include  <SoftwareSerial.h>

// Stepper driver (FlexyStepper)
/*
#define PIN_STEPPER_STEP  6
#define PIN_STEPPER_DIR   7
#define PIN_STEPPER_EN    8
*/

// Current Sensor
#define PIN_CURRENT      A0

// Pinout UNO
#define   CLK_PIN     2       // pin CLK encoderA
#define   DATA_PIN    3       // pin DATA encoderA
#define   PIN_ENABLE  4       // pin enable
#define   PIN_STEP    7       // pin paso 
#define   PIN_DIR     8       // pin direccion
#define   SW_ENC     11       // Switch encoder
#define   SW_REV     12       // Switch encoder
#define   LED_PIN    13       // the number of Arduino's onboard LED pin

// LCD ( LCD 20 x 4 )
#define   LCD_20x4  1
#define   I2C_DIR   0x27    // Dir I2C para el LC20x4
#define   MAXROWS   4       // Numero filas
#define   MAXCOLS   20      // Numero columnas
#define   INT_I2C   0x27    // Depende del hardware 

// Puerto Serie
#define   BPS1152   115200  // Maxima RS232
#define   BPS96     9600    // 9600 bps

#define ENABLED       1     // Bomba activada
#define NOT_ENABLED   0     // Bomba desactivada

// Estado Botones
#define SW_REV_PULSADO 1
#define SW_ENC_PULSADO 2

#define RPM_DEFAULT   60


class Hid
{

  public:

    LiquidCrystal_I2C LCD;

    // Constructor
    #if LCD_20x4     
    Hid():LCD( I2C_DIR , 20 , 4 ){}
    #else
    Hid():LCD( I2C_DIR , 16 , 2 ){}    
    #endif

    void Setup( void );
    void Init( void );
    void Update( byte value1, byte value2 );
    void PrintRPM( int value1 );
    void PrintVol( float value1 );
    void PrintAlarm( void );
    void PrintDir( bool dir );
    byte getButton( void );
    int getEncoder( int state , int counter);
    
  private:

    byte buton = 0;
    byte pulsado = 0;
    byte Lee( void );
    int LeeEncoder( int state , int counter );
    byte threshold = 150;

};


class Peristaltic
{
         
  public:               
    
    class Pantalla:     public Hid {}; // Repasar la implicacion de public Screen{};
    
    class Pantalla      LCD;              // Define el interfaz HiD  ( LCD 4 x 20 ) 
    //class Pump          PUMP;             // Define la clase bomba  
    //class Sensor        SENSOR;           // Define la clase sensor
    
    //    Metodos
    void Setup();                         // Inicia el hardware y abre puerto serie

  private:

    int rpms = RPM_DEFAULT;
    
};
