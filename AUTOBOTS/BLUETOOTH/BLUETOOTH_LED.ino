#include<SoftwareSerial.h>
int LED=10;
char BT_input;
SoftwareSerial Bluetooth(4,5);
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  Bluetooth.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
if(Bluetooth.available())
{
  BT_input = Bluetooth.read();
  Serial.write(BT_input);
  if(BT_input=='1')
  {
    digitalWrite(LED,HIGH);
  }
  else if(BT_input=='0')
  {
    digitalWrite(LED,LOW);
  }
}
if(Serial.available())
{
  BT_input = Serial.read();
  Bluetooth.write(BT_input);
  if(BT_input=='1')
  {
    digitalWrite(LED,HIGH);
  }
  else if(BT_input=='0')
  {
    digitalWrite(LED,LOW);
  }
}
}
