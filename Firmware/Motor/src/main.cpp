#include <Arduino.h>
#include <utilities/Metro.h>
#include <hardware/encoder.h>
#include <hardware/motor.h>

#define Encoder_A 22
#define Encoder_B 23
#define Potentiometer 15
#define Motor_PWM 19
#define Motor_InA 18
#define Motor_InB 5


Metro sampleTime = Metro(100);  
Encoder encoder(Encoder_A,Encoder_B);
Motor motor(Motor_InA,Motor_InB,Motor_PWM);

int computeAngle();
void encoderCallback();

int angle=0;
int potValue = 0;
int controlAction = 0;

void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(Encoder_A),encoderCallback, RISING);
  pinMode(Encoder_A,INPUT);
  pinMode(Encoder_B,INPUT);
  pinMode(Potentiometer,INPUT);
  pinMode(Motor_InA,OUTPUT);
  pinMode(Motor_InB,OUTPUT);
  pinMode(Motor_PWM,OUTPUT);
}

void loop() {

  if (sampleTime.check() == 1) 
  {
    potValue = analogRead(Potentiometer);
    controlAction = map(potValue,0,4095,-255,255);
    motor.move(controlAction);
    angle = computeAngle();
    Serial.print(controlAction);
    Serial.write(",");
    Serial.print(angle);
    Serial.write(13);
    Serial.write(10);
  }
  
}



int computeAngle(){
  int pulses = encoder.getCount();
  int angle = pulses * 360 / (motor.getPPR());
   return angle;
}

void encoderCallback()
{
  encoder.callback();
}