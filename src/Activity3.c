#include <avr/io.h>
#include<avr/interrupt.h>
/**
 * @brief To generate the PWM 
 * 
 */
void Activity3()
{
    unsigned volatile int read_ADC_val;
    // selecting timer 0 with pd6 channel
    DDRD|=(1<<PD6); // SET PIN PORT D

    TCCR0A|=(1<<COM0A1)|(1<<WGM01) |(1<<WGM00);
    // TIMER 0 control reg A, non inverting mode com0, fast pwm wgm

    // timer 0 control reg B, prescalar 64, frequency clk =16Mhz

    TCCR0B|=(1<<CS01)|(1<<CS00);

    TCNT0=0;
    while(1)
    {
        Activity1();
        read_ADC_val=read_ADC();
        if(read_ADC_val > 0 && read_ADC_val <= 200)
        {
            OCR0A=204;

        }
        else if(read_ADC_val >210 && read_ADC_val <=500)
        {
             OCR0A=409;

        }
        else if(read_ADC_val >510 && read_ADC_val <=700)
        {
             OCR0A=716;

        }
        else if(read_ADC_val >710 && read_ADC_val <=1024)
        {
             OCR0A=972;

        }
        else
            OCR0A=0;
    }

}
