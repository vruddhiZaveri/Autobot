#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);
int tempSensor = A0;  //Sensor connected at A0
int LED1=4; //RED PIN
int LED2=5; //GREEN PIN
int LED3=6; //BLUE PIN
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Bluetooth.begin(9600);
pinMode(tempSensor,INPUT);
pinMode(LED1,OUTPUT); //RED PIN
pinMode(LED2,OUTPUT); //GREEN PIN
pinMode(LED3,OUTPUT); //BLUE PIN
}

void loop() {
  // put your main code here, to run repeatedly:
float Sensor_val =analogRead(tempSensor);

Sensor_val=(Sensor_val*500)/1023;
Bluetooth.println(Sensor_val);  //Sending data
// Bluetooth.println(";"); //Sending data
Serial.println(Sensor_val);
delay(1000);
if(Sensor_val>=30)  //temp->incr
{
  RGB_color(0,225,225);
  delay(1000);
  Serial.println("Temperature is HIGH");
}
else if(Sensor_val<=25)
{
  RGB_color(225,0,0);
  delay(1000);
  Serial.println("Temperature is COLD");
}
else{
  RGB_color(225,0,225);
  delay(1000);
  Serial.println("Temperature is Stable");
}
delay(1000);

}

void RGB_color(int red_val, int green_val, int blue_val){
  analogWrite(LED1, red_val);
  analogWrite(LED2, green_val);
  analogWrite(LED3, blue_val);
}
