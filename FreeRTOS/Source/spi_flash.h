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
 * @file spi_flash.h
 * @author Nations
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#ifndef __SPI_FLASH_H__
#define __SPI_FLASH_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "public.h"
#include "apm32f0xx.h"
#include "apm32f0xx_spi.h"

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
 * @{
 */

/** @addtogroup SPI_FLASH_Exported_Types
 * @{
 */
/**
 * @}
 */

/** @addtogroup SPI_FLASH_Exported_Constants
 * @{
 */
/**
 * @brief  SPI Flash supported commands
 */
#define sFLASH_CMD_WRITE 		0x02 /*!< Write to Memory instruction */
#define sFLASH_CMD_WRSR1  		0x01 /*!< Write Status Register instruction */
#define sFLASH_CMD_WRSR2  		0x31 /*!< Write Status Register instruction */
#define sFLASH_CMD_WRSR3  		0x11 /*!< Write Status Register instruction */
#define sFLASH_CMD_WREN  		0x06 /*!< Write enable instruction */
#define sFLASH_CMD_READ  		0x03 /*!< Read from Memory instruction */
#define sFLASH_CMD_RDSR1  		0x05 /*!< Read Status Register instruction  */
#define sFLASH_CMD_RDSR2  		0x35 /*!< Read Status Register instruction  */
#define sFLASH_CMD_RDSR3  		0x15 /*!< Read Status Register instruction  */
#define sFLASH_CMD_RDID  		0x9F /*!< Read identification */
#define sFLASH_CMD_SE    		0x20 /*!< Sector Erase instruction */
#define sFLASH_CMD_BE    		0xD8 /*!< Block Erase instruction */
#define sFLASH_CMD_CE    		0xC7 /*!< Chip Erase instruction */
#define sFLASH_CMD_RST_EN   0x66 /*!< Enable Reset instruction */
#define sFLASH_CMD_RST   		0x99 /*!< Reset Device instruction */

#define sFLASH_WIP_FLAG 		0x01 /*!< Write In Progress (WIP) flag */

#define sFLASH_DUMMY_BYTE   0xA5
#define sFLASH_SPI_PAGESIZE 0x100           //page sector block

#define sFLASH_W25Q128_ID 0x00EF4018
#define sFLASH_W25Q16_ID 0x00EF4015
#define sFLASH_M25P64_ID  0x202017
#define sFLASH_GD25Q64_ID  0xC84017   //128blocks  16sector/block  16pages/sector 4096bytes/sector 256bytes/page

#define sFLASH_SPI                SPI2
#define sFLASH_SPI_CLK            RCM_APB1_PERIPH_SPI2
#define sFLASH_SPI_SCK_PIN        GPIO_PIN_13 /* PB.13 */
#define sFLASH_SPI_SCK_GPIO_PORT  GPIOB      /* GPIOB */
#define sFLASH_SPI_SCK_GPIO_CLK   RCM_AHB_PERIPH_GPIOB
#define sFLASH_SPI_MISO_PIN       GPIO_PIN_14 /* PB.14 */
#define sFLASH_SPI_MISO_GPIO_PORT GPIOB      /* GPIOB */
#define sFLASH_SPI_MISO_GPIO_CLK  RCM_AHB_PERIPH_GPIOB
#define sFLASH_SPI_MOSI_PIN       GPIO_PIN_15 /* PB.15 */
#define sFLASH_SPI_MOSI_GPIO_PORT GPIOB      /* GPIOB */
#define sFLASH_SPI_MOSI_GPIO_CLK  RCM_AHB_PERIPH_GPIOB
#define sFLASH_CS_PIN             GPIO_PIN_6 /* PF.06 */
#define sFLASH_CS_GPIO_PORT       GPIOF      /* GPIOF */
#define sFLASH_CS_GPIO_CLK        RCM_AHB_PERIPH_GPIOF
/**
 * @}
 */

/** @addtogroup SPI_FLASH_Exported_Macros
 * @{
 */
/**
 * @brief  Select sFLASH: Chip Select pin low
 */
#define sFLASH_CS_LOW() GPIO_ClearBit(sFLASH_CS_GPIO_PORT, sFLASH_CS_PIN)
/**
 * @brief  Deselect sFLASH: Chip Select pin high
 */
#define sFLASH_CS_HIGH() GPIO_SetBit(sFLASH_CS_GPIO_PORT, sFLASH_CS_PIN)
/**
 * @}
 */

/** @addtogroup SPI_FLASH_Exported_Functions
 * @{
 */
/**
 * @brief  High layer functions
 */
u8 sFlash_sbyte(u8 dat);
void sFLASH_DeInit(void);
void sFLASH_Init(void);
void sFLASH_EraseSector(uint32_t Addr);
void sFLASH_EraseBlock(uint32_t Addr);
void sFLASH_EraseChip(void);
void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead);
uint32_t sFLASH_ReadID(void);
void sFLASH_StartReadSequence(uint32_t ReadAddr);
void sFLASH_EndReadSequence(void);
void sFLASH_ReadSequence(uint8_t *pBuffer, uint8_t NumByteToRead);

/**
 * @brief  Low layer functions
 */
uint8_t sFLASH_ReadByte(void);
uint8_t sFLASH_SendByte(uint8_t byte);
uint16_t sFLASH_SendHalfWord(uint16_t HalfWord);
void sFLASH_WriteEnable(void);
void sFLASH_CMD(uint8_t byte);
void sFLASH_WaitForWriteEnd(void);
void sFLASH_None_Protect(void);

#ifdef __cplusplus
}
#endif

#endif
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
