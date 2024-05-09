/*****************************************************************************
 * Copyright (c) 2019, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Nations' name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY NATIONS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL NATIONS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ****************************************************************************/

/**
 * @file spi_flash.c
 * @author Nations
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#include "spi_flash.h"

/** @addtogroup Utilities
 * @{
 */

/** @addtogroup
 * @{
 */

/** @addtogroup Common
 * @{
 */

/** @addtogroup SPI_FLASH
 * @brief
 * @{
 */

/** @addtogroup SPI_FLASH_Private_Types
 * @{
 */
/**
 * @}
 */

/** @addtogroup SPI_FLASH_Private_Defines
 * @{
 */
/**
 * @}
 */

/** @addtogroup SPI_FLASH_Private_Macros
 * @{
 */
/**
 * @}
 */

/** @addtogroup SPI_FLASH_Private_Variables
 * @{
 */
/**
 * @}
 */

/** @addtogroup SPI_FLASH_Private_Function_Prototypes
 * @{
 */
/**
 * @}
 */

/** @addtogroup SPI_FLASH_Private_Functions
 * @{
 */

/**
 * @brief  DeInitializes the peripherals used by the SPI FLASH driver.
 */


void sFLASH_Init(void)
{
    GPIO_Config_T gpioConfig;
    SPI_Config_T spiConfig;

    /* Enable related clock*/
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_SPI2);
    RCM_EnableAHBPeriphClock(RCM_AHB_PERIPH_GPIOB);
    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_SYSCFG);

    /* Config alter function*/
    GPIO_ConfigPinAF(sFLASH_SPI_SCK_GPIO_PORT, GPIO_PIN_SOURCE_13, GPIO_AF_PIN0);
    GPIO_ConfigPinAF(sFLASH_SPI_MISO_GPIO_PORT, GPIO_PIN_SOURCE_14, GPIO_AF_PIN0);
    GPIO_ConfigPinAF(sFLASH_SPI_MOSI_GPIO_PORT, GPIO_PIN_SOURCE_15, GPIO_AF_PIN0);

    /* config PIN_13->SCK , PIN_15->MOSI*/
    gpioConfig.pin =  sFLASH_SPI_SCK_PIN | sFLASH_SPI_MOSI_PIN | sFLASH_SPI_MISO_PIN;
    gpioConfig.mode = GPIO_MODE_AF;
    //gpioConfig.outtype = GPIO_OUT_TYPE_PP;
    gpioConfig.speed = GPIO_SPEED_50MHz;
    gpioConfig.pupd = GPIO_PUPD_PD;
    GPIO_Config(sFLASH_SPI_SCK_GPIO_PORT, &gpioConfig);

    /* config PIN_6->NSS*/
    gpioConfig.pin =  sFLASH_CS_PIN;
    gpioConfig.outtype = GPIO_OUT_TYPE_PP;
    gpioConfig.speed = GPIO_SPEED_50MHz;
    gpioConfig.pupd = GPIO_PUPD_PU;
    gpioConfig.mode = GPIO_MODE_OUT;
    GPIO_Config(sFLASH_CS_GPIO_PORT, &gpioConfig);
    GPIO_SetBit(sFLASH_CS_GPIO_PORT, sFLASH_CS_PIN);

    /* config PIN_14  MISO*/
//    gpioConfig.pin = sFLASH_SPI_MISO_PIN;
//    gpioConfig.mode = GPIO_MODE_AF;
//    gpioConfig.pupd = GPIO_PUPD_PU;
//    gpioConfig.speed = GPIO_SPEED_50MHz;
//    GPIO_Config(sFLASH_SPI_MISO_GPIO_PORT, &gpioConfig);

    /* SPI RESET*/
    SPI_Reset(sFLASH_SPI);
    SPI_ConfigStructInit(&spiConfig);

    /* SPI configuration*/
    /* Set Clock polarity is Low, but Slave is High*/
    spiConfig.polarity = SPI_CLKPOL_HIGH;

    /* select master mode*/
    spiConfig.mode = SPI_MODE_MASTER;

    /* SPI Clock Phase is 1EDGE, but Slave is 1EDGE*/
    spiConfig.phase = SPI_CLKPHA_2EDGE;

    /* Enable Software slave control */
    spiConfig.slaveSelect = SPI_SSC_ENABLE;

    /* Set SPI BaudRate divider*/
    spiConfig.baudrateDiv = SPI_BAUDRATE_DIV_4;
    /* Set SPI First bit*/
    spiConfig.firstBit = SPI_FIRST_BIT_MSB;

    /* SPI data length*/
    spiConfig.length = SPI_DATA_LENGTH_8B;
    /* SPI CRC length*/
    spiConfig.crcPolynomial = 7;	//CRC值计算的多项式

    /* Set internal slave*/
    SPI_EnableInternalSlave(sFLASH_SPI);
    SPI_Config(sFLASH_SPI, &spiConfig);
    SPI_ConfigFIFOThreshold(sFLASH_SPI, SPI_RXFIFO_QUARTER);

    SPI_Enable(sFLASH_SPI);
		
//		Delay2(0xfffff);
//		sFLASH_CMD(0x66);
//		Delay2(0xffff);
//		sFLASH_CMD(0x99);
//		Delay2(0xfffff);
}




//u8 sFlash_sbyte(u8 dat) {
//        while (SPI_ReadStatusFlag(SPI2, SPI_FLAG_TXBE) == RESET);
//        SPI_TxData8(SPI2, dat);

//        while (SPI_ReadStatusFlag(SPI2, SPI_FLAG_RXBNE) == RESET);
//        return SPI_RxData8(SPI2);
//}
//    



/**
 * @brief  Erases the specified FLASH sector.
 * @param SectorAddr address of the sector to erase.
 */
void sFLASH_EraseSector(uint32_t Addr)
{
    /*!< Send write enable instruction */
    sFLASH_WriteEnable();

    /*!< Sector Erase */
    /*!< Select the FLASH: Chip Select low */
    sFLASH_CS_LOW();
    /*!< Send Sector Erase instruction */
    sFLASH_SendByte(sFLASH_CMD_SE);
    /*!< Send SectorAddr high nibble address byte */
    sFLASH_SendByte((Addr & 0xFF0000) >> 16);
    /*!< Send SectorAddr medium nibble address byte */
    sFLASH_SendByte((Addr & 0xFF00) >> 8);
    /*!< Send SectorAddr low nibble address byte */
    sFLASH_SendByte(Addr & 0xFF);
    /*!< Deselect the FLASH: Chip Select high */
    sFLASH_CS_HIGH();

    /*!< Wait the end of Flash writing */
    sFLASH_WaitForWriteEnd();
}

/**
 * @brief  Erases the specified FLASH sector.
 * @param SectorAddr address of the sector to erase.
 */
void sFLASH_EraseBlock(uint32_t Addr)
{
    /*!< Send write enable instruction */
    sFLASH_WriteEnable();

    /*!< Sector Erase */
    /*!< Select the FLASH: Chip Select low */
    sFLASH_CS_LOW();
    /*!< Send Sector Erase instruction */
    sFLASH_SendByte(sFLASH_CMD_BE);
    /*!< Send SectorAddr high nibble address byte */
    sFLASH_SendByte((Addr & 0xFF0000) >> 16);
    /*!< Send SectorAddr medium nibble address byte */
    sFLASH_SendByte((Addr & 0xFF00) >> 8);
    /*!< Send SectorAddr low nibble address byte */
    sFLASH_SendByte(Addr & 0xFF);
    /*!< Deselect the FLASH: Chip Select high */
    sFLASH_CS_HIGH();

    /*!< Wait the end of Flash writing */
    sFLASH_WaitForWriteEnd();
}

/**
 * @brief  Erases the entire FLASH.
 */
void sFLASH_EraseChip(void)
{
    /*!< Send write enable instruction */
    sFLASH_WriteEnable();

    /*!< Bulk Erase */
    /*!< Select the FLASH: Chip Select low */
    sFLASH_CS_LOW();
    /*!< Send Bulk Erase instruction  */
    sFLASH_SendByte(sFLASH_CMD_CE);
    /*!< Deselect the FLASH: Chip Select high */
    sFLASH_CS_HIGH();

    /*!< Wait the end of Flash writing */
    sFLASH_WaitForWriteEnd();
}

/**
 * @brief  Writes more than one byte to the FLASH with a single WRITE cycle
 *         (Page WRITE sequence).
 * @note   The number of byte can't exceed the FLASH page size.
 * @param pBuffer pointer to the buffer  containing the data to be written
 *         to the FLASH.
 * @param WriteAddr FLASH's internal address to write to.
 * @param NumByteToWrite number of bytes to write to the FLASH, must be equal
 *         or less than "sFLASH_PAGESIZE" value.
 */
void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
    /*!< Enable the write access to the FLASH */
    sFLASH_WriteEnable();

    /*!< Select the FLASH: Chip Select low */
    sFLASH_CS_LOW();
    /*!< Send "Write to Memory " instruction */
    sFLASH_SendByte(sFLASH_CMD_WRITE);
    /*!< Send WriteAddr high nibble address byte to write to */
    sFLASH_SendByte((WriteAddr & 0xFF0000) >> 16);
    /*!< Send WriteAddr medium nibble address byte to write to */
    sFLASH_SendByte((WriteAddr & 0xFF00) >> 8);
    /*!< Send WriteAddr low nibble address byte to write to */
    sFLASH_SendByte(WriteAddr & 0xFF);

    /*!< while there is data to be written on the FLASH */
    while (NumByteToWrite--)
    {
        /*!< Send the current byte */
        sFLASH_SendByte(*pBuffer);
        /*!< Point on the next byte to be written */
        pBuffer++;
    }

    /*!< Deselect the FLASH: Chip Select high */
    sFLASH_CS_HIGH();

    /*!< Wait the end of Flash writing */
    sFLASH_WaitForWriteEnd();
}

/**
 * @brief  Writes block of data to the FLASH. In this function, the number of
 *         WRITE cycles are reduced, using Page WRITE sequence.
 * @param pBuffer pointer to the buffer  containing the data to be written
 *         to the FLASH.
 * @param WriteAddr FLASH's internal address to write to.
 * @param NumByteToWrite number of bytes to write to the FLASH.
 */
void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
    uint8_t NumOfPage = 0, NumOfSingle = 0, Addr = 0, count = 0, temp = 0;

    Addr        = WriteAddr % sFLASH_SPI_PAGESIZE;
    count       = sFLASH_SPI_PAGESIZE - Addr;
    NumOfPage   = NumByteToWrite / sFLASH_SPI_PAGESIZE;
    NumOfSingle = NumByteToWrite % sFLASH_SPI_PAGESIZE;

    if (Addr == 0) /*!< WriteAddr is sFLASH_PAGESIZE aligned  */
    {
        if (NumOfPage == 0) /*!< NumByteToWrite < sFLASH_PAGESIZE */
        {
            sFLASH_WritePage(pBuffer, WriteAddr, NumByteToWrite);
        }
        else /*!< NumByteToWrite > sFLASH_PAGESIZE */
        {
            while (NumOfPage--)
            {
                sFLASH_WritePage(pBuffer, WriteAddr, sFLASH_SPI_PAGESIZE);
                WriteAddr += sFLASH_SPI_PAGESIZE;
                pBuffer += sFLASH_SPI_PAGESIZE;
            }

            sFLASH_WritePage(pBuffer, WriteAddr, NumOfSingle);
        }
    }
    else /*!< WriteAddr is not sFLASH_PAGESIZE aligned  */
    {
        if (NumOfPage == 0) /*!< NumByteToWrite < sFLASH_PAGESIZE */
        {
            if (NumOfSingle > count) /*!< (NumByteToWrite + WriteAddr) > sFLASH_PAGESIZE */
            {
                temp = NumOfSingle - count;

                sFLASH_WritePage(pBuffer, WriteAddr, count);
                WriteAddr += count;
                pBuffer += count;

                sFLASH_WritePage(pBuffer, WriteAddr, temp);
            }
            else
            {
                sFLASH_WritePage(pBuffer, WriteAddr, NumByteToWrite);
            }
        }
        else /*!< NumByteToWrite > sFLASH_PAGESIZE */
        {
            NumByteToWrite -= count;
            NumOfPage   = NumByteToWrite / sFLASH_SPI_PAGESIZE;
            NumOfSingle = NumByteToWrite % sFLASH_SPI_PAGESIZE;

            sFLASH_WritePage(pBuffer, WriteAddr, count);
            WriteAddr += count;
            pBuffer += count;

            while (NumOfPage--)
            {
                sFLASH_WritePage(pBuffer, WriteAddr, sFLASH_SPI_PAGESIZE);
                WriteAddr += sFLASH_SPI_PAGESIZE;
                pBuffer += sFLASH_SPI_PAGESIZE;
            }

            if (NumOfSingle != 0)
            {
                sFLASH_WritePage(pBuffer, WriteAddr, NumOfSingle);
            }
        }
    }
}

/**
 * @brief  Reads a block of data from the FLASH.
 * @param pBuffer pointer to the buffer that receives the data read from the FLASH.
 * @param ReadAddr FLASH's internal address to read from.
 * @param NumByteToRead number of bytes to read from the FLASH.
 */
void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
{
    /*!< Select the FLASH: Chip Select low */
    sFLASH_CS_LOW();

    /*!< Send "Read from Memory " instruction */
    sFLASH_SendByte(sFLASH_CMD_READ);

    /*!< Send ReadAddr high nibble address byte to read from */
    sFLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
    /*!< Send ReadAddr medium nibble address byte to read from */
    sFLASH_SendByte((ReadAddr & 0xFF00) >> 8);
    /*!< Send ReadAddr low nibble address byte to read from */
    sFLASH_SendByte(ReadAddr & 0xFF);

    while (NumByteToRead--) /*!< while there is data to be read */
    {
        /*!< Read a byte from the FLASH */
        *pBuffer = sFLASH_SendByte(sFLASH_DUMMY_BYTE);
        /*!< Point to the next location where the byte read will be saved */
        pBuffer++;
    }

    /*!< Deselect the FLASH: Chip Select high */
    sFLASH_CS_HIGH();
}

/**
 * @brief  Reads FLASH identification.
 * @return FLASH identification
 */
uint32_t sFLASH_ReadID(void)
{
    uint32_t Temp = 0;
		uint8_t Temp0 = 0, Temp1 = 0, Temp2 = 0;

    /*!< Select the FLASH: Chip Select low */
    sFLASH_CS_LOW();


    /*!< Send "RDID " instruction */
    sFLASH_SendByte(0x9F);
    /*!< Read a byte from the FLASH */
    Temp0 = sFLASH_SendByte(sFLASH_DUMMY_BYTE);

    /*!< Read a byte from the FLASH */
    Temp1 = sFLASH_SendByte(sFLASH_DUMMY_BYTE);

    /*!< Read a byte from the FLASH */
    Temp2 = sFLASH_SendByte(sFLASH_DUMMY_BYTE);

    /*!< Deselect the FLASH: Chip Select high */
    sFLASH_CS_HIGH();


    Temp = (Temp0 << 16) | (Temp1 << 8) | Temp2;

    return Temp;
}

/**
 * @brief  Initiates a read data byte (READ) sequence from the Flash.
 *   This is done by driving the /CS line low to select the device, then the READ
 *   instruction is transmitted followed by 3 bytes address. This function exit
 *   and keep the /CS line low, so the Flash still being selected. With this
 *   technique the whole content of the Flash is read with a single READ instruction.
 * @param ReadAddr FLASH's internal address to read from.
 */
void sFLASH_StartReadSequence(uint32_t ReadAddr)
{
    /*!< Select the FLASH: Chip Select low */
    sFLASH_CS_LOW();

    /*!< Send "Read from Memory " instruction */
    sFLASH_SendByte(sFLASH_CMD_READ);

    /*!< Send the 24-bit address of the address to read from -------------------*/
    /*!< Send ReadAddr high nibble address byte */
    sFLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
    /*!< Send ReadAddr medium nibble address byte */
    sFLASH_SendByte((ReadAddr & 0xFF00) >> 8);
    /*!< Send ReadAddr low nibble address byte */
    sFLASH_SendByte(ReadAddr & 0xFF);
}

void sFLASH_EndReadSequence(void)
{
    sFLASH_CS_HIGH();
}

void sFLASH_ReadSequence(uint8_t *pBuffer, uint8_t NumByteToRead)
{
		int i = 0;
		for(i = 0;i<NumByteToRead;i++)
		{
				*pBuffer = sFLASH_SendByte(sFLASH_DUMMY_BYTE);
				pBuffer++;
		}
}

/**
 * @brief  Reads a byte from the SPI Flash.
 * @note   This function must be used only if the Start_Read_Sequence function
 *         has been previously called.
 * @return Byte Read from the SPI Flash.
 */
uint8_t sFLASH_ReadByte(void)
{
    return (sFLASH_SendByte(sFLASH_DUMMY_BYTE));
}


void sFLASH_CMD(uint8_t byte)
{
	  GPIO_ClearBit(GPIOF, GPIO_PIN_6);
    sFLASH_SendByte(byte);
	  GPIO_SetBit(GPIOF, GPIO_PIN_6);
}

/**
 * @brief  Sends a byte through the SPI interface and return the byte received
 *         from the SPI bus.
 * @param byte byte to send.
 * @return The value of the received byte.
 */
uint8_t sFLASH_SendByte(uint8_t byte)
{
//		uint16_t cnt=0;
    while (((uint16_t)(SPI2->STS & SPI_FLAG_TXBE)) == RESET) {
			//cnt++;
			//if(cnt>=65530)return 0; 	  //超时退出
		}
		*((uint8_t*) & (SPI2->DATA)) = byte;

//    cnt=0;
    while (((uint16_t)(SPI2->STS & SPI_FLAG_RXBNE)) == RESET) {
			//cnt++;
			//if(cnt>=65530) return 0; 	  //超时退出
		}
    return *((uint8_t*) & (SPI2->DATA));   //返回收到的数据	
		
		
//				uint16_t cnt=0;
//    while(SPI_ReadStatusFlag(SPI2,SPI_FLAG_TXBE) == RESET);//等待发送缓存区空
//    SPI_TxData8(SPI2,byte);
//    
//    
//    while(SPI_ReadStatusFlag(SPI2,SPI_FLAG_RXBNE) == RESET);//等待接收缓存区非空
//    
//    return SPI_RxData8(SPI2);

}

/**
 * @brief  Sends a Half Word through the SPI interface and return the Half Word
 *         received from the SPI bus.
 * @param HalfWord Half Word to send.
 * @return The value of the received Half Word.
 */
//uint16_t sFLASH_SendHalfWord(uint16_t HalfWord)
//{
//    /*!< Loop while DAT register in not emplty */
//    while (SPI_I2S_GetStatus(sFLASH_SPI, SPI_I2S_TE_FLAG) == RESET)
//        ;

//    /*!< Send Half Word through the sFLASH peripheral */
//    SPI_I2S_TransmitData(sFLASH_SPI, HalfWord);

//    /*!< Wait to receive a Half Word */
//    while (SPI_I2S_GetStatus(sFLASH_SPI, SPI_I2S_RNE_FLAG) == RESET)
//        ;

//    /*!< Return the Half Word read from the SPI bus */
//    return SPI_I2S_ReceiveData(sFLASH_SPI);
//}

/**
 * @brief  Enables the write access to the FLASH.
 */
void sFLASH_WriteEnable(void)
{
    /*!< Select the FLASH: Chip Select low */
    sFLASH_CS_LOW();

    /*!< Send "Write Enable" instruction */
    sFLASH_SendByte(sFLASH_CMD_WREN);

    /*!< Deselect the FLASH: Chip Select high */
    sFLASH_CS_HIGH();
}

/**
 * @brief .
 */
void sFLASH_None_Protect(void)
{
	Delay2(0xFFFFFF);
    uint8_t flashstatus = 0;
    sFLASH_CS_LOW();
		flashstatus = 0x55;
    sFLASH_SendByte(sFLASH_CMD_WRSR1);
    sFLASH_SendByte(flashstatus);
    sFLASH_CS_HIGH();
	Delay2(0xFFFF);

    do
    {
	  sFLASH_CS_LOW();
    sFLASH_SendByte(sFLASH_CMD_RDSR1);
     flashstatus = sFLASH_SendByte(sFLASH_DUMMY_BYTE);
     sFLASH_CS_HIGH();
	Delay2(0xFFFF);
   } while (flashstatus ==0xFF || flashstatus==0x01);
	

	
    sFLASH_CS_LOW();
    sFLASH_SendByte(sFLASH_CMD_RDSR2);
    do
    {
     flashstatus = sFLASH_SendByte(sFLASH_DUMMY_BYTE);
    } while (flashstatus ==0xFF);
	
    sFLASH_CS_HIGH();
	Delay2(0xFFFF);
	
    sFLASH_CS_LOW();
		flashstatus |= 0x40;
    sFLASH_SendByte(sFLASH_CMD_WRSR2);
    sFLASH_SendByte(flashstatus);
    sFLASH_CS_HIGH();
	Delay2(0xFFFF);
		

    sFLASH_CS_LOW();
    sFLASH_SendByte(sFLASH_CMD_RDSR3);
    flashstatus = sFLASH_SendByte(sFLASH_DUMMY_BYTE);
    sFLASH_CS_HIGH();
	Delay2(0xFFFF);
	
    sFLASH_CS_LOW();
		flashstatus &= 0xFB;
		flashstatus |= 0x80;
		sFLASH_SendByte(sFLASH_CMD_WRSR3);
    sFLASH_SendByte(flashstatus);
    sFLASH_CS_HIGH();
	Delay2(0xFFFF);


}

/**
 * @brief  Polls the status of the Write In Progress (WIP) flag in the FLASH's
 *         status register and loop until write opertaion has completed.
 */
void sFLASH_WaitForWriteEnd(void)
{
    uint8_t flashstatus = 0;

    /*!< Select the FLASH: Chip Select low */
    sFLASH_CS_LOW();

    /*!< Send "Read Status Register" instruction */
    sFLASH_SendByte(sFLASH_CMD_RDSR1);

    /*!< Loop as long as the memory is busy with a write cycle */
    do
    {
        /*!< Send a dummy byte to generate the clock needed by the FLASH
        and put the value of the status register in FLASH_STS variable */
        flashstatus = sFLASH_SendByte(sFLASH_DUMMY_BYTE);

    } while ((flashstatus & sFLASH_WIP_FLAG) == SET); /* Write in progress */

    /*!< Deselect the FLASH: Chip Select high */
    sFLASH_CS_HIGH();
}

/**
 * @}
 */

/**
 * @}
 */
