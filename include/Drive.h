#include "Arduino.h"
#include "Servo.h"
#include "Acelerometer.h"
#include <string.h>

using namespace std;

class Drive
{
private: 
    double RightServoSpeed = 0;
    double LeftServoSpeed = 0;

    void StopMotor(Servo *S)
    {
        S->writeMicroseconds(1500);
    }
    void SetMotor(Servo *S, int percent)
    {
        S->writeMicroseconds ((1500 + (percent / 100 * 200)));
    }
public:
    //what action is being performed 
    String action = "";

    //left Accelerometer
    Acelerometer *LeftA;

    //Right Accelerometer
    Acelerometer *RightA;

    //make varables for time
    unsigned long StartTime = 0;
    unsigned long SetTime = 0;

    //save the current mak speed
    double percent = 0;

    //make boolean to tell if something is being done
    bool Active = false;

    //make servos
    Servo *Right;
    Servo *Left;

    //constructor
    Drive(Servo R, Servo L, Acelerometer Ra, Acelerometer La)
    {
        //make new servo objects
        Right = &R;
        Left = &L;

        //stop the motors just to be sure
        StopMotor(Right);
        StopMotor(Left);

        //make new accelerometer objects
        RightA = &Ra;
        LeftA = &La;
    }

    //update
    void Update()
    {
        if(Active)
        {
            //is the drive moving forward
            if(action == "forward")
            {
                //check if current operation is complete and possably check for corrections
                if ((millis() - StartTime) > SetTime)
                {
                    StopMotor(Right);
                    StopMotor(Left);
                    StartTime = 0;
                    SetTime = 0;
                    Active = false;
                }else 
                {
                    //check 0.2 correction
                    //check if the right is moving faster than the left
                    if(RightA->GetXAcceleration()-0.2 > LeftA->GetXAcceleration())
                    {
                        //set left speed to full speed
                        LeftServoSpeed = percent;
                        //adjust right servospeed
                        RightServoSpeed--;
                        //set the motors
                        SetMotor(Right, RightServoSpeed);
                        SetMotor(Left, LeftServoSpeed);
                        //check if the left is moving faster than the right
                    }else if(RightA->GetXAcceleration() < LeftA->GetXAcceleration()-0.2)
                    {
                        //set right speed to full speed
                        RightServoSpeed = percent;
                        //adjust left servo speed
                        LeftServoSpeed--;
                        //set the motors
                        SetMotor(Right, RightServoSpeed);
                        SetMotor(Left, LeftServoSpeed);
                        
                    }else 
                    {
                        
                    }
                }

            //is the drive moving backwrd?
            }else if (action == "backward")
            {
                //check 0.2 correction
                    //check if the right is moving faster than the left
                    if(RightA->GetXAcceleration()-0.2 < LeftA->GetXAcceleration())
                    {
                        //set left speed to full speed
                        LeftServoSpeed = percent;
                        //adjust right servospeed
                        RightServoSpeed--;
                        //set the motors
                        SetMotor(Right, RightServoSpeed);
                        SetMotor(Left, LeftServoSpeed);
                        //check if the left is moving faster than the right
                    }else if(RightA->GetXAcceleration() > LeftA->GetXAcceleration()-0.2)
                    {
                        //set right speed to full speed
                        RightServoSpeed = percent;
                        //adjust left servo speed
                        LeftServoSpeed--;
                        //set the motors
                        SetMotor(Right, RightServoSpeed);
                        SetMotor(Left, LeftServoSpeed);
                        
                    }else 
                    {
                        
                    }
            //is the drive moving left?
            }else if(action == "left")
            {
                if ((millis() - StartTime) > SetTime)
                {
                    StopMotor(Right);
                    StopMotor(Left);
                    StartTime = 0;
                    SetTime = 0;
                    Active = false;
                }
            //is the drive moving right?
            }else if(action == "right")
            {
                if ((millis() - StartTime) > SetTime)
                {
                    StopMotor(Right);
                    StopMotor(Left);
                    StartTime = 0;
                    SetTime = 0;
                    Active = false;
                } 
            }else
            {
            }
            
        }
    }

    //move forward
    bool forward(int percent, int Time)
    {
    if (true)
    {
        //StartServos
        SetMotor(Right, -percent);
        SetMotor(Left, percent);
                
        //save the server speed
        RightServoSpeed = -percent;
        LeftServoSpeed = percent;

        //set time stuff and set active and action
        StartTime = millis();
        SetTime = Time;
        Active = true;
        action = "forward";

        return true;
    }
    else
        return false;
    }

    //move backward
    bool backward(int percent, int Time)
    {
    if (!Active)
    {
        //StartServos
        SetMotor(Right, percent);
        SetMotor(Left, -percent);
        
        //save the server speed
        RightServoSpeed = percent;
        LeftServoSpeed = -percent;

        //set time stuff and set active
        StartTime = millis();
        SetTime = Time;
        Active = true;
        action = "backward";

        return true;
    }
    else
        return false;
    }

    //turn left
    bool left(int percent, int Time)
    {
    if (!Active)
    {
        //StartServos
        SetMotor(Right, -percent);
        SetMotor(Left, -percent);
        
        //save the server speed
        RightServoSpeed = -percent;
        LeftServoSpeed = -percent;

        //set time stuff and set active
        StartTime = millis();
        SetTime = Time;
        Active = true;
        action = "left";

        return true;
    }
    else
        return false;
    }

    //turn right
    bool right(int percent, int Time)
    {
    if (!Active)
    {
        //StartServos
        SetMotor(Right, percent);
        SetMotor(Left, percent);
        
        //save the server speed
        RightServoSpeed = percent;
        LeftServoSpeed = percent;

        //set time stuff and set active
        StartTime = millis();
        SetTime = Time;
        Active = true;
        action = "right";

        return true;
    }
    else
        return false;
    }
    bool attach(int R, int L)
    {
        Right->attach(R);
        Left->attach(L);

        return true;
    }

    bool SetAcelerometers(int Rx, int Ry, int Lx, int Ly)
    {
        return true;
    }

    bool Stop()
    {
        StopMotor(Right);
        StopMotor(Left);
        return true;
    }
};