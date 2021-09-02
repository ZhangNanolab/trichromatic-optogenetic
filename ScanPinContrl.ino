#include "laser.h" 
laser laser808(3), laser980(4), laser1532(5); // Attribute digital pin for lasers BMC signal
byte max_cycle = 3; // scanning loop times
byte count = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  if(count<cycle)
  { 
    laser980.on();
    laser808.on();
    laser980.sequp();
    laser808.seqdown();
    delay(3000);
    laser808.off();
    
    laser1532.on();
    laser980.seqdown();
    laser1532.sequp();
    delay(3000);
    laser980.off();
    
    laser808.on();
    laser808.sequp();
    laser1532.seqdown();
    delay(3000);
    laser808.off();
    laser1532.off();
    ++count;
    delay(1000);
  }
  else{
    laser808.disattach();
    laser980.disattach();
    laser1532.disattach();
  }
  
}
