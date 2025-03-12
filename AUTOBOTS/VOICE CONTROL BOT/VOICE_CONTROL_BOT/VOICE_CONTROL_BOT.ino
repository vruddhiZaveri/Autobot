#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);
String BT_input;
int m1=7;//motor2 moves forward
int m2=6;//motor2 moves backwards
int m3=5;//motor1 moves backwards
int m4=4;//Motor1 moves forward
void setup() {
  // put your setup code here, to run once:
Bluetooth.begin(9600);
Serial.begin(9600);
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if(Bluetooth.available()>0){
  BT_input=Bluetooth.readString();
  Serial.println(BT_input);
  if(BT_input=="F"||BT_input=="forward"){
    digitalWrite(m1,HIGH);
    digitalWrite(m2,LOW);
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
    delay(100);
  }
  else if(BT_input=="B"||BT_input=="backward"){
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,HIGH);
    digitalWrite(m4,LOW);
    delay(100);
  }
  else if(BT_input=="L"||BT_input=="left"){
    digitalWrite(m1,HIGH);
    digitalWrite(m2,LOW);
    digitalWrite(m3,HIGH);
    digitalWrite(m4,LOW);
    delay(100);
  }
  else if(BT_input=="R"||BT_input=="right"){
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
    delay(100);
  }
  else if(BT_input=="S"||BT_input=="stop"){
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    digitalWrite(m3,LOW);
    digitalWrite(m4,LOW);
    delay(100);
  }
}
}
