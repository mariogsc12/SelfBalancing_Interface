#include <hardware/motor.h>

Motor::Motor(const int _IN1, const int _IN2, const int _PWM):
                  PIN_IN1(_IN1)
                , PIN_IN2(_IN2)
                , PIN_PWM(_PWM)
                , dead_zone(70)
                , pulsesPerRevolution(13*34)
{

}

void Motor::initialize(){
    pinMode(PIN_IN1, OUTPUT); 
    pinMode(PIN_IN2, OUTPUT); 
    pinMode(PIN_PWM, OUTPUT); 
}

void Motor::move(int control_action){
    if(control_action>0){
        digitalWrite(PIN_IN1,1);
        digitalWrite(PIN_IN2,0);
    }
    else if(control_action<0){
        digitalWrite(PIN_IN1,0);
        digitalWrite(PIN_IN2,1);
    }
    else{
        digitalWrite(PIN_IN1,0);
        digitalWrite(PIN_IN2,0);
    }
    control_action=abs(saturate(control_action,-255,255,dead_zone));
    analogWrite(PIN_PWM,control_action);
}

int Motor::getPPR()
{
    return pulsesPerRevolution;
}