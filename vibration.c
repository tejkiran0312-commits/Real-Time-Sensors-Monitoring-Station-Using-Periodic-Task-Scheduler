#include <LPC21xx.H>
#include "hearder.h"
#define VIBR ((IOPIN0>>6)&1)
void vibrator_sensor()
{
if(VIBR==0)
{
uart0_tx_string("VBT:ON\r\n");
}
else
{
uart0_tx_string("VBT:OFF\r\n");
}
}
