#include <Arduino.h>
#include <ps5Controller.h>
#include "config.h"
#include "Motor.h"

Motor lift(35, 32, MAX_RPM);

const int testSpeed = 5; // ความเร็วสำหรับทดสอบ

void setup() {
  Serial.begin(115200);

  ps5.begin(MAC_PS5);
  Serial.println("รอการเชื่อมต่อจอย PS5...");
}

void loop() {
  if (!ps5.isConnected()) {
    lift.run(0);
    return; 
  }

  if (ps5.Up()) {
    lift.run(testSpeed);
  } 
  else if (ps5.Down()) {
    lift.run(-testSpeed);
  } 
  else {
    lift.run(0);
  }

  delay(20);
}