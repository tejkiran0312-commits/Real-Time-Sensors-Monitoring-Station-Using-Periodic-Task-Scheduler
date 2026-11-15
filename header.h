#include <LPC21xx.H>
void delay_ms(unsigned int);
void delay_sec(unsigned int);
int LDR_sensor(void);
void adc_init(void);
int adc_read(unsigned int);
void uart0_init(unsigned int);
void uart0_tx(unsigned char);
unsigned char uart0_rx(void);
void uart0_tx_string(char *);
void uart0_tx_integer(int);
void uart0_tx_float(float);
void FLAME_sensor(void);
int temperator_sensor(void);
int potentiometer_sensor(void);
void timer0_init(void);
void timer0_handler(void)__irq;
void config_vect_timer0(void);
void vibrator_sensor(void);
