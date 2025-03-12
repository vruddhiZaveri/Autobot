#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
int slot1 =5;
int slot2 =7;
int gate_red1=4;
int gate_red2=6;
void setup() {
  // put your setup code here, to run once:
pinMode(slot1,INPUT);
pinMode(slot2,INPUT);
pinMode(gate_red1,OUTPUT);
pinMode(gate_red2,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int data1= digitalRead(slot1);
int data2=digitalRead(slot2);
Serial.println(data1);
Serial.println(data2);

if(data1==0 && data2==0){
  // delay(1000);
Serial.println("not free");
digitalWrite(gate_red1,HIGH);
digitalWrite(gate_red2,HIGH);
}
if(data1==1 && data2==0){
  // delay(1000);
Serial.println("not free");
digitalWrite(gate_red1,LOW);
digitalWrite(gate_red2,HIGH);
}
if(data1==0 && data2==1){
  // delay(1000);
Serial.println("not free");
digitalWrite(gate_red1,HIGH);
digitalWrite(gate_red2,LOW);
}
if(data1==1 && data2==1){
  // delay(1000);
Serial.println("not free");
digitalWrite(gate_red1,LOW);
digitalWrite(gate_red2,LOW);
}

}
