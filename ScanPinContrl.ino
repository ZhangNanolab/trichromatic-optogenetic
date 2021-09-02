int Laser980 = 3; // define digital pin for BMC signal
int Laser808 = 5;
int Laser1532 = 7;

void setup(){
  Serial.begin(9600);
  pinMode(Laser808, OUTPUT);
  pinMode(Laser980, OUTPUT);
  pinMode(Laser1532, OUTPUT);
}

void loop(){
  digitalWrite(ledPin, HIGH); //点亮小灯
  delay(1000); //
  digitalWrite(ledPin, LOW); //熄灭小灯
  delay(1000); // 延时1 秒
}
