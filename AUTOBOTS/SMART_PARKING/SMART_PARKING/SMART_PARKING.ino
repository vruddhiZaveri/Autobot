#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);
int irsensor = 4;
int led =5;

void setup() {
  // put your setup code here, to run once:
Bluetooth.begin(9600);
Serial.begin(9600);
pinMode(irsensor,INPUT);
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensor_val=digitalRead(irsensor);
Bluetooth.println(sensor_val);

if(sensor_val==LOW){
  digitalWrite(led, HIGH);
  delay(500);
}
else if(sensor_val==HIGH){
  digitalWrite(led,LOW);
  delay(500);

}
delay(100);

}
