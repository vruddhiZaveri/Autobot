#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);
char BT_input;
int m1=4;//M1-FORWARDS
int m2=5;//M1-BACWARDS
int m3=6;//M2-BACKWARDS
int m4=7;//M2-FORWARDS

void setup() {
  // put your setup code here, to run once:
  Bluetooth.begin(9600);
  Serial.begin(9600);
pinMode(m1, OUTPUT);
pinMode(m2, OUTPUT);
pinMode(m3, OUTPUT);
pinMode(m4, OUTPUT);

}

void loop() {
//  put your main code here, to run repeatedly:
if (Bluetooth.available()>0){
BT_input=Bluetooth.read();
Serial.println(BT_input);
if(BT_input=='R'){
 digitalWrite(m1, HIGH);
 digitalWrite(m2, LOW);
 digitalWrite(m3, HIGH);
 digitalWrite(m4, LOW);
   delay(100);
}
else if(BT_input=='L'){

 digitalWrite(m1, LOW);
 digitalWrite(m2, HIGH);
 digitalWrite(m3, LOW);
 digitalWrite(m4, HIGH);
 delay(100);
}

else if(BT_input=='F'){

 digitalWrite(m1, HIGH); //TURN
 digitalWrite(m4, HIGH);
 digitalWrite(m2, LOW);
 digitalWrite(m3, LOW);
  delay(100);
}
else if(BT_input=='B'){
 digitalWrite(m2, HIGH);
 digitalWrite(m3, HIGH);
 digitalWrite(m1, LOW); //TURN
 digitalWrite(m4, LOW);
 delay(100);
}
else if (BT_input=='S') {
digitalWrite(m1, LOW); //TURN
 digitalWrite(m2, LOW);
 digitalWrite(m3, LOW);
 digitalWrite(m4, LOW);
 delay(100);
}
// else{
//   digitalWrite(m1, LOW); //TURN
//  digitalWrite(m2, LOW);
//  digitalWrite(m3, LOW);
//  digitalWrite(m4, LOW);
//  delay(100);
// }
}


}
