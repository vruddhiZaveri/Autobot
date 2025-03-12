
int LED=10;      //LED is connected to digital pin number 10
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);         //turn on LED
  delay(1000);                    //Wait for 1 sec
  digitalWrite(LED,LOW);          //turn off LED
  delay(1000);                    //Wait for 1 sec

}
