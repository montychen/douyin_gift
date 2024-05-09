#include "spi_flash.h"

/*!
 * @brief       SPI Write uint8_t data
 *
 * @param       None
 *
 * @retval      None
 *
 * @note
 */
 
static u16 cnt=0;				 

 
void SPI_WriteByte(uint8_t dat)
{
    while (SPI_ReadStatusFlag(SPI2, SPI_FLAG_TXBE) == RESET);

    SPI_TxData8(SPI2, dat);
}

u8 SPI_ReadWriteOneByte(uint8_t dat)
{
    while (((uint16_t)(SPI2->STS)) & ((uint16_t)SPI_FLAG_TXBE) == RESET) {
			cnt++;
			if(cnt>=65530)return 0; 	  //超时退出
		}
		*((uint8_t*) & (SPI2->DATA)) = dat;

    cnt=0;
    while (((uint16_t)(SPI2->STS)) & ((uint16_t)SPI_FLAG_RXBNE) == RESET) {
			cnt++;
			if(cnt>=65530) return 0; 	  //超时退出
		}
    return *((uint8_t*) & (SPI2->DATA));   //返回收到的数据	
}

u16 W25Q64_ReadID(void)
{

	u16 id;

	/*1. 拉低片选*/

	GPIO_WriteBitValue(GPIOF, GPIO_PIN_6, Bit_RESET);

	

	/*2. 发送读取ID的指令*/

	SPI_ReadWriteOneByte(0x90);

	

	/*3. 发送24位的地址-0*/

	SPI_ReadWriteOneByte(0);

	SPI_ReadWriteOneByte(0);

	SPI_ReadWriteOneByte(0);

	

	/*4. 读取芯片的ID*/

	id=SPI_ReadWriteOneByte(0xFF)<<8;

	id|=SPI_ReadWriteOneByte(0xFF);

 

	/*5. 拉高片选*/

	GPIO_WriteBitValue(GPIOF, GPIO_PIN_6, Bit_SET);

	return id;

}
/*!
 * @brief       SPI Init
 *
 * @param       None
 *
 * @retval      None
 *
 * @note
 */
void SPI_Init()
{

    GPIO_Config_T gpioConfig;
    SPI_Config_T spiConfig;
	
    SPI_Disable(SPI2);

    /* Enable related Clock */
    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_SPI2);
    RCM_EnableAHBPeriphClock(RCM_AHB_PERIPH_GPIOA);
    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_SYSCFG);

    /* config PIN_14  MISO */
    gpioConfig.pin =  GPIO_PIN_14 ;
    gpioConfig.mode = GPIO_MODE_AF;
    gpioConfig.outtype = GPIO_OUT_TYPE_OD;
    gpioConfig.pupd = GPIO_PUPD_NO;
    gpioConfig.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOB, &gpioConfig);

    /* config PIN_13->SCK , PIN_15->MOSI */
    gpioConfig.pin = GPIO_PIN_13 | GPIO_PIN_15;
    gpioConfig.mode = GPIO_MODE_AF;
    gpioConfig.pupd = GPIO_PUPD_PU;
    gpioConfig.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOB, &gpioConfig);

    GPIO_ConfigPinAF(GPIOB, GPIO_PIN_SOURCE_13, GPIO_AF_PIN0);
    GPIO_ConfigPinAF(GPIOB, GPIO_PIN_SOURCE_14, GPIO_AF_PIN0);
    GPIO_ConfigPinAF(GPIOB, GPIO_PIN_SOURCE_15, GPIO_AF_PIN0);

		//CS
		gpioConfig.pin= (GPIO_PIN_6);
    gpioConfig.mode = GPIO_MODE_OUT;
    gpioConfig.outtype = GPIO_OUT_TYPE_PP;
    gpioConfig.speed = GPIO_SPEED_50MHz;
    gpioConfig.pupd = GPIO_PUPD_PU;	
		GPIO_Config(GPIOF,&gpioConfig);
		GPIO_WriteBitValue(GPIOF, GPIO_PIN_6, Bit_SET);


    SPI_ConfigStructInit(&spiConfig);

    spiConfig.length = SPI_DATA_LENGTH_8B;

    spiConfig.baudrateDiv = SPI_BAUDRATE_DIV_32;
    /*  2 line full duplex  */
    spiConfig.direction = SPI_DIRECTION_2LINES_FULLDUPLEX;
    /*  LSB first  */
    spiConfig.firstBit = SPI_FIRST_BIT_MSB;
    /*  Slave mode  */
    spiConfig.mode = SPI_MODE_MASTER;
    /*  Polarity is high  */
    spiConfig.polarity = SPI_CLKPOL_HIGH;
    /*  Software select slave enable  */
    spiConfig.slaveSelect = SPI_SSC_ENABLE;
    /*  Phase is 2 edge  */
    spiConfig.phase = SPI_CLKPHA_2EDGE;
    /*  SPI config  */
    SPI_Config(SPI2, &spiConfig);

    SPI_ConfigFIFOThreshold(SPI2, SPI_RXFIFO_QUARTER);

    SPI_Enable(SPI2);
}

