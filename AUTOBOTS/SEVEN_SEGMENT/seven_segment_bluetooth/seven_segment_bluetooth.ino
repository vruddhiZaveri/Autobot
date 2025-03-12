#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 12); // RX (pin 2), TX (pin 12)

#define segA 3
#define segB 4
#define segC 5
#define segD 6
#define segE 7
#define segF 8
#define segG 13

char data = 0;

void setup() {
    Serial.begin(9600);         // For debugging via Serial Monitor
    bluetooth.begin(9600);      // Initialize Bluetooth communication

    // Configure all segment pins as outputs and set them to OFF
    pinMode(segA, OUTPUT);
    pinMode(segB, OUTPUT);
    pinMode(segC, OUTPUT);
    pinMode(segD, OUTPUT);
    pinMode(segE, OUTPUT);
    pinMode(segF, OUTPUT);
    pinMode(segG, OUTPUT);

    // Turn off all segments initially
    turnOffAllSegments();
}

void loop() {
    // Check for incoming Bluetooth data
    if (bluetooth.available() > 0) {
        data = bluetooth.read();    // Read the incoming data from Bluetooth
        Serial.println(data);       // Debug output on the Serial Monitor

        // Only process valid digit characters
        if (data >= '0' && data <= '9') {
            displayDigit(data);     // Display the corresponding digit
        } else {
            turnOffAllSegments();   // Turn off all segments for invalid data
        }
    }
}

void turnOffAllSegments() {
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
}

void displayDigit(char digit) {
    // Turn off all segments before updating
    turnOffAllSegments();

    switch (digit) {
        case '0':
            digitalWrite(segA, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segE, LOW);
            digitalWrite(segF, LOW);
            // segG remains HIGH (off)
            break;
        case '1':
            digitalWrite(segB, LOW);
            digitalWrite(segC, LOW);
            break;
        case '2':
            digitalWrite(segA, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segE, LOW);
            digitalWrite(segG, LOW);
            break;
        case '3':
            digitalWrite(segA, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segG, LOW);
            break;
        case '4':
            digitalWrite(segB, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segF, LOW);
            digitalWrite(segG, LOW);
            break;
        case '5':
            digitalWrite(segA, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segF, LOW);
            digitalWrite(segG, LOW);
            break;
        case '6':
            digitalWrite(segA, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segE, LOW);
            digitalWrite(segF, LOW);
            digitalWrite(segG, LOW);
            break;
        case '7':
            digitalWrite(segA, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segC, LOW);
            break;
        case '8':
            digitalWrite(segA, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segE, LOW);
            digitalWrite(segF, LOW);
            digitalWrite(segG, LOW);
            break;
        case '9':
            digitalWrite(segA, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segF, LOW);
            digitalWrite(segG, LOW);
            break;
    }
}
