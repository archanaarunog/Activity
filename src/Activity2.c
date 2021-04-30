#include <avr/io.h>
/**
 * @brief To do the ADC conversion initiallising the ports
 * 
 */
void init_ADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA =(1<<ADEN) | (7<<ADPS0);
}
/**
 * @brief Read the adc and select the corresponding channels
 * 
 * @param ch 
 * @return uint16_t 
 */

uint16_t read_ADC(uint8_t ch)
{
    init_ADC();
    ADMUX &=0xf8; // clear the pins of adc
    ch &= 0b00000111; //channel value set
    ADMUX |=ch; // assign value of mux based on channel
    ADCSRA |=(1<<ADSC); // strat adc conversion
    while(!(ADCSRA&(1<<ADIF))); // till last bit check interrupt
    ADCSRA |=(1<<ADIF); // set int flag
    return(ADC); // return adc value
}

