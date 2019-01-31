#include <Arduino.h>

class Display{
    public:
    int port = 0;

    void setup(int p)
    {
        port = p;
        pinMode(port,  OUTPUT);
        pinMode(port+1,  OUTPUT);
        pinMode(port+2,  OUTPUT);
        pinMode(port+3,  OUTPUT);
        pinMode(port+4,  OUTPUT);
        pinMode(port+5,  OUTPUT);
        pinMode(port+6,  OUTPUT); 
        pinMode(port+7,  OUTPUT);   
        port = p;
    }
    void ManualSet(int p)
    {
        digitalWrite(port + p, HIGH);
    }

    void Yes()
    {
        digitalWrite(port + 1, HIGH);
        digitalWrite(port + 3, HIGH);
        digitalWrite(port + 6, HIGH);
        digitalWrite(port + 7, HIGH);
        
    }
    void No()
    {
        digitalWrite(port + 1, HIGH);
        digitalWrite(port + 2, HIGH);
        digitalWrite(port + 3, HIGH);

    }
    void Clear()
    {
        
        digitalWrite(port + 0, LOW);
        digitalWrite(port + 1, LOW);
        digitalWrite(port + 2, LOW);
        digitalWrite(port + 3, LOW);
        digitalWrite(port + 4, LOW);
        digitalWrite(port + 5, LOW);
        digitalWrite(port + 6, LOW);
        digitalWrite(port + 7, LOW);
    }
};