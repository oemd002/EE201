/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <ezOutput.h>
ezOutput led(10); 

int val; 

int trigPin = 9; 
int echoPin = 8; 

int ledValue; 

void setup() {
  pinMode(9, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  Serial.begin(9600);
}

void loop() {
  led.loop(); 

  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int duration_us = pulseIn(echoPin, HIGH); 

  int distance_cm = 0.017 * duration_us; 

  if (distance_cm >= 300) {
    led.blink(500, 500); 
  }
  else if (distance_cm < 300 && distance_cm > 200) {
    led.blink(300, 300); 
  }
  else if (distance_cm <= 200 && distance_cm > 100) {
    led.blink(200, 200); 
  }
  else {
    led.blink(100, 100); 
  }

  

  Serial.println("distance: "); 
  Serial.println(distance_cm); 
}


