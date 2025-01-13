#include <Arduino.h>
#include <utilities/Metro.h>
#include <config/Pinouts.h>
#include <config/datatypes.h>
#include <config/definitions.h>

// -------------------------------------------------- //
// ---------------- GLOBAL VARIABLES ---------------- //

Metro printMetro = Metro(50);

// PWM decoder variables
int g_pwm1 = 0;
int g_pwm3 = 0;
int g_pwm5 = 0;
int g_pwm6 = 0;


SwitchMode g_CurrentMode = MODE_IDLE;
RC_Signal g_RC_Signal[4] = {{1,CH1_PWM_MIN,CH1_PWM_CENTER,CH1_PWM_MAX},
                            {3,CH3_PWM_MIN,CH3_PWM_CENTER,CH3_PWM_MAX},
                            {5,CH5_PWM_MIN,CH5_PWM_CENTER,CH5_PWM_MAX},
                            {6,CH6_PWM_MIN,CH6_PWM_CENTER,CH6_PWM_MAX}};

// -------------------------------------------------- //
// ---------------- FUNCTION HEADERS ---------------- //

void printTask();
void PWMDecoder(const int, int *);
void decodePwm1();
void decodePwm3();
void decodePwm5();
void decodePwm6();
void change_SwitchMode(SwitchMode);
SwitchMode get_SwitchCondition(int, int);



// -------------------------------------------------- //
// ----------------------- MAIN --------------------- //

void setup() {
  Serial.begin(115200); // Serial to PC

  // pwm decoder interrupts
  attachInterrupt(digitalPinToInterrupt(RC_CH1), decodePwm1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RC_CH3), decodePwm3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RC_CH5), decodePwm5, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RC_CH6), decodePwm6, CHANGE);
}

void loop() {
  printTask(); 
}





// -------------------------------------------------- //
// -------------- FUNCTION DEFINITIONS -------------- //

void printTask() {
  if (printMetro.check()) {
    change_SwitchMode(get_SwitchCondition(g_pwm5,g_pwm6));
    Serial.print(g_pwm1);
    Serial.print(',');
    Serial.print(g_pwm3);
    Serial.print(',');
    Serial.print(g_CurrentMode);
    Serial.write(13);
    Serial.write(10);
  }
}


void PWMDecoder(const int CH, int *pwm)
{
  static unsigned long riseTime = micros(); 
  if (digitalRead(CH) == 1) { 
    riseTime = micros();
  }
  else { 
    *pwm = micros() - riseTime;
  }
}


void decodePwm1() {
  PWMDecoder(RC_CH1,&g_pwm1);
}

void decodePwm3() {
  PWMDecoder(RC_CH3,&g_pwm3);
}

void decodePwm5() {
  PWMDecoder(RC_CH5,&g_pwm5);
}

void decodePwm6() {
  PWMDecoder(RC_CH6,&g_pwm6);
}


void change_SwitchMode(SwitchMode desiredMode)
{
  if(desiredMode == g_CurrentMode)
  {
    // DO NOTHING
  }
  else
  {
    if(desiredMode==MODE_UP)
    {
      g_CurrentMode = MODE_UP;
    }
    else if(desiredMode==MODE_MIDDLE)
    {
      g_CurrentMode = MODE_MIDDLE;
    }
    else if(desiredMode==MODE_DOWN)
    {
      g_CurrentMode = MODE_DOWN;
    }
    else
    {
      g_CurrentMode = MODE_ERROR;
    }
  }
}

SwitchMode get_SwitchCondition(int pwm5, int pwm6 )
{
  if((pwm5 > (CH5_PWM_CENTER + RC_THRESHOLD)) && (pwm6 > (CH6_PWM_CENTER + RC_THRESHOLD)))
  {
    return MODE_DOWN;
  }
  else if((pwm5 < (CH5_PWM_CENTER - RC_THRESHOLD)) && (pwm6 < (CH6_PWM_CENTER - RC_THRESHOLD)))
  {
    return MODE_UP;
  }
  else if((((pwm5 > (CH5_PWM_CENTER - RC_THRESHOLD))) && ((pwm5 < (CH5_PWM_CENTER + RC_THRESHOLD)))) && 
          (((pwm6 > (CH6_PWM_CENTER - RC_THRESHOLD))) && ((pwm6 < (CH6_PWM_CENTER + RC_THRESHOLD)))))
  {
    return MODE_MIDDLE;
  }
  else
  {
    return MODE_ERROR;
  }
}