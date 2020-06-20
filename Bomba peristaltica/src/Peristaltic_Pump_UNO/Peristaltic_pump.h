/*
    Author: Francisco Ochando
   
    Module: Peristaltic_pump.h
    Fichero de cabecera
    Declara las clases y las variables globales

 */

#include  <Arduino.h>
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
#include  <TimerOne.h>
#include  <SoftwareSerial.h>


// Pinout UNO
#define   CLK_PIN     2     // pin CLK encoderA
#define   DATA_PIN    3     // pin DATA encoderA
#define   PIN_STEP    7     // pin paso 
#define   PIN_DIR     8     // pin direccion
#define   PIN_ENABLE  9     // pin enable motor
#define   PIN_ALR     10    // pin led alarma
#define   SW_ENC      11    // Switch encoder
#define   SW_REV      12    // Switch direccion
#define   PIN_LED     13    // Arduino's onboard LED pin
#define   PIN_POT     A0    // pin potenciometro
#define   PIN_CURRENT A1    // pin current sensor

// LCD ( LCD 20 x 4 )
#define   LCD_20x4    1     // Poner a 0 para utilizar un LCD 16x2
#define   I2C_DIR     0x27  // Dir I2C para el LC20x4
#define   MAXROWS     4     // Numero filas
#define   MAXCOLS     20    // Numero columnas
#define   INT_I2C     0x27  // Depende del hardware 

// Puerto Serie
#define   BPS1152   115200  // Maxima RS232
#define   BPS96     9600    // 9600 bps

#define   ENABLED   1       // Bomba activada
#define   DISABLED  0       // Bomba desactivada

// Estado Botones
#define   SW_REV_PULSADO 1
#define   SW_ENC_PULSADO 2
#define   ENCODER   0

// Estado bomba
#define   RPM_DEFAULT 60
#define   RPM_MAX     400


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
    void setAlarm( void );
    void setDir( bool dir );
    void setON( bool on );
    void ReadButton( void );
    int ReadPot( int pot , int antpot );
    byte getButton( void );
    byte getBut( void );
    bool ButPressed( void );
    int getEncoder( int state , int counter);
    void setRPM( long valor , int antvalor );
    int getRPM( void );
    void Reset( void );
    
  private:

    byte but = 0;
    byte pressed = 0;
    void Read( void );
    int LeeEncoder( int state , int counter );
    int rpm = 0;
    byte trigger = 200;

};


class Peristaltic
{
         
  public:               
    
    class Pantalla:     public Hid {}; // Repasar la implicacion de public Screen{};
    
    class Pantalla      LCD;           // Define el interfaz HiD  ( LCD 4 x 20 ) 
    //class Pump          MOTOR;         // Define la clase bomba  
    //class Sensor        SENSOR;        // Define la clase sensor
    
    //    Metodos
    void Setup();                      // Inicia el hardware y abre puerto serie

  private:

    int rpms = RPM_DEFAULT;
    
};