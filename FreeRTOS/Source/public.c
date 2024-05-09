#include "public.h"

//void Delay(void)
//{
//    volatile uint32_t delay = 0x02ff0;
//    while (--delay);
//}



void Delay2(volatile uint32_t delay)
{
    while (--delay);
}
