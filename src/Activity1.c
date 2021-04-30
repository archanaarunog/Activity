#include <avr/io.h>
#include "Activity1.h"
/**
 * @brief Initialising the pins 
 * 
 */
void init_port()
{
    LED_Port |= LED_Pin; // set output pin for led Port b pin 0
    SetPortD&=~Seat_Pin; //clear bit for input pin button
    Input |=Seat_Pin; //set bit at high
    SetPortD&=~Heater_Pin; //clear bit for input pin heater
    Input|=Heater_Pin; //set bit at high
}

/**
 * @brief Checking whether both heater and seat button is ON
 * 
 * @return int return 1 if both buttons are pressed
 */

int Activity1(void)
{
    init_port();
   // while(1)
    //{
       if(Switch_Press) //switch press both seat and heater
        {
        LED_Output |=LED_Pin;
        return 1;
        }
        else
        {
        LED_Output &=~LED_Pin;
        return 0;
        }
   // }
}
