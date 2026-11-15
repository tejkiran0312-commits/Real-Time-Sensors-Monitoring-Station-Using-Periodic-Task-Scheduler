#include <LPC21xx.H>
#include "hearder.h"
int temperator_sensor()
{
int temp,
adc_val2=adc_read(2);
temp=(adc_val2*3.3*100)/1023;
return temp;
}
