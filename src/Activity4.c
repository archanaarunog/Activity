//#include<Activity4.h>
#include<avr/io.h>
#include<string.h>

#define BAUD 9600
#define F_CPU 16000000
#define BAUD_RATE ((F_CPU)/(BAUD*16UL)-1)
/**
 * @brief initialising the ports for USART
 * 
 */

void USART_init()
{
    UBRR0H = (BAUD_RATE>>8); // set baud rate to register
    UBRR0L = BAUD_RATE;

    UCSR0C = (1<<UCSZ01) | (1<<UCSZ00); // set syn com for 8 bit tx
    UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) | (1<<TXCIE0); //enable transmitter and reciever
}
/**
 * @brief To write the data 
 * 
 * @param data 
 */

void write(char data)
{
    while(!(UCSR0A & (1<<UDRE0)))
    {

    }
    UDR0=data;
}
/**
 * @brief Read the data and go to write function and display message
 * 
 * @param data 
 */
void Display(uint16_t data)
{
    int i=0;
    if(data>=0 && data<=200)
    {
        unsigned char read[]="Temperature is 20 Degree Celcius";
        i=0;
        while(read[i]!=0)
        {
            write(read[i]);
            i++;
        }
    }
    else if(data>=210 && data<=500)
    {
        unsigned char read[]="Temperature is 25 Degree Celcius";
        i=0;
        while(read[i]!=0)
        {
            write(read[i]);
            i++;
        }
    }
    if(data>=510 && data<=700)
    {
        unsigned char read[]="Temperature is 29 Degree Celcius";
        i=0;
        while(read[i]!=0)
        {
            write(read[i]);
            i++;
        }
    }
    if(data>=710 && data<=1024)
    {
        unsigned char read[]="Temperature is 33 Degree Celcius";
        i=0;
        while(read[i]!=0)
        {
            write(read[i]);
            i++;
        }
    }
    if(data>710 && data<=1024)
    {
        unsigned char read[]="Temperature is 20 Degree Celcius";
        i=0;
        while(read[i]!=0)
        {
            write(read[i]);
            i++;
        }
    }
}
