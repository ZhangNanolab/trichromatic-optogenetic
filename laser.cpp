#include "laser.h"
#include "Arduino.h"

laser::laser(int laseridx, byte p, bool state):pin(p)
{
  pinMode(pin,OUTPUT);
  digitalWrite(pin,state);
}

laser::~laser()
{
  disattach();
}

void laser::on()
{
  digitalWrite(pin,HIGHT);
}

void laser::off()
{
  digitalWrite(pin,LOW);
}

bool laser::getState()
{
  return digitalRead(pin);
}

void laser::disattach()
{
  digitalWrite(pin,LOW);
  pinMode(pin,INPUT);
}
