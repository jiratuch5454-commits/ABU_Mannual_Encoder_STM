#include <Arduino.h>
#include <ps5Controller.h>
#include "config.h"
#include "Motor.h"

Motor lift(25, 32, MAX_RPM);

const int testSpeed = 130; // ความเร็วสำหรับทดสอบ

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
    Serial.println("ยกขึ้น");
  } 
  else if (ps5.Down()) {
    lift.run(-testSpeed);
    Serial.println("ยกลง");
  } 
  else {
    lift.run(0);
  }

  delay(20);
}