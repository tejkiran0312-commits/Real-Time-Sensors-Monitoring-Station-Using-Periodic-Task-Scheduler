#include <LPC21xx.H>
#include "hearder.h"
int potentiometer_sensor()
{
unsigned int adc_val2=0,poten_per=0,vout=0;
adc_val2=adc_read(1);
vout=(adc_val2*100)/1023;
poten_per=vout-0.05/0.01;
return poten_per;
}
