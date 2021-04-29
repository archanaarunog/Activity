#include <avr/io.h>

int main()
{
    int status=0;
    status= Activity1();
    if(status==1)
    {
        uint16_t sensor=0;
        sensor=read_ADC(0);
        Activity3(sensor);
        Display(sensor);
    }

    return 0;

}
