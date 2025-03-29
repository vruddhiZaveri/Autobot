#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial Bluetooth(8,9);
char BT_input;
Servo myservo;
int pos =0;
int m1=5;//M1-FORWARDS
int m2=4;//M1-BACWARDS
int m3=7;//M2-BACKWARDS
int m4=6;//M2-FORWARDS

void setup() {
  // put your setup code here, to run once:
  Bluetooth.begin(9600);
  Serial.begin(9600);
pinMode(m1, OUTPUT);
pinMode(m2, OUTPUT);
pinMode(m3, OUTPUT);
pinMode(m4, OUTPUT);
myservo.attach(3);

}

void loop() {
//  put your main code here, to run repeatedly:
if (Bluetooth.available()>0){
BT_input=Bluetooth.read();
Serial.println(BT_input);
if(BT_input=='F'){        //FORWARD 
 digitalWrite(m1, HIGH);
 digitalWrite(m2, LOW);
 digitalWrite(m3, HIGH);
 digitalWrite(m4, LOW);
   delay(10);
}
else if(BT_input=='B'){     //BACKWARD
 digitalWrite(m1, LOW);
 digitalWrite(m2, HIGH);
 digitalWrite(m3, LOW);
 digitalWrite(m4, HIGH);
 delay(10);
}

else if(BT_input=='L'){     //LEFT

 digitalWrite(m1, HIGH);
 digitalWrite(m2, LOW);
 digitalWrite(m3, LOW);
 digitalWrite(m4, HIGH);
  delay(10);
}
else if(BT_input=='R'){     //RIGHT
 digitalWrite(m1, LOW); 
 digitalWrite(m2, HIGH);
 digitalWrite(m3, HIGH);
 digitalWrite(m4, LOW);
 delay(10);
}
else if (BT_input=='S') {     //STOP
digitalWrite(m1, LOW); 
 digitalWrite(m2, LOW);
 digitalWrite(m3, LOW);
 digitalWrite(m4, LOW);
 delay(10);
}

else if(BT_input=='W') {      //GRAB
  myservo.write(90);
}
else if(BT_input=='w') {     //LEAVE
  myservo.write(0);
}
}
}
