#include <Wire.h> // Library for I2C communication
#include <SoftwareSerial.h>// import the serial library
#include "NewPing.h"

#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define MAX_DISTANCE 200

int redLed = 5;
int button = 6;
int distance;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
//SoftwareSerial BT(11, 10); // RX, TX

void setup() {

  
  pinMode(redLed, OUTPUT);  
  pinMode(button, INPUT);

  digitalWrite(redLed, LOW);
  Serial.begin(9600);
  //BT.begin(115200);
}

void loop(){
  
  distance = sonar.ping_cm();

if ((distance > 10) && (distance < 70)){
  Serial.println(1);
  digitalWrite(redLed, HIGH);
  //BT.println(1);
}
else
{
  digitalWrite(redLed, LOW);
}
  delay(20);

if ((digitalRead(button) == HIGH)) {
  //BT.println(2);
  Serial.println(2);
}
delay(600);   

}
