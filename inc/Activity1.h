#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED

#define LED_Port (DDRB)
#define LED_Output (PORTB)
#define LED_Pin ((1<<PB0))
#define SetPortD (DDRD)
#define Input (PORTD)
#define Seat_Pin ((1<<PD2))
#define Heater_Pin ((1<<PD3))
#define Switch_Press (!(PIND&(1<<PD2))&&!(PIND&(1<<PD3)))
void init_port();
int Activity1();


#endif // ACTIVITY1_H_INCLUDED
