#include<Adafruit_NeoPixel.h>
#include<SoftwareSerial.h>

SoftwareSerial Bluetooth(4,5);
#define PIN 2
#define NUMPIXELS 10
char BT_input;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS,PIN,NEO_GRB+NEO_KHZ800);
int delayVal=50;

int colors[][3]={
  {255,0,0},
  {0,255,0},
  {0,0,255},
  {225,225,0},
  {0,225,225},
  {225,0,225}
};

void setup() {
  // put your setup code here, to run once:
Bluetooth.begin(9600);
Serial.begin(9600);
pixels.begin();
}

void setColor(int r, int g, int b){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(r,g,b));
    pixels.show();
    delay(delayVal);
  }}


// void displayPattern1(){
//   for (int i =0;i<6; i++){
//     setColor(colors[i][0],colors[i][1],colors[i][2]);

//   }
// }
// void displayPattern2() {
//   for (int i = NUMPIXELS - 1; i >= 0; i--) {
//     setColor(0, 255, 0);                  // Green backward
//   }
//   for (int i = 0; i < NUMPIXELS; i++) {
//     setColor(0, 0, 255);                  // Blue forward
//   }
// }

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
  void displayCyan(){
  for(int i=0;i<NUMPIXELS;i++){
    setColor(0,225,225);
    pixels.clear();
  }
  }
  void displayPurple(){
  for(int i=0;i<NUMPIXELS;i++){
    setColor(225,0,225);
    pixels.clear();
  }
  }
  void displayYellow(){
  for(int i=0;i<NUMPIXELS;i++){
    setColor(225,255,0);
    pixels.clear();
  }
}
  void displayWhite(){
  for(int i=0;i<NUMPIXELS;i++){
    setColor(225,225,225);
    pixels.clear();
  }
}
void Stop(){
  
    setColor(0,0,0);
    pixels.clear();
  }



void loop() {
  // put your main code here, to run repeatedly:
if (Bluetooth.available()) {
    BT_input = Bluetooth.read();          // Read Bluetooth input
    Serial.println(BT_input);

    if (BT_input == 'R') {                // If 'R' is received
      Serial.println("Red Pattern");
      displayRed();
      }
      
    else if (BT_input == 'G') {                // If 'R' is received
      Serial.println("Green Pattern");
      displayGreen();}
      
    else if (BT_input == 'B') {                // If 'R' is received
      Serial.println("Blue Pattern");
      displayBlue();}
      
    else if (BT_input == 'C') {                // If 'R' is received
      Serial.println("Cyan Pattern");
      displayCyan();}
      
    else if (BT_input == 'P') {                // If 'R' is received
      Serial.println("Purple Pattern");
      displayPurple();}
      
    else if (BT_input == 'Y') {                // If 'R' is received
      Serial.println("Yellow Pattern");
      displayYellow();
    }
    else if (BT_input == 'W') {                // If 'R' is received
      Serial.println("White Pattern");
      displayWhite();
    }
    else if (BT_input =='S'){
      Stop();
    }
  }
}
     
    
    
  //   else if (BT_input == 'D') {         // If 'D' is received
  //     Serial.println("Pattern 4");
  //     displayPattern2();
  //   }

  //   pixels.clear();                       // Clear all pixels after the pattern
  

