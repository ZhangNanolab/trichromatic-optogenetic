#ifndef _LASER_H_
#define _LASER_H_

#include "Arduino.h"

class Laser
{
  private:
    byte p1; //pin to ctrl Laser.
    byte p2; //pins to ctrl power seqs.
    byte p3; 
    
  public:
    Laser(byte p1,byte p2,byte p3 bool state=LOW);
    ~Laser();
    int getIndex();
    byte getPin();
    void on();
    void off();
    void sequp();
    void seqdwon();
    void seqend();
    boolean getState();
    void disattach();
}

#endif
