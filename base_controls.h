#ifndef base_h
#define base_h
#include "base.h"
#endif
class base_controls : public base
{

  public:
    int leftMotorForward = 5;  // left motors forward
    int leftMotorReverse = 4;  // left motors reverse
    int rightMotorForward = 7; // right motors forward
    int rightMotorReverse = 6; // right motors reverse

    int echoPin = 9;    // attach pin D9 Arduino to pin Echo of HC-SR04
    int trigPin = 8;    // attach pin D8 Arduino to pin Trig of HC-SR04

    long duration;      // duration of soundwave travel
    int distance;       // calculated distance using formula: duration * 0.034 / 2

    void forwards();    // moves forwards
    void backwards();   // moves backwards
    void left();        // moves left
    void right();       // moves right
    void stop();        // stop or idle (no input)

    void donut();       // moves in a circle
    int getDistance();  // calculates distance
    void avoid(int distance);   // avoids nearby obstacles
};