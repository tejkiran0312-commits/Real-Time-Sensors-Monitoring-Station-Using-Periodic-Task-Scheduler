#include<lpc21xx.h>
#include "hearder.h"
int LDR_sensor()
{
int adc_val2,ldr_per;
adc_val2=adc_read(3);
ldr_per=(adc_val2*100)/1023;
return ldr_per;
}
