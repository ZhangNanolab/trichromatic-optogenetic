#include "laser.h" 
laser laser808(3,4,5), laser980(6,7,8), laser1532(9,10,11); // Attribute digital pin for lasers BMC signal and built-inside power stage sequence enable
byte max_cycle = 3; // scanning loop times
byte count = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  if(count<cycle)
  { 
    laser980.sequp();
    laser808.seqdown();
    laser980.on();
    laser808.on();
    delay(3000);
    laser980.off();
    laser808.off();
    laser808.seqend();
    laser980.seqend();
    
    laser980.seqdown();
    laser1532.sequp();
    laser1532.on();
    laser980.on();
    delay(3000);
    laser980.off();
    laser1532.off();
    laser1532.seqend();
    laser980.seqend();
    
    laser808.sequp();
    laser1532.seqdown();
    laser808.on();
    laser1532.on();
    delay(3000);
    laser808.off();
    laser1532.off();
    laser808.seqend();
    laser1532.seqend();
    ++count;
    delay(1000);
  }
  else{
    laser808.disattach();
    laser980.disattach();
    laser1532.disattach();
  }
  
}
