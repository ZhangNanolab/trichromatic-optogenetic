#include "laser.h"
#include "Arduino.h"

laser::laser(byte p1,byte p2,byte p3, bool state)
{
  pinMode(p1,OUTPUT); // digital ctrl
  pinMode(p2,OUTPUT); // sequp ctrl
  pinMode(p3,OUTPUT); // seqdown ctrl
  digitalWrite(p1,state);
}

laser::~laser()
{
  disattach();
}

void laser::sequp()
{
  digitalWrite(p2,HIGHT);
}

void laser::seqdown()
{
  digitalWrite(p3,HIGHT);
}

void laser::seqend()
{
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
}

void laser::on()
{
  digitalWrite(p1,HIGHT);
}

void laser::off()
{
  digitalWrite(p1,LOW);
}


bool laser::getState()
{
  return digitalRead(pin);
}

void laser::disattach()
{
  digitalWrite(p1,LOW);
  pinMode(p1,INPUT);
}
