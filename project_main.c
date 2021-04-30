#include <avr/io.h>

int main(void)
{
    while(1)
    {
    int status=0;
    status= Activity1();
    if(status==1)
    {
        uint16_t temp=0;
        temp=read_ADC(0);
        Activity3();
        Display(temp);

    }
    }
    return 0;
}

}
