#include<SoftwareSerial.h>
int sensor=4;
int sensor_val;

void setup() {
  // put your setup code here, to run once:
pinMode(sensor, INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
sensor_val=digitalRead(sensor);
if(sensor_val==HIGH)
{
  Serial.println("Motion is detected");
  delay(100);
}
else {
    Serial.println("Motion not detected");
    delay(100);
    
}
}

