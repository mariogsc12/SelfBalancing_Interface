#include <Arduino.h>
#include <utilities/Metro.h>
#include <hardware/encoder.h>

#define Encoder_A 22
#define Encoder_B 23

Metro sampleTime = Metro(100);  
Encoder encoder(Encoder_A,Encoder_B);


int computeAngle();
void encoderCallback();

int angle=0;
int encoderPulses=0;

void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(Encoder_A),encoderCallback, RISING);
}

void loop() {

  if (sampleTime.check() == 1) 
  {
    Serial.print(angle);
    angle = computeAngle();
  }
  
}



int computeAngle(){
  return encoder.getCount();
}

void encoderCallback()
{
  encoder.callback();
}