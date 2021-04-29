#include <avr/io.h>
void init_port()
{
    DDRB |=(1<<PB0); // set output pin for led Port b pin 0
    DDRD&=~(1<<PD2); //clear bit for input pin button
    PORTD|=(1<<PD2); //set bit at high
    DDRD&=~(1<<PD3); //clear bit for input pin heater
    PORTD|=(1<<PD3); //set bit at high
}

int Activity1(void)
{
    init_port();
       while(1)
    {

       if(!(PIND&(1<<PD2))&&!(PIND&(1<<PD3))) //switch press)
        {
        PORTB|=(1<<PB0);
        return 1;
        }
        else
        {
        PORTB&=~(1<<PB0);
        return 0;
        }
    }
}
