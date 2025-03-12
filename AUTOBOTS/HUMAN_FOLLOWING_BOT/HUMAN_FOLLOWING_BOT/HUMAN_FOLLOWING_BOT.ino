// #include<SoftwareSerial.h>
// SoftwareSerial Bluetooth(2,3);
// int echopin =4;
// int trigpin =5;
// long duration;
// int distance;
// char BT_input;
// int m1=8;
// int m2=9;
// int m3=10;
// int m4=11;
// void setup() {
//   // put your setup code here, to run once:
// Bluetooth.begin(9600);
// Serial.begin(9600);
// pinMode(echopin, INPUT);
// pinMode(trigpin, OUTPUT);
// pinMode(m1, OUTPUT);
// pinMode(m2, OUTPUT);
// pinMode(m3, OUTPUT);
// pinMode(m4, OUTPUT);
// }
// void forward(){
//   digitalWrite(m1,LOW);
//   digitalWrite(m2,HIGH);
//   digitalWrite(m3,HIGH);
//   digitalWrite(m4,LOW);
// }

// void backward(){
//   digitalWrite(m1,HIGH);
//   digitalWrite(m2,LOW);
//   digitalWrite(m3,LOW);
//   digitalWrite(m4,HIGH);
// }

// void left(){
//   digitalWrite(m1,LOW);
//   digitalWrite(m2,HIGH);
//   digitalWrite(m3,LOW);
//   digitalWrite(m4,HIGH);
// }

// void right(){
//   digitalWrite(m1,HIGH);
//   digitalWrite(m2,LOW);
//   digitalWrite(m3,HIGH);
//   digitalWrite(m4,LOW);
// }

// void stop(){
//   digitalWrite(m1,LOW);
//   digitalWrite(m2,LOW);
//   digitalWrite(m3,LOW);
//   digitalWrite(m4,LOW);
// }


// void loop() {
//   // put your main code here, to run repeatedly:
//   dist();
//   Serial.println(distance);
//   // delay(10);
//   while(distance > 15){
//     digitalWrite(trigpin,LOW);
//     delayMicroseconds(2);
//     digitalWrite(trigpin, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(trigpin,LOW);
//     duration=pulseIn(echopin,HIGH);
//     distance = duration*0.034/2;
//     Serial.print(distance);
//     // forward();
//     Serial.println("\t MOTOR MOVING");
//   }
//   // else {
//   //    stop();
//   //     Serial.println("MOTOR STOP");


//   // }
// }


// void dist(){
//   digitalWrite(trigpin,LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigpin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigpin,LOW);
//   duration=pulseIn(echopin,HIGH);
//   distance = duration*0.034/2;
// }
#define trigPin 5
#define echoPin 4

long duration;
int distance;
int led1= 13;

int M1 = 8;
int M2 = 9;
int M3 = 10;
int M4 = 11;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1,OUTPUT);

  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(M3,OUTPUT);
  pinMode(M4,OUTPUT);
 
  Serial.begin(9600);
}

void loop ()
{
  sensor();
 
   if (distance<=15)
  {
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
    delay(100);
    
    }

    if (distance>15){
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
    delay(100);  
    }
}

void sensor(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
