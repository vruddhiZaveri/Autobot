#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(4,5);
char data=0;
int m1=10;
int m2=11;
void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
   if(Bluetooth.available()>0)
   {
    data=Bluetooth.read();
    Serial.print(data);

    if(data=='1')
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }  
  else if(data=='2')
  {
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }
    else if(data=='3')
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  }
   }
}
