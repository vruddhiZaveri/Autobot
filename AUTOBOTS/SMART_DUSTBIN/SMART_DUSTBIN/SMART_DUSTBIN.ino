#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);
int echopin = 4;
int trigpin = 5;
long duration;
int distance;
int BT_input;
void setup() {
  // put your setup code here, to run once:
Bluetooth.begin(9600);
Serial.begin(9600);
pinMode(echopin, INPUT);
pinMode(trigpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration= pulseIn(echopin,HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
  delay(500);
  Bluetooth.println(distance);
  delay(500);

}
