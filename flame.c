#include<lpc21xx.h>
#include "hearder.h"
#define FLAME ((IOPIN0>>5)&1)
void FLAME_sensor()
{
if(FLAME==0)
{
        uart0_tx_string("FLAME SENSOR : FIRE DETECTED\r\n");

}
else
{
        uart0_tx_string("FLAME SENSOR : NO FIRE DETECTED\r\n");

}
//uart0_tx_string("\r\n");
}
