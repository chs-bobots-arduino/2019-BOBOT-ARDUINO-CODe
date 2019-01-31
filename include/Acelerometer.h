#pragma once
#include <Arduino.h>

class Acelerometer
{
public:
    //save pins
    int xPin = 0;
    int yPin = 0;

    //constructure
    Acelerometer(int x, int y){
        xPin = x;
        yPin = y;
        
        pinMode(x, INPUT);
        pinMode(y, INPUT);
    }
    //velocity = distance/time
    //finall distance = time * (acceleration*time + start velocity)
    //period update loop
    int GetXAcceleration()
    {
        
        return (((pulseIn(xPin, HIGH)/ 10) - 500) * 8)+100;
    }
    int GetYAcceleration()
    {
        
        return (((pulseIn(yPin, HIGH)/ 10) - 500) * 8)+100;
    }
};
