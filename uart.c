#include<lpc21xx.h>
#include "hearder.h"
void uart0_init(unsigned int baud)
{
unsigned int pclk,result=0;
if(VPBDIV==0x0)
pclk=15000000;
if(VPBDIV==0x01)
pclk=60000000;
if(VPBDIV==0x02)
pclk=30000000;
result=pclk/(16*baud);
PINSEL0|=0x05;
U0LCR=0x83;
U0DLL=result&0xff;
U0DLM=(result>>8)&0xff;
U0LCR=0x03;
}
#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}

#define RDR (U0LSR&1)
unsigned char uart0_rx()
{
while(RDR==0);
return U0RBR;
}

void uart0_tx_string(char *p)
{
while(*p!=0)
{
uart0_tx(*p);
p++;
}
}

void uart0_tx_integer(int adc_val)
{
char a[20];
int i;
if(adc_val==0)
{
uart0_tx('0');
        return;
}
if(adc_val<0)
{
uart0_tx('-');
adc_val=-adc_val;
}
for(i=0;adc_val;adc_val=adc_val/10,i++)
{
a[i]=adc_val%10+48;
}
for(i=i-1;i>=0;i--)
uart0_tx(a[i]);
}


void uart0_tx_float(float adc_val)
{
int num;
if(adc_val<0)
{
adc_val=-adc_val;
uart0_tx('-');
}
if(adc_val==0)
{
uart0_tx_string("0.0");
return;
}
num=adc_val;
uart0_tx_integer(num);
uart0_tx('.');
num=(adc_val-num)*1000000;
uart0_tx_integer(num);
}

