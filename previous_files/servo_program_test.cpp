#include <Arduino.h>
#include <ESP32Servo.h>

#define ServoPin 23

Servo servo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(ServoPin, 550, 2400);
  servo.write(90);
}

int current_angle = 90;


void loop() {
  // put your main code here, to run repeatedly:

  // ask user to input angle, and use that integer to control servo



  /*
  For our servo, the range of angle is 0-180

  For the head to turn right, set it towards 0
  For the head to turn left, set it towards 180

  While we want it to face exactly farward (90), we can set it to 90
  */
  
  Serial.println("Please input angle:");
  while(Serial.available() == 0);
  int target_angle = Serial.parseInt();
  Serial.print("Angle is: ");
  Serial.println(target_angle);

  // instead of direct turning, we allow it to move only 10 degree each time

  if (current_angle < target_angle){
    for (int i = current_angle; i <= target_angle; i++){
      servo.write(i);
      delay(20);
    }
  }
  else{
    for (int i = current_angle; i >= target_angle; i--){
      servo.write(i);
      delay(20);
    }
  }

  current_angle = target_angle;

  delay(1000);

}