#include<lpc21xx.h>
#include"hearder.h"
void delay_ms(unsigned int ms)
{
T0PR=14999;
T0TC=T0PC=0;
T0TCR=0X02;
T0TCR=0X01;
while(T0TC<ms);
T0TCR=0X00;
}
void delay_sec(unsigned int sec)
{
T0PR=14999999;
T0TC=T0PC=0;
T0TCR=0X02;
T0TCR=0X01;
while(T0TC<sec);
T0TCR=0X00;
}
