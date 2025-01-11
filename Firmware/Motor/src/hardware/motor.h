#include <utilities/common.h>
#include <Arduino.h>

class Motor{
    private:
        const int PIN_IN1;
        const int PIN_IN2;
        const int PIN_PWM;
        const int dead_zone;
        const int pulsesPerRevolution;
    public:
        Motor(const int, const int, const int);
        void initialize();
        void move(int);
        int getPPR();
};