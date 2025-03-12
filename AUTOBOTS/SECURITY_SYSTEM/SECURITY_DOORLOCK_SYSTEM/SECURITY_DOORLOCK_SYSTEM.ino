#include<Adafruit_NeoPixel.h>
#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(3,2);
#define PIN 4
#define NUMPIXELS 10
char Bt_input;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS,PIN,NEO_GRB+NEO_KHZ800);
int delayVal=50;

int colors[][3]={
  {255,0,0},
  {0,225,0},
  {0,0,225},
  {255,225,0},
  {0,225,225},
  {255,0,225}
};

void setup(){
  Bluetooth.begin(9600);
  Serial.begin(9600);
  pixels.begin();
}

void setColor(int r, int g, int b){
  for(int i=0;i<2;i++){
    pixels.setPixelColor(i,pixels.Color(r,g,b));
    pixels.show();
    delay(delayVal);
  }
}

void displayRed(){
  for(int i=0;i<NUMPIXELS;i++){
    setColor(225,0,0);
    pixels.clear();
  }
  }
  void displayBlue(){
  for(int i=0;i<NUMPIXELS;i++){
    setColor(0,0,225);
    pixels.clear();

  }
  }
  void displayGreen(){
  for(int i=0;i<NUMPIXELS;i++){
    setColor(0,225,0);
    pixels.clear();
  }
  }
  
void Stop(){
  
    setColor(0,0,0);
    pixels.clear();
  }

void loop(){
  if(Bluetooth.available()>0){
    Bt_input = Bluetooth.read();
    Serial.println(Bt_input);
    if(Bt_input=='T'){
      Serial.print("correct");
      displayGreen();
      delay(1);
    }
    else if (Bt_input=='S'){
      Serial.print("stopped");
      Stop();
    }
    else if (Bt_input=='R'){
      Serial.print("incorrect");
      displayRed();
      // Stop();
    }
    else{
      Serial.print("incorrect");
      displayRed();
    }
  }
}



