#include "Activity3.h"
/**
 * @brief To generate the PWM 
 * 
 */
void Activity3()
{
    unsigned volatile int read_ADC_val;
   TCCR1A|=(1<<COM1A1)|(1<<WGM10)|(1<<WGM11); // FAST MODE 011 SET LAST THREE BITS
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);    // PRESCALAR TO 64
    DDRB|=(1<<PB1);
    while(1)
    {
        read_ADC_val=read_ADC(0);
        if(read_ADC_val > 0 && read_ADC_val <= 200)
        {
            OCR1A=205;
        }
        else if(read_ADC_val >210 && read_ADC_val <=500)
        {
             OCR1A=409;
        }
        else if(read_ADC_val >510 && read_ADC_val <=700)
        {
             OCR1A=716;
        }
        else if(read_ADC_val >710 && read_ADC_val <=1024)
        {
             OCR1A=972;

        }
        else
            OCR1A=0;
    }


}
