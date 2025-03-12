#include<SoftwareSerial.h>
char x;
int button = 10;
int count =0;
SoftwareSerial Bluetooth(4,5);
void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT_PULLUP);
  Bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code he
  if(Bluetooth.available()>0){
  int val = digitalRead(button);
  Serial.println(val);
  Bluetooth.println(val);
  count++;
  Serial.println(count);
  
  }
}
