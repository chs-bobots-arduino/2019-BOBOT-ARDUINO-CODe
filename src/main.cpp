#include <Arduino.h>
#include "Drive.h"
#include <HardwareSerial.h>
#include "LightSensor.h"
#include "Display.h"
#include "Servo.h"

Servo R;
Servo L;

Acelerometer Ar(2,3);
Acelerometer Al(4,5);

Drive DriveControl(R, L, Ar, Al);

Display display;

LightSensor light(5); 

void setup() {
  display.setup(4);

  Serial.begin(9600);
  
  DriveControl.attach(13,12);
  //DriveControl.forward(100, 100);
  DriveControl.Stop();
   pinMode(A3, INPUT); 

}

void loop() {
  display.Yes();
  Serial.println(analogRead(3));
  Serial.flush();
  delay(100);

  //Serial.print(digitalWrite(10));
  //Serial.print(digitalRead(10));
  //Serial.println("X Acceleration : " + String(Ar.GetXAcceleration()));
  //Serial.println("Y Acceleration : " + String(Ar.GetYAcceleration()));
  delay(1000);
  display.Clear();
  delay(1000);
  //DriveControl.Update();
}