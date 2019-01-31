#pragma once
#include <Arduino.h>

class LightSensor{
    public:
    int port = 0;
    LightSensor(int port)
    {
        pinMode(port, INPUT);
    }

    double Read()
    {
        return analogRead(port);
    }
};