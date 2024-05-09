#ifndef _DMX_H_
#define _DMX_H_

#include "public.h"

#define DMX_BUF_SIZE       (64)


#define MasterCH    25 //


#define CONSOLE      (0X00)
#define CONSOLE_RDM  (0XCC)
#define MASTER       (0X01)
#define STORE        (0X64)

void USART_Init(void);

#endif
