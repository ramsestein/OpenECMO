
#include "Peristaltic_pump.h"
#include "Pump.h"

//#define SW_REV_PULSADO 1
//#define SW_ENC_PULSADO 2

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// LiquidCrystal_I2C lcd(0x27,16,2);
// Set the LCD address to 0x27 for a 20 chars and 4 line display
//LiquidCrystal_I2C lcd(0x27,20,4);
Pump pump_;

void Hid::Setup() {
  // Initialize I2C
  Wire.begin();
  // Initialize the LCD and print a message
  LCD.init();
  LCD.backlight();
  LCD.clear();
  LCD.setCursor( 0,0 );
  LCD.print(F("ECMO COVID-19"));
  LCD.setCursor( 0,1 );
  LCD.print(F("Peristaltic Pump"));
}

void Hid::Init()
{
 
  LCD.setCursor( 0,2 );
  LCD.print(F("RPM: "));
  LCD.setCursor( 0,3 );
  LCD.print(F("VOL: "));
  LCD.setCursor( 10,3 );
  LCD.print( "mL/min");

}

void Hid::Update( byte value1, byte value2 )
{
 
  LCD.setCursor( 0,2 );
  LCD.print(F("RPM: "));
  LCD.print( value1 );
  LCD.setCursor( 0,3 );
  LCD.print(F("VOL: "));
  LCD.print( value2 );
  LCD.print( " mL/min");

}

void Hid::PrintRPM( int value1 )
{
  
  LCD.setCursor( 5 , 2 );
  LCD.print( value1 );
  LCD.print( "  " );

}

void Hid::PrintVol( float value1 )
{
  
  LCD.setCursor( 5 , 3 );
  LCD.print( value1 );
  LCD.print( " mL/min");

}

void Hid::PrintAlarm( void )
{
  
  LCD.setCursor( 11 , 2 );
  LCD.print( "< ALARM >");

}

void Hid::PrintDir( bool dir )
{
  
  LCD.setCursor( 17 , 0 );
  if(dir) {
    LCD.print( ">>>");   
  } else {
    LCD.print( "<<<");    
  }

}

byte Hid::Lee( void )
{
  
  //    Switch Inversion giro
  if ( !digitalRead(SW_REV) ) {
    buton = SW_REV_PULSADO;
    pulsado++;
  }
             
  //    Switch Encoder
  if ( !digitalRead(SW_ENC) ) {
    buton = SW_ENC_PULSADO;  
    pulsado++;
  }
   
  return buton;
}

int Hid::LeeEncoder( int state, int counter ) {
  //state = (state<<1) | digitalRead(CLK_PIN) | 0xe000;
  if (state==0xf000){
    state=0x0000;
    if(digitalRead(DATA_PIN)) {
      counter--;
      if (counter < 0 ) { counter = 400 - counter; }
    } 
    else
    {
      counter++;
      if (counter > 400 ) counter = 0;
    }
    PrintRPM( counter );
    PrintVol( pump_.getVolume(counter) );
  }
  return counter;  
}

int Hid::getEncoder( int state, int counter ) {
  return LeeEncoder( state , counter);
}

byte Hid::getButton()
{
  byte hid = Lee();
  if (hid != 0 && pulsado > threshold) 
  {
    buton = 0;
    pulsado = 0;
    return Lee();
  }
  else
  {
    return 0;
  }
}
