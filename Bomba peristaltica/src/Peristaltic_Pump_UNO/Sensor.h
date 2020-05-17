
#include  <Arduino.h>

#define ENABLED_SENSOR_CURRENT  1

class Sensor
{
  
  public:
    //Sensor();
    unsigned int begin(void);
#if ENABLED_SENSOR_CURRENT
    void readCurrent( void );
#endif
  private:
    void _init(void);
#if ENABLED_SENSOR_CURRENT
    float getCurrent( byte samples ); 
#endif

};
