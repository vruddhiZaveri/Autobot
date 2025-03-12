#include<SoftwareSerial.h>
SoftwareSerial Bluetooth (2,3);
int LEFT = 4;
int RIGHT = 5;
int UP = 6;
int DOWN =7;

void setup() {
  // put your setup code here, to run once:

pinMode(LEFT, INPUT);
pinMode(RIGHT, INPUT);
pinMode(UP, INPUT);
pinMode(DOWN, INPUT);

Serial.begin(9600);
Bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int Sensorvalue1=digitalRead(LEFT);
int Sensorvalue2=digitalRead(RIGHT);
int Sensorvalue3=digitalRead(DOWN);
int Sensorvalue4=digitalRead(UP);


if(Sensorvalue1== HIGH){
  Bluetooth.print("A");
  delay(1000);
}
else if (Sensorvalue2== HIGH) {
  Bluetooth.print("B");
  delay(1000);
}
else if (Sensorvalue3== HIGH) {
  Bluetooth.print("C");
  delay(1000);
}
else if (Sensorvalue3== HIGH) {
  Bluetooth.print("D");
  delay(1000);

}





Serial.print(Sensorvalue1);
 Serial.print("\t");
Serial.print(Sensorvalue2);
 Serial.print("\t");
Serial.print(Sensorvalue3);
 Serial.print("\t");
Serial.print(Sensorvalue4);
 Serial.println("\t");
}
