#include <avr/io.h>
#include<avr/interrupt.h>
void Activity3()
{
    unsigned volatile int read_ADC_val;
    // selecting timer 0 with pd6 channel
    DDRD|=(1<<PD6); // SET PIN PORT D

    TCCR0A|=(1<<COM0A1)|(1<<WGM01) |(1<<WGM00);
    // TIMER 0 control reg a, non inv mode com0, fast pwm wgm

    // timer 0 control reg b prescalar 64, f clk =16mhz

    TCCR0B|=(1<<CS01)|(1<<CS00);

    TCNT0=0;
    while(1)
    {
        Activity1();
        read_ADC_val=Activity2();
        if(read_ADC_val > 0 && read_ADC_val <= 200)
        {
            OCR0A=51;
            Activity4("20 deg cel\n");
        }
        else if(read_ADC_val >210 && read_ADC_val <=500)
        {
             OCR0A=102;
        }
        else if(read_ADC_val >510 && read_ADC_val <=700)
        {
             OCR0A=180;
        }
        else if(read_ADC_val >710 && read_ADC_val <=1024)
        {
             OCR0A=250;
        }
    }

}
