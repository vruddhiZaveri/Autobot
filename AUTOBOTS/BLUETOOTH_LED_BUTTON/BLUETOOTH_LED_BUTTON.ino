#include<SoftwareSerial.h>
char x;
int LED1 = 8;
int LED2 = 9;
int LED3 = 10;
SoftwareSerial Bluetooth(4,5);
void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
Bluetooth.begin(9600);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Bluetooth.available()>0)
{
  x = Bluetooth.read();
  Serial.write(x);
  if(x=='a')
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    delay(1000);
  }
   else if(x=='b')
 {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    delay(1000);
  }
 else if(x=='c')
  {
     digitalWrite(LED1, LOW);
     digitalWrite(LED2, LOW);
     digitalWrite(LED3, HIGH);
     delay(1000);
   }
}
  else 
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    }

}





