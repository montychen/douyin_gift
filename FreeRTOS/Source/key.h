#ifndef _KEY_H_
#define _KEY_H_

#include "public.h"
//#include "adc.h"

#define key1 1
#define key2 2
#define key3 3
#define key4 4

void Key_Init(void);
u16 Key_ADC_GetValue(void);
u16 adc_key_remove_shake(void);
void Key_ADC_Isr(void);


#endif
