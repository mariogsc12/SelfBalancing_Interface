#include <Arduino.h>

class Encoder{
    private:
        const int PIN_A;
        const int PIN_B;
        int counter;
        int angle;
        int pulesPerRevolution;
    public:
        Encoder(const int, const int);
        void callback();
        void initialize();
        int getCount();
        void computeAngle();
        int getAngle();
};