#ifndef _LASER_H_
#define _LASER_H_

#include "Arduino.h"

class Laser
{
  private:
    byte pin; //pin to ctrl Laser.
    
  public:
    Laser(byte p, bool state=LOW);
    ~Laser();
    byte getPin();
    void on();
    void off();
    boolean getState();
    void disattach();
}

#endif
