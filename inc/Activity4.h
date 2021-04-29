#ifndef ACTIVITY4_H_INCLUDED
#define ACTIVITY4_H_INCLUDED

void USART_init();
char USART_read();
void USART_write(char data);
void write_string(char *string);
void Activity4(char *data);

#endif // ACTIVITY4_H_INCLUDED