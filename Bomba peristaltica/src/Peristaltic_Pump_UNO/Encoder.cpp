
/*
class Encoder
{
  byte state;
  byte pin0, pin1;
  int value;

  byte readState()
  {
    return (digitalRead(pin0) == HIGH ? 1u : 0u)
         | (digitalRead(pin1) == HIGH ? 2u : 0u);
  }
public:
  Encoder(int p0, int p1) :
    pin0(p0), pin1(p1), value(0), state(0) {}
  
  void init()
  {
    pinMode(pin0, INPUT);
    pinMode(pin1, INPUT);
    digitalWrite(pin0, 1);  // enable internal pullup
    digitalWrite(pin1, 1);  // enable internal pullup
    value = 0;
    state = readState();
  }

  bool poll()
  {
    // State transition table
    static char tbl[16] =
    { 0, +1, -1, 0,
      // position 3 = 00 to 11, can't really do anythin, so 0
      -1, 0, -2, +1,
      // position 2 = 01 to 10, assume a bounce, should be 01 -> 00 -> 10
      +1, +2, 0, -1,
      // position 1 = 10 to 01, assume a bounce, should be 10 -> 00 -> 01
      0, -1, +1, 0
      // position 0 = 11 to 10, can't really do anything
    };
  
    byte t = readState();
    char movement = tbl[(state << 2) | t];
    if (movement != 0)
    {
      value += movement;
      state = t;
      return true;
    }
    return false;
  }
  
  int getValue()
  {
    return value;
  }
};
*/
