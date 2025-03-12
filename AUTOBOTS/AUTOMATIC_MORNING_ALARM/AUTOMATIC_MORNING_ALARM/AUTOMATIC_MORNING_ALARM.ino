#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(3,4);
int LDR=A0;
int LED=13;
int Buzzer=10;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Bluetooth.begin(9600);
pinMode(LDR,INPUT);
pinMode(LED,OUTPUT);
pinMode(Buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensor_val = analogRead(A0);
Serial.println(sensor_val);
Bluetooth.println(sensor_val);
delay(1000);
if(sensor_val>=350){
  Serial.println("WAKE UP");
  digitalWrite(LED, LOW);
  digitalWrite(Buzzer, HIGH);
  delay(500);
  digitalWrite(Buzzer,LOW);
  
}
else if(sensor_val<=350){
  digitalWrite(LED,HIGH);
  digitalWrite(Buzzer,LOW);
  delay(500);
}
else{
  digitalWrite(LED,LOW);
  digitalWrite(Buzzer,LOW);
}
}
