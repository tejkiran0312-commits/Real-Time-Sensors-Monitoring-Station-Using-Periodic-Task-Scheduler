#include<lpc21xx.h>
#include "hearder.h"
void adc_init()
{
PINSEL1=0x15400000;
ADCR=0x00200400;
}
#define DONE (ADDR>>31&1)
int adc_read(unsigned int ch_num)
{
unsigned int result=0;
ADCR|=(1<<ch_num);
ADCR|=(1<<24);
while(DONE==0);
ADCR^=(1<<24);
ADCR^=(1<<ch_num);
result=((ADDR>>6)&0x3ff);
return result;


}
