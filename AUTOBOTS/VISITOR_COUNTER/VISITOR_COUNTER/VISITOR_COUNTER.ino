#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
SoftwareSerial Bluetooth(2,3);
int PIRsensor = 4;
const int rs= 8,en=9,d4=10,d5=11,d6=12,d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int counter=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Bluetooth.begin(9600);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("Visitor Counter");
pinMode(PIRsensor,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensor_val=digitalRead(PIRsensor);
if(Bluetooth.available()>0){
  int data=Bluetooth.read();
  if(data=="0"){
    counter==0;
  }
}
  if(sensor_val==1){
    counter+=1;
    Bluetooth.println(counter);
    lcd.setCursor(0,1);
    lcd.print("Count-");
    lcd.setCursor(9,1);
    lcd.print(counter);
    lcd.print("Count-");
    Serial.println(counter);
    Bluetooth.println(counter);

}

delay(1000);
}
