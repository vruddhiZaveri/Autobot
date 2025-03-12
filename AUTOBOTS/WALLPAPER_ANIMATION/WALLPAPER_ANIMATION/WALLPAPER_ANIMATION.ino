#include<SoftwareSerial.h>
int PotPin = A0;
int sensorVal = 0;

SoftwareSerial Bluetooth(4,5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Bluetooth.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensorVal=analogRead(PotPin);
  sensorVal= sensorVal/4;
  Serial.println(sensorVal);
  Bluetooth.println(sensorVal);
  delay(1000);


}
