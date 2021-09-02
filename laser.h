#ifndef _LASER_H_
#define _LASER_H_

#include "Arduino.h"

class Laser
{
  private:
    byte pin; //pin to ctrl Laser.
    
  public:
    Laser(int laseridx, byte p, bool state=LOW);
    ~Laser();
    int getIndex();
    byte getPin();
    void on();
    void off();
    void sequp();
    void seqdwon();
    boolean getState();
    void disattach();
}

#endif
