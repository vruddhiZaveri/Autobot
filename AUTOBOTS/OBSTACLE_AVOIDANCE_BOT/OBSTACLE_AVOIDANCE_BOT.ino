#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);
int echopin = 4;
int trigpin = 5;
long duration;
int distance;
char BT_input;
int m1=8;//M1-FORWARDS
int m2=9;//M1-BACWARDS
int m3=10;//M2-BACKWARDS
int m4=11;//M2-FORWARDS
void setup() {
  // put your setup code here, to run once:
Bluetooth.begin(9600);
Serial.begin(9600);
pinMode(echopin, INPUT);
pinMode(trigpin, OUTPUT);
pinMode(m1, OUTPUT);
pinMode(m2, OUTPUT);
pinMode(m3, OUTPUT);
pinMode(m4, OUTPUT);
}
void  backward(){
  digitalWrite(m1, HIGH); //TURN
 digitalWrite(m2, LOW);
 digitalWrite(m3, LOW);
 digitalWrite(m4, HIGH);
  delay(100);
}
void forward(){
 digitalWrite(m1, LOW); //TURN
  digitalWrite(m2, HIGH);
 digitalWrite(m3, HIGH);
 digitalWrite(m4, LOW);
 delay(100);
}
void left(){
   digitalWrite(m1, LOW);
 digitalWrite(m2, HIGH);
 digitalWrite(m3, LOW);
 digitalWrite(m4, HIGH);
 delay(100);
}
void right(){
  digitalWrite(m1, HIGH);
 digitalWrite(m2, LOW);
 digitalWrite(m3, HIGH);
 digitalWrite(m4, LOW);
   delay(100);
}
void stop(){
  digitalWrite(m1, LOW); //TURN
 digitalWrite(m2, LOW);
 digitalWrite(m3, LOW);
 digitalWrite(m4, LOW);
 delay(100);
}
void dist(){
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration= pulseIn(echopin,HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
  delay(10);
}

void loop() {  
  dist();
  forward();
  while(distance<=15){
    stop();
    backward();
    left();
    dist();
    Serial.println("MOTOR STOP");
    if (distance > 15) {
      break;
    }
  }
}

