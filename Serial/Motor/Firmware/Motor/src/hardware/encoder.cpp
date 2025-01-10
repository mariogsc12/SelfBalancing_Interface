#include <hardware/encoder.h>


Encoder::Encoder(const int a, const int b):PIN_A(a),PIN_B(b),counter(0),angle(0),pulesPerRevolution(34*28){}

void Encoder::callback()
{
    if (digitalRead(PIN_A) == digitalRead(PIN_B)) {
        counter++;
    } else {
        counter--;
    }
}

void Encoder::initialize()
{
    pinMode(PIN_A, INPUT);
    pinMode(PIN_B, INPUT);
}

int Encoder::getCount()
{
    return counter;
}

void Encoder::computeAngle()
{
    angle = 360 * (counter / pulesPerRevolution);
}

int Encoder::getAngle()
{
    return angle;
}