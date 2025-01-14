#include <utilities/utilites.h>
#include <config/definitions.h>
#include <Arduino.h>

int scaleRcSignal(int value, RC_Signal *rc_signal, int channel)
{
    int id = channel - 1;
    return map(value,rc_signal[id].PwmMin,rc_signal[id].PwmMax,-100,100);
}