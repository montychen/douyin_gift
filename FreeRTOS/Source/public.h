#ifndef _PUBLIC_H_
#define _PUBLIC_H_

#include "stdio.h"
#include "apm32f0xx.h"
#include "apm32f0xx_adc.h"
#include "apm32f0xx_gpio.h"
#include "apm32f0xx_rcm.h"
#include "apm32f0xx_misc.h"
#include "apm32f0xx_tmr.h"
#include "apm32f0xx_spi.h"

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;

void Delay2(volatile u32 delay);



#endif
