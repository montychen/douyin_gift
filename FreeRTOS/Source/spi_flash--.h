#ifndef _SPIFLASH_H_
#define _SPIFLASH_H_

#include "public.h"


u16 W25Q64_ReadID(void);
void SPI_WriteByte(uint8_t dat);
u8 SPI_ReadWriteOneByte(uint8_t dat);
void SPI_Init(void);

#endif
