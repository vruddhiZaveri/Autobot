#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);

String BT_input;
int time;
int m1=8;
int m2=9;
int m3=10;
int m4=11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Bluetooth.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
}
void forward(){
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,HIGH);
  digitalWrite(m4,LOW);
}
void stop(){
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
}


void loop() {
  if(Bluetooth.available()>0)
  {
    BT_input=Bluetooth.readString();
    Serial.println(BT_input);
    time=BT_input.toInt();
    time=time*1000;
    Serial.println(time);
    forward();
    delay(time);
    stop();
  }
}



