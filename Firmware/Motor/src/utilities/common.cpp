#include <utilities/common.h>

int saturate(int value,int min,int max,int dead_zone){
    if(value>max)value=max;
    else if(value<min)value=min;
    else if(value<dead_zone && value > 0)value=0;
    else if(value>-dead_zone && value < 0)value = 0;
    return value;
}